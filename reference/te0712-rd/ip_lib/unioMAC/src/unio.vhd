-------------------------------------------------------------------------------
-- Company			: Trenz Electronic
-- Engineer			: Oleksandr Kiyenko a.kienko@gmail.com
-- 
-- Create Date		: 29.05.2013
-- Design Name		: 
-- Module Name		:    
-- Project Name		: 
-- Target Devices	: 
-- Tool versions	: 
-- Description		: Serial for UNI/O MAC read core
--
-- Dependencies		: None
--
-- Revision			: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
-------------------------------------------------------------------------------
entity unio is
generic (
	C_DEBUG	: boolean := true;
	C_CLK_FREQ	: INTEGER := 100000000	-- clk Frequency in Herz
);
port ( 
	rst_n		: in  STD_LOGIC;
	clk 		: in  STD_LOGIC;		
--	tick		: in  STD_LOGIC;		
	scio_o 		: out STD_LOGIC	:= '0';
	scio_i 		: in  STD_LOGIC;
	scio_t 		: out STD_LOGIC := '1';
	mac 		: out STD_LOGIC_VECTOR(47 downto 0);
	mac_lo 		: out STD_LOGIC_VECTOR(31 downto 0);
	mac_hi 		: out STD_LOGIC_VECTOR(15 downto 0);
	dbg_out	    : out STD_LOGIC;
	dbg_mak     : out STD_LOGIC;
	valid		: out STD_LOGIC	:= '0'
);
end unio;
-------------------------------------------------------------------------------
architecture Behavioral of unio is
-------------------------------------------------------------------------------
signal baud_gen_cnt	: INTEGER range 0 to C_CLK_FREQ / 50000;	-- 50 kHz
signal sample		: STD_LOGIC;
signal hsample		: STD_LOGIC;
type sm_state_type	is (
	ST_IDLE,
	ST_STB_1, ST_STB_2, ST_STB_3, ST_STB_4, ST_STB_5,
	ST_WRITE_1, ST_WRITE_2, ST_WRITE_3, ST_WRITE_4, ST_WRITE_5, ST_WRITE_6,
	ST_WRITE_7, ST_WRITE_8, ST_WRITE_9, ST_WRITE_10, ST_WRITE_11, ST_WRITE_12,
	ST_WRITE_13, ST_WRITE_14, ST_WRITE_15, ST_WRITE_16, ST_WRITE_17, 
	ST_WRITE_18, ST_WRITE_19,
	ST_READ_1, ST_READ_2, ST_READ_3, ST_READ_4, ST_READ_5, ST_READ_6,
	ST_READ_7, ST_READ_8, ST_READ_9, ST_READ_10, ST_READ_11, ST_READ_12,
	ST_READ_13, ST_READ_14, ST_READ_15, ST_READ_16, ST_READ_17, ST_READ_18,
	ST_READ_19
);
signal sm_state		: sm_state_type := ST_STB_1;-- Start from standby pulse
type cmd_sm_state_type is (
	ST_HDR, ST_ADDR, ST_RD_CMD, ST_RD_MSB, ST_RD_LSB,
	ST_RD_M0, ST_RD_M1, ST_RD_M2, ST_RD_M3, ST_RD_M4, ST_RD_M5, 
	ST_END
);
signal cmd_sm_state	: cmd_sm_state_type	:= ST_HDR;
signal dly_cnt		: INTEGER range 0 to 30;
type cmd_type is (
	CMD_NONE,
	CMD_STANDBY,
	CMD_WRITE,
	CMD_READ
);
constant INS_READ	: STD_LOGIC_VECTOR( 7 downto 0) := x"03";
constant INS_CRRD	: STD_LOGIC_VECTOR( 7 downto 0) := x"06";
constant INS_WRITE	: STD_LOGIC_VECTOR( 7 downto 0) := x"6C";
constant INS_WREN	: STD_LOGIC_VECTOR( 7 downto 0) := x"96";
constant INS_WRDI	: STD_LOGIC_VECTOR( 7 downto 0) := x"91";
constant INS_RDSR	: STD_LOGIC_VECTOR( 7 downto 0) := x"05";
constant INS_WRSR	: STD_LOGIC_VECTOR( 7 downto 0) := x"6E";
constant INS_ERAL	: STD_LOGIC_VECTOR( 7 downto 0) := x"6D";
constant INS_SETAL	: STD_LOGIC_VECTOR( 7 downto 0) := x"67";

