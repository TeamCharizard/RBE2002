// Verilog netlist produced by program LSE :  version Diamond (64-bit) 3.5.0.102
// Netlist written on Thu Oct 29 16:25:58 2015
//
// Verilog Description of module test
//

module test (sda, scl, led);   // c:/users/joseph martin/enccount/test.vhd(4[8:12])
    input sda /* synthesis .original_dir=IN_OUT */ ;   // c:/users/joseph martin/enccount/test.vhd(5[7:10])
    input scl /* synthesis .original_dir=IN_OUT */ ;   // c:/users/joseph martin/enccount/test.vhd(5[12:15])
    output led;   // c:/users/joseph martin/enccount/test.vhd(5[35:38])
    
    wire osclk /* synthesis SET_AS_NETWORK=osclk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(9[9:14])
    
    wire GND_net, VCC_net, sda_c, scl_c, clk;
    wire [13:0]c;   // c:/users/joseph martin/enccount/test.vhd(26[12:13])
    
    wire osclk_enable_9, n329, c_13__N_29, led_c, clk_N_59;
    wire [1:0]state;   // c:/users/joseph martin/enccount/test.vhd(41[12:17])
    wire [2:0]bit_num;   // c:/users/joseph martin/enccount/test.vhd(43[12:19])
    wire [7:0]\reg ;   // c:/users/joseph martin/enccount/test.vhd(45[12:15])
    
    wire n507, n66, n67, n715, osclk_enable_14, n268, n714, n721;
    wire [1:0]state_1__N_30;
    
    wire n767, n214, n217, n14, n719, n713, n718, n10, n62, 
        n63, n64, n65, n66_adj_1, n67_adj_2, n68, n69, n70, 
        n71, n72, n73, n74, n75, n12, n717, n716, n712, n10_adj_3, 
        osclk_enable_7, n65_adj_4, n737, n1, n798, osclk_enable_15, 
        n68_adj_5;
    
    VHI i2 (.Z(VCC_net));
    FD1P3IX reg_i0_i4 (.D(\reg [3]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [4]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i4.GSR = "ENABLED";
    FD1P3AX state_i0_i0 (.D(state_1__N_30[0]), .SP(osclk_enable_9), .CK(osclk), 
            .Q(state[0]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam state_i0_i0.GSR = "ENABLED";
    LUT4 i1_4_lut (.A(n217), .B(n737), .C(n10_adj_3), .D(n767), .Z(state_1__N_30[1])) /* synthesis lut_function=(!(A+(((D)+!C)+!B))) */ ;   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam i1_4_lut.init = 16'h0040;
    IB sda_pad (.I(sda), .O(sda_c));   // c:/users/joseph martin/enccount/test.vhd(5[7:10])
    OB led_pad (.I(led_c), .O(led));   // c:/users/joseph martin/enccount/test.vhd(5[35:38])
    LUT4 i2_4_lut (.A(n65_adj_4), .B(n68_adj_5), .C(\reg [3]), .D(\reg [5]), 
         .Z(n737)) /* synthesis lut_function=(!(((C+(D))+!B)+!A)) */ ;   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam i2_4_lut.init = 16'h0008;
    LUT4 i609_3_lut (.A(\reg [4]), .B(\reg [6]), .C(\reg [2]), .Z(n767)) /* synthesis lut_function=(A+(B+(C))) */ ;
    defparam i609_3_lut.init = 16'hfefe;
    FD1P3AX last_scl_56 (.D(scl_c), .SP(osclk_enable_7), .CK(osclk), .Q(n217));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam last_scl_56.GSR = "ENABLED";
    OSCH osc (.STDBY(GND_net), .OSC(osclk)) /* synthesis syn_instantiated=1 */ ;
    defparam osc.NOM_FREQ = "2.08";
    FD1P3AX last_sda_55 (.D(sda_c), .SP(osclk_enable_7), .CK(osclk), .Q(n214));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam last_sda_55.GSR = "ENABLED";
    LUT4 i4_4_lut (.A(scl_c), .B(bit_num[0]), .C(\reg [0]), .D(\reg [1]), 
         .Z(n10_adj_3)) /* synthesis lut_function=(!((B+!(C (D)))+!A)) */ ;   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam i4_4_lut.init = 16'h2000;
    FD1P3IX reg_i0_i5 (.D(\reg [4]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [5]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i5.GSR = "ENABLED";
    FD1P3AX led_51 (.D(\reg [0]), .SP(osclk_enable_7), .CK(osclk), .Q(led_c));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam led_51.GSR = "ENABLED";
    FD1P3IX bit_num__i0 (.D(n268), .SP(osclk_enable_7), .CD(n329), .CK(osclk), 
            .Q(bit_num[0]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam bit_num__i0.GSR = "ENABLED";
    FD1P3IX reg_i0_i6 (.D(\reg [5]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [6]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i6.GSR = "ENABLED";
    GSR GSR_INST (.GSR(VCC_net));
    LUT4 i611_2_lut (.A(c_13__N_29), .B(clk), .Z(clk_N_59)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;
    defparam i611_2_lut.init = 16'h6666;
    LUT4 i20_2_lut (.A(bit_num[1]), .B(bit_num[0]), .Z(n67)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;   // c:/users/joseph martin/enccount/test.vhd(43[12:19])
    defparam i20_2_lut.init = 16'h6666;
    CCU2D c_176_add_4_15 (.A0(c[13]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(GND_net), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n718), 
          .S0(n62));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_15.INIT0 = 16'hfaaa;
    defparam c_176_add_4_15.INIT1 = 16'h0000;
    defparam c_176_add_4_15.INJECT1_0 = "NO";
    defparam c_176_add_4_15.INJECT1_1 = "NO";
    FD1S3IX c_176__i0 (.D(n75), .CK(osclk), .CD(c_13__N_29), .Q(c[0])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i0.GSR = "ENABLED";
    FD1P3AX state_i0_i1 (.D(state_1__N_30[1]), .SP(osclk_enable_9), .CK(osclk), 
            .Q(state[1]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam state_i0_i1.GSR = "ENABLED";
    LUT4 i531_3_lut (.A(bit_num[2]), .B(bit_num[1]), .C(bit_num[0]), .Z(n66)) /* synthesis lut_function=(!(A (B (C))+!A !(B (C)))) */ ;   // c:/users/joseph martin/enccount/test.vhd(43[12:19])
    defparam i531_3_lut.init = 16'h6a6a;
    FD1S3AX clk_50 (.D(clk_N_59), .CK(osclk), .Q(clk));   // c:/users/joseph martin/enccount/test.vhd(28[3] 34[10])
    defparam clk_50.GSR = "ENABLED";
    LUT4 i1_2_lut_rep_4_3_lut_4_lut (.A(clk), .B(c_13__N_29), .C(n217), 
         .D(scl_c), .Z(osclk_enable_15)) /* synthesis lut_function=(!(A+((C+!(D))+!B))) */ ;
    defparam i1_2_lut_rep_4_3_lut_4_lut.init = 16'h0400;
    FD1P3IX reg_i0_i0 (.D(sda_c), .SP(osclk_enable_15), .CD(n507), .CK(osclk), 
            .Q(\reg [0]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i0.GSR = "ENABLED";
    LUT4 i622_4_lut (.A(c[6]), .B(n12), .C(c[5]), .D(c[7]), .Z(c_13__N_29)) /* synthesis lut_function=(!(A+(B+(C+(D))))) */ ;
    defparam i622_4_lut.init = 16'h0001;
    LUT4 i5_4_lut (.A(c[4]), .B(n721), .C(c[11]), .D(c[12]), .Z(n12)) /* synthesis lut_function=(A+((C+(D))+!B)) */ ;
    defparam i5_4_lut.init = 16'hfffb;
    TSALL TSALL_INST (.TSALL(GND_net));
    FD1P3IX bit_num__i1 (.D(n67), .SP(osclk_enable_14), .CD(n329), .CK(osclk), 
            .Q(bit_num[1]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam bit_num__i1.GSR = "ENABLED";
    IB scl_pad (.I(scl), .O(scl_c));   // c:/users/joseph martin/enccount/test.vhd(5[12:15])
    CCU2D c_176_add_4_13 (.A0(c[11]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[12]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n717), 
          .COUT(n718), .S0(n64), .S1(n63));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_13.INIT0 = 16'hfaaa;
    defparam c_176_add_4_13.INIT1 = 16'hfaaa;
    defparam c_176_add_4_13.INJECT1_0 = "NO";
    defparam c_176_add_4_13.INJECT1_1 = "NO";
    FD1P3IX reg_i0_i1 (.D(\reg [0]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [1]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i1.GSR = "ENABLED";
    FD1P3IX reg_i0_i2 (.D(\reg [1]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [2]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i2.GSR = "ENABLED";
    FD1P3IX bit_num__i2 (.D(n66), .SP(osclk_enable_14), .CD(n329), .CK(osclk), 
            .Q(bit_num[2]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam bit_num__i2.GSR = "ENABLED";
    FD1S3IX c_176__i1 (.D(n74), .CK(osclk), .CD(c_13__N_29), .Q(c[1])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i1.GSR = "ENABLED";
    FD1S3IX c_176__i2 (.D(n73), .CK(osclk), .CD(c_13__N_29), .Q(c[2])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i2.GSR = "ENABLED";
    FD1S3IX c_176__i3 (.D(n72), .CK(osclk), .CD(c_13__N_29), .Q(c[3])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i3.GSR = "ENABLED";
    FD1S3IX c_176__i4 (.D(n71), .CK(osclk), .CD(c_13__N_29), .Q(c[4])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i4.GSR = "ENABLED";
    FD1S3IX c_176__i5 (.D(n70), .CK(osclk), .CD(c_13__N_29), .Q(c[5])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i5.GSR = "ENABLED";
    FD1S3IX c_176__i6 (.D(n69), .CK(osclk), .CD(c_13__N_29), .Q(c[6])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i6.GSR = "ENABLED";
    FD1S3IX c_176__i7 (.D(n68), .CK(osclk), .CD(c_13__N_29), .Q(c[7])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i7.GSR = "ENABLED";
    FD1S3IX c_176__i8 (.D(n67_adj_2), .CK(osclk), .CD(c_13__N_29), .Q(c[8])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i8.GSR = "ENABLED";
    FD1S3IX c_176__i9 (.D(n66_adj_1), .CK(osclk), .CD(c_13__N_29), .Q(c[9])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i9.GSR = "ENABLED";
    FD1S3IX c_176__i10 (.D(n65), .CK(osclk), .CD(c_13__N_29), .Q(c[10])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i10.GSR = "ENABLED";
    FD1S3IX c_176__i11 (.D(n64), .CK(osclk), .CD(c_13__N_29), .Q(c[11])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i11.GSR = "ENABLED";
    FD1S3IX c_176__i12 (.D(n63), .CK(osclk), .CD(c_13__N_29), .Q(c[12])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i12.GSR = "ENABLED";
    FD1S3IX c_176__i13 (.D(n62), .CK(osclk), .CD(c_13__N_29), .Q(c[13])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176__i13.GSR = "ENABLED";
    FD1P3IX reg_i0_i3 (.D(\reg [2]), .SP(osclk_enable_15), .CD(n507), 
            .CK(osclk), .Q(\reg [3]));   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam reg_i0_i3.GSR = "ENABLED";
    PUR PUR_INST (.PUR(VCC_net));
    defparam PUR_INST.RST_PULSE = 1;
    CCU2D c_176_add_4_11 (.A0(c[9]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[10]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n716), 
          .COUT(n717), .S0(n66_adj_1), .S1(n65));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_11.INIT0 = 16'hfaaa;
    defparam c_176_add_4_11.INIT1 = 16'hfaaa;
    defparam c_176_add_4_11.INJECT1_0 = "NO";
    defparam c_176_add_4_11.INJECT1_1 = "NO";
    CCU2D c_176_add_4_9 (.A0(c[7]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[8]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n715), 
          .COUT(n716), .S0(n68), .S1(n67_adj_2));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_9.INIT0 = 16'hfaaa;
    defparam c_176_add_4_9.INIT1 = 16'hfaaa;
    defparam c_176_add_4_9.INJECT1_0 = "NO";
    defparam c_176_add_4_9.INJECT1_1 = "NO";
    LUT4 i2_3_lut_4_lut (.A(osclk_enable_15), .B(n68_adj_5), .C(n65_adj_4), 
         .D(bit_num[0]), .Z(n329)) /* synthesis lut_function=(!((((D)+!C)+!B)+!A)) */ ;   // c:/users/joseph martin/enccount/test.vhd(41[12:17])
    defparam i2_3_lut_4_lut.init = 16'h0080;
    LUT4 i1_3_lut_4_lut (.A(n217), .B(n798), .C(state[1]), .D(state[0]), 
         .Z(n507)) /* synthesis lut_function=(!(A+!(B (C+!(D))))) */ ;
    defparam i1_3_lut_4_lut.init = 16'h4044;
    VLO i1 (.Z(GND_net));
    LUT4 i562_4_lut (.A(bit_num[0]), .B(n65_adj_4), .C(n719), .D(n68_adj_5), 
         .Z(n268)) /* synthesis lut_function=(!(A (C (D))+!A (B+!(C (D))))) */ ;
    defparam i562_4_lut.init = 16'h1aaa;
    LUT4 i561_2_lut (.A(scl_c), .B(n217), .Z(n719)) /* synthesis lut_function=(!((B)+!A)) */ ;
    defparam i561_2_lut.init = 16'h2222;
    LUT4 i7_4_lut (.A(c[0]), .B(n14), .C(n10), .D(c[8]), .Z(n721)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i7_4_lut.init = 16'h8000;
    CCU2D c_176_add_4_7 (.A0(c[5]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[6]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n714), 
          .COUT(n715), .S0(n70), .S1(n69));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_7.INIT0 = 16'hfaaa;
    defparam c_176_add_4_7.INIT1 = 16'hfaaa;
    defparam c_176_add_4_7.INJECT1_0 = "NO";
    defparam c_176_add_4_7.INJECT1_1 = "NO";
    CCU2D c_176_add_4_5 (.A0(c[3]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[4]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n713), 
          .COUT(n714), .S0(n72), .S1(n71));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_5.INIT0 = 16'hfaaa;
    defparam c_176_add_4_5.INIT1 = 16'hfaaa;
    defparam c_176_add_4_5.INJECT1_0 = "NO";
    defparam c_176_add_4_5.INJECT1_1 = "NO";
    LUT4 i6_4_lut (.A(c[9]), .B(c[10]), .C(c[2]), .D(c[13]), .Z(n14)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i6_4_lut.init = 16'h8000;
    CCU2D c_176_add_4_3 (.A0(c[1]), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[2]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n712), 
          .COUT(n713), .S0(n74), .S1(n73));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_3.INIT0 = 16'hfaaa;
    defparam c_176_add_4_3.INIT1 = 16'hfaaa;
    defparam c_176_add_4_3.INJECT1_0 = "NO";
    defparam c_176_add_4_3.INJECT1_1 = "NO";
    CCU2D c_176_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(c[0]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .COUT(n712), 
          .S1(n75));   // c:/users/joseph martin/enccount/test.vhd(29[9:10])
    defparam c_176_add_4_1.INIT0 = 16'hF000;
    defparam c_176_add_4_1.INIT1 = 16'h0555;
    defparam c_176_add_4_1.INJECT1_0 = "NO";
    defparam c_176_add_4_1.INJECT1_1 = "NO";
    LUT4 i1_2_lut (.A(bit_num[1]), .B(bit_num[2]), .Z(n65_adj_4)) /* synthesis lut_function=(A (B)) */ ;   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam i1_2_lut.init = 16'h8888;
    LUT4 i2_2_lut (.A(c[1]), .B(c[3]), .Z(n10)) /* synthesis lut_function=(A (B)) */ ;
    defparam i2_2_lut.init = 16'h8888;
    LUT4 i618_2_lut_rep_6 (.A(clk), .B(c_13__N_29), .Z(osclk_enable_7)) /* synthesis lut_function=(!(A+!(B))) */ ;
    defparam i618_2_lut_rep_6.init = 16'h4444;
    LUT4 i1_3_lut_4_lut_adj_1 (.A(osclk_enable_15), .B(n68_adj_5), .C(n65_adj_4), 
         .D(bit_num[0]), .Z(osclk_enable_14)) /* synthesis lut_function=(A (B ((D)+!C))) */ ;   // c:/users/joseph martin/enccount/test.vhd(41[12:17])
    defparam i1_3_lut_4_lut_adj_1.init = 16'h8808;
    LUT4 i1_4_lut_adj_2 (.A(n798), .B(n329), .C(n1), .D(n217), .Z(osclk_enable_9)) /* synthesis lut_function=(A (B+(C (D)))+!A (B)) */ ;
    defparam i1_4_lut_adj_2.init = 16'heccc;
    LUT4 i1_2_lut_rep_5_3_lut (.A(clk), .B(c_13__N_29), .C(scl_c), .Z(n798)) /* synthesis lut_function=(!(A+!(B (C)))) */ ;
    defparam i1_2_lut_rep_5_3_lut.init = 16'h4040;
    LUT4 i1_2_lut_adj_3 (.A(state[1]), .B(state[0]), .Z(n68_adj_5)) /* synthesis lut_function=(!(A+!(B))) */ ;   // c:/users/joseph martin/enccount/test.vhd(41[12:17])
    defparam i1_2_lut_adj_3.init = 16'h4444;
    LUT4 i21_2_lut (.A(n214), .B(sda_c), .Z(n1)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;   // c:/users/joseph martin/enccount/test.vhd(5[7:10])
    defparam i21_2_lut.init = 16'h6666;
    LUT4 i3_4_lut (.A(scl_c), .B(n214), .C(sda_c), .D(n217), .Z(state_1__N_30[0])) /* synthesis lut_function=(!(((C+!(D))+!B)+!A)) */ ;   // c:/users/joseph martin/enccount/test.vhd(47[3] 77[10])
    defparam i3_4_lut.init = 16'h0800;
    
endmodule
//
// Verilog Description of module TSALL
// module not written out since it is a black-box. 
//

//
// Verilog Description of module PUR
// module not written out since it is a black-box. 
//

