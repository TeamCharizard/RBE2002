library ieee;
use ieee.std_logic_1164.all;

entity filter is
	generic(num_phases : integer);
	port(input : in std_logic;
		 output : out std_logic;
		 clk : in std_logic);
end filter;

architecture arch of filter is
begin
	process(clk)
		variable reg : std_logic_vector(num_phases-1 downto 0);
		variable x : std_logic;
	begin
		if rising_edge(clk) then
			reg := reg(num_phases-2 downto 0) & input;
		
			x := '1';
		
			for i in 1 to num_phases-1 loop
				x := x and (reg(0) xnor reg(i));
			end loop;
			
			if x = '1' then
				output <= reg(0);
			end if;
		end if;
	end process;
end arch;