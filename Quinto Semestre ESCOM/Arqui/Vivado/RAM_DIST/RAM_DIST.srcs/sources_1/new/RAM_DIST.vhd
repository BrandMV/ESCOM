----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09.11.2021 10:58:37
-- Design Name: 
-- Module Name: RAM_DIST - PROGRAMA
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity RAM_DIST is
    GENERIC( N_BITS_ADR : INTEGER := 6;
             N_BITS_DIN : INTEGER := 8
     );
    Port ( ADR : in STD_LOGIC_VECTOR (N_BITS_ADR-1 downto 0);  -- BUS DE DIRECCIONES ME DICE TAMAÑO DE MEMORIA
           DIN : in STD_LOGIC_VECTOR (N_BITS_DIN downto 0);
           WR_EN : in STD_LOGIC;
           CLK : in STD_LOGIC;
           DOUT : out STD_LOGIC_VECTOR (N_BITS_DIN downto 0));
end RAM_DIST;

architecture PROGRAMA of RAM_DIST is
TYPE MEMORIA IS ARRAY(0 TO 2**N_BITS_ADR-1) OF STD_LOGIC_VECTOR(DIN'RANGE);
SIGNAL MEM_DIST : MEMORIA;

begin

    PRAM : PROCESS( CLK )
    BEGIN  
    -- CLEAR NO SE PONE, SI SE PONE LA HERRAMIENTA USA FLIP-FLOPS
--IF( CLR = '1' ) THEN
           -- MEM_DIST <= (OTHERS => (OTHERS => '0'));    --  Se pone en 0
        --ELSIF( CLK'EVENT AND CLK = '1' ) THEN
        IF( rising_edge(CLK) ) THEN
            IF( WR_EN = '1' ) THEN          --  Escritura Sincrona
                MEM_DIST( conv_integer(ADR) ) <= DIN;  
            END IF;
        END IF;
    END PROCESS PRAM;

    DOUT <= MEM_DIST( conv_integer(ADR) );  -- Lectura asincrona

end PROGRAMA;
