----------------------------------------------------------------------------------
-- Company: ESCOM-IPN
-- Engineer: Team:  Carlos Huerta Garcia
--                  Brandon David Meza Vargas
--                  Kyuseop Shim
-- Create Date: 10/13/2021 11:07:26 AM
-- Design Name: ALU
-- Module Name: ALU - Behavioral
-- Project Name: ALU
-- Target Devices: 
-- Tool Versions: VHDL 2008
-- Description: ALU for 4 bits
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.02 - File Completed
-- Additional Comments:
--
-----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;

entity ALU is
    generic (N : integer := 4);
    Port (A, B : in std_logic_vector (N - 1 downto 0);
            OP : in std_logic_vector (1 downto 0);
            AINVERT, BINVERT : in std_logic;
            RES : inout std_logic_vector (N - 1 downto 0);
            CN, NG, Z, OV : out std_logic
            );
end ALU;

architecture Behavioral of ALU is
begin
    P_AU : process (A, B, AINVERT, BINVERT, OP)
    variable MUXA, MUXB, P, G: std_logic_vector(N - 1 downto 0);
    variable PK, GJPK, C0PI: std_logic;
    variable C: std_logic_vector(N downto 0);
    begin
        C := (others => '0');
        C(0) := BINVERT;
        for I in 0 to N - 1 loop
            MUXA(I) := A(I) xor AINVERT;
            MUXB(I) := B(I) xor BINVERT;
            case OP is
                when "00"=>
                    RES(I) <= MUXA(I) and MUXB(I);
                when "01"=>
                    RES(I) <= MUXA(I) or MUXB(I);
                when "10"=>
                    RES(I) <= MUXA(I) xor MUXB(I);
                when others =>
                    P(I) := MUXA(I) xor MUXB(I);
                    G(I) := MUXA(I) and MUXB(I);
                    RES(I) <= P(I) xor C(I);
                    GJPK := '0';
                    for J in 0 to I - 1 loop
                        PK := '1';
                        for K in J + 1 to I loop
                            PK := PK and P(K);
                        end loop;
                        GJPK := GJPK or (G(J) and PK);
                    end loop;
                    C0PI := C(0);
                    for L in 0 to I loop
                        C0PI := C0PI and P(L);
                    end loop;
                    C(I + 1) := G(I) or GJPK or C0PI;
            end case;
        end loop;
        CN <= C(N);
        OV <= C(N) xor C(N-1);
    end process P_AU;
    NG <= RES(N - 1);
    Z <= '1' when RES = 0 else '0';
end Behavioral;
