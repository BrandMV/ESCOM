library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity MEMDATOS_tb is
 GENERIC( N_BITS_DIN : INTEGER := 8;
          N_BITS_ADR : INTEGER := 8
       );
end;

architecture bench of MEMDATOS_tb is

  component MEMDATOS
      GENERIC( N_BITS_DIN : INTEGER := 8;
               N_BITS_ADR : INTEGER := 8
       );
      Port ( A : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);
             DI : in STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
             WD : in STD_LOGIC;
             CLK : in STD_LOGIC;
             DOUT : out STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0));
  end component;

  signal A: STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);
  signal DI: STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
  signal WD: STD_LOGIC;
  signal CLK: STD_LOGIC;
  signal DOUT: STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);

  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  -- Insert values for generic parameters !!
  uut: MEMDATOS generic map ( N_BITS_DIN => 8,
                              N_BITS_ADR => 8)
                   port map ( A          => A,
                              DI         => DI,
                              WD         => WD,
                              CLK        => CLK,
                              DOUT       => DOUT );

  stimulus: process
  begin
  
    -- Put initialisation code here
    DI <= X"A2";
    A <= X"23";
    WD <= '0';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"A2";
    A <= X"23";
    WD <= '1';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"13";
    A <= X"24";
    WD <= '0';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"13";
    A <= X"24";
    WD <= '1';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"98";
    A <= X"25";
    WD <= '0';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"98";
    A <= X"25";
    WD <= '1';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"45";
    A <= X"26";
    WD <= '0';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"45";
    A <= X"26";
    WD <= '1';
    WAIT UNTIL rising_edge (CLK);
    
    DI <= X"32";
    A <= X"23";
    WD <= '0';
    wait for 100 ns;
    wait for 100 ns;
    DI <= X"32";
    A <= X"24";
    WD <= '0';
    wait for 100 ns;
    
    DI <= X"32";
    A <= X"25";
    WD <= '0';
    wait for 100 ns;
    
    DI <= X"32";
    A <= X"26";
    WD <= '0';
    -- Put test bench stimulus code here

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
