################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_config.c \
../PollingDataClient.c \
../Timer1_PWM.c \
../TimerCompareMode.c \
../device.c \
../gpio.c \
../lcd.c \
../main.c \
../poller.c 

OBJS += \
./DIO_config.o \
./PollingDataClient.o \
./Timer1_PWM.o \
./TimerCompareMode.o \
./device.o \
./gpio.o \
./lcd.o \
./main.o \
./poller.o 

C_DEPS += \
./DIO_config.d \
./PollingDataClient.d \
./Timer1_PWM.d \
./TimerCompareMode.d \
./device.d \
./gpio.d \
./lcd.d \
./main.d \
./poller.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse_V2\workspaces\AdvEmbedded_Project\Vehicle-Direction-FinalProject\Source\include" -I"D:\Eclipse_V2\workspaces\AdvEmbedded_Project\Vehicle-Direction-FinalProject\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega64 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


