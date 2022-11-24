################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/src/stm32f4xx_hal.c \
../lib/hal/src/stm32f4xx_hal_adc.c \
../lib/hal/src/stm32f4xx_hal_adc_ex.c \
../lib/hal/src/stm32f4xx_hal_can.c \
../lib/hal/src/stm32f4xx_hal_cec.c \
../lib/hal/src/stm32f4xx_hal_cortex.c \
../lib/hal/src/stm32f4xx_hal_crc.c \
../lib/hal/src/stm32f4xx_hal_cryp.c \
../lib/hal/src/stm32f4xx_hal_cryp_ex.c \
../lib/hal/src/stm32f4xx_hal_dac.c \
../lib/hal/src/stm32f4xx_hal_dac_ex.c \
../lib/hal/src/stm32f4xx_hal_dcmi.c \
../lib/hal/src/stm32f4xx_hal_dcmi_ex.c \
../lib/hal/src/stm32f4xx_hal_dma.c \
../lib/hal/src/stm32f4xx_hal_dma2d.c \
../lib/hal/src/stm32f4xx_hal_dma_ex.c \
../lib/hal/src/stm32f4xx_hal_eth.c \
../lib/hal/src/stm32f4xx_hal_flash.c \
../lib/hal/src/stm32f4xx_hal_flash_ex.c \
../lib/hal/src/stm32f4xx_hal_flash_ramfunc.c \
../lib/hal/src/stm32f4xx_hal_fmpi2c.c \
../lib/hal/src/stm32f4xx_hal_fmpi2c_ex.c \
../lib/hal/src/stm32f4xx_hal_gpio.c \
../lib/hal/src/stm32f4xx_hal_hash.c \
../lib/hal/src/stm32f4xx_hal_hash_ex.c \
../lib/hal/src/stm32f4xx_hal_hcd.c \
../lib/hal/src/stm32f4xx_hal_i2c.c \
../lib/hal/src/stm32f4xx_hal_i2c_ex.c \
../lib/hal/src/stm32f4xx_hal_i2s.c \
../lib/hal/src/stm32f4xx_hal_i2s_ex.c \
../lib/hal/src/stm32f4xx_hal_irda.c \
../lib/hal/src/stm32f4xx_hal_iwdg.c \
../lib/hal/src/stm32f4xx_hal_ltdc.c \
../lib/hal/src/stm32f4xx_hal_msp_template.c \
../lib/hal/src/stm32f4xx_hal_nand.c \
../lib/hal/src/stm32f4xx_hal_nor.c \
../lib/hal/src/stm32f4xx_hal_pccard.c \
../lib/hal/src/stm32f4xx_hal_pcd.c \
../lib/hal/src/stm32f4xx_hal_pcd_ex.c \
../lib/hal/src/stm32f4xx_hal_pwr.c \
../lib/hal/src/stm32f4xx_hal_pwr_ex.c \
../lib/hal/src/stm32f4xx_hal_qspi.c \
../lib/hal/src/stm32f4xx_hal_rcc.c \
../lib/hal/src/stm32f4xx_hal_rcc_ex.c \
../lib/hal/src/stm32f4xx_hal_rng.c \
../lib/hal/src/stm32f4xx_hal_rtc.c \
../lib/hal/src/stm32f4xx_hal_rtc_ex.c \
../lib/hal/src/stm32f4xx_hal_sai.c \
../lib/hal/src/stm32f4xx_hal_sai_ex.c \
../lib/hal/src/stm32f4xx_hal_sd.c \
../lib/hal/src/stm32f4xx_hal_sdram.c \
../lib/hal/src/stm32f4xx_hal_smartcard.c \
../lib/hal/src/stm32f4xx_hal_spdifrx.c \
../lib/hal/src/stm32f4xx_hal_spi.c \
../lib/hal/src/stm32f4xx_hal_sram.c \
../lib/hal/src/stm32f4xx_hal_tim.c \
../lib/hal/src/stm32f4xx_hal_tim_ex.c \
../lib/hal/src/stm32f4xx_hal_uart.c \
../lib/hal/src/stm32f4xx_hal_usart.c \
../lib/hal/src/stm32f4xx_hal_wwdg.c \
../lib/hal/src/stm32f4xx_ll_fmc.c \
../lib/hal/src/stm32f4xx_ll_fsmc.c \
../lib/hal/src/stm32f4xx_ll_sdmmc.c \
../lib/hal/src/stm32f4xx_ll_usb.c \
../lib/hal/src/system_stm32f4xx.c 

