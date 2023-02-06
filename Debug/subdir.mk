################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_config.c \
../PollingDataClient.c \
../TimerCompareMode.c \
../device.c \
../gpio.c \
../lcd.c \
../main.c \
../poller.c \
../pwm.c 

OBJS += \
./DIO_config.o \
./PollingDataClient.o \
./TimerCompareMode.o \
./device.o \
./gpio.o \
./lcd.o \
./main.o \
./poller.o \
./pwm.o 

C_DEPS += \
./DIO_config.d \
./PollingDataClient.d \
./TimerCompareMode.d \
./device.d \
./gpio.d \
./lcd.d \
./main.d \
./poller.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


