----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta García
--          Brandon David Meza Vargas
--          Kyuseop Shim 
-- Module Name: REGISTROS



 --             *****PRÁCTICA ARCHIVO DE REGISTROS****

----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.all;

entity REGISTROS is
    GENERIC( N_BITS_ADR : INTEGER := 2;
             N_BITS_DIN : INTEGER := 8
     );
    Port ( WR_REG, RD_REG1, RD_REG2 : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);  -- BUS DE DIRECCIONES ME DICE TAMA?O DE MEMORIA
           WR_DATA : in STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
           WR : in STD_LOGIC;
           CLK : in STD_LOGIC;
           RD_DATA1, RD_DATA2 : out STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0));
end REGISTROS;

architecture ARCHIVO of REGISTROS is
TYPE MEMORIA IS ARRAY(0 TO 2**N_BITS_ADR-1) OF STD_LOGIC_VECTOR(WR_DATA'RANGE);
SIGNAL MEM_DIST : MEMORIA;

begin

    PRAM : PROCESS( CLK )
    BEGIN  
        IF( rising_edge(CLK) ) THEN
            IF( WR = '1' ) THEN          --  Escritura Sincrona
                MEM_DIST( conv_integer(WR_REG) ) <= WR_DATA;  
            END IF;
        END IF;
    END PROCESS PRAM;

    RD_DATA1 <= MEM_DIST( conv_integer(RD_REG1) );  -- Lectura asincrona
    RD_DATA2 <= MEM_DIST( conv_integer(RD_REG2) );  -- Lectura asincrona

end ARCHIVO;
