################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/fonts.c \
../lib/bsp/stm32f4_accelerometer.c \
../lib/bsp/stm32f4_discovery.c \
../lib/bsp/stm32f4_gpio.c \
../lib/bsp/stm32f4_i2c.c \
../lib/bsp/stm32f4_lcd.c \
../lib/bsp/stm32f4_spi.c \
../lib/bsp/stm32f4_sys.c \
../lib/bsp/stm32f4_timer.c \
../lib/bsp/stm32f4_uart.c \
../lib/bsp/systick.c 

OBJS += \
./lib/bsp/fonts.o \
./lib/bsp/stm32f4_accelerometer.o \
./lib/bsp/stm32f4_discovery.o \
./lib/bsp/stm32f4_gpio.o \
./lib/bsp/stm32f4_i2c.o \
./lib/bsp/stm32f4_lcd.o \
./lib/bsp/stm32f4_spi.o \
./lib/bsp/stm32f4_sys.o \
./lib/bsp/stm32f4_timer.o \
./lib/bsp/stm32f4_uart.o \
./lib/bsp/systick.o 

C_DEPS += \
./lib/bsp/fonts.d \
./lib/bsp/stm32f4_accelerometer.d \
./lib/bsp/stm32f4_discovery.d \
./lib/bsp/stm32f4_gpio.d \
./lib/bsp/stm32f4_i2c.d \
./lib/bsp/stm32f4_lcd.d \
./lib/bsp/stm32f4_spi.d \
./lib/bsp/stm32f4_sys.d \
./lib/bsp/stm32f4_timer.d \
./lib/bsp/stm32f4_uart.d \
./lib/bsp/systick.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/%.o lib/bsp/%.su: ../lib/bsp/%.c lib/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -c -I../appli -I../lib/hal/inc -I../lib/bsp -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/lis302dl -I../lib/bsp/lis3dsh -I../lib/bsp/audio -I../lib/bsp/ov9655 -I../lib/bsp/stmpe811 -I../lib/bsp/LCD -I../lib/middleware/ -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../lib/middleware/webserver -I../lib/middleware/webserver/lwip -I../lib/middleware/webserver/lwip/src/include -I../lib/middleware/webserver/lwip/system -I../lib/middleware/webserver/lwip/src/include/ipv4 -I../lib/middleware/webserver/lwip/src/include/lwip -I../lib/middleware/webserver/lwip/port -I../lib/middleware/webserver/STD_lib -I../lib/middleware/usb_device/Class/HID/Inc -I../lib/middleware/usb_device/Class/MSC/Inc -I../lib/middleware/usb_device/Core/Inc -I../lib/middleware/usb_host/Class/MSC/Inc -I../lib/middleware/usb_host/Core/Inc -I../lib/middleware/usb_host/Class/HID/Inc -I../lib/middleware/usb_host/ -I../lib/middleware/PDM -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-bsp

clean-lib-2f-bsp:
	-$(RM) ./lib/bsp/fonts.d ./lib/bsp/fonts.o ./lib/bsp/fonts.su ./lib/bsp/stm32f4_accelerometer.d ./lib/bsp/stm32f4_accelerometer.o ./lib/bsp/stm32f4_accelerometer.su ./lib/bsp/stm32f4_discovery.d ./lib/bsp/stm32f4_discovery.o ./lib/bsp/stm32f4_discovery.su ./lib/bsp/stm32f4_gpio.d ./lib/bsp/stm32f4_gpio.o ./lib/bsp/stm32f4_gpio.su ./lib/bsp/stm32f4_i2c.d ./lib/bsp/stm32f4_i2c.o ./lib/bsp/stm32f4_i2c.su ./lib/bsp/stm32f4_lcd.d ./lib/bsp/stm32f4_lcd.o ./lib/bsp/stm32f4_lcd.su ./lib/bsp/stm32f4_spi.d ./lib/bsp/stm32f4_spi.o ./lib/bsp/stm32f4_spi.su ./lib/bsp/stm32f4_sys.d ./lib/bsp/stm32f4_sys.o ./lib/bsp/stm32f4_sys.su ./lib/bsp/stm32f4_timer.d ./lib/bsp/stm32f4_timer.o ./lib/bsp/stm32f4_timer.su ./lib/bsp/stm32f4_uart.d ./lib/bsp/stm32f4_uart.o ./lib/bsp/stm32f4_uart.su ./lib/bsp/systick.d ./lib/bsp/systick.o ./lib/bsp/systick.su

.PHONY: clean-lib-2f-bsp

