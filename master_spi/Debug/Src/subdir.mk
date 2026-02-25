################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/spi.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart1.c 

OBJS += \
./Src/main.o \
./Src/spi.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart1.o 

C_DEPS += \
./Src/main.d \
./Src/spi.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"F:/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"F:/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/spi.cyclo ./Src/spi.d ./Src/spi.o ./Src/spi.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart1.cyclo ./Src/uart1.d ./Src/uart1.o ./Src/uart1.su

.PHONY: clean-Src

