----------------------------------------------------------------------------------
library ieee;
use ieee.STD_LOGIC_1164.all;
use ieee.numeric_std.all;
library UNISIM; 
use UNISIM.VCOMPONENTS.ALL;
----------------------------------------------------------------------------------
entity ft601_if is
generic(
	C_USE_BUFG				: BOOLEAN				:= TRUE;
	C_LED_DELAY				: integer				:= 25000000;
	-- Interface related
	C_TDEST_WIDTH			: integer				:= 2;
	C_TDEST_VALUE			: integer				:= 1
);
port (
	clk_in					: in  STD_LOGIC;

	data_io					: inout STD_LOGIC_VECTOR(15 downto 0);
	--data_o_debug					: out STD_LOGIC_VECTOR(15 downto 0);
	--data_i_debug					: out STD_LOGIC_VECTOR(15 downto 0);
	be_io					  : inout STD_LOGIC_VECTOR( 1 downto 0);
	--be_o_debug					  : out STD_LOGIC_VECTOR( 1 downto 0);
	--be_i_debug					  : out STD_LOGIC_VECTOR( 1 downto 0);
	txe_n_in				: in  STD_LOGIC;
	rxf_n_in				: in  STD_LOGIC;
	siwu_n_out		  : out STD_LOGIC;
	wr_n_out				: out STD_LOGIC;
	rd_n_out				: out STD_LOGIC;
	oe_n_out				: out STD_LOGIC;
	reset_n_out				: out STD_LOGIC;
	wakeup_n_out			: out STD_LOGIC;
	led_out					: out STD_LOGIC;
	
	axis_aclk				: out STD_LOGIC;
	
	m_axis_tvalid			: out STD_LOGIC;
	m_axis_tready			: in  STD_LOGIC;
	m_axis_tdata			: out STD_LOGIC_VECTOR(15 downto 0);
	m_axis_tkeep			: out STD_LOGIC_VECTOR( 1 downto 0);
	m_axis_tdest			: out STD_LOGIC_VECTOR(C_TDEST_WIDTH-1 downto 0);
	m_axis_tlast			: out STD_LOGIC;

	s_axis_tvalid			: in  STD_LOGIC;
	s_axis_tready			: out STD_LOGIC;
	s_axis_tdata			: in  STD_LOGIC_VECTOR(15 downto 0);
	s_axis_tkeep			: in  STD_LOGIC_VECTOR(1 downto 0);
	s_axis_tlast			: in  STD_LOGIC
);
end ft601_if;
----------------------------------------------------------------------------------
architecture arch_imp of ft601_if is
----------------------------------------------------------------------------------
constant net_gnd			: STD_LOGIC := '0';
constant net_vcc			: STD_LOGIC := '1';
constant C_LD_DELAY			: STD_LOGIC_VECTOR(8 downto 0) := "000000000";
----------------------------------------------------------------------------------
type sm_state_type is (ST_IDLE, ST_TX, ST_OE, ST_RX, ST_TE);
signal sm_state				: sm_state_type := ST_IDLE;
--------------------------------------------------------------------------------
signal clk					: STD_LOGIC;
signal data_t				: STD_LOGIC;
signal data_o				: STD_LOGIC_VECTOR(15 downto 0);
signal data_i				: STD_LOGIC_VECTOR(15 downto 0);
signal m_axis_tkeep_sig				: STD_LOGIC_VECTOR(1 downto 0);
signal tx_be_drv			: STD_LOGIC_VECTOR( 1 downto 0);
signal rx_ready_drv			: STD_LOGIC;
signal tx_valid_drv			: STD_LOGIC;
signal led_cnt				: integer range 0 to C_LED_DELAY-1;
----------------------------------------------------------------------------------
begin
----------------------------------------------------------------------------------
--data_o_debug <= data_o;
--be_o_debug <= m_axis_tkeep_sig;

--m_axis_tkeep  <= m_axis_tkeep_sig;

--data_i_debug <= data_i;
--be_i_debug <= tx_be_drv;