OBJS += \
./lib/hal/src/stm32f4xx_hal.o \
./lib/hal/src/stm32f4xx_hal_adc.o \
./lib/hal/src/stm32f4xx_hal_adc_ex.o \
./lib/hal/src/stm32f4xx_hal_can.o \
./lib/hal/src/stm32f4xx_hal_cec.o \
./lib/hal/src/stm32f4xx_hal_cortex.o \
./lib/hal/src/stm32f4xx_hal_crc.o \
./lib/hal/src/stm32f4xx_hal_cryp.o \
./lib/hal/src/stm32f4xx_hal_cryp_ex.o \
./lib/hal/src/stm32f4xx_hal_dac.o \
./lib/hal/src/stm32f4xx_hal_dac_ex.o \
./lib/hal/src/stm32f4xx_hal_dcmi.o \
./lib/hal/src/stm32f4xx_hal_dcmi_ex.o \
./lib/hal/src/stm32f4xx_hal_dma.o \
./lib/hal/src/stm32f4xx_hal_dma2d.o \
./lib/hal/src/stm32f4xx_hal_dma_ex.o \
./lib/hal/src/stm32f4xx_hal_eth.o \
./lib/hal/src/stm32f4xx_hal_flash.o \
./lib/hal/src/stm32f4xx_hal_flash_ex.o \
./lib/hal/src/stm32f4xx_hal_flash_ramfunc.o \
./lib/hal/src/stm32f4xx_hal_fmpi2c.o \
./lib/hal/src/stm32f4xx_hal_fmpi2c_ex.o \
./lib/hal/src/stm32f4xx_hal_gpio.o \
./lib/hal/src/stm32f4xx_hal_hash.o \
./lib/hal/src/stm32f4xx_hal_hash_ex.o \
./lib/hal/src/stm32f4xx_hal_hcd.o \
./lib/hal/src/stm32f4xx_hal_i2c.o \
./lib/hal/src/stm32f4xx_hal_i2c_ex.o \
./lib/hal/src/stm32f4xx_hal_i2s.o \
./lib/hal/src/stm32f4xx_hal_i2s_ex.o \
./lib/hal/src/stm32f4xx_hal_irda.o \
./lib/hal/src/stm32f4xx_hal_iwdg.o \
./lib/hal/src/stm32f4xx_hal_ltdc.o \
./lib/hal/src/stm32f4xx_hal_msp_template.o \
./lib/hal/src/stm32f4xx_hal_nand.o \
./lib/hal/src/stm32f4xx_hal_nor.o \
./lib/hal/src/stm32f4xx_hal_pccard.o \
./lib/hal/src/stm32f4xx_hal_pcd.o \
./lib/hal/src/stm32f4xx_hal_pcd_ex.o \
./lib/hal/src/stm32f4xx_hal_pwr.o \
./lib/hal/src/stm32f4xx_hal_pwr_ex.o \
./lib/hal/src/stm32f4xx_hal_qspi.o \
./lib/hal/src/stm32f4xx_hal_rcc.o \
./lib/hal/src/stm32f4xx_hal_rcc_ex.o \
./lib/hal/src/stm32f4xx_hal_rng.o \
./lib/hal/src/stm32f4xx_hal_rtc.o \
./lib/hal/src/stm32f4xx_hal_rtc_ex.o \
./lib/hal/src/stm32f4xx_hal_sai.o \
./lib/hal/src/stm32f4xx_hal_sai_ex.o \
./lib/hal/src/stm32f4xx_hal_sd.o \
./lib/hal/src/stm32f4xx_hal_sdram.o \
./lib/hal/src/stm32f4xx_hal_smartcard.o \
./lib/hal/src/stm32f4xx_hal_spdifrx.o \
./lib/hal/src/stm32f4xx_hal_spi.o \
./lib/hal/src/stm32f4xx_hal_sram.o \
./lib/hal/src/stm32f4xx_hal_tim.o \
./lib/hal/src/stm32f4xx_hal_tim_ex.o \
./lib/hal/src/stm32f4xx_hal_uart.o \
./lib/hal/src/stm32f4xx_hal_usart.o \
./lib/hal/src/stm32f4xx_hal_wwdg.o \
./lib/hal/src/stm32f4xx_ll_fmc.o \
./lib/hal/src/stm32f4xx_ll_fsmc.o \
./lib/hal/src/stm32f4xx_ll_sdmmc.o \
./lib/hal/src/stm32f4xx_ll_usb.o \
./lib/hal/src/system_stm32f4xx.o 

