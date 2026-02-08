-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_2_ROM_AdEe is 
    generic(
             DataWidth     : integer := 7; 
             AddressWidth     : integer := 5; 
             AddressRange    : integer := 30
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_2_ROM_AdEe is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 to 8=> "0000000", 9 => "0110010", 10 => "0111001", 11 => "0101111", 
    12 => "1011111", 13 => "0111101", 14 => "0111110", 15 => "1000001", 
    16 => "0110111", 17 => "0111010", 18 => "1000010", 19 => "1001110", 
    20 => "1000101", 21 => "1001000", 22 => "1010001", 23 => "1001001", 
    24 => "1000110", 25 => "1001111", 26 => "1010010", 27 => "1001011", 
    28 => "1001100", 29 => "0000000" );


begin 


memory_access_guard_0: process (address0) 
begin
      address0_tmp <= address0;
--synthesis translate_off
      if (CONV_INTEGER(address0) > AddressRange-1) then
           address0_tmp <= (others => '0');
      else 
           address0_tmp <= address0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(address0_tmp)); 
        end if;
    end if;
end process;

end rtl;

