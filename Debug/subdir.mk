################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../EXTI_prog.c \
../GIE_program.c \
../LCD_prog.c \
../UART_Prog.c \
../croutine.c \
../event_groups.c \
../heap_2.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../stream_buffer.c \
../tasks.c \
../timers.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./EXTI_prog.o \
./GIE_program.o \
./LCD_prog.o \
./UART_Prog.o \
./croutine.o \
./event_groups.o \
./heap_2.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./stream_buffer.o \
./tasks.o \
./timers.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./EXTI_prog.d \
./GIE_program.d \
./LCD_prog.d \
./UART_Prog.d \
./croutine.d \
./event_groups.d \
./heap_2.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./stream_buffer.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