C_DEPS += \
./lib/hal/src/stm32f4xx_hal.d \
./lib/hal/src/stm32f4xx_hal_adc.d \
./lib/hal/src/stm32f4xx_hal_adc_ex.d \
./lib/hal/src/stm32f4xx_hal_can.d \
./lib/hal/src/stm32f4xx_hal_cec.d \
./lib/hal/src/stm32f4xx_hal_cortex.d \
./lib/hal/src/stm32f4xx_hal_crc.d \
./lib/hal/src/stm32f4xx_hal_cryp.d \
./lib/hal/src/stm32f4xx_hal_cryp_ex.d \
./lib/hal/src/stm32f4xx_hal_dac.d \
./lib/hal/src/stm32f4xx_hal_dac_ex.d \
./lib/hal/src/stm32f4xx_hal_dcmi.d \
./lib/hal/src/stm32f4xx_hal_dcmi_ex.d \
./lib/hal/src/stm32f4xx_hal_dma.d \
./lib/hal/src/stm32f4xx_hal_dma2d.d \
./lib/hal/src/stm32f4xx_hal_dma_ex.d \
./lib/hal/src/stm32f4xx_hal_eth.d \
./lib/hal/src/stm32f4xx_hal_flash.d \
./lib/hal/src/stm32f4xx_hal_flash_ex.d \
./lib/hal/src/stm32f4xx_hal_flash_ramfunc.d \
./lib/hal/src/stm32f4xx_hal_fmpi2c.d \
./lib/hal/src/stm32f4xx_hal_fmpi2c_ex.d \
./lib/hal/src/stm32f4xx_hal_gpio.d \
./lib/hal/src/stm32f4xx_hal_hash.d \
./lib/hal/src/stm32f4xx_hal_hash_ex.d \
./lib/hal/src/stm32f4xx_hal_hcd.d \
./lib/hal/src/stm32f4xx_hal_i2c.d \
./lib/hal/src/stm32f4xx_hal_i2c_ex.d \
./lib/hal/src/stm32f4xx_hal_i2s.d \
./lib/hal/src/stm32f4xx_hal_i2s_ex.d \
./lib/hal/src/stm32f4xx_hal_irda.d \
./lib/hal/src/stm32f4xx_hal_iwdg.d \
./lib/hal/src/stm32f4xx_hal_ltdc.d \
./lib/hal/src/stm32f4xx_hal_msp_template.d \
./lib/hal/src/stm32f4xx_hal_nand.d \
./lib/hal/src/stm32f4xx_hal_nor.d \
./lib/hal/src/stm32f4xx_hal_pccard.d \
./lib/hal/src/stm32f4xx_hal_pcd.d \
./lib/hal/src/stm32f4xx_hal_pcd_ex.d \
./lib/hal/src/stm32f4xx_hal_pwr.d \
./lib/hal/src/stm32f4xx_hal_pwr_ex.d \
./lib/hal/src/stm32f4xx_hal_qspi.d \
./lib/hal/src/stm32f4xx_hal_rcc.d \
./lib/hal/src/stm32f4xx_hal_rcc_ex.d \
./lib/hal/src/stm32f4xx_hal_rng.d \
./lib/hal/src/stm32f4xx_hal_rtc.d \
./lib/hal/src/stm32f4xx_hal_rtc_ex.d \
./lib/hal/src/stm32f4xx_hal_sai.d \
./lib/hal/src/stm32f4xx_hal_sai_ex.d \
./lib/hal/src/stm32f4xx_hal_sd.d \
./lib/hal/src/stm32f4xx_hal_sdram.d \
./lib/hal/src/stm32f4xx_hal_smartcard.d \
./lib/hal/src/stm32f4xx_hal_spdifrx.d \
./lib/hal/src/stm32f4xx_hal_spi.d \
./lib/hal/src/stm32f4xx_hal_sram.d \
./lib/hal/src/stm32f4xx_hal_tim.d \
./lib/hal/src/stm32f4xx_hal_tim_ex.d \
./lib/hal/src/stm32f4xx_hal_uart.d \
./lib/hal/src/stm32f4xx_hal_usart.d \
./lib/hal/src/stm32f4xx_hal_wwdg.d \
./lib/hal/src/stm32f4xx_ll_fmc.d \
./lib/hal/src/stm32f4xx_ll_fsmc.d \
./lib/hal/src/stm32f4xx_ll_sdmmc.d \
./lib/hal/src/stm32f4xx_ll_usb.d \
./lib/hal/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/src/%.o lib/hal/src/%.su: ../lib/hal/src/%.c lib/hal/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -c -I../appli -I../lib/hal/inc -I../lib/bsp -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/lis302dl -I../lib/bsp/lis3dsh -I../lib/bsp/audio -I../lib/bsp/ov9655 -I../lib/bsp/stmpe811 -I../lib/bsp/LCD -I../lib/middleware/ -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../lib/middleware/webserver -I../lib/middleware/webserver/lwip -I../lib/middleware/webserver/lwip/src/include -I../lib/middleware/webserver/lwip/system -I../lib/middleware/webserver/lwip/src/include/ipv4 -I../lib/middleware/webserver/lwip/src/include/lwip -I../lib/middleware/webserver/lwip/port -I../lib/middleware/webserver/STD_lib -I../lib/middleware/usb_device/Class/HID/Inc -I../lib/middleware/usb_device/Class/MSC/Inc -I../lib/middleware/usb_device/Core/Inc -I../lib/middleware/usb_host/Class/MSC/Inc -I../lib/middleware/usb_host/Core/Inc -I../lib/middleware/usb_host/Class/HID/Inc -I../lib/middleware/usb_host/ -I../lib/middleware/PDM -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-src

