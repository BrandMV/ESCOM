library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity sumResAnticipado_tb is
end;

architecture bench of sumResAnticipado_tb is

  component sumResAnticipado
      generic ( N : integer := 4 );
      Port ( A : in STD_LOGIC_VECTOR (N-1 downto 0);
             B : in STD_LOGIC_VECTOR (N-1 downto 0);
             BINVERT : in STD_LOGIC;
             S : inout STD_LOGIC_VECTOR (N-1 downto 0);
             CN, NF, Z, OV : out STD_LOGIC);
  end component;

  signal A: STD_LOGIC_VECTOR (3 downto 0);
  signal B: STD_LOGIC_VECTOR (3 downto 0);
  signal BINVERT: STD_LOGIC;
  signal S: STD_LOGIC_VECTOR (3 downto 0);
  signal CN, NF, Z, OV: STD_LOGIC;

begin

  -- Insert values for generic parameters !!
  uut: sumResAnticipado generic map ( N       => 4 )
                           port map ( A       => A,
                                      B       => B,
                                      BINVERT => BINVERT,
                                      S       => S,
                                      CN      => CN,
                                      NF      => NF,
                                      Z       => Z,
                                      OV      => OV );

  stimulus: process
  begin
  
    A <= "0101";
    B <= "0011";
    BINVERT <= '0';
    
    wait for 100 ns;
    
    BINVERT <= '1';

    wait;

    wait;
  end process;


end;
