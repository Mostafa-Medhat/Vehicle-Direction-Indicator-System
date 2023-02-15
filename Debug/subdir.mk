################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_config.c \
../PollingDataClient.c \
../Timer1_PWM.c \
../device.c \
../gpio.c \
../main.c \
../pwm_timer0.c \
../pwm_timer2.c 

OBJS += \
./DIO_config.o \
./PollingDataClient.o \
./Timer1_PWM.o \
./device.o \
./gpio.o \
./main.o \
./pwm_timer0.o \
./pwm_timer2.o 

C_DEPS += \
./DIO_config.d \
./PollingDataClient.d \
./Timer1_PWM.d \
./device.d \
./gpio.d \
./main.d \
./pwm_timer0.d \
./pwm_timer2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\4th year\Embedded\projects\FinalProject\Vehicle-Direction-FinalProject\Source\include" -I"E:\4th year\Embedded\projects\FinalProject\Vehicle-Direction-FinalProject\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega64 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


