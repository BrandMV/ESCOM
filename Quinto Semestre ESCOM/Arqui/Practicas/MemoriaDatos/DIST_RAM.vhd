----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/09/2021 10:58:34 AM
-- Design Name: 
-- Module Name: DIST_RAM - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity DIST_RAM is
    generic (ADR_BITS : integer := 8;
             D_BITS: integer := 8);
    Port ( ADR : in STD_LOGIC_VECTOR (ADR_BITS - 1 downto 0);
           DIN : in STD_LOGIC_VECTOR (D_BITS - 1 downto 0);
           WR_EN : in STD_LOGIC;
           CLK : in STD_LOGIC;
           DOUT : out STD_LOGIC_VECTOR (D_BITS - 1 downto 0));
end DIST_RAM;

architecture Behavioral of DIST_RAM is
type DIST_RAM is array (0 to 2**ADR_BITS - 1) of std_logic_vector (DIN'range);
signal MY_DIST_RAM : DIST_RAM;
begin

    process(CLK)
    begin
        --if (CLR = '1') then
            --MY_DIST_RAM <= (others => (others => '0')); --async
        if (rising_edge(CLK)) then
            if( WR_EN = '1') then --sync
                MY_DIST_RAM (conv_integer(ADR)) <= DIN;
            end if;
        end if;
    end process;
    DOUT <= MY_DIST_RAM(conv_integer(ADR)); --async

end Behavioral;
