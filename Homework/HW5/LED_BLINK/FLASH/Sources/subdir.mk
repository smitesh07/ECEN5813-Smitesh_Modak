################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Freedom.c" \
"../Sources/Systick.c" \
"../Sources/TPM1.c" \
"../Sources/arm_cm0.c" \
"../Sources/main.c" \
"../Sources/mcg.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/Freedom.c \
../Sources/Systick.c \
../Sources/TPM1.c \
../Sources/arm_cm0.c \
../Sources/main.c \
../Sources/mcg.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/Freedom_c.obj \
./Sources/Systick_c.obj \
./Sources/TPM1_c.obj \
./Sources/arm_cm0_c.obj \
./Sources/main_c.obj \
./Sources/mcg_c.obj \
./Sources/sa_mtb_c.obj \

C_DEPS += \
./Sources/Freedom.d \
./Sources/Systick.d \
./Sources/TPM1.d \
./Sources/arm_cm0.d \
./Sources/main.d \
./Sources/mcg.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/Freedom_c.obj" \
"./Sources/Systick_c.obj" \
"./Sources/TPM1_c.obj" \
"./Sources/arm_cm0_c.obj" \
"./Sources/main_c.obj" \
"./Sources/mcg_c.obj" \
"./Sources/sa_mtb_c.obj" \

C_DEPS_QUOTED += \
"./Sources/Freedom.d" \
"./Sources/Systick.d" \
"./Sources/TPM1.d" \
"./Sources/arm_cm0.d" \
"./Sources/main.d" \
"./Sources/mcg.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/Freedom_c.obj \
./Sources/Systick_c.obj \
./Sources/TPM1_c.obj \
./Sources/arm_cm0_c.obj \
./Sources/main_c.obj \
./Sources/mcg_c.obj \
./Sources/sa_mtb_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Freedom_c.obj: ../Sources/Freedom.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Freedom.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Freedom_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Systick_c.obj: ../Sources/Systick.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Systick.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Systick_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TPM1_c.obj: ../Sources/TPM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TPM1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/TPM1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/arm_cm0_c.obj: ../Sources/arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/arm_cm0.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/arm_cm0_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/main_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcg_c.obj: ../Sources/mcg.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcg.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/mcg_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb_c.obj: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/sa_mtb_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


