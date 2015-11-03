// Verilog netlist produced by program LSE :  version Diamond (64-bit) 3.5.0.102
// Netlist written on Mon Nov 02 14:42:05 2015
//
// Verilog Description of module i2c_slave
//

module i2c_slave (scl_x, sda_x, scl, sda, enc1a, enc1b, enc2a, 
            enc2b);   // c:/users/joseph martin/enccount/i2c.vhd(5[8:17])
    output scl_x;   // c:/users/joseph martin/enccount/i2c.vhd(9[8:13])
    output sda_x;   // c:/users/joseph martin/enccount/i2c.vhd(9[15:20])
    input scl /* synthesis .original_dir=IN_OUT */ ;   // c:/users/joseph martin/enccount/i2c.vhd(10[5:8])
    inout sda;   // c:/users/joseph martin/enccount/i2c.vhd(11[5:8])
    input enc1a;   // c:/users/joseph martin/enccount/i2c.vhd(12[5:10])
    input enc1b;   // c:/users/joseph martin/enccount/i2c.vhd(12[12:17])
    input enc2a;   // c:/users/joseph martin/enccount/i2c.vhd(13[5:10])
    input enc2b;   // c:/users/joseph martin/enccount/i2c.vhd(13[12:17])
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    
    wire GND_net, VCC_net, scl_x_c, sda_x_c, scl_c, enc1a_c, enc1b_c, 
        enc2a_c, enc2b_c, sda_out;
    wire [7:0]count1;   // c:/users/joseph martin/enccount/i2c.vhd(22[9:15])
    wire [7:0]count2;   // c:/users/joseph martin/enccount/i2c.vhd(23[9:15])
    
    wire last_sda, last_scl;
    wire [2:0]state;   // c:/users/joseph martin/enccount/i2c.vhd(62[12:17])
    wire [7:0]\reg ;   // c:/users/joseph martin/enccount/i2c.vhd(63[12:15])
    wire [2:0]bit_num;   // c:/users/joseph martin/enccount/i2c.vhd(64[12:19])
    wire [1:0]byte_num;   // c:/users/joseph martin/enccount/i2c.vhd(65[12:20])
    
    wire ack, waiting_ack, do_wait;
    wire [15:0]timeout;   // c:/users/joseph martin/enccount/i2c.vhd(69[12:19])
    
    wire n1653, n3733, n3732, n2277;
    wire [7:0]reg_7__N_60;
    
    wire n19, ack_N_121, n18, n75;
    wire [7:0]sda_out_N_96;
    
    wire n2246, n85, n3385, n3384, n5, n2257, n3380, n13, n16, 
        n3383, n84, n74, sda_out_N_93, n3411, n3642;
    wire [7:0]reg_7__N_52;
    wire [7:0]reg_7__N_4;
    wire [2:0]state_2__N_1;
    
    wire do_wait_N_137, waiting_ack_N_130, n2255, n13_adj_173, clk_enable_8, 
        n3607, clk_enable_1, n2275, n3403, n2247, n2171, n2173, 
        n2175, n2861, n15, n1322, n4, n2274, n49, n3382, n2754, 
        n2899, n67, n68, n3379, n3752, n3751, n3750, n3731, 
        n3730, n3749, n3748, n3747, n3746, n3729, n3744, n12, 
        n3386, n14, n2147, n3447, n6, n785, n3743, n83, n73, 
        n2177, n2179, n2181, n3742, n1350, n3638, n72, n71, 
        n70, n3617, n82, n81, n80, n3444, n2160, n3381, n3404, 
        n2169, n2884, n3395, n3741, n3612, n3433, n79, n78, 
        n77, n76, n2150, n3639, n18_adj_174, clk_enable_9, n1591, 
        n20, n3740, n3429, n3728, n3857, n3739, n10, n3755, 
        n3738, n3737, n3736, n3735, n3734, n3727, n3726, n3754, 
        n3753, n4_adj_175;
    
    VHI i2 (.Z(VCC_net));
    FD1S3IX state_i0 (.D(n2275), .CK(clk), .CD(state_2__N_1[2]), .Q(state[0])) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam state_i0.GSR = "ENABLED";
    CCU2D timeout_715_add_4_3 (.A0(timeout[1]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[2]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3379), .COUT(n3380), .S0(n84), .S1(n83));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_3.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_3.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_3.INJECT1_0 = "NO";
    defparam timeout_715_add_4_3.INJECT1_1 = "NO";
    GSR GSR_INST (.GSR(VCC_net));
    FD1S3AX waiting_ack_116 (.D(waiting_ack_N_130), .CK(clk), .Q(waiting_ack)) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam waiting_ack_116.GSR = "ENABLED";
    FD1S3AX do_wait_117 (.D(n2257), .CK(clk), .Q(do_wait)) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam do_wait_117.GSR = "ENABLED";
    FD1S3AX ack_118 (.D(n2255), .CK(clk), .Q(ack)) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam ack_118.GSR = "ENABLED";
    FD1S3AX sda_out_121 (.D(n2247), .CK(clk), .Q(sda_out));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam sda_out_121.GSR = "ENABLED";
    FD1P3AX reg_i0 (.D(reg_7__N_4[0]), .SP(clk_enable_1), .CK(clk), .Q(\reg [0]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i0.GSR = "ENABLED";
    FD1S3AX last_sda_125 (.D(sda_x_c), .CK(clk), .Q(last_sda));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam last_sda_125.GSR = "ENABLED";
    FD1S3AX last_scl_126 (.D(scl_x_c), .CK(clk), .Q(last_scl));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam last_scl_126.GSR = "ENABLED";
    OSCH osc (.STDBY(GND_net), .OSC(clk)) /* synthesis syn_instantiated=1 */ ;
    defparam osc.NOM_FREQ = "10.23";
    CCU2D timeout_715_add_4_17 (.A0(timeout[15]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(GND_net), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n3386), .S0(n70));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_17.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_17.INIT1 = 16'h0000;
    defparam timeout_715_add_4_17.INJECT1_0 = "NO";
    defparam timeout_715_add_4_17.INJECT1_1 = "NO";
    IB scl_pad (.I(scl), .O(scl_c));   // c:/users/joseph martin/enccount/i2c.vhd(10[5:8])
    PFUMX i1452 (.BLUT(n2274), .ALUT(n2884), .C0(n1322), .Z(n2275));
    OB sda_x_pad (.I(sda_x_c), .O(sda_x));   // c:/users/joseph martin/enccount/i2c.vhd(9[15:20])
    CCU2D timeout_715_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[0]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .COUT(n3379), .S1(n85));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_1.INIT0 = 16'hF000;
    defparam timeout_715_add_4_1.INIT1 = 16'h0555;
    defparam timeout_715_add_4_1.INJECT1_0 = "NO";
    defparam timeout_715_add_4_1.INJECT1_1 = "NO";
    FD1S3IX timeout_715__i0 (.D(n85), .CK(clk), .CD(n785), .Q(timeout[0])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i0.GSR = "ENABLED";
    OB scl_x_pad (.I(scl_x_c), .O(scl_x));   // c:/users/joseph martin/enccount/i2c.vhd(9[8:13])
    CCU2D timeout_715_add_4_15 (.A0(timeout[13]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[14]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3385), .COUT(n3386), .S0(n72), .S1(n71));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_15.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_15.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_15.INJECT1_0 = "NO";
    defparam timeout_715_add_4_15.INJECT1_1 = "NO";
    IB enc1a_pad (.I(enc1a), .O(enc1a_c));   // c:/users/joseph martin/enccount/i2c.vhd(12[5:10])
    LUT4 i1360_3_lut (.A(n2181), .B(\reg [7]), .C(n2899), .Z(sda_out_N_96[7])) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(153[7] 158[14])
    defparam i1360_3_lut.init = 16'hcaca;
    FD1S3AX byte_num_717__i0 (.D(n15), .CK(clk), .Q(byte_num[0]));   // c:/users/joseph martin/enccount/i2c.vhd(142[5] 174[12])
    defparam byte_num_717__i0.GSR = "ENABLED";
    FD1P3AX reg_i7 (.D(reg_7__N_4[7]), .SP(clk_enable_8), .CK(clk), .Q(\reg [7]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i7.GSR = "ENABLED";
    FD1P3AX reg_i6 (.D(reg_7__N_4[6]), .SP(clk_enable_8), .CK(clk), .Q(\reg [6]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i6.GSR = "ENABLED";
    FD1P3AX reg_i5 (.D(reg_7__N_4[5]), .SP(clk_enable_8), .CK(clk), .Q(\reg [5]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i5.GSR = "ENABLED";
    FD1P3AX reg_i4 (.D(reg_7__N_4[4]), .SP(clk_enable_8), .CK(clk), .Q(\reg [4]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i4.GSR = "ENABLED";
    FD1P3AX reg_i3 (.D(reg_7__N_4[3]), .SP(clk_enable_8), .CK(clk), .Q(\reg [3]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i3.GSR = "ENABLED";
    FD1P3AX reg_i2 (.D(reg_7__N_4[2]), .SP(clk_enable_8), .CK(clk), .Q(\reg [2]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i2.GSR = "ENABLED";
    FD1S3IX bit_num_716__i0 (.D(n20), .CK(clk), .CD(n1350), .Q(bit_num[0]));   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam bit_num_716__i0.GSR = "ENABLED";
    FD1P3AX reg_i1 (.D(reg_7__N_4[1]), .SP(clk_enable_8), .CK(clk), .Q(\reg [1]));   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3JX state_i2 (.D(n3857), .SP(clk_enable_9), .PD(state_2__N_1[2]), 
            .CK(clk), .Q(state[2])) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam state_i2.GSR = "ENABLED";
    BB sda_pad (.I(GND_net), .T(sda_out), .B(sda), .O(n1591));   // c:/users/joseph martin/enccount/i2c.vhd(56[2:5])
    FD1S3IX state_i1 (.D(n2277), .CK(clk), .CD(state_2__N_1[2]), .Q(state[1])) /* synthesis lse_init_val=0 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam state_i1.GSR = "ENABLED";
    PFUMX i1432 (.BLUT(n3444), .ALUT(ack_N_121), .C0(n3752), .Z(n2255));
    PFUMX i13 (.BLUT(n5), .ALUT(n3403), .C0(n3752), .Z(n1322));
    IB enc1b_pad (.I(enc1b), .O(enc1b_c));   // c:/users/joseph martin/enccount/i2c.vhd(12[12:17])
    IB enc2a_pad (.I(enc2a), .O(enc2a_c));   // c:/users/joseph martin/enccount/i2c.vhd(13[5:10])
    IB enc2b_pad (.I(enc2b), .O(enc2b_c));   // c:/users/joseph martin/enccount/i2c.vhd(13[12:17])
    LUT4 i2847_2_lut_3_lut_3_lut_4_lut (.A(state[1]), .B(n3751), .C(n2899), 
         .D(n3752), .Z(n3642)) /* synthesis lut_function=(A (C+(D))+!A ((C+(D))+!B)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i2847_2_lut_3_lut_3_lut_4_lut.init = 16'hfff1;
    LUT4 i21_4_lut_then_4_lut (.A(n68), .B(timeout[15]), .C(state[1]), 
         .D(state[2]), .Z(n3754)) /* synthesis lut_function=(!(A (C+(D))+!A (B+(C+(D))))) */ ;
    defparam i21_4_lut_then_4_lut.init = 16'h000b;
    LUT4 i21_4_lut_else_4_lut (.A(n68), .B(timeout[15]), .C(state[1]), 
         .D(state[2]), .Z(n3753)) /* synthesis lut_function=(!(A (C+!(D))+!A (B+(C+!(D))))) */ ;
    defparam i21_4_lut_else_4_lut.init = 16'h0b00;
    LUT4 i1_2_lut_3_lut_4_lut (.A(bit_num[2]), .B(n3735), .C(n2150), .D(bit_num[0]), 
         .Z(n1350)) /* synthesis lut_function=(A (B (C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i1_2_lut_3_lut_4_lut.init = 16'h8000;
    LUT4 i1_2_lut_rep_34_3_lut_4_lut (.A(state[1]), .B(n3751), .C(n68), 
         .D(timeout[15]), .Z(n3743)) /* synthesis lut_function=(A (C+!(D))+!A (B (C+!(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1_2_lut_rep_34_3_lut_4_lut.init = 16'he0ee;
    LUT4 i1467_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [3]), .D(n2173), 
         .Z(reg_7__N_4[4])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1467_3_lut_4_lut.init = 16'hf1e0;
    LUT4 i1461_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [6]), .D(n2179), 
         .Z(reg_7__N_4[7])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1461_3_lut_4_lut.init = 16'hf1e0;
    LUT4 i1469_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [2]), .D(n2171), 
         .Z(reg_7__N_4[3])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1469_3_lut_4_lut.init = 16'hf1e0;
    LUT4 i2001_2_lut_rep_42 (.A(state[0]), .B(state[2]), .Z(n3751)) /* synthesis lut_function=(A+(B)) */ ;
    defparam i2001_2_lut_rep_42.init = 16'heeee;
    LUT4 i2033_2_lut (.A(state[0]), .B(n1653), .Z(n2274)) /* synthesis lut_function=(A (B)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam i2033_2_lut.init = 16'h8888;
    LUT4 i835_4_lut (.A(n3748), .B(n13), .C(n18_adj_174), .D(n3752), 
         .Z(n1653)) /* synthesis lut_function=(!((B (C+!(D))+!B (C (D)))+!A)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i835_4_lut.init = 16'h0a22;
    LUT4 i2_3_lut (.A(scl_x_c), .B(last_sda), .C(sda_x_c), .Z(n13)) /* synthesis lut_function=(!((B+!(C))+!A)) */ ;
    defparam i2_3_lut.init = 16'h2020;
    FD1S3IX timeout_715__i1 (.D(n84), .CK(clk), .CD(n785), .Q(timeout[1])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i1.GSR = "ENABLED";
    LUT4 i1_2_lut_rep_24_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(n3750), 
         .D(ack), .Z(n3733)) /* synthesis lut_function=(A (B ((D)+!C)+!B !(C))+!A ((D)+!C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_24_3_lut_4_lut.init = 16'hdf0f;
    LUT4 i1465_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [4]), .D(n2175), 
         .Z(reg_7__N_4[5])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1465_3_lut_4_lut.init = 16'hf1e0;
    decoder_U5 dec1 (.count1({count1}), .clk(clk), .GND_net(GND_net), 
            .enc1b_c(enc1b_c), .enc1a_c(enc1a_c));   // c:/users/joseph martin/enccount/i2c.vhd(46[9:28])
    FD1S3IX timeout_715__i2 (.D(n83), .CK(clk), .CD(n785), .Q(timeout[2])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i2.GSR = "ENABLED";
    FD1S3IX timeout_715__i3 (.D(n82), .CK(clk), .CD(n785), .Q(timeout[3])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i3.GSR = "ENABLED";
    FD1S3IX timeout_715__i4 (.D(n81), .CK(clk), .CD(n785), .Q(timeout[4])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i4.GSR = "ENABLED";
    FD1S3IX timeout_715__i5 (.D(n80), .CK(clk), .CD(n785), .Q(timeout[5])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i5.GSR = "ENABLED";
    FD1S3IX timeout_715__i6 (.D(n79), .CK(clk), .CD(n785), .Q(timeout[6])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i6.GSR = "ENABLED";
    FD1S3IX timeout_715__i7 (.D(n78), .CK(clk), .CD(n785), .Q(timeout[7])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i7.GSR = "ENABLED";
    FD1S3IX timeout_715__i8 (.D(n77), .CK(clk), .CD(n785), .Q(timeout[8])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i8.GSR = "ENABLED";
    FD1S3IX timeout_715__i9 (.D(n76), .CK(clk), .CD(n785), .Q(timeout[9])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i9.GSR = "ENABLED";
    FD1S3IX timeout_715__i10 (.D(n75), .CK(clk), .CD(n785), .Q(timeout[10])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i10.GSR = "ENABLED";
    FD1S3IX timeout_715__i11 (.D(n74), .CK(clk), .CD(n785), .Q(timeout[11])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i11.GSR = "ENABLED";
    FD1S3IX timeout_715__i12 (.D(n73), .CK(clk), .CD(n785), .Q(timeout[12])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i12.GSR = "ENABLED";
    FD1S3IX timeout_715__i13 (.D(n72), .CK(clk), .CD(n785), .Q(timeout[13])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i13.GSR = "ENABLED";
    FD1S3IX timeout_715__i14 (.D(n71), .CK(clk), .CD(n785), .Q(timeout[14])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i14.GSR = "ENABLED";
    FD1S3IX timeout_715__i15 (.D(n70), .CK(clk), .CD(n785), .Q(timeout[15])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715__i15.GSR = "ENABLED";
    \filter(4)_U4  scl_filter (.clk(clk), .scl_c(scl_c), .scl_x_c(scl_x_c));   // c:/users/joseph martin/enccount/i2c.vhd(38[15:33])
    LUT4 i2_2_lut_rep_40_3_lut (.A(state[0]), .B(state[2]), .C(state[1]), 
         .Z(n3749)) /* synthesis lut_function=(A+(B+(C))) */ ;
    defparam i2_2_lut_rep_40_3_lut.init = 16'hfefe;
    LUT4 i2798_2_lut_rep_31_3_lut_4_lut (.A(state[0]), .B(state[2]), .C(n68), 
         .D(timeout[15]), .Z(n3740)) /* synthesis lut_function=(A (C+!(D))+!A (B (C+!(D)))) */ ;
    defparam i2798_2_lut_rep_31_3_lut_4_lut.init = 16'he0ee;
    LUT4 i2_3_lut_4_lut_4_lut (.A(do_wait), .B(n3748), .C(sda_x_c), .D(n3751), 
         .Z(n3404)) /* synthesis lut_function=(!((((D)+!C)+!B)+!A)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(74[4] 80[11])
    defparam i2_3_lut_4_lut_4_lut.init = 16'h0080;
    decoder dec2 (.clk(clk), .count2({count2}), .GND_net(GND_net), .enc2b_c(enc2b_c), 
            .enc2a_c(enc2a_c));   // c:/users/joseph martin/enccount/i2c.vhd(49[9:28])
    LUT4 i1463_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [5]), .D(n2177), 
         .Z(reg_7__N_4[6])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1463_3_lut_4_lut.init = 16'hf1e0;
    FD1S3AX byte_num_717__i1 (.D(n14), .CK(clk), .Q(byte_num[1]));   // c:/users/joseph martin/enccount/i2c.vhd(142[5] 174[12])
    defparam byte_num_717__i1.GSR = "ENABLED";
    FD1S3IX bit_num_716__i1 (.D(n19), .CK(clk), .CD(n1350), .Q(bit_num[1]));   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam bit_num_716__i1.GSR = "ENABLED";
    FD1S3IX bit_num_716__i2 (.D(n18), .CK(clk), .CD(n1350), .Q(bit_num[2]));   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam bit_num_716__i2.GSR = "ENABLED";
    LUT4 i1473_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [0]), .D(reg_7__N_52[0]), 
         .Z(reg_7__N_4[1])) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1473_3_lut_4_lut.init = 16'hf1e0;
    LUT4 i1936_3_lut_4_lut (.A(n2899), .B(n3752), .C(\reg [1]), .D(count1[1]), 
         .Z(n2169)) /* synthesis lut_function=(A (C)+!A (B (C)+!B (D))) */ ;
    defparam i1936_3_lut_4_lut.init = 16'hf1e0;
    CCU2D timeout_715_add_4_13 (.A0(timeout[11]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[12]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3384), .COUT(n3385), .S0(n74), .S1(n73));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_13.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_13.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_13.INJECT1_0 = "NO";
    defparam timeout_715_add_4_13.INJECT1_1 = "NO";
    PFUMX i1424 (.BLUT(n2246), .ALUT(sda_out_N_93), .C0(n3750), .Z(n2247));
    LUT4 i1_4_lut (.A(n3395), .B(n3429), .C(timeout[3]), .D(timeout[13]), 
         .Z(n68)) /* synthesis lut_function=((B+!(C (D)))+!A) */ ;
    defparam i1_4_lut.init = 16'hdfff;
    LUT4 i5_3_lut (.A(timeout[2]), .B(n10), .C(timeout[5]), .Z(n3395)) /* synthesis lut_function=(A (B (C))) */ ;
    defparam i5_3_lut.init = 16'h8080;
    LUT4 scl_x_I_0_130_2_lut_rep_43 (.A(scl_x_c), .B(last_scl), .Z(n3752)) /* synthesis lut_function=(!((B)+!A)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam scl_x_I_0_130_2_lut_rep_43.init = 16'h2222;
    CCU2D timeout_715_add_4_11 (.A0(timeout[9]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[10]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3383), .COUT(n3384), .S0(n76), .S1(n75));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_11.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_11.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_11.INJECT1_0 = "NO";
    defparam timeout_715_add_4_11.INJECT1_1 = "NO";
    LUT4 i227_2_lut_3_lut_4_lut (.A(scl_x_c), .B(last_scl), .C(n68), .D(timeout[15]), 
         .Z(n785)) /* synthesis lut_function=(!(A (B (C+!(D)))+!A (C+!(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam i227_2_lut_3_lut_4_lut.init = 16'h2f22;
    LUT4 i851_2_lut_3_lut_2_lut (.A(scl_x_c), .B(last_scl), .Z(n3750)) /* synthesis lut_function=(!(A+!(B))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam i851_2_lut_3_lut_2_lut.init = 16'h4444;
    LUT4 i1_2_lut_3_lut_4_lut_adj_16 (.A(n3750), .B(n3741), .C(n3734), 
         .D(n3744), .Z(n3612)) /* synthesis lut_function=(!((B+(C+(D)))+!A)) */ ;
    defparam i1_2_lut_3_lut_4_lut_adj_16.init = 16'h0002;
    LUT4 reg_7__I_0_i1_3_lut_4_lut (.A(scl_x_c), .B(last_scl), .C(reg_7__N_60[0]), 
         .D(reg_7__N_52[0]), .Z(reg_7__N_4[0])) /* synthesis lut_function=(A (B (D)+!B (C))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam reg_7__I_0_i1_3_lut_4_lut.init = 16'hfd20;
    LUT4 i2845_2_lut_3_lut (.A(scl_x_c), .B(last_scl), .C(sda_x_c), .Z(n2884)) /* synthesis lut_function=((B+!(C))+!A) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam i2845_2_lut_3_lut.init = 16'hdfdf;
    LUT4 i2_4_lut (.A(n3750), .B(n3638), .C(n3746), .D(n3747), .Z(n2147)) /* synthesis lut_function=(!((B+(C+!(D)))+!A)) */ ;
    defparam i2_4_lut.init = 16'h0200;
    LUT4 i2801_4_lut (.A(n3748), .B(state[0]), .C(waiting_ack), .D(ack), 
         .Z(n3638)) /* synthesis lut_function=(A (B+(C+(D)))) */ ;
    defparam i2801_4_lut.init = 16'haaa8;
    LUT4 i6_4_lut (.A(timeout[8]), .B(n12), .C(timeout[7]), .D(timeout[12]), 
         .Z(n3429)) /* synthesis lut_function=(A+(B+(C+(D)))) */ ;
    defparam i6_4_lut.init = 16'hfffe;
    LUT4 i2_3_lut_4_lut (.A(scl_x_c), .B(last_scl), .C(n3755), .D(n2147), 
         .Z(n2150)) /* synthesis lut_function=(A (B (D)+!B (C+(D)))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[7:38])
    defparam i2_3_lut_4_lut.init = 16'hff20;
    LUT4 i4_4_lut (.A(timeout[1]), .B(timeout[6]), .C(timeout[4]), .D(timeout[9]), 
         .Z(n10)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i4_4_lut.init = 16'h8000;
    LUT4 i5_4_lut (.A(timeout[14]), .B(timeout[0]), .C(timeout[10]), .D(timeout[11]), 
         .Z(n12)) /* synthesis lut_function=(A+(B+(C+(D)))) */ ;
    defparam i5_4_lut.init = 16'hfffe;
    LUT4 i1_2_lut_rep_21_3_lut_4_lut (.A(n3748), .B(n3749), .C(bit_num[2]), 
         .D(bit_num[1]), .Z(n3730)) /* synthesis lut_function=(A (B (C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1_2_lut_rep_21_3_lut_4_lut.init = 16'h8000;
    PFUMX i1434 (.BLUT(do_wait_N_137), .ALUT(n3447), .C0(n3752), .Z(n2257));
    LUT4 i1_2_lut (.A(byte_num[1]), .B(byte_num[0]), .Z(n49)) /* synthesis lut_function=(A+(B)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(65[12:20])
    defparam i1_2_lut.init = 16'heeee;
    LUT4 i1_2_lut_3_lut_4_lut_adj_17 (.A(n3748), .B(n3749), .C(count2[0]), 
         .D(n49), .Z(n67)) /* synthesis lut_function=(A (B (C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1_2_lut_3_lut_4_lut_adj_17.init = 16'h8000;
    LUT4 i2_2_lut_3_lut_4_lut (.A(n3747), .B(n3740), .C(n3750), .D(n3741), 
         .Z(n6)) /* synthesis lut_function=((B+((D)+!C))+!A) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2_2_lut_3_lut_4_lut.init = 16'hffdf;
    LUT4 i1_2_lut_rep_20_3_lut_4_lut (.A(bit_num[1]), .B(n3743), .C(bit_num[0]), 
         .D(bit_num[2]), .Z(n3729)) /* synthesis lut_function=(A (B (C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i1_2_lut_rep_20_3_lut_4_lut.init = 16'h8000;
    LUT4 i967_3_lut_4_lut (.A(state[2]), .B(n3748), .C(n1591), .D(sda_x_c), 
         .Z(reg_7__N_60[0])) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(74[4] 80[11])
    defparam i967_3_lut_4_lut.init = 16'hf780;
    LUT4 i889_3_lut_4_lut_4_lut_4_lut (.A(state[2]), .B(n3748), .C(n13_adj_173), 
         .D(state[0]), .Z(n2160)) /* synthesis lut_function=(!(A ((D)+!B)+!A ((C+!(D))+!B))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(74[4] 80[11])
    defparam i889_3_lut_4_lut_4_lut_4_lut.init = 16'h0488;
    LUT4 i2_3_lut_4_lut_4_lut_4_lut (.A(state[1]), .B(n3748), .C(do_wait), 
         .D(n3751), .Z(n3447)) /* synthesis lut_function=(A (B (C (D)))+!A (B (C))) */ ;
    defparam i2_3_lut_4_lut_4_lut_4_lut.init = 16'hc040;
    LUT4 i2009_2_lut (.A(state[2]), .B(state[1]), .Z(n2861)) /* synthesis lut_function=(A+(B)) */ ;
    defparam i2009_2_lut.init = 16'heeee;
    CCU2D timeout_715_add_4_9 (.A0(timeout[7]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[8]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3382), .COUT(n3383), .S0(n78), .S1(n77));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_9.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_9.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_9.INJECT1_0 = "NO";
    defparam timeout_715_add_4_9.INJECT1_1 = "NO";
    LUT4 i2546_4_lut_4_lut (.A(bit_num[1]), .B(n3743), .C(n3726), .D(bit_num[2]), 
         .Z(n18)) /* synthesis lut_function=(!(A ((C (D)+!C !(D))+!B)+!A !(B (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2546_4_lut_4_lut.init = 16'h4c80;
    LUT4 i2_3_lut_rep_18_4_lut (.A(bit_num[0]), .B(n3730), .C(n3752), 
         .D(n2147), .Z(n3727)) /* synthesis lut_function=(!(((C+!(D))+!B)+!A)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2_3_lut_rep_18_4_lut.init = 16'h0800;
    LUT4 i2_3_lut_4_lut_adj_18 (.A(n3744), .B(n3734), .C(n2899), .D(n3733), 
         .Z(n3617)) /* synthesis lut_function=(A+(B+(C+(D)))) */ ;
    defparam i2_3_lut_4_lut_adj_18.init = 16'hfffe;
    LUT4 i1_2_lut_rep_19_3_lut_4_lut_4_lut (.A(n3743), .B(bit_num[0]), .C(bit_num[2]), 
         .D(bit_num[1]), .Z(n3728)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i1_2_lut_rep_19_3_lut_4_lut_4_lut.init = 16'h8000;
    LUT4 i1_2_lut_rep_39 (.A(timeout[15]), .B(n68), .Z(n3748)) /* synthesis lut_function=((B)+!A) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_39.init = 16'hdddd;
    CCU2D timeout_715_add_4_7 (.A0(timeout[5]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[6]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3381), .COUT(n3382), .S0(n80), .S1(n79));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_7.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_7.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_7.INJECT1_0 = "NO";
    defparam timeout_715_add_4_7.INJECT1_1 = "NO";
    LUT4 i1990_3_lut_4_lut (.A(n3744), .B(n3734), .C(n3741), .D(sda_out_N_96[7]), 
         .Z(sda_out_N_93)) /* synthesis lut_function=(!(A (C)+!A (B (C)+!B (C+!(D))))) */ ;
    defparam i1990_3_lut_4_lut.init = 16'h0f0e;
    LUT4 i1454_4_lut (.A(state[1]), .B(n3752), .C(n1322), .D(n1653), 
         .Z(n2277)) /* synthesis lut_function=(A (B (C+(D))+!B !(C+!(D)))+!A (B (C))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(71[3] 188[10])
    defparam i1454_4_lut.init = 16'hcac0;
    LUT4 i1985_2_lut_rep_33_3_lut (.A(timeout[15]), .B(n68), .C(do_wait), 
         .Z(n3742)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1985_2_lut_rep_33_3_lut.init = 16'hd0d0;
    LUT4 i1353_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[4]), .D(count1[4]), 
         .Z(n2175)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1353_3_lut_4_lut.init = 16'hf780;
    LUT4 i1_2_lut_rep_26_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(bit_num[1]), 
         .D(n3749), .Z(n3735)) /* synthesis lut_function=(A (B (C (D)))+!A (C (D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_26_3_lut_4_lut.init = 16'hd000;
    LUT4 i2_2_lut_rep_38_3_lut (.A(timeout[15]), .B(n68), .C(state[1]), 
         .Z(n3747)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i2_2_lut_rep_38_3_lut.init = 16'hd0d0;
    LUT4 i2066_4_lut (.A(n3741), .B(n2160), .C(n3728), .D(n3747), .Z(ack_N_121)) /* synthesis lut_function=(A+!(((D)+!C)+!B)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(92[5] 140[14])
    defparam i2066_4_lut.init = 16'haaea;
    LUT4 i2_2_lut_3_lut_4_lut_adj_19 (.A(timeout[15]), .B(n68), .C(n3750), 
         .D(ack), .Z(n3444)) /* synthesis lut_function=(!(A ((C+!(D))+!B)+!A (C+!(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i2_2_lut_3_lut_4_lut_adj_19.init = 16'h0d00;
    LUT4 i4_4_lut_adj_20 (.A(n3747), .B(state[0]), .C(n3746), .D(n3752), 
         .Z(state_2__N_1[2])) /* synthesis lut_function=(!(((C+!(D))+!B)+!A)) */ ;
    defparam i4_4_lut_adj_20.init = 16'h0800;
    PFUMX i1471 (.BLUT(n2754), .ALUT(n2169), .C0(n3642), .Z(reg_7__N_4[2]));
    LUT4 i1077_4_lut (.A(n3744), .B(n3728), .C(n6), .D(n3752), .Z(waiting_ack_N_130)) /* synthesis lut_function=(A (C+(D))+!A !((C+(D))+!B)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i1077_4_lut.init = 16'haaa4;
    LUT4 i1355_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[5]), .D(count1[5]), 
         .Z(n2177)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1355_3_lut_4_lut.init = 16'hf780;
    CCU2D timeout_715_add_4_5 (.A0(timeout[3]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(timeout[4]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n3380), .COUT(n3381), .S0(n82), .S1(n81));   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam timeout_715_add_4_5.INIT0 = 16'hfaaa;
    defparam timeout_715_add_4_5.INIT1 = 16'hfaaa;
    defparam timeout_715_add_4_5.INJECT1_0 = "NO";
    defparam timeout_715_add_4_5.INJECT1_1 = "NO";
    PFUMX i34 (.BLUT(n16), .ALUT(n3404), .C0(n3747), .Z(n18_adj_174));
    LUT4 i1986_2_lut_rep_32_3_lut (.A(timeout[15]), .B(n68), .C(ack), 
         .Z(n3741)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1986_2_lut_rep_32_3_lut.init = 16'hd0d0;
    LUT4 i1_2_lut_rep_29_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(byte_num[0]), 
         .D(n3749), .Z(n3738)) /* synthesis lut_function=(A (B (C (D)))+!A (C (D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_29_3_lut_4_lut.init = 16'hd000;
    LUT4 i3_4_lut (.A(\reg [5]), .B(\reg [4]), .C(\reg [6]), .D(n3639), 
         .Z(n13_adj_173)) /* synthesis lut_function=(A+(B+(C+!(D)))) */ ;
    defparam i3_4_lut.init = 16'hfeff;
    LUT4 i2802_4_lut (.A(\reg [0]), .B(\reg [3]), .C(\reg [1]), .D(\reg [2]), 
         .Z(n3639)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i2802_4_lut.init = 16'h8000;
    LUT4 i1351_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[3]), .D(count1[3]), 
         .Z(n2173)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1351_3_lut_4_lut.init = 16'hf780;
    LUT4 i2_3_lut_adj_21 (.A(sda_x_c), .B(last_sda), .C(scl_x_c), .Z(n5)) /* synthesis lut_function=(!(A+!(B (C)))) */ ;
    defparam i2_3_lut_adj_21.init = 16'h4040;
    LUT4 i2042_4_lut (.A(n3742), .B(n3731), .C(n3744), .D(n3732), .Z(do_wait_N_137)) /* synthesis lut_function=(A+(B (C (D)))) */ ;
    defparam i2042_4_lut.init = 16'heaaa;
    LUT4 i1_2_lut_3_lut (.A(timeout[15]), .B(n68), .C(count2[1]), .Z(n4_adj_175)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_3_lut.init = 16'hd0d0;
    LUT4 i1_2_lut_rep_22_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(n3750), 
         .D(ack), .Z(n3731)) /* synthesis lut_function=(!(A (B ((D)+!C)+!B !(C))+!A ((D)+!C))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_22_3_lut_4_lut.init = 16'h20f0;
    \filter(4)_U3  sda_filter (.clk(clk), .n1591(n1591), .sda_x_c(sda_x_c));   // c:/users/joseph martin/enccount/i2c.vhd(42[15:33])
    LUT4 i2_4_lut_adj_22 (.A(n3737), .B(n3748), .C(n3728), .D(n2861), 
         .Z(n3403)) /* synthesis lut_function=(!((B ((D)+!C)+!B !(C))+!A)) */ ;
    defparam i2_4_lut_adj_22.init = 16'h20a0;
    PFUMX i24 (.BLUT(n3612), .ALUT(n3607), .C0(n3752), .Z(clk_enable_8));
    LUT4 i2539_2_lut_3_lut_4_lut_4_lut_4_lut (.A(bit_num[2]), .B(n3735), 
         .C(n2150), .D(n3736), .Z(n19)) /* synthesis lut_function=(A (B+(C (D)))+!A !(B (C (D))+!B !(C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2539_2_lut_3_lut_4_lut_4_lut_4_lut.init = 16'hbccc;
    LUT4 i1_2_lut_rep_27_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(bit_num[0]), 
         .D(n3749), .Z(n3736)) /* synthesis lut_function=(A (B (C (D)))+!A (C (D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_27_3_lut_4_lut.init = 16'hd000;
    PFUMX i1948 (.BLUT(n67), .ALUT(n3433), .C0(count1[0]), .Z(reg_7__N_52[0]));
    LUT4 i1984_2_lut_rep_35_3_lut (.A(timeout[15]), .B(n68), .C(waiting_ack), 
         .Z(n3744)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1984_2_lut_rep_35_3_lut.init = 16'hd0d0;
    LUT4 i1357_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[6]), .D(count1[6]), 
         .Z(n2179)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1357_3_lut_4_lut.init = 16'hf780;
    LUT4 i1349_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[2]), .D(count1[2]), 
         .Z(n2171)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1349_3_lut_4_lut.init = 16'hf780;
    LUT4 i2531_2_lut_3_lut_3_lut_4_lut (.A(bit_num[2]), .B(n3735), .C(n2150), 
         .D(n3736), .Z(n20)) /* synthesis lut_function=(A (B (C+(D))+!B !(C (D)+!C !(D)))+!A !(C (D)+!C !(D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2531_2_lut_3_lut_3_lut_4_lut.init = 16'h8ff0;
    LUT4 i2069_2_lut_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(sda_out), 
         .D(n3749), .Z(n2246)) /* synthesis lut_function=(A ((C+!(D))+!B)+!A (C+!(D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i2069_2_lut_3_lut_4_lut.init = 16'hf2ff;
    LUT4 i1359_3_lut_4_lut (.A(n49), .B(n3743), .C(count2[7]), .D(count1[7]), 
         .Z(n2181)) /* synthesis lut_function=(A (B (C)+!B (D))+!A (D)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i1359_3_lut_4_lut.init = 16'hf780;
    LUT4 i2811_4_lut (.A(n49), .B(n3411), .C(count1[1]), .D(n4_adj_175), 
         .Z(n2754)) /* synthesis lut_function=(A (B (C+(D))+!B !(C+!(D)))+!A (B (C))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2811_4_lut.init = 16'hcac0;
    LUT4 i2533_2_lut_rep_17_3_lut_3_lut_4_lut (.A(bit_num[2]), .B(n3735), 
         .C(n2150), .D(n3736), .Z(n3726)) /* synthesis lut_function=(!(A (B+!(C (D)))+!A !(C (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(89[4] 185[11])
    defparam i2533_2_lut_rep_17_3_lut_3_lut_4_lut.init = 16'h7000;
    LUT4 i2517_2_lut_4_lut (.A(n2147), .B(n3752), .C(n3729), .D(n3738), 
         .Z(n15)) /* synthesis lut_function=(A (B (D)+!B !(C (D)+!C !(D)))+!A (D)) */ ;
    defparam i2517_2_lut_4_lut.init = 16'hdf20;
    LUT4 i2_4_lut_adj_23 (.A(timeout[15]), .B(count2[1]), .C(n68), .D(n49), 
         .Z(n3411)) /* synthesis lut_function=(A (B+!(C (D)))+!A (B+!(D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(65[12:20])
    defparam i2_4_lut_adj_23.init = 16'hceff;
    LUT4 i1_4_lut_adj_24 (.A(n3728), .B(n4), .C(state[0]), .D(n3746), 
         .Z(n16)) /* synthesis lut_function=(!((B (C (D))+!B (C+!(D)))+!A)) */ ;
    defparam i1_4_lut_adj_24.init = 16'h0a88;
    LUT4 i2525_4_lut_4_lut (.A(byte_num[0]), .B(n3743), .C(n3727), .D(byte_num[1]), 
         .Z(n14)) /* synthesis lut_function=(!(A ((C (D)+!C !(D))+!B)+!A !(B (D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(82[7:19])
    defparam i2525_4_lut_4_lut.init = 16'h4c80;
    LUT4 i43_4_lut (.A(n3617), .B(n3747), .C(n3752), .D(n3739), .Z(clk_enable_1)) /* synthesis lut_function=(!(A (B+!(C (D)))+!A (B (C)+!B !((D)+!C)))) */ ;
    defparam i43_4_lut.init = 16'h3505;
    LUT4 i1_2_lut_3_lut_4_lut_adj_25 (.A(timeout[15]), .B(n68), .C(n13_adj_173), 
         .D(state[0]), .Z(n4)) /* synthesis lut_function=(A (B (C (D)))+!A (C (D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_3_lut_4_lut_adj_25.init = 16'hd000;
    LUT4 i1_2_lut_rep_28_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(n13_adj_173), 
         .D(state[0]), .Z(n3737)) /* synthesis lut_function=(!(A ((C+!(D))+!B)+!A (C+!(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_28_3_lut_4_lut.init = 16'h0d00;
    LUT4 i2_2_lut_rep_25_3_lut_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(n3751), 
         .D(state[1]), .Z(n3734)) /* synthesis lut_function=(A ((C+!(D))+!B)+!A (C+!(D))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i2_2_lut_rep_25_3_lut_3_lut_4_lut.init = 16'hf2ff;
    LUT4 i1_2_lut_rep_23_3_lut_3_lut_4_lut (.A(timeout[15]), .B(n68), .C(n3751), 
         .D(state[1]), .Z(n3732)) /* synthesis lut_function=(!(A ((C+!(D))+!B)+!A (C+!(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_2_lut_rep_23_3_lut_3_lut_4_lut.init = 16'h0d00;
    LUT4 i2019_2_lut_rep_37_3_lut (.A(timeout[15]), .B(n68), .C(state[2]), 
         .Z(n3746)) /* synthesis lut_function=(A (B (C))+!A (C)) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i2019_2_lut_rep_37_3_lut.init = 16'hd0d0;
    PUR PUR_INST (.PUR(VCC_net));
    defparam PUR_INST.RST_PULSE = 1;
    LUT4 i3_4_lut_adj_26 (.A(count2[0]), .B(n3748), .C(n3749), .D(n49), 
         .Z(n3433)) /* synthesis lut_function=(A+!(B (C (D)))) */ ;
    defparam i3_4_lut_adj_26.init = 16'hbfff;
    LUT4 i1_2_lut_4_lut (.A(n3748), .B(state[2]), .C(state[0]), .D(state[1]), 
         .Z(n3607)) /* synthesis lut_function=(!((B (C+(D))+!B ((D)+!C))+!A)) */ ;
    defparam i1_2_lut_4_lut.init = 16'h0028;
    LUT4 i2099_4_lut (.A(n3743), .B(bit_num[1]), .C(bit_num[0]), .D(bit_num[2]), 
         .Z(n2899)) /* synthesis lut_function=(A (B+(C+(D)))) */ ;
    defparam i2099_4_lut.init = 16'haaa8;
    LUT4 i2839_2_lut_2_lut (.A(n1653), .B(n1322), .Z(clk_enable_9)) /* synthesis lut_function=((B)+!A) */ ;
    defparam i2839_2_lut_2_lut.init = 16'hdddd;
    LUT4 i1_3_lut_rep_30_4_lut (.A(timeout[15]), .B(n68), .C(state[0]), 
         .D(state[2]), .Z(n3739)) /* synthesis lut_function=(!(A ((C (D)+!C !(D))+!B)+!A (C (D)+!C !(D)))) */ ;   // c:/users/joseph martin/enccount/i2c.vhd(72[15:22])
    defparam i1_3_lut_rep_30_4_lut.init = 16'h0dd0;
    VLO i1 (.Z(GND_net));
    TSALL TSALL_INST (.TSALL(GND_net));
    PFUMX i2860 (.BLUT(n3753), .ALUT(n3754), .C0(state[0]), .Z(n3755));
    LUT4 m0_lut (.Z(n3857)) /* synthesis lut_function=0, syn_instantiated=1 */ ;
    defparam m0_lut.init = 16'h0000;
    
endmodule
//
// Verilog Description of module decoder_U5
//

module decoder_U5 (count1, clk, GND_net, enc1b_c, enc1a_c);
    output [7:0]count1;
    input clk;
    input GND_net;
    input enc1b_c;
    input enc1a_c;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [7:0]n37;
    wire [1:0]last;   // c:/users/joseph martin/enccount/decoder.vhd(25[12:16])
    
    wire B_in, n3375, n1329, n1144, n3376, A_in, n3378, n3377;
    
    FD1S3AX c_i7_719__i0 (.D(n37[0]), .CK(clk), .Q(count1[0])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i0.GSR = "ENABLED";
    FD1S3AX last_i0 (.D(B_in), .CK(clk), .Q(last[0])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=9, LSE_RCOL=28, LSE_LLINE=46, LSE_RLINE=46 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(27[3] 34[10])
    defparam last_i0.GSR = "ENABLED";
    CCU2D c_i7_719_add_4_3 (.A0(n1329), .B0(n1144), .C0(count1[1]), .D0(GND_net), 
          .A1(n1329), .B1(n1144), .C1(count1[2]), .D1(GND_net), .CIN(n3375), 
          .COUT(n3376), .S0(n37[1]), .S1(n37[2]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719_add_4_3.INIT0 = 16'he1e1;
    defparam c_i7_719_add_4_3.INIT1 = 16'he1e1;
    defparam c_i7_719_add_4_3.INJECT1_0 = "NO";
    defparam c_i7_719_add_4_3.INJECT1_1 = "NO";
    FD1S3AX last_i1 (.D(A_in), .CK(clk), .Q(last[1])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=9, LSE_RCOL=28, LSE_LLINE=46, LSE_RLINE=46 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(27[3] 34[10])
    defparam last_i1.GSR = "ENABLED";
    CCU2D c_i7_719_add_4_9 (.A0(n1329), .B0(n1144), .C0(count1[7]), .D0(GND_net), 
          .A1(GND_net), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n3378), 
          .S0(n37[7]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719_add_4_9.INIT0 = 16'he1e1;
    defparam c_i7_719_add_4_9.INIT1 = 16'h0000;
    defparam c_i7_719_add_4_9.INJECT1_0 = "NO";
    defparam c_i7_719_add_4_9.INJECT1_1 = "NO";
    FD1S3AX c_i7_719__i7 (.D(n37[7]), .CK(clk), .Q(count1[7])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i7.GSR = "ENABLED";
    FD1S3AX c_i7_719__i6 (.D(n37[6]), .CK(clk), .Q(count1[6])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i6.GSR = "ENABLED";
    FD1S3AX c_i7_719__i5 (.D(n37[5]), .CK(clk), .Q(count1[5])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i5.GSR = "ENABLED";
    FD1S3AX c_i7_719__i4 (.D(n37[4]), .CK(clk), .Q(count1[4])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i4.GSR = "ENABLED";
    FD1S3AX c_i7_719__i3 (.D(n37[3]), .CK(clk), .Q(count1[3])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i3.GSR = "ENABLED";
    FD1S3AX c_i7_719__i2 (.D(n37[2]), .CK(clk), .Q(count1[2])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i2.GSR = "ENABLED";
    FD1S3AX c_i7_719__i1 (.D(n37[1]), .CK(clk), .Q(count1[1])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719__i1.GSR = "ENABLED";
    CCU2D c_i7_719_add_4_7 (.A0(n1329), .B0(n1144), .C0(count1[5]), .D0(GND_net), 
          .A1(n1329), .B1(n1144), .C1(count1[6]), .D1(GND_net), .CIN(n3377), 
          .COUT(n3378), .S0(n37[5]), .S1(n37[6]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719_add_4_7.INIT0 = 16'he1e1;
    defparam c_i7_719_add_4_7.INIT1 = 16'he1e1;
    defparam c_i7_719_add_4_7.INJECT1_0 = "NO";
    defparam c_i7_719_add_4_7.INJECT1_1 = "NO";
    LUT4 i21_4_lut_3_lut_4_lut (.A(B_in), .B(A_in), .C(last[1]), .D(last[0]), 
         .Z(n1144)) /* synthesis lut_function=(A (B (C (D)+!C !(D))+!B !(C (D)+!C !(D)))+!A !(B (C (D)+!C !(D))+!B !(C (D)+!C !(D)))) */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam i21_4_lut_3_lut_4_lut.init = 16'h9669;
    LUT4 last_0__bdd_4_lut (.A(last[0]), .B(last[1]), .C(B_in), .D(A_in), 
         .Z(n1329)) /* synthesis lut_function=(!(A (B ((D)+!C)+!B (C+(D)))+!A !(B (C (D))+!B !(C+!(D))))) */ ;
    defparam last_0__bdd_4_lut.init = 16'h4182;
    CCU2D c_i7_719_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(n1144), .B1(count1[0]), .C1(GND_net), .D1(GND_net), 
          .COUT(n3375), .S1(n37[0]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719_add_4_1.INIT0 = 16'hF000;
    defparam c_i7_719_add_4_1.INIT1 = 16'ha999;
    defparam c_i7_719_add_4_1.INJECT1_0 = "NO";
    defparam c_i7_719_add_4_1.INJECT1_1 = "NO";
    CCU2D c_i7_719_add_4_5 (.A0(n1329), .B0(n1144), .C0(count1[3]), .D0(GND_net), 
          .A1(n1329), .B1(n1144), .C1(count1[4]), .D1(GND_net), .CIN(n3376), 
          .COUT(n3377), .S0(n37[3]), .S1(n37[4]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_719_add_4_5.INIT0 = 16'he1e1;
    defparam c_i7_719_add_4_5.INIT1 = 16'he1e1;
    defparam c_i7_719_add_4_5.INJECT1_0 = "NO";
    defparam c_i7_719_add_4_5.INJECT1_1 = "NO";
    \filter(4)_U1  B_filter (.clk(clk), .enc1b_c(enc1b_c), .B_in(B_in));   // c:/users/joseph martin/enccount/decoder.vhd(19[13:31])
    \filter(4)_U2  A_filter (.clk(clk), .enc1a_c(enc1a_c), .A_in(A_in));   // c:/users/joseph martin/enccount/decoder.vhd(14[13:31])
    
endmodule
//
// Verilog Description of module \filter(4)_U1 
//

module \filter(4)_U1  (clk, enc1b_c, B_in);
    input clk;
    input enc1b_c;
    output B_in;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i1 (.D(enc1b_c), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(enc1b_c), .SP(output_N_144), .CK(clk), .Q(B_in));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    LUT4 i2831_4_lut (.A(enc1b_c), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2831_4_lut.init = 16'h8001;
    
endmodule
//
// Verilog Description of module \filter(4)_U2 
//

module \filter(4)_U2  (clk, enc1a_c, A_in);
    input clk;
    input enc1a_c;
    output A_in;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    FD1S3AX reg_i1 (.D(enc1a_c), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(enc1a_c), .SP(output_N_144), .CK(clk), .Q(A_in));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    LUT4 i2834_4_lut (.A(enc1a_c), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2834_4_lut.init = 16'h8001;
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    
endmodule
//
// Verilog Description of module \filter(4)_U4 
//

module \filter(4)_U4  (clk, scl_c, scl_x_c);
    input clk;
    input scl_c;
    output scl_x_c;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i1 (.D(scl_c), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=38, LSE_RLINE=38 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(scl_c), .SP(output_N_144), .CK(clk), .Q(scl_x_c));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=38, LSE_RLINE=38 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=38, LSE_RLINE=38 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    LUT4 i2842_4_lut (.A(scl_c), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2842_4_lut.init = 16'h8001;
    
endmodule
//
// Verilog Description of module decoder
//

module decoder (clk, count2, GND_net, enc2b_c, enc2a_c);
    input clk;
    output [7:0]count2;
    input GND_net;
    input enc2b_c;
    input enc2a_c;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [1:0]last;   // c:/users/joseph martin/enccount/decoder.vhd(25[12:16])
    
    wire B_in, A_in, n3371;
    wire [7:0]n1540;
    wire [7:0]n37;
    
    wire n3372, n1593, n1747, n3373, n3374;
    
    FD1S3AX last_i0 (.D(B_in), .CK(clk), .Q(last[0])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=9, LSE_RCOL=28, LSE_LLINE=49, LSE_RLINE=49 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(27[3] 34[10])
    defparam last_i0.GSR = "ENABLED";
    FD1S3AX last_i1 (.D(A_in), .CK(clk), .Q(last[1])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=9, LSE_RCOL=28, LSE_LLINE=49, LSE_RLINE=49 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(27[3] 34[10])
    defparam last_i1.GSR = "ENABLED";
    CCU2D c_i7_718_add_4_3 (.A0(n1540[5]), .B0(count2[1]), .C0(GND_net), 
          .D0(GND_net), .A1(n1540[5]), .B1(count2[2]), .C1(GND_net), 
          .D1(GND_net), .CIN(n3371), .COUT(n3372), .S0(n37[1]), .S1(n37[2]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718_add_4_3.INIT0 = 16'h5666;
    defparam c_i7_718_add_4_3.INIT1 = 16'h5666;
    defparam c_i7_718_add_4_3.INJECT1_0 = "NO";
    defparam c_i7_718_add_4_3.INJECT1_1 = "NO";
    CCU2D c_i7_718_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(n1593), .B1(n1747), .C1(count2[0]), .D1(GND_net), 
          .COUT(n3371), .S1(n37[0]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718_add_4_1.INIT0 = 16'hF000;
    defparam c_i7_718_add_4_1.INIT1 = 16'h9696;
    defparam c_i7_718_add_4_1.INJECT1_0 = "NO";
    defparam c_i7_718_add_4_1.INJECT1_1 = "NO";
    FD1S3AX c_i7_718__i0 (.D(n37[0]), .CK(clk), .Q(count2[0])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i0.GSR = "ENABLED";
    LUT4 i1_4_lut (.A(B_in), .B(last[1]), .C(last[0]), .D(A_in), .Z(n1540[5])) /* synthesis lut_function=(!(A (B+!(C (D)+!C !(D)))+!A !(B (C (D)+!C !(D))))) */ ;
    defparam i1_4_lut.init = 16'h6006;
    FD1S3AX c_i7_718__i1 (.D(n37[1]), .CK(clk), .Q(count2[1])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i1.GSR = "ENABLED";
    LUT4 i10_2_lut (.A(B_in), .B(A_in), .Z(n1593)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;   // c:/users/joseph martin/enccount/decoder.vhd(11[9:13])
    defparam i10_2_lut.init = 16'h6666;
    LUT4 i9_2_lut (.A(last[1]), .B(last[0]), .Z(n1747)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;   // c:/users/joseph martin/enccount/decoder.vhd(25[12:16])
    defparam i9_2_lut.init = 16'h6666;
    FD1S3AX c_i7_718__i2 (.D(n37[2]), .CK(clk), .Q(count2[2])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i2.GSR = "ENABLED";
    FD1S3AX c_i7_718__i3 (.D(n37[3]), .CK(clk), .Q(count2[3])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i3.GSR = "ENABLED";
    FD1S3AX c_i7_718__i4 (.D(n37[4]), .CK(clk), .Q(count2[4])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i4.GSR = "ENABLED";
    FD1S3AX c_i7_718__i5 (.D(n37[5]), .CK(clk), .Q(count2[5])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i5.GSR = "ENABLED";
    FD1S3AX c_i7_718__i6 (.D(n37[6]), .CK(clk), .Q(count2[6])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i6.GSR = "ENABLED";
    FD1S3AX c_i7_718__i7 (.D(n37[7]), .CK(clk), .Q(count2[7])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718__i7.GSR = "ENABLED";
    CCU2D c_i7_718_add_4_5 (.A0(n1540[5]), .B0(count2[3]), .C0(GND_net), 
          .D0(GND_net), .A1(n1540[5]), .B1(count2[4]), .C1(GND_net), 
          .D1(GND_net), .CIN(n3372), .COUT(n3373), .S0(n37[3]), .S1(n37[4]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718_add_4_5.INIT0 = 16'h5666;
    defparam c_i7_718_add_4_5.INIT1 = 16'h5666;
    defparam c_i7_718_add_4_5.INJECT1_0 = "NO";
    defparam c_i7_718_add_4_5.INJECT1_1 = "NO";
    CCU2D c_i7_718_add_4_7 (.A0(n1540[5]), .B0(count2[5]), .C0(GND_net), 
          .D0(GND_net), .A1(n1540[5]), .B1(count2[6]), .C1(GND_net), 
          .D1(GND_net), .CIN(n3373), .COUT(n3374), .S0(n37[5]), .S1(n37[6]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718_add_4_7.INIT0 = 16'h5666;
    defparam c_i7_718_add_4_7.INIT1 = 16'h5666;
    defparam c_i7_718_add_4_7.INJECT1_0 = "NO";
    defparam c_i7_718_add_4_7.INJECT1_1 = "NO";
    CCU2D c_i7_718_add_4_9 (.A0(n1540[5]), .B0(count2[7]), .C0(GND_net), 
          .D0(GND_net), .A1(GND_net), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n3374), .S0(n37[7]));   // c:/users/joseph martin/enccount/decoder.vhd(28[4] 32[13])
    defparam c_i7_718_add_4_9.INIT0 = 16'h5666;
    defparam c_i7_718_add_4_9.INIT1 = 16'h0000;
    defparam c_i7_718_add_4_9.INJECT1_0 = "NO";
    defparam c_i7_718_add_4_9.INJECT1_1 = "NO";
    \filter(4)  B_filter (.clk(clk), .enc2b_c(enc2b_c), .B_in(B_in));   // c:/users/joseph martin/enccount/decoder.vhd(19[13:31])
    \filter(4)_U0  A_filter (.clk(clk), .enc2a_c(enc2a_c), .A_in(A_in));   // c:/users/joseph martin/enccount/decoder.vhd(14[13:31])
    
endmodule
//
// Verilog Description of module \filter(4) 
//

module \filter(4)  (clk, enc2b_c, B_in);
    input clk;
    input enc2b_c;
    output B_in;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i1 (.D(enc2b_c), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(enc2b_c), .SP(output_N_144), .CK(clk), .Q(B_in));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=19, LSE_RLINE=19 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    LUT4 i2825_4_lut (.A(enc2b_c), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2825_4_lut.init = 16'h8001;
    
endmodule
//
// Verilog Description of module \filter(4)_U0 
//

module \filter(4)_U0  (clk, enc2a_c, A_in);
    input clk;
    input enc2a_c;
    output A_in;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i1 (.D(enc2a_c), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(enc2a_c), .SP(output_N_144), .CK(clk), .Q(A_in));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    LUT4 i2828_4_lut (.A(enc2a_c), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2828_4_lut.init = 16'h8001;
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=38, LSE_LCOL=13, LSE_RCOL=31, LSE_LLINE=14, LSE_RLINE=14 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    
endmodule
//
// Verilog Description of module \filter(4)_U3 
//

module \filter(4)_U3  (clk, n1591, sda_x_c);
    input clk;
    input n1591;
    output sda_x_c;
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/i2c.vhd(25[9:12])
    wire [3:0]\reg ;   // c:/users/joseph martin/enccount/filter.vhd(14[12:15])
    
    wire output_N_144;
    
    FD1S3AX reg_i1 (.D(n1591), .CK(clk), .Q(\reg [0])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=42, LSE_RLINE=42 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i1.GSR = "ENABLED";
    FD1P3AX output_16 (.D(n1591), .SP(output_N_144), .CK(clk), .Q(sda_x_c));   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam output_16.GSR = "ENABLED";
    FD1S3AX reg_i3 (.D(\reg [1]), .CK(clk), .Q(\reg [2])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=42, LSE_RLINE=42 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i3.GSR = "ENABLED";
    FD1S3AX reg_i2 (.D(\reg [0]), .CK(clk), .Q(\reg [1])) /* synthesis LSE_LINE_FILE_ID=37, LSE_LCOL=15, LSE_RCOL=33, LSE_LLINE=42, LSE_RLINE=42 */ ;   // c:/users/joseph martin/enccount/filter.vhd(17[3] 29[10])
    defparam reg_i2.GSR = "ENABLED";
    LUT4 i2837_4_lut (.A(n1591), .B(\reg [1]), .C(\reg [2]), .D(\reg [0]), 
         .Z(output_N_144)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;
    defparam i2837_4_lut.init = 16'h8001;
    
endmodule
//
// Verilog Description of module PUR
// module not written out since it is a black-box. 
//

//
// Verilog Description of module TSALL
// module not written out since it is a black-box. 
//

