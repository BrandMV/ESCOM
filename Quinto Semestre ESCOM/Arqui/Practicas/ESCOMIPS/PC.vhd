

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.all;

entity PC is
    GENERIC( N : INTEGER := 8 );
    Port ( D : in STD_LOGIC_VECTOR (7 downto 0);
           Q : inout STD_LOGIC_VECTOR (7 downto 0);
           CLK,CLR : in STD_LOGIC;
           WPC : in STD_LOGIC);
end PC;

architecture PROGRAMA of PC is

begin
    PPC : PROCESS( CLK,CLR )
    BEGIN
        IF( CLR = '1' ) THEN -- USA CLR, ENTONCES SINTETIZAREMOS CON FLIP FLOPS
            Q <= (OTHERS => '0');
        ELSIF( rising_edge(CLK) ) THEN
            IF( WPC = '1' ) THEN
                Q <= D;
            ELSE
                Q <= Q + 1;
            END IF;
        END IF;
    END PROCESS PPC;

end PROGRAMA;
