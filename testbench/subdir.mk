################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./testbench/main.o 

CPP_DEPS += \
./testbench/main.d 


# Each subdirectory must supply rules for building sources it contributes
testbench/main.o: D:/PhD_Study/JSCC_LDPC/jscc_6bit_min_sum_hdl/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -IC:/Xilinx/Vitis_HLS/2021.2/win64/tools/auto_cc/include -IC:/Xilinx/Vitis_HLS/2021.2/include/etc -IC:/Xilinx/Vitis_HLS/2021.2/include -IC:/Xilinx/Vitis_HLS/2021.2/include/ap_sysc -IC:/Xilinx/Vitis_HLS/2021.2/win64/tools/systemc/include -ID:/PhD_Study/JSCC_LDPC -O0 -g3 -Wall -Wno-unknown-pragmas -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"testbench/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


