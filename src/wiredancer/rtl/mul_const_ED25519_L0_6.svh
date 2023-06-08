logic [131-1:0] out_p;
logic [131-1:0] out_n;
logic [M-1:0] p_m_o;
logic [M-1:0] n_m_o;
logic [2-1:0][M-1:0] p_m_o_p;
logic [161-1:0] p_s_1_00;
logic [ 40-1:0] p_s_0_00;
logic [ 33-1:0] p_s_0_06;
logic [ 11-1:0] p_s_0_18;
logic [ 40-1:0] p_s_0_12;
`SHADD_6_1C( 40, p_s_0_00,   0,  10,  12,  24,  31,  33, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]});
`SHADD_6_1C( 33, p_s_0_06,   0,   5,  10,  12,  15,  26, {33'b0, in0[0+:  6]}, {33'b0, in0[0+:  6]}, {33'b0, in0[0+:  6]}, {33'b0, in0[0+:  6]}, {33'b0, in0[0+:  6]}, {33'b0, in0[0+:  6]});
`SHADD_6_1C( 40, p_s_0_12,   0,   5,  18,  21,  23,  33, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]}, {40'b0, in0[0+:  6]});
`SHADD_6_1C( 11, p_s_0_18,   0,   2,   4,   0,   0,   0, {11'b0, in0[0+:  6]}, {11'b0, in0[0+:  6]}, {11'b0, in0[0+:  6]}, {11'b0, '0}, {11'b0, '0}, {11'b0, '0});
`SHADD_6_1C(161, p_s_1_00,   0,  37,  72, 120,   0,   0, {161'b0, p_s_0_00}, {161'b0, p_s_0_06}, {161'b0, p_s_0_12}, {161'b0, p_s_0_18}, {161'b0, '0}, {161'b0, '0});
assign out_p = p_s_1_00 << 0;
assign p_m_o = p_m_o_p[2-1];
always_ff@(posedge clk) p_m_o_p[0] <= m_i;
always_ff@(posedge clk) p_m_o_p[1] <= p_m_o_p[1-1];
logic [2-1:0][M-1:0] n_m_o_p;
logic [ 39-1:0] n_s_0_06;
logic [126-1:0] n_s_1_00;
logic [ 31-1:0] n_s_0_00;
logic [ 25-1:0] n_s_0_12;
logic [ 36-1:0] n_s_0_18;
`SHADD_6_1C( 31, n_s_0_00,   0,   2,  12,  15,  17,  24, {31'b0, in0[0+:  6]}, {31'b0, in0[0+:  6]}, {31'b0, in0[0+:  6]}, {31'b0, in0[0+:  6]}, {31'b0, in0[0+:  6]}, {31'b0, in0[0+:  6]});
`SHADD_6_1C( 39, n_s_0_06,   0,   6,  11,  16,  30,  32, {39'b0, in0[0+:  6]}, {39'b0, in0[0+:  6]}, {39'b0, in0[0+:  6]}, {39'b0, in0[0+:  6]}, {39'b0, in0[0+:  6]}, {39'b0, in0[0+:  6]});
`SHADD_6_1C( 25, n_s_0_12,   0,   2,   4,   9,  14,  18, {25'b0, in0[0+:  6]}, {25'b0, in0[0+:  6]}, {25'b0, in0[0+:  6]}, {25'b0, in0[0+:  6]}, {25'b0, in0[0+:  6]}, {25'b0, in0[0+:  6]});
`SHADD_6_1C( 36, n_s_0_18,   0,   9,  13,  19,  24,  29, {36'b0, in0[0+:  6]}, {36'b0, in0[0+:  6]}, {36'b0, in0[0+:  6]}, {36'b0, in0[0+:  6]}, {36'b0, in0[0+:  6]}, {36'b0, in0[0+:  6]});
`SHADD_6_1C(126, n_s_1_00,   0,  27,  63,  86,   0,   0, {126'b0, n_s_0_00}, {126'b0, n_s_0_06}, {126'b0, n_s_0_12}, {126'b0, n_s_0_18}, {126'b0, '0}, {126'b0, '0});
assign out_n = n_s_1_00 << 2;
assign n_m_o = n_m_o_p[2-1];
always_ff@(posedge clk) n_m_o_p[0] <= m_i;
always_ff@(posedge clk) n_m_o_p[1] <= n_m_o_p[1-1];
always_ff@(posedge clk) out0 <= out_p - out_n;
always_ff@(posedge clk) m_o <= p_m_o;