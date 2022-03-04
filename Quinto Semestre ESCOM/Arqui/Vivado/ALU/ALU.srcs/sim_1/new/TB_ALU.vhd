library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity ALU_tb is
end;

architecture bench of ALU_tb is

  component ALU
      GENERIC( N: INTEGER := 4 );
      Port ( Z, NF, CN, OV : out STD_LOGIC;
             A, B : in STD_LOGIC_VECTOR (N-1 downto 0);
             AINVERT : in STD_LOGIC;
             BINVERT : in STD_LOGIC;
             OP : in STD_LOGIC_VECTOR (1 downto 0);
             RES : inout STD_LOGIC_VECTOR (N-1 downto 0));
  end component;

  signal Z, NF, CN, OV: STD_LOGIC;
  signal A, B: STD_LOGIC_VECTOR (3 downto 0);
  signal AINVERT: STD_LOGIC;
  signal BINVERT: STD_LOGIC;
  signal OP: STD_LOGIC_VECTOR (1 downto 0);
  signal RES: STD_LOGIC_VECTOR (3 downto 0);

begin

  -- Insert values for generic parameters !!
  uut: ALU generic map ( N       => 4 )
              port map ( Z       => Z,
                         NF      => NF,
                         CN      => CN,
                         OV      => OV,
                         A       => A,
                         B       => B,
                         AINVERT => AINVERT,
                         BINVERT => BINVERT,
                         OP      => OP,
                         RES     => RES );

  stimulus: process
  begin
  
    
    AINVERT  <= '0';
    BINVERT  <= '0';
    OP <= "00";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '0';
    BINVERT  <= '0';
    OP <= "01";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '0';
    BINVERT  <= '0';
    OP <= "10";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '1';
    BINVERT  <= '1';
    OP <= "01";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '1';
    BINVERT  <= '1';
    OP <= "00";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;

    AINVERT  <= '1';
    BINVERT  <= '0';
    OP <= "10";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '0';
    BINVERT  <= '0';
    OP <= "11";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '0';
    BINVERT  <= '0';
    OP <= "11";
    A <= "0101";
    B <= "0111";
    
    wait for 100 ns;

    AINVERT  <= '0';
    BINVERT  <= '1';
    OP <= "11";
    A <= "0101";
    B <= "1110";
    
    wait for 100 ns;
    
    AINVERT  <= '0';
    BINVERT  <= '1';
    OP <= "11";
    A <= "0101";
    B <= "0101";
    
    wait for 100 ns;
    
    AINVERT  <= '1';
    BINVERT  <= '1';
    OP <= "01";
    A <= "0101";
    B <= "0101";
    
    wait;
  end process;


end;
