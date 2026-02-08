############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project jscc_6bit_min_sum_hdl
set_top ldpcDec
add_files jscc_6bit_min_sum_hdl/ldpcDec.cpp
add_files -tb jscc_6bit_min_sum_hdl/main.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xcvu9p-flga2104-2L-e}
create_clock -period 10 -name default
source "./jscc_6bit_min_sum_hdl/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
