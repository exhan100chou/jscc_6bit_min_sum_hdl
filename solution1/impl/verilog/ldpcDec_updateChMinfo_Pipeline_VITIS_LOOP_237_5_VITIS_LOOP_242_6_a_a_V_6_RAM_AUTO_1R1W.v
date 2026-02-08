// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1 ns / 1 ps
module ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_237_5_VITIS_LOOP_242_6_a_a_V_6_RAM_AUTO_1R1W (
address0, ce0, q0, reset,clk);

parameter DataWidth = 6;
parameter AddressWidth = 5;
parameter AddressRange = 30;

input[AddressWidth-1:0] address0;
input ce0;
output reg[DataWidth-1:0] q0;
input reset;
input clk;

reg [DataWidth-1:0] ram[0:AddressRange-1];

initial begin
    $readmemh("./ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_237_5_VITIS_LOOP_242_6_a_a_V_6_RAM_AUTO_1R1W.dat", ram);
end



always @(posedge clk)  
begin 
    if (ce0) 
    begin
        q0 <= ram[address0];
    end
end



endmodule

