library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity decoder is
	port(A, B, clk : in std_logic; count : out unsigned(7 downto 0));
end decoder;

architecture arch of decoder is
	signal c : unsigned(7 downto 0) := "00001111";
	signal A_in, B_in : std_logic;
begin

	A_filter : entity work.filter
		generic map(num_phases => 4)
		port map(input => A, output => A_in, clk => clk);
		
	
	B_filter : entity work.filter
		generic map(num_phases => 4)
		port map(input => B, output => B_in, clk => clk);

	count <= c;
	process(clk)
		variable last : std_logic_vector(1 downto 0);
	begin
		if rising_edge(clk) then
			case last & A_in & B_in is
				when "0010" | "1011" | "1101" | "0100" => c <= c + 1;
				when "0001" | "0111" | "1110" | "1000" => c <= c - 1;
				when others =>
			end case;
			last := A_in & B_in;
		end if;
	end process;
end arch;

