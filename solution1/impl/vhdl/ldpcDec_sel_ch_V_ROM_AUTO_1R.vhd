-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity ldpcDec_sel_ch_V_ROM_AUTO_1R is 
    generic(
             DataWidth     : integer := 7; 
             AddressWidth     : integer := 6; 
             AddressRange    : integer := 50
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          address1      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce1       : in std_logic; 
          q1         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of ldpcDec_sel_ch_V_ROM_AUTO_1R is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address1_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "0000000", 1 => "0000001", 2 => "0000010", 3 => "0000011", 
    4 => "0000100", 5 => "0000101", 6 => "0000110", 7 => "0000111", 
    8 => "0001000", 9 => "0001001", 10 => "0001010", 11 => "0001100", 
    12 => "0001110", 13 => "0010000", 14 => "0010010", 15 => "0010100", 
    16 => "0010110", 17 => "0011000", 18 => "0011010", 19 => "0011100", 
    20 => "0011110", 21 => "0100010", 22 => "0100110", 23 => "0101010", 
    24 => "0101110", 25 => "0110001", 26 => "0110101", 27 => "0111001", 
    28 => "0111100", 29 => "1000000", 30 => "1000100", 31 => "1000111", 
    32 => "1001010", 33 => "1001101", 34 => "1010000", 35 => "1010011", 
    36 => "1010110", 37 => "1011001", 38 => "1011100", 39 => "1011111", 
    40 => "1100010", 41 => "1100101", 42 => "1101000", 43 => "1101011", 
    44 => "1101110", 45 => "1110001", 46 => "1110100", 47 => "1110111", 
    48 => "1111010", 49 => "1111101" );


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

memory_access_guard_1: process (address1) 
begin
      address1_tmp <= address1;
--synthesis translate_off
      if (CONV_INTEGER(address1) > AddressRange-1) then
           address1_tmp <= (others => '0');
      else 
           address1_tmp <= address1;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(address0_tmp)); 
        end if;
        if (ce1 = '1') then 
            q1 <= mem(CONV_INTEGER(address1_tmp)); 
        end if;
    end if;
end process;

end rtl;