reset_n_out			<= '1';
wakeup_n_out		<= '1';
siwu_n_out			<= '1';
axis_aclk			<= clk;
m_axis_tdest		<= STD_LOGIC_VECTOR(TO_UNSIGNED(C_TDEST_VALUE,C_TDEST_WIDTH));
----------------------------------------------------------------------------------
bufg_gen: if C_USE_BUFG = TRUE generate
	bufg_inst: BUFG
	port map (
		I			=> clk_in,
		O			=> clk
	);
end generate;
no_bufg_gen: if C_USE_BUFG = FALSE generate
	clk				<= clk_in;
end generate;
----------------------------------------------------------------------------------
-- FIFO Interfaces
tx_be_drv			<= s_axis_tkeep;
rx_ready_drv		<= m_axis_tready;
tx_valid_drv		<= s_axis_tvalid;
----------------------------------------------------------------------------------
data_buf_gen: for i in 0 to 15 generate
	obuft_d_inst: IOBUF
	port map (
		I			=> data_i(i),
		T			=> data_t,
		O			=> data_o(i),
		IO			=> data_io(i)
	);
end generate;


be_buf_gen: for i in 0 to 1 generate
	obuft_be_inst: IOBUF
	port map (
		I			=> tx_be_drv(i),
		T			=> data_t,
		O			=> m_axis_tkeep(i),
		IO		=> be_io(i)
	);
end generate;

process(clk)	-- Bus Logic
begin
	if(clk = '1' and clk'event)then
		m_axis_tdata		<= data_o;
		if((rxf_n_in = '0') and (sm_state = ST_RX))then
			m_axis_tvalid	<= '1';
		else
			m_axis_tvalid	<= '0';
		end if;
	end if;
end process;

process(clk)	-- LED Logic
begin
	if(clk = '1' and clk'event)then
		if(sm_state /= ST_IDLE)then
			led_cnt			<= C_LED_DELAY-1;
			led_out			<= '1';
		else
			if(led_cnt = 0)then
				led_out		<= '0';
			else
				led_cnt		<= led_cnt - 1;
			end if;
		end if;
	end if;
end process;

----------------------------------------------------------------------------------
process(clk)	-- Bus Logic
begin
	if(clk = '1' and clk'event)then
		case sm_state is
			when ST_IDLE => 
				if((tx_valid_drv = '1') and (txe_n_in = '0'))then
					sm_state		<= ST_TE;
				elsif((rx_ready_drv = '1') and (rxf_n_in = '0'))then -- Wenn FT600 Daten für FPGA hat und Axi Master ready ist Daten anzunehmen
					sm_state		<= ST_OE;
				end if;
			when ST_TE =>
				sm_state	<= ST_TX;
			when ST_TX =>
				if((tx_valid_drv = '0') or (txe_n_in = '1') or (s_axis_tlast = '1' and tx_valid_drv = '1'))then
					sm_state		<= ST_IDLE;
				end if;
			when ST_OE =>
				sm_state		<= ST_RX;
			when ST_RX =>
				if((rx_ready_drv = '0') or (rxf_n_in = '1'))then -- solange RX state bis Ft600 sagt RXF = high oder Axi Master nicht mehr ready ist bzw keine Daten mehr durchgeben kann
					sm_state		<= ST_IDLE;
				end if;   
		end case;
	end if;
end process;
----------------------------------------------------------------------------------
s_axis_tready		<= (not txe_n_in) when (sm_state = ST_TX) else '0';
wr_n_out			<= (not s_axis_tvalid) when (sm_state = ST_TX) else '1';
data_i				<= s_axis_tdata;
data_t				<= '0' when (sm_state = ST_TX or sm_state = ST_TE) else '1';
rd_n_out			<= '0' when (sm_state = ST_RX) else '1';
oe_n_out			<= '0' when ((sm_state = ST_RX) or (sm_state = ST_OE)) else '1';
m_axis_tlast		<= '0';
----------------------------------------------------------------------------------
end arch_imp;
