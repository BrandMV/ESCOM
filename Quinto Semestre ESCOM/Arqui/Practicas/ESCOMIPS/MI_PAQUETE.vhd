
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


package MI_PAQUETE is

    component DIVISOR is
        GENERIC( N : INTEGER := 50000); --1Hz
        PORT( OSC_CLK : in std_logic;
              CLR : in STD_LOGIC;
              CLK : inout STD_LOGIC );
    end component;

    component PROGRAMA is
        GENERIC( BITS_BUS_DIR   : INTEGER := 8;
                 BITS_BUS_DATOS : INTEGER := 15   ); 
        Port ( BUS_DIR   : in STD_LOGIC_VECTOR (BITS_BUS_DIR-1 downto 0);
               BUS_DATOS : out STD_LOGIC_VECTOR (BITS_BUS_DATOS-1 downto 0));
    end component;

    component REGISTROS is
        GENERIC( N_BITS_ADR : INTEGER := 2;
                 N_BITS_DIN : INTEGER := 8
         );
        Port ( WR_REG, RD_REG1, RD_REG2 : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);  -- BUS DE DIRECCIONES ME DICE TAMAï¿½O DE MEMORIA
               WR_DATA : in STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
               WR : in STD_LOGIC;
               CLK : in STD_LOGIC;
               RD_DATA1, RD_DATA2 : out STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0));
    end component;
    
    component ALU is
        GENERIC( N: INTEGER := 8 );
        Port ( Z, NF, CN, OV : out STD_LOGIC;
               A, B : in STD_LOGIC_VECTOR (N-1 downto 0);
               AINVERT : in STD_LOGIC;
               BINVERT : in STD_LOGIC;
               OP : in STD_LOGIC_VECTOR (1 downto 0);
               RES : inout STD_LOGIC_VECTOR (N-1 downto 0));
    end component;
    
    component PC is
        GENERIC( N : INTEGER := 8 );
        Port ( D : in STD_LOGIC_VECTOR (7 downto 0);
               Q : inout STD_LOGIC_VECTOR (7 downto 0);
               CLK,CLR : in STD_LOGIC;
               WPC : in STD_LOGIC);
    end component;
    
    component MEMDATOS is
        GENERIC( N_BITS_DIN : INTEGER := 8;
                 N_BITS_ADR : INTEGER := 8
         );
        Port ( A : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);  -- BUS DE DIRECCIONES ME DICE TAMAÑO DE MEMORIA
               DI : in STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
               WD : in STD_LOGIC;
               CLK : in STD_LOGIC;
               DOUT : out STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0));
    end component;
    
    component CONTROL is
        Port ( COD_FUN : in STD_LOGIC_VECTOR (3 downto 0);
               COD_OPC : in STD_LOGIC_VECTOR (4 downto 0);
               Z, N, C, OV : in STD_LOGIC;
               CLK, CLR : in STD_LOGIC;
               WPC, SR1, SWD, WR, SOP, SOP2, WD, SR : out STD_LOGIC;
               ALUOP : out STD_LOGIC_VECTOR (3 downto 0));
    end component;


end MI_PAQUETE;

PACKAGE BODY MI_PAQUETE is


END MI_PAQUETE;




