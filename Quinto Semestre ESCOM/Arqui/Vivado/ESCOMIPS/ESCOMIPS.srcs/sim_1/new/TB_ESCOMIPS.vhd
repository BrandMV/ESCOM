library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity ESCOMIPS_tb is
end;

architecture bench of ESCOMIPS_tb is

  component ESCOMIPS
      Port ( CLK, CLR : in STD_LOGIC;
             A  : out STD_LOGIC_VECTOR(7 DOWNTO 0);
             Di : out STD_LOGIC_VECTOR(7 DOWNTO 0));
  end component;

  signal CLK, CLR: STD_LOGIC;
  signal A: STD_LOGIC_VECTOR(7 DOWNTO 0);
  signal Di: STD_LOGIC_VECTOR(7 DOWNTO 0);
  
  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  uut: ESCOMIPS port map ( CLK => CLK,
                           CLR => CLR,
                           A   => A,
                           Di  => Di );

  stimulus: process
  begin
     CLR <= '1';
    wait until rising_edge (CLK);
    
    CLR <= '0';
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
    wait until rising_edge (CLK);
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
