----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta García
--          Brandon David Meza Vargas
--          Kyuseop Shim 
-- Module Name: sumador-restador - PROGRAM



 --             *****Practica Sumador Restador*****

----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sumadorRestador is
    GENERIC( N : INTEGER := 4 );
    Port ( A, B : in STD_LOGIC_VECTOR (N-1 downto 0);
           BINVERT : in STD_LOGIC;
           S : inout STD_LOGIC_VECTOR (N-1 downto 0);
           CN : inout STD_LOGIC;
           NF : out STD_LOGIC;
           OV : out STD_LOGIC;
           Z : out STD_LOGIC);
end sumadorRestador;

architecture PROGRAM of sumadorRestador is

begin

    PSR : PROCESS( A, B, BINVERT )
    variable EB : std_logic_vector(N-1 downto 0);
    variable C : std_logic_vector(N downto 0);
    variable SAUX : std_logic_vector(N-1 downto 0); --Para guardar los valores de resultado en el proceso
    BEGIN
        C(0) := BINVERT;
        FOR I IN 0 TO N-1 LOOP
            EB(I) := B(I) XOR BINVERT;
            SAUX(I) := A(I) XOR EB(I) XOR C(I); 
            C(I+1) := (A(I) AND C(I)) OR (EB(I) AND C(I)) OR (A(I) AND EB(I));
            S(I) <= SAUX(I);
         END LOOP;
         CN <= C(N);
         NF <= SAUX(N-1); --Bandera Negative
         OV <= C(N) xor C(N-1); --Bandera Overflow
         Z <= (SAUX(0) NOR SAUX(1)) NOR (SAUX(2) NOR SAUX(3)); --Bandera Zero
     END PROCESS PSR;


end PROGRAM;
