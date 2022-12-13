################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/middleware/usb_device/Core/Src/subdir.mk
-include lib/middleware/usb_device/Class/MSC/Src/subdir.mk
-include lib/middleware/usb_device/Class/HID/Src/subdir.mk
-include lib/hal/src/subdir.mk
-include lib/bsp/vl53l1x/low_layer/platform/subdir.mk
-include lib/bsp/vl53l1x/low_layer/core/subdir.mk
-include lib/bsp/vl53l1x/subdir.mk
-include lib/bsp/tft_ili9341/subdir.mk
-include lib/bsp/stmpe811/subdir.mk
-include lib/bsp/ov9655/subdir.mk
-include lib/bsp/lis3dsh/subdir.mk
-include lib/bsp/lis302dl/subdir.mk
-include lib/bsp/LCD/subdir.mk
-include lib/bsp/subdir.mk
-include lib/subdir.mk
-include appli/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Projet_hipp_fonctionnel_v1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Projet_hipp_fonctionnel_v1.elf \

MAP_FILES += \
Projet_hipp_fonctionnel_v1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Projet_hipp_fonctionnel_v1.list \

OBJCOPY_BIN += \
Projet_hipp_fonctionnel_v1.bin \


# All Target
all: main-build

# Main-build Target
main-build: Projet_hipp_fonctionnel_v1.elf secondary-outputs

# Tool invocations
Projet_hipp_fonctionnel_v1.elf Projet_hipp_fonctionnel_v1.map: $(OBJS) $(USER_OBJS) ../lib/LinkerScript.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Projet_hipp_fonctionnel_v1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../lib/LinkerScript.ld" --specs=nosys.specs -Wl,-Map="Projet_hipp_fonctionnel_v1.map" -Wl,--gc-sections -static -L../lib/middleware/PDM --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Projet_hipp_fonctionnel_v1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Projet_hipp_fonctionnel_v1.list"
	@echo 'Finished building: $@'
	@echo ' '

Projet_hipp_fonctionnel_v1.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Projet_hipp_fonctionnel_v1.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Projet_hipp_fonctionnel_v1.bin Projet_hipp_fonctionnel_v1.elf Projet_hipp_fonctionnel_v1.list Projet_hipp_fonctionnel_v1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
