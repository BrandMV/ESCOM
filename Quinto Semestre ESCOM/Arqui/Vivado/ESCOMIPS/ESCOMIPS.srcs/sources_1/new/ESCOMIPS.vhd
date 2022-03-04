----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta García
--          Brandon David Meza Vargas
--          Kyuseop Shim 


 --             *****PROCESADOR ESCOMIPS*****

----------------------------------------------------------------------------------

library IEEE;
library WORK;
use IEEE.STD_LOGIC_1164.ALL;
use WORK.MI_PAQUETE.ALL;

entity ESCOMIPS is
    Port ( CLK, CLR : in STD_LOGIC; --PARA SIMULAR LLAMAR CLK, AL PROBAR EN TARJETA OSC_CLK
           A  : out STD_LOGIC_VECTOR(7 DOWNTO 0);
           Di : out STD_LOGIC_VECTOR(7 DOWNTO 0));
end ESCOMIPS;

architecture PROCESADOR of ESCOMIPS is
SIGNAL AC, MWD, MR, RD1, RD2, ES, DO, MOP, MOP2, RALU : STD_LOGIC_VECTOR(7 DOWNTO 0);
SIGNAL I           : STD_LOGIC_VECTOR(14 DOWNTO 0);
SIGNAL WPC, SR1, SWD, WR, SOP, SOP2, WD, SR : STD_LOGIC;
SIGNAL ALUOP : STD_LOGIC_VECTOR( 3 DOWNTO 0 );
SIGNAL MR1   : STD_LOGIC_VECTOR(1 DOWNTO 0);
--SIGNAL CLK   : STD_LOGIC; --DESCOMENTAR AL USAR TARJETA
SIGNAL Z, N, C, OV   : STD_LOGIC; 
begin

    --contador
--    A <= I(7 downto 0) when I(7 downto 0) = "00000101" else "00000000";
--    Di <= RD1 when I(7 downto 0) = "00000101" else "00000000";
    
      --par impar
      A  <= I(7 DOWNTO 0);
    Di <= RD1;

    --FIBO
--    A  <= I(7 DOWNTO 0) WHEN( I(7 DOWNTO 0) = "01001000" ) ELSE "00000000";
--    Di <= RD1 WHEN( I(7 DOWNTO 0) = "01001000" ) ELSE "00000000";

      --comparación
--     A  <= I(7 DOWNTO 0);
--     Di <= RD1;
    
    --PARA PROBAR EN TARJETA
--    DIV : DIVISOR PORT MAP(
--            OSC_CLK => OSC_CLK,
--            CLK     => CLK,
--            CLR     => CLR
--            );
    
    U_CONTROL : CONTROL PORT MAP(
                COD_FUN => I(3 DOWNTO 0),
                COD_OPC => I(14 DOWNTO 10),
                Z       => Z,
                C       => C,
                N       => N,
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
                ALUOP   => ALUOP    
                );
    
    P_C : PC PORT MAP(
            D => I(7 DOWNTO 0),
            Q => AC,
            CLR => CLR,
            CLK => CLK,
            WPC => WPC
           );
    
    --MEM_PROG : PROGRAMA PORT MAP( AC, I ); --NOTACION POSICIONAL
    MEM_PROG : PROGRAMA PORT MAP( --Notación nominal
                BUS_DIR   => AC,
                BUS_DATOS => I
                 );
    --MUX MR
    MR <= DO WHEN( SR = '0' ) ELSE RALU;
    --MUX R1
    MR1 <= I(7 DOWNTO 6) WHEN (SR1 = '0') ELSE I(9 DOWNTO 8);
    --MUX WD
    MWD <= I(7 DOWNTO 0) WHEN (SWD = '0') ELSE MR;
    
    ARCH_REG : REGISTROS PORT MAP(
                RD_REG1  => MR1,
                RD_REG2  => I(5 DOWNTO 4),
                WR_REG   => I(9 DOWNTO 8),
                WR_DATA  => MWD,
                CLK      => CLK,
                WR       => WR,
                RD_DATA1 => RD1,
                RD_DATA2 => RD2
                );       
                
     --EXTENSOR DE SIGNO
     ES <= "00"&I(5 DOWNTO 0) WHEN( I(5) = '0' ) ELSE "11"&I(5 DOWNTO 0);
     --MUX OP
     MOP <= ES WHEN ( SOP = '0' ) ELSE I(7 DOWNTO 0);
     --MUX OP2
     MOP2 <= RD2 WHEN ( SOP2 = '0' ) ELSE MOP;
     
     ALUC : ALU PORT MAP(
            Z       => Z,
            NF      => N,
            CN      => C,
            OV      => OV,
            A       => RD1,
            B       => MOP2,
            AINVERT => ALUOP(3),
            BINVERT => ALUOP(2),
            OP      => ALUOP(1 DOWNTO 0),
            RES     => RALU
            );
     
     MEM_DATOS : MEMDATOS PORT MAP(
                 A    => I(7 DOWNTO 0),
                 DI   => RD1,
                 CLK  => CLK,
                 WD   => WD,
                 DOUT => DO
                );
                
   
end PROCESADOR;
