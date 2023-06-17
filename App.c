/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: APP.c
 *
 * Description: Source file for the Application Layer
 *
 * Author: Abdelmonem Magdi
 *
 *******************************************************************************/

#include "keypad.h"
#include "lcd.h"
#include <util/delay.h>

/*
 * Description :
 * Calculate The Result Between 2 Numbers
 * Add / Sub / Divide / MUL
 */

sint32 calc(sint32 v1 , sint32 v2 , uint8 c)
{
	sint32 Res = 0 ;

	switch(c)
	{
	case '+':
		Res = v1 + v2 ;
		break ;
	case '-':
		Res = v1 - v2 ;
		break;
	case '/':
		Res = v1 / v2 ;
		break;
	case '*':
		Res = v1 * v2 ;
		break;
	default:
		break;
	}

	return Res;
}

/* This Code is Written for solving Simple Calculation between 2 numbers only*/

int main(void)
{
	/* Using Flag To Control Which Var should be stored in*/
	uint8 key = 0 , op = '+' , flag = 0 ;

	sint32 var1 = 0 , var2 = 0 ;

	LCD_init() ; /* Initialization LCD */

	while(1)
	{
		key = KEYPAD_getPressedKey();

		if(key == '=') /* Equal and Calculate The Result */
		{
			LCD_moveCursor(1,10); /* move the cursor to Row 1 and column 10 */
			var1 = calc(var1,var2,op);
			LCD_intgerToString(var1);
			flag = 2 ;
			var2 = 0 ;
		}
		else if(key == 13) /* on/off Button to (Clear The LCD) */
		{
			LCD_clearScreen(); // Clear Screen
			var1 = 0 ;
			flag = 0 ;
			var2 = 0 ;
		}
		else if((key >= 0) && (key <= 9)) /* Store The 2 Numbers */
		{
			if(flag == 0)
			{
				var1 = (var1 * 10) + key ;
				LCD_intgerToString(key);
			}
			else
			{
				var2 = (var2 * 10) + key ;
				LCD_intgerToString(key);
			}
		}
		else /* Enter here if The operator's Button was pressed */
		{
			/* Enter here if the user wants to perform a calculation
			 * on the previous output */
			if(flag == 2)
			{
				LCD_clearScreen(); // Clear Screen
				LCD_displayString("Ans");
			}

			op = key ;
			LCD_displayCharacter(key);
			flag = 1 ;

		}

		_delay_ms(500);
	}
}
