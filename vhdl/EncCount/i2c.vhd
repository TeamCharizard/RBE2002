library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity i2c_slave is
	generic (
			 addr : std_logic_vector(6 downto 0) := "0001111");
	
	port (scl_x, sda_x  : out std_logic;
		  scl : inout std_logic;
		  sda : inout std_logic;
		  enc1a, enc1b : in std_logic;
		  enc2a, enc2b : in std_logic);
end entity;

architecture arch of i2c_slave is
	type state_t is (IDLE, READ_ADDR, READ_DATA, WRITE_DATA_ACK, WRITE_DATA);
	
	signal scl_out, sda_out: std_logic;
	signal scl_in, sda_in : std_logic;
	
	signal count1 : unsigned(7 downto 0);
	signal count2 : unsigned(7 downto 0);

	signal clk : std_logic;
	
	COMPONENT OSCH
	GENERIC  (NOM_FREQ: string);
	PORT (STDBY   : IN  std_logic;
		OSC     : OUT std_logic;
		SEDSTDBY: OUT std_logic);
	END COMPONENT;
begin
	osc : OSCH
		GENERIC MAP(NOM_FREQ => "10.23")
		port map(STDBY => '0', OSC => clk, SEDSTDBY => OPEN);
		
	scl_filter : entity work.filter
		generic map(num_phases => 4)
		port map(input => scl, output => scl_in, clk => clk);
		
	sda_filter : entity work.filter
		generic map(num_phases => 4)
		port map(input => sda, output => sda_in, clk => clk);
		
	dec1 : entity work.decoder
		port map(A => enc1a, B => enc1b, clk => clk, count => count1);
		
	dec2 : entity work.decoder
		port map(A => enc2a, B => enc2b, clk => clk, count => count2);

	sda_x <= sda_in;
	scl_x <= scl_in;

	-- SDA and SCL are open drain
	sda <= '0' when sda_out = '0' else 'Z';
	-- NOTE: Since we don't implement clock stretching, we don't need to drive scl
	--scl <= '0' when scl_out = '0' else 'Z';

	process (clk) 
		variable last_sda, last_scl : std_logic;
		variable state : state_t := IDLE;
		variable reg : std_logic_vector(7 downto 0);
		variable bit_num : natural range 0 to 7 := 0;
		variable byte_num : natural range 0 to 3 := 0;
		variable ack : std_logic := '0';
		variable waiting_ack : std_logic := '0';
		variable do_wait : std_logic := '0';
		variable timeout : integer range 0 to 41599;
	begin
		if (rising_edge(clk)) then
			timeout := timeout + 1;
			
			if timeout = 41599 then
				timeout := 0;
				waiting_ack := '0';
				do_wait := '0';
				ack := '0';
				state := IDLE;
			end if;
		
			if state = IDLE then
				scl_out <= '1';
				sda_out <= '1';
				bit_num := 0;
				byte_num := 0;
			end if; 
				
			if scl_in = '1' and last_scl = '0' then
				timeout := 0;
			
				case state is
				when READ_ADDR => 
					-- Shift in SDA
					reg := reg(6 downto 0) & sda_in;
					-- After reading 8 bits,
					if bit_num = 7 then
						bit_num := 0;
						-- If we see our address
						if (reg(7 downto 1) = addr) then
							-- Go to read or write state based on R/W bit
							state := READ_DATA when reg(0) = '1' else WRITE_DATA_ACK;
							-- Acknowledge
							ack := '1';
						else
							-- Otherwise, not us, go to IDLE
							state := IDLE;
						end if;
					else
						bit_num := bit_num + 1;
					end if;
				when READ_DATA =>
					if do_wait = '1' then
						do_wait := '0';
						
						-- No ack
						if sda_in = '1' then
							state := IDLE;
						end if;
					end if;
				when WRITE_DATA_ACK =>
					state := WRITE_DATA;
				when WRITE_DATA => -- (i.e. reading data from master)
					-- Shift in SDA
					reg := reg(6 downto 0) & sda;
					
					-- After reading 8 bits,
					if bit_num = 7 then
						bit_num := 0;
						
						-- TODO: does this device need to respond to any commands?
						-- Right now it won't
						
						ack := '1';
						state := IDLE;
					else
						bit_num := bit_num + 1;
					end if;
				when others =>
				end case;
			elsif scl_in = '0' and last_scl = '1' then
				if ack = '1' then
					ack := '0';
					sda_out <= '0';
				else
				case state is
				when READ_DATA =>
					if waiting_ack = '1' then
						waiting_ack := '0';
						sda_out <= '1'; -- release the line
						do_wait := '1';
					else
						if bit_num = 0 then
							case byte_num is
								when 0 => reg := std_logic_vector(count1);
								when others => reg := std_logic_vector(count2);
							end case;
						end if;
					
						sda_out <= reg(7);
						reg(7 downto 1) := reg(6 downto 0);					
						if bit_num = 7 then
							bit_num := 0;
							byte_num := byte_num + 1;
							
							waiting_ack := '1';
						else 
							bit_num := bit_num + 1;
						end if;
					end if;
				when others =>
					sda_out <= '1'; -- release line
				end case;
				end if;
			elsif scl_in = '1' then
				-- Check for start and stop bits
				if sda_in = '0' and last_sda = '1' then
					-- START bit
					state := READ_ADDR;
					--led <= '1';
				elsif sda_in = '1' and last_sda = '0' then
					-- STOP bit
					state := IDLE;
				end if;
			end if;
			last_sda := sda_in;
			last_scl := scl_in;
		end if;
	end	process;
end arch;