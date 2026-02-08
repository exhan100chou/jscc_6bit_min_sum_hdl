-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_1_ROM_Acud is 
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


architecture rtl of ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_1_ROM_Acud is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "0011110", 1 => "0100010", 2 => "0110001", 3 => "0110101", 
    4 => "0100110", 5 => "1000000", 6 => "0000000", 7 => "0101110", 
    8 => "0101010", 9 => "0100011", 10 => "0011111", 11 => "0101011", 
    12 => "0110110", 13 => "0100000", 14 => "0101100", 15 => "0100111", 
    16 => "0100100", 17 => "0101000", 18 => "0110011", 19 => "0110100", 
    20 => "0110000", 21 => "0100101", 22 => "0111000", 23 => "1000011", 
    24 => "0101001", 25 => "0100001", 26 => "0101101", 27 => "0111111", 
    28 => "0111011", 29 => "0000000" );


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

