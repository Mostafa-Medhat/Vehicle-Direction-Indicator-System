################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/GCC/ATMega323/port.c 

OBJS += \
./Source/portable/GCC/ATMega323/port.o 

C_DEPS += \
./Source/portable/GCC/ATMega323/port.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/GCC/ATMega323/%.o: ../Source/portable/GCC/ATMega323/%.c Source/portable/GCC/ATMega323/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse_V2\workspaces\AdvEmbedded_Project\Vehicle-Direction-FinalProject\Source\include" -I"D:\Eclipse_V2\workspaces\AdvEmbedded_Project\Vehicle-Direction-FinalProject\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega64 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


