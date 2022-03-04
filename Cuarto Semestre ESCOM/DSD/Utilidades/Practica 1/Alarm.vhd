-- ==================================================== --
-- ==============                ALARM              =================== --
-- ==================================================== --

LIBRARY IEEE; 
USE IEEE.STD_LOGIC_1164.ALL;
ENTITY CA IS
	PORT(
		A,B,C,D,SEL,REF: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		DISPLAY: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
		);
END CA; 

ARCHITECTURE A_CA OF CA IS
	SIGNAL DATA: STD_LOGIC_VECTOR(1 DOWNTO 0);
	CONSTANT greaterThan: STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000111";
	CONSTANT lessThan: STD_LOGIC_VECTOR(6 DOWNTO 0) := "0110001";
	CONSTANT equals: STD_LOGIC_VECTOR(6 DOWNTO 0) := "1110110";
	BEGIN

		-- ~~~MULTIPLEXOR PROCESS~~~ --

		MUX: PROCESS(SEL)
			BEGIN
				CASE SEL IS
					WHEN "00" => DATA <= A;
					WHEN "01" => DATA <= B;
					WHEN "10" => DATA <= C;
					WHEN OTHERS => DATA <= D;
				END CASE;
			END PROCESS MUX;

		-- ~~~COMPARATOR AND DECODER ~~~ --

		COMP_DECO: PROCESS(DATA, REF)
			BEGIN
				IF(DATA > REF) THEN
					DISPLAY <= greaterThan;
				ELSIF(DATA < REF) THEN
					DISPLAY <= lessThan;
				ELSE
					DISPLAY <= equals;
				END IF;
			END PROCESS COMP_DECO;
	END A_CA;

