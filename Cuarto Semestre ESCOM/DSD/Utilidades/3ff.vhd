library IEEE;
use IEEE.std_logic_1164.all;

entity reg is
    port(clk,clr,ecd,eci:in std_logic;
        c: in std_logic_vector (1 downto 0);
        dato:in std_logic_vector (2 downto 0);
        q: inout std_logic_vector (2 downto 0)
    );
end entity;

architecture a_reg of reg is
    signal aux: std_logic_vector (2 downto 0);
    begin
    --MULIPLEXORES------------------------------------------------------
    mux2: process (c) begin
        case c is 
            when "00" =>
                aux(2)<=dato(2);
            when "01" =>
                aux(2)<= edc;
            when "10" =>
                aux(2)<=q(1);
            when others=> --11
                aux(2)<= q(2);
        end case;
    end process mux2;

    mux1: process (c) begin
        case c is 
            when "00" =>
                aux(1)<=dato(1);
            when "01" =>
                aux(1)<= q(2);
            when "10" =>
                aux(1)<=q(0);
            when others=> --11
                aux(1)<= q(1);
        end case;
    end process mux1;

    mux0: process (c) begin
        case c is 
            when "00" =>
                aux(0)<=dato(0);
            when "01" =>
                aux(0)<= q(1);
            when "10" =>
                aux(0)<=eci;
            when others=> --11
                aux(0)<= q(0);
        end case;
    end process mux0;
    --MULIPLEXORES------------------------------------------------------

    --REGISTROS-----------------------------------------------------
    process (clk, clr) begin
        if (clr='0') then
            q<="000";
        elsif (clk'event and clk='1') then
            q<=aux;
        end if;
    end process;   
    --REGISTROS-----------------------------------------------------
end architecture;