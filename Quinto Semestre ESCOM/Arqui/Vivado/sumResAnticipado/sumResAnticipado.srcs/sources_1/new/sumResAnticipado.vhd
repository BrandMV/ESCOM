----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta García
--          Brandon David Meza Vargas
--          Kyuseop Shim 
-- Module Name: Sumador-restador carreo antipicado



 --             *****Practica Sumador Restador Con Acarreo Anticipado*****

----------------------------------------------------------------------------------



library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.ALL;


entity sumResAnticipado is
    generic ( N : integer := 4 );
    Port ( A : in STD_LOGIC_VECTOR (N-1 downto 0);
           B : in STD_LOGIC_VECTOR (N-1 downto 0);
           BINVERT : in STD_LOGIC;
           S : inout STD_LOGIC_VECTOR (N-1 downto 0);
           CN, NF, Z, OV : out STD_LOGIC);
end sumResAnticipado;

architecture Behavioral of sumResAnticipado is
begin
    PAU2 : process( A, B, BINVERT )
    variable EB, P, G : std_logic_vector (N-1 downto 0);
    variable PK, T2, PL, T3 : std_logic;
    variable C : std_logic_vector (N downto 0);
    begin
        C(0) := BINVERT;
        for i in 0 to N-1 loop
            EB(i) := B(i) xor BINVERT;
            P(i) := A(i) xor EB(i);
            G(i) := A(i) AND EB(i);
            S(i) <= P(i) xor C(i);
            T2 := '0';
            for j in 0 to i-1 loop
                PK := '1';
                for k in j+1 to i loop
                    PK := PK AND P(k);
                end loop;
                T2 := T2 OR (G(j) AND PK);
            end loop;
            PL := '1';
            for l in 0 to i loop
                PL := PL and P(l);
                T3 := C(0) and PL;
            end loop;
            
            C(i+1) := G(i) or T2 or T3;
            
        end loop;  
        
        CN <= C(N); --Carry flag
        OV <= C(N) xor C(N-1);  -- Overflow flag 
        
    end process PAU2;
        Z <= '1' when ( S = 0 ) else '0';   --Zero flag
        NF <= S(N-1);   --Negative flag

end Behavioral;
