################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IR.c \
../LCD.c \
../Test-1.c \
../Ultrasonic.c \
../motors.c 

OBJS += \
./IR.o \
./LCD.o \
./Test-1.o \
./Ultrasonic.o \
./motors.o 

C_DEPS += \
./IR.d \
./LCD.d \
./Test-1.d \
./Ultrasonic.d \
./motors.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