constant DEF_ADDR	: STD_LOGIC_VECTOR( 7 downto 0) := x"A0";
constant DEF_HDR	: STD_LOGIC_VECTOR( 7 downto 0) := x"55";
constant EUI48_ADDR	: STD_LOGIC_VECTOR(15 downto 0) := x"00FA";

signal cmd			: cmd_type;
signal cmd_ack		: STD_LOGIC	:= '0';
signal wr_data		: STD_LOGIC_VECTOR( 7 downto 0);
signal wr_mak		: STD_LOGIC;
signal write_data	: STD_LOGIC_VECTOR( 7 downto 0);
signal read_data	: STD_LOGIC_VECTOR( 7 downto 0);
signal mak			: STD_LOGIC;
signal edge			: STD_LOGIC;
signal pdata		: STD_LOGIC;

signal toggle		: STD_LOGIC;
signal toggle_d		: STD_LOGIC;

signal mac_i		: std_logic_vector(47 downto 0);

-------------------------------------------------------------------------------
begin
-------------------------------------------------------------------------------
    dbg_out <= scio_i;
    dbg_mak <= wr_mak; 
        
    mac_lo <= mac_i(31 downto 0);
    mac_hi <= mac_i(47 downto 32);
    
    mac <= mac_i;

--hsample <= tick;

--process(clk)
--begin
	--if(rst_n = '0')then
