################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/middleware/usb_device/Class/MSC/Src/usbd_msc.c \
../lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.c \
../lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.c \
../lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.c \
../lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.c 

OBJS += \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc.o \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.o \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.o \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.o \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.o 

C_DEPS += \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc.d \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.d \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.d \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.d \
./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.d 


# Each subdirectory must supply rules for building sources it contributes
lib/middleware/usb_device/Class/MSC/Src/%.o lib/middleware/usb_device/Class/MSC/Src/%.su: ../lib/middleware/usb_device/Class/MSC/Src/%.c lib/middleware/usb_device/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -c -I../appli -I../lib/hal/inc -I../lib/bsp -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/lis302dl -I../lib/bsp/lis3dsh -I../lib/bsp/audio -I../lib/bsp/ov9655 -I../lib/bsp/stmpe811 -I../lib/bsp/LCD -I../lib/middleware/ -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../lib/middleware/webserver -I../lib/middleware/webserver/lwip -I../lib/middleware/webserver/lwip/src/include -I../lib/middleware/webserver/lwip/system -I../lib/middleware/webserver/lwip/src/include/ipv4 -I../lib/middleware/webserver/lwip/src/include/lwip -I../lib/middleware/webserver/lwip/port -I../lib/middleware/webserver/STD_lib -I../lib/middleware/usb_device/Class/HID/Inc -I../lib/middleware/usb_device/Class/MSC/Inc -I../lib/middleware/usb_device/Core/Inc -I../lib/middleware/usb_host/Class/MSC/Inc -I../lib/middleware/usb_host/Core/Inc -I../lib/middleware/usb_host/Class/HID/Inc -I../lib/middleware/usb_host/ -I../lib/middleware/PDM -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-middleware-2f-usb_device-2f-Class-2f-MSC-2f-Src

clean-lib-2f-middleware-2f-usb_device-2f-Class-2f-MSC-2f-Src:
	-$(RM) ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc.d ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc.o ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc.su ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.d ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.o ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_bot.su ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.d ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.o ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_data.su ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.d ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.o ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_scsi.su ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.d ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.o ./lib/middleware/usb_device/Class/MSC/Src/usbd_msc_storage_template.su

.PHONY: clean-lib-2f-middleware-2f-usb_device-2f-Class-2f-MSC-2f-Src

