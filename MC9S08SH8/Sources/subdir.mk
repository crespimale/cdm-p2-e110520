################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/DISPLAY.c" \
"../Sources/MATKEY.c" \
"../Sources/MCUinit.c" \
"../Sources/MEF.c" \
"../Sources/PORT.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/DISPLAY.c \
../Sources/MATKEY.c \
../Sources/MCUinit.c \
../Sources/MEF.c \
../Sources/PORT.c \
../Sources/main.c \

OBJS += \
./Sources/DISPLAY_c.obj \
./Sources/MATKEY_c.obj \
./Sources/MCUinit_c.obj \
./Sources/MEF_c.obj \
./Sources/PORT_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/DISPLAY_c.obj" \
"./Sources/MATKEY_c.obj" \
"./Sources/MCUinit_c.obj" \
"./Sources/MEF_c.obj" \
"./Sources/PORT_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/DISPLAY_c.d \
./Sources/MATKEY_c.d \
./Sources/MCUinit_c.d \
./Sources/MEF_c.d \
./Sources/PORT_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/DISPLAY_c.obj \
./Sources/MATKEY_c.obj \
./Sources/MCUinit_c.obj \
./Sources/MEF_c.obj \
./Sources/PORT_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/DISPLAY_c.obj: ../Sources/DISPLAY.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/DISPLAY.args" -ObjN="Sources/DISPLAY_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MATKEY_c.obj: ../Sources/MATKEY.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MATKEY.args" -ObjN="Sources/MATKEY_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCUinit_c.obj: ../Sources/MCUinit.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MCUinit.args" -ObjN="Sources/MCUinit_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MEF_c.obj: ../Sources/MEF.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MEF.args" -ObjN="Sources/MEF_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/PORT_c.obj: ../Sources/PORT.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/PORT.args" -ObjN="Sources/PORT_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


