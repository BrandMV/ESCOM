----------------------------------------------------------------------------------
-- Arquitectura de Computadoras
-- Alumnos:
--          Carlos Huerta García
--          Brandon David Meza Vargas
--          Kyuseop Shim 


 --             *****Unidad de control*****

----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity CONTROL is
    Port ( COD_FUN : in STD_LOGIC_VECTOR (3 downto 0);
           COD_OPC : in STD_LOGIC_VECTOR (4 downto 0);
           Z, N, C, OV : in STD_LOGIC;
           CLK, CLR : in STD_LOGIC;
           WPC, SR1, SWD, WR, SOP, SOP2, WD, SR : out STD_LOGIC;
           ALUOP : out STD_LOGIC_VECTOR (3 downto 0));
end CONTROL;

architecture UNIDAD of CONTROL is
--Señales necesarias
SIGNAL LF, RZ, RN, RC, ROV : STD_LOGIC;
SIGNAL EQ, NEQ, LT, LET, GT, GET : STD_LOGIC;
SIGNAL BEQ, BNEQ, BLT, BLET, BGT, BGET, TIPOR: STD_LOGIC;
SIGNAL SDOPC, SM : STD_LOGIC;
SIGNAL A : STD_LOGIC_VECTOR( 4 DOWNTO 0 );
SIGNAL M : STD_LOGIC_VECTOR( 12 DOWNTO 0 );
--MEMORIAS
TYPE MEMF IS ARRAY ( 0 TO 15 ) OF STD_LOGIC_VECTOR( 12 DOWNTO 0 ); --MEMORIA CODIGO DE FUNCION
TYPE MEMO IS ARRAY ( 0 TO 31 ) OF STD_LOGIC_VECTOR( 12 DOWNTO 0 ); --MEMORIA CODIGO DE OPERACION
--TIPO DE DATO PARA AUTOMATA
TYPE ESTADOS IS (EDO_A);
SIGNAL EDO_ACT, EDO_SGTE : ESTADOS;

CONSTANT MEM_FUN : MEMF := ( --TIPO ROM
    "0011000011101",    --ADD
    "0011000111101",    --SUB
    "0011000000101",    --AND
    "0011000001101",    --OR
    "0011000010101",    --XOR
    "0011001101101",    --NAND
    "0011001100101",    --NOR
    "0011000110101",    --XNOR
    "0000000111100",    --CP
    OTHERS => (OTHERS => '0')
);
CONSTANT MEM_OPC  : MEMO := (
    "0000000000000", --NO SALTO
    "0001000000000", --LI
    "0011000000000", --LWI
    "0100000000010", --SWI
    "0011010011101", --ADDI
    "0011010111101", --SUBI
    "1000000000000", --B
    "0100110111100", --CPI
    "1000000000000", --BEQ
    "1000000000000", --BNEQ
    "1000000000000", --BLT
    "1000000000000", --BLET
    "1000000000000", --BGT
    "1000000000000", --BGET
    "0000000000000", --NOP
    OTHERS => (OTHERS => '0')
);

begin

    --SALIDAS
    WPC   <= M(12);
    SR1   <= M(11);
    SWD   <= M(10);
    WR    <= M(9);
    SOP   <= M(9); 
    SOP2  <= M(7);
    ALUOP <= M(6 DOWNTO 3);
    LF    <= M(2);
    WD    <= M(1); 
    SR    <= M(0);
    
    AUTOMATA : PROCESS( EDO_ACT, BEQ, BNEQ, BLT, BLET, BGT, BGET, TIPOR, EQ, NEQ, LT, LET, GT, GET )
    BEGIN
        SM    <= '0';
        SDOPC <= '0';
        CASE EDO_ACT IS 
            WHEN EDO_A => 
                IF( TIPOR = '0' ) THEN
                    IF( BEQ = '1' ) THEN
                        SM <= '1'; 
                        IF( EQ = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
                        
                    ELSIF (BNEQ = '1' ) THEN
                        SM <= '1'; 
                        IF( NEQ = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
                        
                    ELSIF (BLT = '1' ) THEN
                        SM <= '1';
                        IF( LT = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
                        
                    ELSIF (BLET = '1' ) THEN
                        SM <= '1';
                        IF( LET = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
                      
                    ELSIF (BGT = '1' ) THEN
                        SM <= '1';
                        IF( GT = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
     
                    ELSIF (BGET = '1' ) THEN
                        SM <= '1';
                        IF( GET = '1' ) THEN
                            SDOPC    <= '1';
                        END IF;
                    ELSE
                        SM    <= '1';
                        SDOPC <= '1';
                    END IF;
                END IF;
                EDO_SGTE <= EDO_A;
        END CASE;
    END PROCESS AUTOMATA;
    
    TRANSICION : PROCESS( CLK, CLR )
    BEGIN
        if ( CLR = '1' ) THEN -- PARA REINICIAR AUTOMATA
            EDO_ACT <= EDO_A;    
        ELSIF( rising_edge(CLK) ) THEN
            EDO_ACT <= EDO_SGTE;
        END IF;
    
    END PROCESS TRANSICION;
    
    --Registro de estados
    REG_EDO: PROCESS(CLK, CLR) --SE COLOCAN SEÑALES ASINCRONAS DE CONTROL
    BEGIN
        IF( CLR = '1' ) THEN
            RZ  <= '0';
            RN  <= '0';
            RC  <= '0';
            ROV <= '0';
        ELSIF( CLK'EVENT AND CLK ='1' ) THEN --DENTRO DE AQUI SINCRONO
        --LF SINCRONO POR ESTAR DENTRO DE CLK
            IF( LF = '1' ) THEN 
                RZ  <= Z;
                RN  <= N;
                RC  <= C;
                ROV <= OV; 
            END IF;
        END IF;
    END PROCESS REG_EDO;
    
    --BLOQUE DE CONDICION
    EQ  <= RZ;
    NEQ <= NOT RZ;
    LT  <= (NOT RZ) AND (RN XOR ROV);
    LET <= RZ OR (RN XOR ROV);
    GT  <= (NOT RZ) AND (NOT(RN XOR ROV));
    GET <= RZ OR NOT(RN XOR ROV);
    
    --DECODIFICADOR DE INSTRUCCION
    TIPOR <= '1' WHEN( COD_OPC = "00000" ) ELSE '0';
    BEQ   <= '1' WHEN( COD_OPC = "01000" ) ELSE '0';
    BNEQ  <= '1' WHEN( COD_OPC = "01001" ) ELSE '0';
    BLT   <= '1' WHEN( COD_OPC = "01010" ) ELSE '0';
    BLET  <= '1' WHEN( COD_OPC = "01011" ) ELSE '0';
    BGT   <= '1' WHEN( COD_OPC = "01100" ) ELSE '0';
    BGET  <= '1' WHEN( COD_OPC = "01101" ) ELSE '0';
    
    --MUX CHIKITO
    A <= "00000" WHEN ( SDOPC = '0' ) ELSE COD_OPC;
    M <= MEM_FUN( conv_integer(COD_FUN) ) WHEN ( SM = '0' ) ELSE MEM_OPC( conv_integer(A) );
end UNIDAD;
