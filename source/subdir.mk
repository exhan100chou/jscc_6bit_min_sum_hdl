################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ldpcDec.cpp 

OBJS += \
./source/ldpcDec.o 

CPP_DEPS += \
./source/ldpcDec.d 


# Each subdirectory must supply rules for building sources it contributes
source/ldpcDec.o: D:/PhD_Study/JSCC_LDPC/jscc_6bit_min_sum_hdl/ldpcDec.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vitis_HLS/2021.2/win64/tools/auto_cc/include -IC:/Xilinx/Vitis_HLS/2021.2/include/etc -IC:/Xilinx/Vitis_HLS/2021.2/include -IC:/Xilinx/Vitis_HLS/2021.2/include/ap_sysc -IC:/Xilinx/Vitis_HLS/2021.2/win64/tools/systemc/include -ID:/PhD_Study/JSCC_LDPC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


