################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/KEYPAD/keypad.c 

OBJS += \
./Src/HAL/KEYPAD/keypad.o 

C_DEPS += \
./Src/HAL/KEYPAD/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/KEYPAD/%.o: ../Src/HAL/KEYPAD/%.c Src/HAL/KEYPAD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


