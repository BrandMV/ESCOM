library library IEEE;
use IEEE.std_logic_1164.all;

entity FFE is
    port(PRE, CLR, CLK, X: in std_logic;
    Q,NQ: out std_logic);
end entity

architecture A_FFE of FFE is
    
begin
    procces(CLR, PRE, CLK, X)
    begin
        if(CLR='1') then
            Q<='0';
            NQ<='1';
        elsif(CLK'event and CLK='0') then
            if(PRE='0') then
                Q<='1';
                NQ<='0';
            elsif(X='0') then
                Q<='0';
                NQ<='1';
            else
                Q<='1';
                NQ<='0';
            end if;
        else
            if() then
        end if;
    end process;
    
end architecture A_FFE;