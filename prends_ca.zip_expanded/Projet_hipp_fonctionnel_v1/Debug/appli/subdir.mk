################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../appli/demo_accelerometer.c \
../appli/demo_camera.c \
../appli/main.c \
../appli/nrf24l01.c 

OBJS += \
./appli/demo_accelerometer.o \
./appli/demo_camera.o \
./appli/main.o \
./appli/nrf24l01.o 

C_DEPS += \
./appli/demo_accelerometer.d \
./appli/demo_camera.d \
./appli/main.d \
./appli/nrf24l01.d 


# Each subdirectory must supply rules for building sources it contributes
appli/%.o appli/%.su: ../appli/%.c appli/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -c -I../appli -I../lib/hal/inc -I../lib/bsp -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/lis302dl -I../lib/bsp/lis3dsh -I../lib/bsp/audio -I../lib/bsp/ov9655 -I../lib/bsp/stmpe811 -I../lib/bsp/LCD -I../lib/middleware/ -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../lib/middleware/webserver -I../lib/middleware/webserver/lwip -I../lib/middleware/webserver/lwip/src/include -I../lib/middleware/webserver/lwip/system -I../lib/middleware/webserver/lwip/src/include/ipv4 -I../lib/middleware/webserver/lwip/src/include/lwip -I../lib/middleware/webserver/lwip/port -I../lib/middleware/webserver/STD_lib -I../lib/middleware/usb_device/Class/HID/Inc -I../lib/middleware/usb_device/Class/MSC/Inc -I../lib/middleware/usb_device/Core/Inc -I../lib/middleware/usb_host/Class/MSC/Inc -I../lib/middleware/usb_host/Core/Inc -I../lib/middleware/usb_host/Class/HID/Inc -I../lib/middleware/usb_host/ -I../lib/middleware/PDM -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-appli

clean-appli:
	-$(RM) ./appli/demo_accelerometer.d ./appli/demo_accelerometer.o ./appli/demo_accelerometer.su ./appli/demo_camera.d ./appli/demo_camera.o ./appli/demo_camera.su ./appli/main.d ./appli/main.o ./appli/main.su ./appli/nrf24l01.d ./appli/nrf24l01.o ./appli/nrf24l01.su

.PHONY: clean-appli

