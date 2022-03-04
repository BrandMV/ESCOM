library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity CONTROL_tb is
end;

architecture bench of CONTROL_tb is

  component CONTROL
      Port ( COD_FUN : in STD_LOGIC_VECTOR (3 downto 0);
             COD_OPC : in STD_LOGIC_VECTOR (4 downto 0);
             Z, N, C, OV : in STD_LOGIC;
             CLK, CLR : in STD_LOGIC;
             WPC, SR1, SWD, WR, SOP, SOP2, WD, SR : out STD_LOGIC;
             ALUOP : out STD_LOGIC_VECTOR (3 downto 0));
  end component;

  signal COD_FUN: STD_LOGIC_VECTOR (3 downto 0);
  signal COD_OPC: STD_LOGIC_VECTOR (4 downto 0);
  signal Z, N, C, OV: STD_LOGIC;
  signal CLK, CLR: STD_LOGIC;
  signal WPC, SR1, SWD, WR, SOP, SOP2, WD, SR: STD_LOGIC;
  signal ALUOP: STD_LOGIC_VECTOR (3 downto 0);

  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  uut: CONTROL port map ( COD_FUN => COD_FUN,
                          COD_OPC => COD_OPC,
                          Z       => Z,
                          N       => N,
                          C       => C,
                          OV      => OV,
                          CLK     => CLK,
                          CLR     => CLR,
                          WPC     => WPC,
                          SR1     => SR1,
                          SWD     => SWD,
                          WR      => WR,
                          SOP     => SOP,
                          SOP2    => SOP2,
                          WD      => WD,
                          SR      => SR,
                          ALUOP   => ALUOP );

  stimulus: process
  begin
  
    -- Put initialisation code here
    --TIPO R
    --RESET
    CLR     <= '1';
    COD_OPC <= "00000";
    COD_FUN <= "0000";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --ADD
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0000";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --SUB
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0001";
    Z       <= '0';
    C       <= '1';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);

    --AND
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0010";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);

    --OR
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0011";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --XOR
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0100";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);

    --NAND
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0101";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --NOR
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0110";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --XNOR
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "0111";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --Instrucciones Tipo I y B
    --LI
    CLR     <= '0';
    COD_OPC <= "00001";
    COD_FUN <= "0111";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --LWI
    CLR     <= '0';
    COD_OPC <= "00010";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --SWI
    CLR     <= '0';
    COD_OPC <= "00010";
    COD_FUN <= "0000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --ADDI
    CLR     <= '0';
    COD_OPC <= "00100";
    COD_FUN <= "0110";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --SUBI
    CLR     <= '0';
    COD_OPC <= "00101";
    COD_FUN <= "1010";
    Z       <= '1';
    C       <= '1';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --B
    CLR     <= '0';
    COD_OPC <= "00110";
    COD_FUN <= "0011";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CPI
    CLR     <= '0';
    COD_OPC <= "00111";
    COD_FUN <= "1100";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --Instrucciones de brinco condicional
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '1';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --BEQ (No salto)
    CLR     <= '0';
    COD_OPC <= "01000";
    COD_FUN <= "1111";
    Z       <= '0';
    C       <= '1';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    --BEQ (salto)
    CLR     <= '0';
    COD_OPC <= "01000";
    COD_FUN <= "1111";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    --BNEQ(No salto)
    CLR     <= '0';
    COD_OPC <= "01001";
    COD_FUN <= "1011";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --BNEQ(Salto)
    CLR     <= '0';
    COD_OPC <= "01001";
    COD_FUN <= "1101";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    --BLT (NO SALTO)
    CLR     <= '0';
    COD_OPC <= "01010";
    COD_FUN <= "1110";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    --BLT(SALTO)
    CLR     <= '0';
    COD_OPC <= "01010";
    COD_FUN <= "1100";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    --BLET(NO SALTO)
    CLR     <= '0';
    COD_OPC <= "01011";
    COD_FUN <= "0011";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    --BLET(SALTO)
    CLR     <= '0';
    COD_OPC <= "01011";
    COD_FUN <= "0011";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    --BGT(NO SALTO)
    CLR     <= '0';
    COD_OPC <= "01100";
    COD_FUN <= "0001";
    Z       <= '1';
    C       <= '0';
    N       <= '0';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    --BGT(SALTO)
    CLR     <= '0';
    COD_OPC <= "01100";
    COD_FUN <= "0000";
    Z       <= '0';
    C       <= '0';
    N       <= '1';
    OV      <= '1';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    --BGET(NO SALTO)
    CLR     <= '0';
    COD_OPC <= "01101";
    COD_FUN <= "0010";
    Z       <= '0';
    C       <= '0';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    
    --CP
    CLR     <= '0';
    COD_OPC <= "00000";
    COD_FUN <= "1000";
    Z       <= '1';
    C       <= '1';
    N       <= '0';
    OV      <= '0';
    wait until rising_edge (CLK);
    --BGET(SALTO)
    CLR     <= '0';
    COD_OPC <= "01101";
    COD_FUN <= "0010";
    Z       <= '1';
    C       <= '1';
    N       <= '0';
    OV      <= '0';
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