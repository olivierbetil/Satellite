################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../lib/startup_stm32.s 

OBJS += \
./lib/startup_stm32.o 

S_DEPS += \
./lib/startup_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.s lib/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/olivi/Documents/GitHub/Satellite/prends_ca.zip_expanded/Projet_hipp_fonctionnel_v1/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-lib

clean-lib:
	-$(RM) ./lib/startup_stm32.d ./lib/startup_stm32.o

.PHONY: clean-lib

