-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_5_ROM_Ag8j is 
    generic(
             DataWidth     : integer := 5; 
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


architecture rtl of ldpcDec_updateChMinfo_Pipeline_VITIS_LOOP_151_3_VITIS_LOOP_156_4_rowPara_ch_V_5_ROM_Ag8j is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 to 18=> "00000", 19 => "11011", 20 => "11100", 21 => "10010", 22 => "10011", 
    23 => "11110", 24 => "11000", 25 => "10101", 26 => "11001", 27 => "11111", 
    28 => "10110", 29 => "00000" );


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

