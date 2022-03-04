library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity sumadorRestador_tb is
end;

architecture bench of sumadorRestador_tb is

  component sumadorRestador
      GENERIC( N : INTEGER := 4 );
      Port ( A, B : in STD_LOGIC_VECTOR (N-1 downto 0);
             BINVERT : in STD_LOGIC;
             S : inout STD_LOGIC_VECTOR (N-1 downto 0);
             CN : inout STD_LOGIC;
             NF : out STD_LOGIC;
             OV : out STD_LOGIC;
             Z : out STD_LOGIC);
  end component;

  signal A, B: STD_LOGIC_VECTOR (3 downto 0);
  signal BINVERT: STD_LOGIC;
  signal S: STD_LOGIC_VECTOR (3 downto 0);
  signal CN: STD_LOGIC;
  signal NF: STD_LOGIC;
  signal OV: STD_LOGIC;
  signal Z: STD_LOGIC;

begin

  -- Insert values for generic parameters !!
  uut: sumadorRestador generic map ( N       => 4 )
                          port map ( A       => A,
                                     B       => B,
                                     BINVERT => BINVERT,
                                     S       => S,
                                     CN      => CN,
                                     NF      => NF,
                                     OV      => OV,
                                     Z       => Z );

  stimulus: process
  begin
  
   A <= "0000";
    B <= "0000";
    BINVERT <= '0';
    
    wait for 100 ns;
    
    BINVERT <= '1';

    wait;
  end process;


end;
