-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity ldpcDec_updateSrcMinfo_rowPara_src_V_3_ROM_AUTO_1R is 
    generic(
             DataWidth     : integer := 7; 
             AddressWidth     : integer := 5; 
             AddressRange    : integer := 20
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of ldpcDec_updateSrcMinfo_rowPara_src_V_3_ROM_AUTO_1R is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "1010110", 1 => "1001011", 2 => "1001100", 3 => "1001101", 
    4 => "1011000", 5 => "0111111", 6 => "1000000", 7 => "1000001", 
    8 => "0110010", 9 => "1000010", 10 => "0110100", 11 => "1000011", 
    12 => "1000100", 13 => "1000101", 14 => "1000110", 15 => "1000111", 
    16 => "1001000", 17 => "1001001", 18 => "1001010", 19 => "0111011" );


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

