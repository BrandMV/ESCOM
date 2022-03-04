----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/16/2021 05:11:49 PM
-- Design Name: 
-- Module Name: DIST_RAM_tb - Behavioral
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


-- Testbench created online at:
--   https://www.doulos.com/knowhow/perl/vhdl-testbench-creation-using-perl/
-- Copyright Doulos Ltd

library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity DIST_RAM_tb is
    generic (ADR_BITS : integer := 8;
               D_BITS: integer := 8);
end;

architecture bench of DIST_RAM_tb is

  component DIST_RAM
      generic (ADR_BITS : integer := 8;
               D_BITS: integer := 8);
      Port ( ADR : in STD_LOGIC_VECTOR (ADR_BITS - 1 downto 0);
             DIN : in STD_LOGIC_VECTOR (D_BITS - 1 downto 0);
             WR_EN : in STD_LOGIC;
             CLK : in STD_LOGIC;
             DOUT : out STD_LOGIC_VECTOR (D_BITS - 1 downto 0));
  end component;

  signal ADR: STD_LOGIC_VECTOR (ADR_BITS - 1 downto 0);
  signal DIN: STD_LOGIC_VECTOR (D_BITS - 1 downto 0);
  signal WR_EN: STD_LOGIC;
  signal CLK: STD_LOGIC;
  signal DOUT: STD_LOGIC_VECTOR (D_BITS - 1 downto 0);

  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  -- Insert values for generic parameters !!
  uut: DIST_RAM generic map ( ADR_BITS => ADR_BITS,
                              D_BITS   =>  D_BITS)
                   port map ( ADR      => ADR,
                              DIN      => DIN,
                              WR_EN    => WR_EN,
                              CLK      => CLK,
                              DOUT     => DOUT );

  stimulus: process
  begin
  
    -- Put initialisation code here
    DIN <= X"A2";
    ADR <= X"23";
    WR_EN <= '0';
    wait until rising_edge (CLK);

    -- Put test bench stimulus code here
    WR_EN <= '1';
    wait until rising_edge (CLK);
    
    DIN <= X"13";
    ADR <= X"24";
    WR_EN <= '0';
    wait until rising_edge (CLK);
    
    WR_EN <= '1';
    wait until rising_edge (CLK);
    
    DIN <= X"98";
    ADR <= X"25";
    WR_EN <= '0';
    wait until rising_edge (CLK);
    
    WR_EN <= '1';
    wait until rising_edge (CLK);
    
    DIN <= X"45";
    ADR <= X"26";
    WR_EN <= '0';
    wait until rising_edge (CLK);
    
    WR_EN <= '1';
    wait until rising_edge (CLK);
    
    DIN <= X"32";
    ADR <= X"23";
    WR_EN <= '0';
    wait until rising_edge (CLK);
    
    ADR <= X"24";
    wait until rising_edge (CLK);
    
    ADR <= X"25";
    wait until rising_edge (CLK);
    
    ADR <= X"26";
    wait until rising_edge (CLK);
    
    stop_the_clock <= true;
    wait;
  end process;

  clocking: process
  begin
    while not stop_the_clock loop
      CLK <= '0', '1' after clock_period / 2;
      wait for clock_period;
    end loop;
    wait;
  end process;

end;