clean-lib-2f-hal-2f-src:
	-$(RM) ./lib/hal/src/stm32f4xx_hal.d ./lib/hal/src/stm32f4xx_hal.o ./lib/hal/src/stm32f4xx_hal.su ./lib/hal/src/stm32f4xx_hal_adc.d ./lib/hal/src/stm32f4xx_hal_adc.o ./lib/hal/src/stm32f4xx_hal_adc.su ./lib/hal/src/stm32f4xx_hal_adc_ex.d ./lib/hal/src/stm32f4xx_hal_adc_ex.o ./lib/hal/src/stm32f4xx_hal_adc_ex.su ./lib/hal/src/stm32f4xx_hal_can.d ./lib/hal/src/stm32f4xx_hal_can.o ./lib/hal/src/stm32f4xx_hal_can.su ./lib/hal/src/stm32f4xx_hal_cec.d ./lib/hal/src/stm32f4xx_hal_cec.o ./lib/hal/src/stm32f4xx_hal_cec.su ./lib/hal/src/stm32f4xx_hal_cortex.d ./lib/hal/src/stm32f4xx_hal_cortex.o ./lib/hal/src/stm32f4xx_hal_cortex.su ./lib/hal/src/stm32f4xx_hal_crc.d ./lib/hal/src/stm32f4xx_hal_crc.o ./lib/hal/src/stm32f4xx_hal_crc.su ./lib/hal/src/stm32f4xx_hal_cryp.d ./lib/hal/src/stm32f4xx_hal_cryp.o ./lib/hal/src/stm32f4xx_hal_cryp.su ./lib/hal/src/stm32f4xx_hal_cryp_ex.d ./lib/hal/src/stm32f4xx_hal_cryp_ex.o ./lib/hal/src/stm32f4xx_hal_cryp_ex.su ./lib/hal/src/stm32f4xx_hal_dac.d ./lib/hal/src/stm32f4xx_hal_dac.o ./lib/hal/src/stm32f4xx_hal_dac.su ./lib/hal/src/stm32f4xx_hal_dac_ex.d ./lib/hal/src/stm32f4xx_hal_dac_ex.o ./lib/hal/src/stm32f4xx_hal_dac_ex.su ./lib/hal/src/stm32f4xx_hal_dcmi.d ./lib/hal/src/stm32f4xx_hal_dcmi.o ./lib/hal/src/stm32f4xx_hal_dcmi.su ./lib/hal/src/stm32f4xx_hal_dcmi_ex.d ./lib/hal/src/stm32f4xx_hal_dcmi_ex.o ./lib/hal/src/stm32f4xx_hal_dcmi_ex.su ./lib/hal/src/stm32f4xx_hal_dma.d ./lib/hal/src/stm32f4xx_hal_dma.o ./lib/hal/src/stm32f4xx_hal_dma.su ./lib/hal/src/stm32f4xx_hal_dma2d.d ./lib/hal/src/stm32f4xx_hal_dma2d.o ./lib/hal/src/stm32f4xx_hal_dma2d.su ./lib/hal/src/stm32f4xx_hal_dma_ex.d ./lib/hal/src/stm32f4xx_hal_dma_ex.o ./lib/hal/src/stm32f4xx_hal_dma_ex.su ./lib/hal/src/stm32f4xx_hal_eth.d ./lib/hal/src/stm32f4xx_hal_eth.o ./lib/hal/src/stm32f4xx_hal_eth.su ./lib/hal/src/stm32f4xx_hal_flash.d ./lib/hal/src/stm32f4xx_hal_flash.o ./lib/hal/src/stm32f4xx_hal_flash.su ./lib/hal/src/stm32f4xx_hal_flash_ex.d ./lib/hal/src/stm32f4xx_hal_flash_ex.o ./lib/hal/src/stm32f4xx_hal_flash_ex.su ./lib/hal/src/stm32f4xx_hal_flash_ramfunc.d ./lib/hal/src/stm32f4xx_hal_flash_ramfunc.o ./lib/hal/src/stm32f4xx_hal_flash_ramfunc.su ./lib/hal/src/stm32f4xx_hal_fmpi2c.d ./lib/hal/src/stm32f4xx_hal_fmpi2c.o ./lib/hal/src/stm32f4xx_hal_fmpi2c.su ./lib/hal/src/stm32f4xx_hal_fmpi2c_ex.d ./lib/hal/src/stm32f4xx_hal_fmpi2c_ex.o ./lib/hal/src/stm32f4xx_hal_fmpi2c_ex.su ./lib/hal/src/stm32f4xx_hal_gpio.d ./lib/hal/src/stm32f4xx_hal_gpio.o ./lib/hal/src/stm32f4xx_hal_gpio.su ./lib/hal/src/stm32f4xx_hal_hash.d ./lib/hal/src/stm32f4xx_hal_hash.o ./lib/hal/src/stm32f4xx_hal_hash.su ./lib/hal/src/stm32f4xx_hal_hash_ex.d ./lib/hal/src/stm32f4xx_hal_hash_ex.o ./lib/hal/src/stm32f4xx_hal_hash_ex.su ./lib/hal/src/stm32f4xx_hal_hcd.d ./lib/hal/src/stm32f4xx_hal_hcd.o ./lib/hal/src/stm32f4xx_hal_hcd.su ./lib/hal/src/stm32f4xx_hal_i2c.d ./lib/hal/src/stm32f4xx_hal_i2c.o ./lib/hal/src/stm32f4xx_hal_i2c.su ./lib/hal/src/stm32f4xx_hal_i2c_ex.d ./lib/hal/src/stm32f4xx_hal_i2c_ex.o ./lib/hal/src/stm32f4xx_hal_i2c_ex.su ./lib/hal/src/stm32f4xx_hal_i2s.d ./lib/hal/src/stm32f4xx_hal_i2s.o ./lib/hal/src/stm32f4xx_hal_i2s.su ./lib/hal/src/stm32f4xx_hal_i2s_ex.d ./lib/hal/src/stm32f4xx_hal_i2s_ex.o ./lib/hal/src/stm32f4xx_hal_i2s_ex.su ./lib/hal/src/stm32f4xx_hal_irda.d ./lib/hal/src/stm32f4xx_hal_irda.o ./lib/hal/src/stm32f4xx_hal_irda.su ./lib/hal/src/stm32f4xx_hal_iwdg.d ./lib/hal/src/stm32f4xx_hal_iwdg.o ./lib/hal/src/stm32f4xx_hal_iwdg.su ./lib/hal/src/stm32f4xx_hal_ltdc.d ./lib/hal/src/stm32f4xx_hal_ltdc.o ./lib/hal/src/stm32f4xx_hal_ltdc.su ./lib/hal/src/stm32f4xx_hal_msp_template.d ./lib/hal/src/stm32f4xx_hal_msp_template.o ./lib/hal/src/stm32f4xx_hal_msp_template.su ./lib/hal/src/stm32f4xx_hal_nand.d ./lib/hal/src/stm32f4xx_hal_nand.o ./lib/hal/src/stm32f4xx_hal_nand.su ./lib/hal/src/stm32f4xx_hal_nor.d ./lib/hal/src/stm32f4xx_hal_nor.o ./lib/hal/src/stm32f4xx_hal_nor.su ./lib/hal/src/stm32f4xx_hal_pccard.d ./lib/hal/src/stm32f4xx_hal_pccard.o ./lib/hal/src/stm32f4xx_hal_pccard.su ./lib/hal/src/stm32f4xx_hal_pcd.d ./lib/hal/src/stm32f4xx_hal_pcd.o ./lib/hal/src/stm32f4xx_hal_pcd.su ./lib/hal/src/stm32f4xx_hal_pcd_ex.d ./lib/hal/src/stm32f4xx_hal_pcd_ex.o ./lib/hal/src/stm32f4xx_hal_pcd_ex.su ./lib/hal/src/stm32f4xx_hal_pwr.d ./lib/hal/src/stm32f4xx_hal_pwr.o ./lib/hal/src/stm32f4xx_hal_pwr.su ./lib/hal/src/stm32f4xx_hal_pwr_ex.d ./lib/hal/src/stm32f4xx_hal_pwr_ex.o ./lib/hal/src/stm32f4xx_hal_pwr_ex.su ./lib/hal/src/stm32f4xx_hal_qspi.d ./lib/hal/src/stm32f4xx_hal_qspi.o ./lib/hal/src/stm32f4xx_hal_qspi.su ./lib/hal/src/stm32f4xx_hal_rcc.d ./lib/hal/src/stm32f4xx_hal_rcc.o ./lib/hal/src/stm32f4xx_hal_rcc.su ./lib/hal/src/stm32f4xx_hal_rcc_ex.d ./lib/hal/src/stm32f4xx_hal_rcc_ex.o ./lib/hal/src/stm32f4xx_hal_rcc_ex.su ./lib/hal/src/stm32f4xx_hal_rng.d ./lib/hal/src/stm32f4xx_hal_rng.o ./lib/hal/src/stm32f4xx_hal_rng.su ./lib/hal/src/stm32f4xx_hal_rtc.d ./lib/hal/src/stm32f4xx_hal_rtc.o ./lib/hal/src/stm32f4xx_hal_rtc.su ./lib/hal/src/stm32f4xx_hal_rtc_ex.d ./lib/hal/src/stm32f4xx_hal_rtc_ex.o ./lib/hal/src/stm32f4xx_hal_rtc_ex.su ./lib/hal/src/stm32f4xx_hal_sai.d ./lib/hal/src/stm32f4xx_hal_sai.o ./lib/hal/src/stm32f4xx_hal_sai.su ./lib/hal/src/stm32f4xx_hal_sai_ex.d ./lib/hal/src/stm32f4xx_hal_sai_ex.o ./lib/hal/src/stm32f4xx_hal_sai_ex.su ./lib/hal/src/stm32f4xx_hal_sd.d ./lib/hal/src/stm32f4xx_hal_sd.o ./lib/hal/src/stm32f4xx_hal_sd.su ./lib/hal/src/stm32f4xx_hal_sdram.d ./lib/hal/src/stm32f4xx_hal_sdram.o ./lib/hal/src/stm32f4xx_hal_sdram.su ./lib/hal/src/stm32f4xx_hal_smartcard.d ./lib/hal/src/stm32f4xx_hal_smartcard.o ./lib/hal/src/stm32f4xx_hal_smartcard.su ./lib/hal/src/stm32f4xx_hal_spdifrx.d ./lib/hal/src/stm32f4xx_hal_spdifrx.o ./lib/hal/src/stm32f4xx_hal_spdifrx.su ./lib/hal/src/stm32f4xx_hal_spi.d ./lib/hal/src/stm32f4xx_hal_spi.o ./lib/hal/src/stm32f4xx_hal_spi.su ./lib/hal/src/stm32f4xx_hal_sram.d ./lib/hal/src/stm32f4xx_hal_sram.o ./lib/hal/src/stm32f4xx_hal_sram.su
	-$(RM) ./lib/hal/src/stm32f4xx_hal_tim.d ./lib/hal/src/stm32f4xx_hal_tim.o ./lib/hal/src/stm32f4xx_hal_tim.su ./lib/hal/src/stm32f4xx_hal_tim_ex.d ./lib/hal/src/stm32f4xx_hal_tim_ex.o ./lib/hal/src/stm32f4xx_hal_tim_ex.su ./lib/hal/src/stm32f4xx_hal_uart.d ./lib/hal/src/stm32f4xx_hal_uart.o ./lib/hal/src/stm32f4xx_hal_uart.su ./lib/hal/src/stm32f4xx_hal_usart.d ./lib/hal/src/stm32f4xx_hal_usart.o ./lib/hal/src/stm32f4xx_hal_usart.su ./lib/hal/src/stm32f4xx_hal_wwdg.d ./lib/hal/src/stm32f4xx_hal_wwdg.o ./lib/hal/src/stm32f4xx_hal_wwdg.su ./lib/hal/src/stm32f4xx_ll_fmc.d ./lib/hal/src/stm32f4xx_ll_fmc.o ./lib/hal/src/stm32f4xx_ll_fmc.su ./lib/hal/src/stm32f4xx_ll_fsmc.d ./lib/hal/src/stm32f4xx_ll_fsmc.o ./lib/hal/src/stm32f4xx_ll_fsmc.su ./lib/hal/src/stm32f4xx_ll_sdmmc.d ./lib/hal/src/stm32f4xx_ll_sdmmc.o ./lib/hal/src/stm32f4xx_ll_sdmmc.su ./lib/hal/src/stm32f4xx_ll_usb.d ./lib/hal/src/stm32f4xx_ll_usb.o ./lib/hal/src/stm32f4xx_ll_usb.su ./lib/hal/src/system_stm32f4xx.d ./lib/hal/src/system_stm32f4xx.o ./lib/hal/src/system_stm32f4xx.su

.PHONY: clean-lib-2f-hal-2f-src