--		toggle	<= '0';
	--elsif(clk = '1' and clk'event)then
	  -- toggle_d <= toggle;
	   --if tick='1' then
		--	toggle <= not toggle;
  	   --end if;
	   --if toggle='1' and toggle_d='0' then
		--	sample <= '1';
	   --else		
		--	sample <= '0';
  	   --end if;
	--end if;
--end process;


process(clk, rst_n)
begin
	if(rst_n = '0')then
		baud_gen_cnt	<= 0;
	elsif(clk = '1' and clk'event)then
		if(baud_gen_cnt = (C_CLK_FREQ / 50000))then
			baud_gen_cnt	<= 0;
			sample			<= '1';
		else
			baud_gen_cnt	<= baud_gen_cnt + 1;
			sample			<= '0';
		end if;
		if(baud_gen_cnt = (C_CLK_FREQ / 50000 / 2))then
			hsample			<= '1';
		else
			hsample			<= '0';
		end if;
	end if;
end process;



process(clk, rst_n)
begin
	if(rst_n = '0')then
		pdata	<= '0';
		edge	<= '0';
	elsif(clk = '1' and clk'event)then
		if(hsample = '1')then
			edge	<= scio_i;
		end if;
--		if(pdata = '0' and scio_i = '1')then
--			edge	<= '1';
--		elsif(pdata = '1' and scio_i = '0')then
--			edge	<= '0';
--		end if;
--		pdata	<= scio_i;
	end if;
end process;

process(clk, rst_n)
begin
	if(rst_n = '0')then
		sm_state	<= ST_STB_1;
		scio_o		<= '1';	-- Drive 1
		scio_t		<= '0';	-- Standby pulse
	elsif(clk = '1' and clk'event)then
		if(sample = '1')then
			case sm_state is
				when ST_STB_1 =>
					cmd_ack		<= '0';
					scio_o		<= '1';	-- Drive 1
					scio_t		<= '0';	-- Standby pulse
					dly_cnt		<= 30;	-- Standby pulse
					sm_state	<= ST_STB_2;
				when ST_STB_2 =>
					if(dly_cnt = 0)then
						sm_state	<= ST_STB_3;
						scio_o		<= '0';	-- Drive 0
						scio_t		<= '0';	-- Header low pulse
						dly_cnt		<= 6;	-- Header low pulse
					else
						dly_cnt		<= dly_cnt - 1;
					end if;
				when ST_STB_3 =>
					sm_state	<= ST_STB_4;
				when ST_STB_4 =>
					sm_state	<= ST_STB_5;
					cmd_ack		<= '1';
				when ST_STB_5 =>
					sm_state	<= ST_IDLE;
					cmd_ack		<= '0';
						
			
				when ST_IDLE =>
					cmd_ack		<= '0';
					case cmd is
						when CMD_NONE =>	-- Go to default state
							scio_t		<= '1';
						when CMD_STANDBY =>
							scio_o		<= '1';	-- Drive 1
							scio_t		<= '0';	-- Standby pulse
							dly_cnt		<= 30;	-- 20 * 5 = 1 ms Standby pulse
							sm_state	<= ST_STB_1;
						when CMD_WRITE =>
							sm_state	<= ST_WRITE_1;
							scio_t		<= '0';	-- Drive bus
							scio_o		<= not wr_data(7);	-- Inverted
							write_data	<= wr_data;
							mak			<= wr_mak;
						when CMD_READ =>
							scio_t		<= '1';
							scio_o		<= '0';
							sm_state	<= ST_READ_1;
							mak			<= wr_mak;
					end case;
					
				when ST_WRITE_1	=>	sm_state	<= ST_WRITE_2;
					scio_o		<= write_data(7);	-- Direct
				when ST_WRITE_2 =>	sm_state	<= ST_WRITE_3;
					scio_o		<= not write_data(6);	-- Inverted
				when ST_WRITE_3 =>	sm_state	<= ST_WRITE_4;
					scio_o		<= write_data(6);		-- Direct
				when ST_WRITE_4 =>	sm_state	<= ST_WRITE_5;
					scio_o		<= not write_data(5);	-- Inverted
				when ST_WRITE_5 =>	sm_state	<= ST_WRITE_6;
					scio_o		<= write_data(5);		-- Direct
				when ST_WRITE_6 =>	sm_state	<= ST_WRITE_7;
					scio_o		<= not write_data(4);	-- Inverted
				when ST_WRITE_7 =>	sm_state	<= ST_WRITE_8;
					scio_o		<= write_data(4);		-- Direct
				when ST_WRITE_8 =>	sm_state	<= ST_WRITE_9;
					scio_o		<= not write_data(3);	-- Inverted
				when ST_WRITE_9 =>	sm_state	<= ST_WRITE_10;
					scio_o		<= write_data(3);		-- Direct
				when ST_WRITE_10 =>	sm_state	<= ST_WRITE_11;
					scio_o		<= not write_data(2);	-- Inverted
				when ST_WRITE_11 =>	sm_state	<= ST_WRITE_12;
					scio_o		<= write_data(2);		-- Direct
				when ST_WRITE_12 =>	sm_state	<= ST_WRITE_13;
					scio_o		<= not write_data(1);	-- Inverted
				when ST_WRITE_13 =>	sm_state	<= ST_WRITE_14;
					scio_o		<= write_data(1);		-- Direct
				when ST_WRITE_14 =>	sm_state	<= ST_WRITE_15;
					scio_o		<= not write_data(0);	-- Inverted
				when ST_WRITE_15 =>	sm_state	<= ST_WRITE_16;
					scio_o		<= write_data(0);		-- Direct
				when ST_WRITE_16 =>	sm_state	<= ST_WRITE_17;
					scio_o		<= not mak;				-- Inverted
				when ST_WRITE_17 =>	sm_state	<= ST_WRITE_18;
					scio_o		<= mak;					-- Direct
				when ST_WRITE_18 =>	sm_state	<= ST_WRITE_19;
					scio_t		<= '1';					-- SAK time
					cmd_ack		<= '1';
				when ST_WRITE_19 =>	sm_state	<= ST_IDLE;
					cmd_ack		<= '0';
					

				when ST_READ_1 =>	sm_state	<= ST_READ_2;
				when ST_READ_2 =>	sm_state	<= ST_READ_3;
					read_data(7)<= edge;
				when ST_READ_3 =>	sm_state	<= ST_READ_4;
				when ST_READ_4 =>	sm_state	<= ST_READ_5;
					read_data(6)<= edge;
				when ST_READ_5 =>	sm_state	<= ST_READ_6;
				when ST_READ_6 =>	sm_state	<= ST_READ_7;
					read_data(5)<= edge;
				when ST_READ_7 =>	sm_state	<= ST_READ_8;
				when ST_READ_8 =>	sm_state	<= ST_READ_9;
					read_data(4)<= edge;
				when ST_READ_9 =>	sm_state	<= ST_READ_10;
				when ST_READ_10 =>	sm_state	<= ST_READ_11;
					read_data(3)<= edge;
				when ST_READ_11 =>	sm_state	<= ST_READ_12;
				when ST_READ_12 =>	sm_state	<= ST_READ_13;
					read_data(2)<= edge;
				when ST_READ_13 =>	sm_state	<= ST_READ_14;
				when ST_READ_14 =>	sm_state	<= ST_READ_15;
					read_data(1)<= edge;
				when ST_READ_15 =>	sm_state	<= ST_READ_16;
				when ST_READ_16 =>	sm_state	<= ST_READ_17;
					read_data(0)<= edge;
					scio_t		<= '0';					-- Drive MAK
					scio_o		<= not mak;				-- Inverted
				when ST_READ_17 =>	sm_state	<= ST_READ_18;
					scio_o		<= mak;					-- Direct
					scio_t		<= '0';					-- Drive MAK
				when ST_READ_18 =>	sm_state	<= ST_READ_19;
					scio_t		<= '1';					-- SAK time
					cmd_ack		<= '1';
				when ST_READ_19 =>	sm_state	<= ST_IDLE;
					cmd_ack		<= '0';
					
			end case;
		end if;
	end if;
end process;

process(clk,rst_n)
begin
	if(rst_n = '0')then
		cmd_sm_state	<= ST_HDR;
	elsif(clk = '1' and clk'event)then
		if(sample = '1')then
			case cmd_sm_state is
				when ST_HDR		=> 
					cmd			<= CMD_WRITE;
					wr_data		<= DEF_HDR;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state	<= ST_ADDR;
					end if;
				when ST_ADDR		=> 
					cmd			<= CMD_WRITE;
					wr_data		<= DEF_ADDR;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state	<= ST_RD_CMD;
					end if;
				when ST_RD_CMD		=> 
					cmd			<= CMD_WRITE;
					wr_data		<= INS_READ;
					wr_mak			<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state	<= ST_RD_MSB;
					end if;
				when ST_RD_MSB		=> 
					cmd			<= CMD_WRITE;
					wr_data		<= EUI48_ADDR(15 downto 8);
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state	<= ST_RD_LSB;
					end if;
				when ST_RD_LSB		=> 
					cmd			<= CMD_WRITE;
					wr_data		<= EUI48_ADDR(7 downto 0);
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state	<= ST_RD_M0;
					end if;
				when ST_RD_M0		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						cmd_sm_state		<= ST_RD_M1;
					end if;
				when ST_RD_M1		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						mac_i(47 downto 40)	<= read_data;
						cmd_sm_state		<= ST_RD_M2;
					end if;
				when ST_RD_M2		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						mac_i(39 downto 32)	<= read_data;
						cmd_sm_state		<= ST_RD_M3;
					end if;
				when ST_RD_M3		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						mac_i(31 downto 24)	<= read_data;
						cmd_sm_state		<= ST_RD_M4;
					end if;
				when ST_RD_M4		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '1';
					if(cmd_ack = '1')then
						mac_i(23 downto 16)	<= read_data;
						cmd_sm_state		<= ST_RD_M5;
					end if;
				when ST_RD_M5		=> 
					cmd			<= CMD_READ;
					wr_mak		<= '0';
					if(cmd_ack = '1')then
						mac_i(15 downto 8)	<= read_data;
						cmd_sm_state		<= ST_END;
					end if;
				when ST_END =>
					if(cmd_ack = '1')then
						cmd			<= CMD_STANDBY;
						cmd_sm_state	<= ST_HDR;
						--wr_data		<= DEF_HDR;
						wr_mak		<= '1';
						mac_i(7 downto 0)	<= read_data;
						valid			<= '1';
					end if;
					--cmd			<= CMD_NONE;
					
			end case;
		end if;
	end if;
end process;
--dbg	<= sample;
-------------------------------------------------------------------------------
end Behavioral;
