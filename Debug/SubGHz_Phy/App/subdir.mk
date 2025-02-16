################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SubGHz_Phy/App/app_subghz_phy.c \
../SubGHz_Phy/App/subghz_phy_app.c 

OBJS += \
./SubGHz_Phy/App/app_subghz_phy.o \
./SubGHz_Phy/App/subghz_phy_app.o 

C_DEPS += \
./SubGHz_Phy/App/app_subghz_phy.d \
./SubGHz_Phy/App/subghz_phy_app.d 


# Each subdirectory must supply rules for building sources it contributes
SubGHz_Phy/App/%.o SubGHz_Phy/App/%.su SubGHz_Phy/App/%.cyclo: ../SubGHz_Phy/App/%.c SubGHz_Phy/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../SubGHz_Phy/App -I../SubGHz_Phy/Target -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Utilities/trace/adv_trace -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Drivers/STM32WLxx_HAL_Driver/Inc -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Utilities/misc -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Utilities/sequencer -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Utilities/timer -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Utilities/lpm/tiny_lpm -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Drivers/CMSIS/Device/ST/STM32WLxx/Include -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Middlewares/Third_Party/SubGHz_Phy -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -IC:/Users/micha/STM32Cube/Repository/STM32Cube_FW_WL_V1.3.0/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SubGHz_Phy-2f-App

clean-SubGHz_Phy-2f-App:
	-$(RM) ./SubGHz_Phy/App/app_subghz_phy.cyclo ./SubGHz_Phy/App/app_subghz_phy.d ./SubGHz_Phy/App/app_subghz_phy.o ./SubGHz_Phy/App/app_subghz_phy.su ./SubGHz_Phy/App/subghz_phy_app.cyclo ./SubGHz_Phy/App/subghz_phy_app.d ./SubGHz_Phy/App/subghz_phy_app.o ./SubGHz_Phy/App/subghz_phy_app.su

.PHONY: clean-SubGHz_Phy-2f-App

