################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1918591855: ../image.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"E:/ti/ccs1031/sysconfig_1_8_0/sysconfig_cli.bat" -s "E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/.metadata/product.json" --script "C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/image.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_net_wifi_config.json: build-1918591855 ../image.syscfg
syscfg/: build-1918591855

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs" --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/MCU+Image" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/source" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/kernel/nortos" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/kernel/nortos/posix" --include_path="E:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=NORTOS_SUPPORT -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/MCU+Image/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-365186287: ../uartecho.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"E:/ti/ccs1031/sysconfig_1_8_0/sysconfig_cli.bat" -s "E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/.metadata/product.json" --script "C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/uartecho.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-365186287 ../uartecho.syscfg
syscfg/ti_drivers_config.h: build-365186287
syscfg/ti_utils_build_linker.cmd.genlibs: build-365186287
syscfg/syscfg_c.rov.xs: build-365186287
syscfg/ti_utils_runtime_model.gv: build-365186287
syscfg/ti_utils_runtime_Makefile: build-365186287
syscfg/: build-365186287

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs" --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/MCU+Image" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/source" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/kernel/nortos" --include_path="E:/ti/ccs1031/simplelink_cc32xx_sdk_5_10_00_02/kernel/nortos/posix" --include_path="E:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=NORTOS_SUPPORT -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/vcucu/workspace_v10/uartecho_CC3220S_LAUNCHXL_nortos_ccs/MCU+Image/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


