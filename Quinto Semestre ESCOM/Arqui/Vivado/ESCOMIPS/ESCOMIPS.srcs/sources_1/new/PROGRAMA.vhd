
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;

entity PROGRAMA is
    GENERIC( BITS_BUS_DIR   : INTEGER := 8;
             BITS_BUS_DATOS : INTEGER := 15   ); 
    Port ( BUS_DIR   : in STD_LOGIC_VECTOR (BITS_BUS_DIR-1 downto 0);
           BUS_DATOS : out STD_LOGIC_VECTOR (BITS_BUS_DATOS-1 downto 0));
end PROGRAMA;

architecture MEMORIA of PROGRAMA is
    --CODIGOS DE OPERACION
    CONSTANT OP_TR  : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00000";
    CONSTANT OP_LI  : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00001";
    CONSTANT OP_LWI : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00010";
    CONSTANT OP_SWI : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00011";
    CONSTANT OP_B   : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00110";
    constant OP_ADDI: STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00100";
    constant OP_SUBI: STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00101";
    constant OP_CPI : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "00111";
    constant OP_EQ  : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01000";
    constant OP_NEQ : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01001";
    constant OP_LT  : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01010";
    constant OP_LET : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01011";
    constant OP_GT  : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01100";
    constant OP_GET : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01101";
    constant NOP    : STD_LOGIC_VECTOR( 4 DOWNTO 0 ) := "01110";

    --CODIGOS DE FUNCION
    CONSTANT FUNC_ADD  : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0000";
    CONSTANT FUNC_SUB  : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0001";
    CONSTANT FUNC_AND  : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0010";
    CONSTANT FUNC_OR   : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0011";
    CONSTANT FUNC_XOR  : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0100";
    CONSTANT FUNC_NAND : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0101";
    CONSTANT FUNC_NOR  : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0110";
    CONSTANT FUNC_XNOR : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "0111";
    CONSTANT FUNC_CP   : STD_LOGIC_VECTOR( 3 DOWNTO 0 ) := "1000";
    --S/U
    CONSTANT SU  :  STD_LOGIC_VECTOR( 1 DOWNTO 0 ) := "00";
    
    --REGISTROS
    CONSTANT R0 : STD_LOGIC_VECTOR( 1 DOWNTO 0 ) := "00";
    CONSTANT R1 : STD_LOGIC_VECTOR( 1 DOWNTO 0 ) := "01";
    CONSTANT R2 : STD_LOGIC_VECTOR( 1 DOWNTO 0 ) := "10";
    CONSTANT R3 : STD_LOGIC_VECTOR( 1 DOWNTO 0 ) := "11";
    
    TYPE MEM_ROM IS ARRAY( 0 TO 2**BITS_BUS_DIR-1 ) OF STD_LOGIC_VECTOR( BUS_DATOS'RANGE );
    CONSTANT MEM_PROG : MEM_ROM := (
                                     --PROGRAMA CONTADOR
--                                     OP_LI&R0&X"01",                --LI RO #1
--                                     OP_LI&R1&X"07",                --LI R1, #7
--                                     OP_TR&R1&R1&R0&FUNC_ADD,       --ADD R1, R1 R0
--                                     OP_SWI&R1&X"05",               --SWI R1, 5
--                                     OP_B&SU&X"02",                 --B CICLO
                                     
--                                     --NUMEROS PARES E IMPARES
--                                     OP_LI&R0&X"01",
--                                     OP_ADDI&R0&R0&"000001",
--                                     OP_LI&R1&X"01",
--                                     OP_TR&R1&R0&R1&FUNC_AND,
--                                     OP_EQ&SU&X"08",
--                                     OP_LI&R1&X"0F",
--                                     OP_SWI&R1&X"0A",
--                                     OP_B&SU&X"01",
--                                     OP_LI&R1&X"F0",
--                                     OP_SWI&R1&X"0A",
--                                     OP_B&SU&X"01",
                                       

                                     --FIBONACCI
--                                     OP_LI&R0&X"00",
--                                     OP_LI&R1&X"01",
--                                     OP_LI&R2&X"00",
--                                     OP_TR&R0&R0&R1&FUNC_ADD,
--                                     OP_SWI&R0&X"48",
--                                     OP_TR&R1&R0&R1&FUNC_ADD,
--                                     OP_SWI&R1&X"48",
--                                     OP_ADDI&R2&R2&"000010",
--                                     OP_CPI&R2&X"0C",
--                                     OP_NEQ&SU&X"03",
--                                     NOP&SU&SU&SU&SU&SU,
--                                     OP_B&SU&X"0A",

                                    --comparar numeros
                                    OP_LI&R0&"00010111",
                                    OP_LI&R1&"11010011",
                                    OP_LI&R2&X"A5", --165
                                    OP_TR&SU&R0&R1&FUNC_CP,
                                    OP_GT&SU&"00000110",
                                    OP_ADDI&R0&R1&"000000",
                                    OP_TR&SU&R0&R2&FUNC_CP,
                                    OP_GT&SU&"00001001",
                                    OP_ADDI&R0&R2&"000000",
                                    OP_SWI&R0&X"14",
                                    OP_B&SU&"00001001",
                                     OTHERS => ( OTHERS => '0' )    --primer others recorre las 128 datos y el segundo para las direcciones
                                   );
begin
    BUS_DATOS <= MEM_PROG( CONV_INTEGER(BUS_DIR) );
end MEMORIA;
