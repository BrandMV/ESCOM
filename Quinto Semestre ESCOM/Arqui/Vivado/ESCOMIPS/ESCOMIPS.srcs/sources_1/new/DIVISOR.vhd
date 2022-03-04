
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DIVISOR is
    GENERIC( N : INTEGER := 50000); --1Hz
    PORT( OSC_CLK : in std_logic;
          CLR : in STD_LOGIC;
          CLK : inout STD_LOGIC );
end DIVISOR;

architecture VOLTAJE of DIVISOR is
SIGNAL CONT : INTEGER RANGE 0 TO (2**10)*N-1;

begin
     PDIV : PROCESS( OSC_CLK, CLR )
     BEGIN
        IF( CLR = '1' ) THEN
            CLK  <= '0';
            CONT <= 0;
        ELSIF( OSC_CLK'EVENT AND OSC_CLK = '1' ) THEN 
            CONT <= CONT + 1;
            IF( CONT = 0 ) THEN
                CLK <= NOT CLK;
            END IF;
        END IF;
     END PROCESS PDIV; 


end VOLTAJE;
