----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta Garcíaa
--          Brandon David Meza Vargas
--          Kyuseop Shim 
-- Module Name: MEMDATOS



 --             *****Practica MEMORIA DE DATOS****

----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.all;

entity MEMDATOS is
    GENERIC( N_BITS_DIN : INTEGER := 8;
             N_BITS_ADR : INTEGER := 8
     );
    Port ( A : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);  -- BUS DE DIRECCIONES ME DICE TAMAÑO DE MEMORIA
           DI : in STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0);
           WD : in STD_LOGIC;
           CLK : in STD_LOGIC;
           DOUT : out STD_LOGIC_VECTOR (N_BITS_DIN-1 downto 0));
end MEMDATOS;

architecture PROGRAMA of MEMDATOS is
TYPE MEMORIA IS ARRAY(0 TO 2**N_BITS_ADR-1) OF STD_LOGIC_VECTOR(DI'RANGE);
SIGNAL MEM_DIST : MEMORIA;

begin

    PRAM : PROCESS( CLK )
    BEGIN  
        IF( rising_edge(CLK) ) THEN
            IF( WD = '1' ) THEN          --  Escritura Sincrona
                MEM_DIST( conv_integer(A) ) <= DI;  
            END IF;
        END IF;
    END PROCESS PRAM;

    DOUT <= MEM_DIST( conv_integer(A) );  -- Lectura asincrona

end PROGRAMA;
