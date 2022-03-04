library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity Registro is
    GENERIC (
             N_BITS_ADR : INTEGER := 2;
             N_BITS_DIN : INTEGER := 8
             );
    Port ( WR_REG, RD_REG1, RD_REG2 : in std_logic_vector(N_BITS_ADR-1 downto 0);
           WR_DATA : in std_logic_vector(N_BITS_DIN-1 downto 0);
           WR: in std_logic;
           CLK: in std_logic;
           RD_DATA1, RD_DATA2: OUT std_logic_vector(N_BITS_DIN-1 downto 0)
           ); 
end Registro;

architecture Archivo of Registro is
TYPE MEMORIA IS ARRAY(0 TO 2**N_BITS_ADR-1) OF std_logic_vector(WR_DATA'RANGE);
SIGNAL MEM_DIST : MEMORIA;
begin
    PRAM: PROCESS(CLK)
    BEGIN
        IF(rising_edge(CLK)) THEN
            IF(WR='1') THEN
            MEM_DIST(CONV_INTEGER(WR_REG)) <= WR_DATA;
            END IF;
        END IF;
    END PROCESS PRAM;
    
    RD_DATA1 <= MEM_DIST(CONV_INTEGER(RD_REG1));
    RD_DATA2 <= MEM_DIST(CONV_INTEGER(RD_REG2));

end Archivo;
            
        
          
         
            