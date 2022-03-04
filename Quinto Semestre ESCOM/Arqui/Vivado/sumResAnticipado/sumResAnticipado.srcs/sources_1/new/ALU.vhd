library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.ALL;

entity ALU is
    GENERIC( N: INTEGER := 4 );
    Port ( Z, NF, CN, OV : out STD_LOGIC;
           A, B : in STD_LOGIC_VECTOR (N-1 downto 0);
           AINVERT : in STD_LOGIC;
           BINVERT : in STD_LOGIC;
           OP : in STD_LOGIC_VECTOR (1 downto 0);
           RES : inout STD_LOGIC_VECTOR (N-1 downto 0);
           S : inout STD_LOGIC_VECTOR (N-1 downto 0));
end ALU;

architecture Behavioral of ALU is

begin
    PAU2 : process( A, B, AINVERT, BINVERT, OP )
        variable MUXA, MUXB, P, G : std_logic_vector (N-1 downto 0);
        variable PK, T2, PL, T3 : std_logic;
        variable C : std_logic_vector (N downto 0);
        begin
            C(0) := BINVERT;
            for I in 0 to N-1 loop
                MUXA(I) := A(I) XOR AINVERT;
                MUXB(I) := B(I) XOR BINVERT;
                CASE OP IS
                    WHEN "00" =>
                        RES(I) <= MUXA(I) AND MUXB(I);
                    WHEN "01" =>
                        RES(I) <= MUXA(I) OR MUXB(I);
                    WHEN "10" =>
                        RES(I) <= MUXA(I) XOR MUXB(I);
                    WHEN OTHERS => 
--                        EB(i) := B(i) xor BINVERT; replaced by MUXB
                        P(I) := A(I) xor MUXB(I);
                        G(I) := A(I) AND MUXB(I);
                        S(i) <= P(I) xor C(I);
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
                
                     END CASE;
            end loop;  
            
            CN <= C(N); --Carry flag
            OV <= C(N) xor C(N-1);  -- Overflow flag 
            
        end process PAU2;
            Z <= '1' when ( S = 0 ) else '0';   --Zero flag concurrent
            NF <= S(N-1);   --Negative flag


end Behavioral;
