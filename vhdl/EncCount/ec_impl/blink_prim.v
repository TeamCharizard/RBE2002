// Verilog netlist produced by program LSE :  version Diamond (64-bit) 3.5.0.102
// Netlist written on Thu Oct 29 10:00:38 2015
//
// Verilog Description of module blink
//

module blink (led, led2, inp);   // c:/users/joseph martin/enccount/blink.vhd(7[8:13])
    output led;   // c:/users/joseph martin/enccount/blink.vhd(8[6:9])
    output led2;   // c:/users/joseph martin/enccount/blink.vhd(8[30:34])
    input inp;   // c:/users/joseph martin/enccount/blink.vhd(8[52:55])
    
    wire clk /* synthesis SET_AS_NETWORK=clk, is_clock=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(12[9:12])
    
    wire GND_net, VCC_net, led_c, led2_c_c;
    wire [24:0]count;   // c:/users/joseph martin/enccount/blink.vhd(26[12:17])
    
    wire n9, n162, n25, n24, n23, n206, n205, n22, n204, n203, 
        n21, n20, led_N_52, n8, n6, n10, n106, n107, n108, 
        n109, n110, n111, n112, n113, n114, n115, n116, n117, 
        n118, n119, n120, n121, n122, n123, n124, n125, n126, 
        n127, n128, n129, n130, n209, n187, n202, n201, n200, 
        n199, n198, n197, n196, n195;
    
    VHI i2 (.Z(VCC_net));
    FD1S3IX count_24__i0 (.D(n130), .CK(clk), .CD(n162), .Q(n25)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i0.GSR = "ENABLED";
    FD1S3AX led_15 (.D(led_N_52), .CK(clk), .Q(led_c));   // c:/users/joseph martin/enccount/blink.vhd(28[3] 35[10])
    defparam led_15.GSR = "ENABLED";
    FD1S3IX count_24__i24 (.D(n106), .CK(clk), .CD(n162), .Q(count[24])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i24.GSR = "ENABLED";
    OSCH osc (.STDBY(GND_net), .OSC(clk)) /* synthesis syn_instantiated=1 */ ;
    defparam osc.NOM_FREQ = "53.2";
    LUT4 i4_4_lut (.A(n187), .B(count[19]), .C(count[21]), .D(count[20]), 
         .Z(n10)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i4_4_lut.init = 16'h8000;
    CCU2D count_24_add_4_25 (.A0(count[23]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[24]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n206), .S0(n107), .S1(n106));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_25.INIT0 = 16'hfaaa;
    defparam count_24_add_4_25.INIT1 = 16'hfaaa;
    defparam count_24_add_4_25.INJECT1_0 = "NO";
    defparam count_24_add_4_25.INJECT1_1 = "NO";
    OB led2_pad (.I(led2_c_c), .O(led2));   // c:/users/joseph martin/enccount/blink.vhd(8[30:34])
    OB led_pad (.I(led_c), .O(led));   // c:/users/joseph martin/enccount/blink.vhd(8[6:9])
    CCU2D count_24_add_4_23 (.A0(count[21]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[22]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n205), .COUT(n206), .S0(n109), .S1(n108));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_23.INIT0 = 16'hfaaa;
    defparam count_24_add_4_23.INIT1 = 16'hfaaa;
    defparam count_24_add_4_23.INJECT1_0 = "NO";
    defparam count_24_add_4_23.INJECT1_1 = "NO";
    CCU2D count_24_add_4_21 (.A0(count[19]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[20]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n204), .COUT(n205), .S0(n111), .S1(n110));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_21.INIT0 = 16'hfaaa;
    defparam count_24_add_4_21.INIT1 = 16'hfaaa;
    defparam count_24_add_4_21.INJECT1_0 = "NO";
    defparam count_24_add_4_21.INJECT1_1 = "NO";
    CCU2D count_24_add_4_19 (.A0(count[17]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[18]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n203), .COUT(n204), .S0(n113), .S1(n112));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_19.INIT0 = 16'hfaaa;
    defparam count_24_add_4_19.INIT1 = 16'hfaaa;
    defparam count_24_add_4_19.INJECT1_0 = "NO";
    defparam count_24_add_4_19.INJECT1_1 = "NO";
    LUT4 i1_2_lut (.A(led_c), .B(n162), .Z(led_N_52)) /* synthesis lut_function=(!(A (B)+!A !(B))) */ ;
    defparam i1_2_lut.init = 16'h6666;
    LUT4 i94_4_lut (.A(n9), .B(count[24]), .C(count[23]), .D(n10), .Z(n162)) /* synthesis lut_function=(A (B (C+(D)))+!A (B (C))) */ ;
    defparam i94_4_lut.init = 16'hc8c0;
    CCU2D count_24_add_4_17 (.A0(count[15]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[16]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n202), .COUT(n203), .S0(n115), .S1(n114));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_17.INIT0 = 16'hfaaa;
    defparam count_24_add_4_17.INIT1 = 16'hfaaa;
    defparam count_24_add_4_17.INJECT1_0 = "NO";
    defparam count_24_add_4_17.INJECT1_1 = "NO";
    PUR PUR_INST (.PUR(VCC_net));
    defparam PUR_INST.RST_PULSE = 1;
    FD1S3IX count_24__i1 (.D(n129), .CK(clk), .CD(n162), .Q(n24)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i1.GSR = "ENABLED";
    LUT4 i3_3_lut (.A(count[8]), .B(count[6]), .C(count[7]), .Z(n8)) /* synthesis lut_function=(A+(B+(C))) */ ;
    defparam i3_3_lut.init = 16'hfefe;
    LUT4 i88_4_lut (.A(n209), .B(count[17]), .C(count[16]), .D(count[15]), 
         .Z(n187)) /* synthesis lut_function=(A (B+(C))+!A (B+(C (D)))) */ ;
    defparam i88_4_lut.init = 16'hfcec;
    GSR GSR_INST (.GSR(VCC_net));
    LUT4 i3_2_lut (.A(count[18]), .B(count[22]), .Z(n9)) /* synthesis lut_function=(A (B)) */ ;
    defparam i3_2_lut.init = 16'h8888;
    LUT4 i1_4_lut (.A(count[9]), .B(count[11]), .C(n8), .D(count[10]), 
         .Z(n6)) /* synthesis lut_function=(A (B)+!A (B (C+(D)))) */ ;
    defparam i1_4_lut.init = 16'hccc8;
    TSALL TSALL_INST (.TSALL(GND_net));
    LUT4 i4_4_lut_adj_1 (.A(count[13]), .B(count[12]), .C(count[14]), 
         .D(n6), .Z(n209)) /* synthesis lut_function=(A (B (C (D)))) */ ;
    defparam i4_4_lut_adj_1.init = 16'h8000;
    CCU2D count_24_add_4_15 (.A0(count[13]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[14]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n201), .COUT(n202), .S0(n117), .S1(n116));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_15.INIT0 = 16'hfaaa;
    defparam count_24_add_4_15.INIT1 = 16'hfaaa;
    defparam count_24_add_4_15.INJECT1_0 = "NO";
    defparam count_24_add_4_15.INJECT1_1 = "NO";
    CCU2D count_24_add_4_13 (.A0(count[11]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[12]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n200), .COUT(n201), .S0(n119), .S1(n118));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_13.INIT0 = 16'hfaaa;
    defparam count_24_add_4_13.INIT1 = 16'hfaaa;
    defparam count_24_add_4_13.INJECT1_0 = "NO";
    defparam count_24_add_4_13.INJECT1_1 = "NO";
    CCU2D count_24_add_4_11 (.A0(count[9]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[10]), .B1(GND_net), .C1(GND_net), 
          .D1(GND_net), .CIN(n199), .COUT(n200), .S0(n121), .S1(n120));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_11.INIT0 = 16'hfaaa;
    defparam count_24_add_4_11.INIT1 = 16'hfaaa;
    defparam count_24_add_4_11.INJECT1_0 = "NO";
    defparam count_24_add_4_11.INJECT1_1 = "NO";
    CCU2D count_24_add_4_9 (.A0(count[7]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(count[8]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n198), .COUT(n199), .S0(n123), .S1(n122));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_9.INIT0 = 16'hfaaa;
    defparam count_24_add_4_9.INIT1 = 16'hfaaa;
    defparam count_24_add_4_9.INJECT1_0 = "NO";
    defparam count_24_add_4_9.INJECT1_1 = "NO";
    CCU2D count_24_add_4_7 (.A0(n20), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(count[6]), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n197), 
          .COUT(n198), .S0(n125), .S1(n124));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_7.INIT0 = 16'hfaaa;
    defparam count_24_add_4_7.INIT1 = 16'hfaaa;
    defparam count_24_add_4_7.INJECT1_0 = "NO";
    defparam count_24_add_4_7.INJECT1_1 = "NO";
    CCU2D count_24_add_4_5 (.A0(n22), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(n21), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n196), 
          .COUT(n197), .S0(n127), .S1(n126));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_5.INIT0 = 16'hfaaa;
    defparam count_24_add_4_5.INIT1 = 16'hfaaa;
    defparam count_24_add_4_5.INJECT1_0 = "NO";
    defparam count_24_add_4_5.INJECT1_1 = "NO";
    CCU2D count_24_add_4_3 (.A0(n24), .B0(GND_net), .C0(GND_net), .D0(GND_net), 
          .A1(n23), .B1(GND_net), .C1(GND_net), .D1(GND_net), .CIN(n195), 
          .COUT(n196), .S0(n129), .S1(n128));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_3.INIT0 = 16'hfaaa;
    defparam count_24_add_4_3.INIT1 = 16'hfaaa;
    defparam count_24_add_4_3.INJECT1_0 = "NO";
    defparam count_24_add_4_3.INJECT1_1 = "NO";
    CCU2D count_24_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(n25), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .COUT(n195), .S1(n130));   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24_add_4_1.INIT0 = 16'hF000;
    defparam count_24_add_4_1.INIT1 = 16'h0555;
    defparam count_24_add_4_1.INJECT1_0 = "NO";
    defparam count_24_add_4_1.INJECT1_1 = "NO";
    FD1S3IX count_24__i23 (.D(n107), .CK(clk), .CD(n162), .Q(count[23])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i23.GSR = "ENABLED";
    FD1S3IX count_24__i22 (.D(n108), .CK(clk), .CD(n162), .Q(count[22])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i22.GSR = "ENABLED";
    FD1S3IX count_24__i21 (.D(n109), .CK(clk), .CD(n162), .Q(count[21])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i21.GSR = "ENABLED";
    FD1S3IX count_24__i20 (.D(n110), .CK(clk), .CD(n162), .Q(count[20])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i20.GSR = "ENABLED";
    FD1S3IX count_24__i19 (.D(n111), .CK(clk), .CD(n162), .Q(count[19])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i19.GSR = "ENABLED";
    FD1S3IX count_24__i18 (.D(n112), .CK(clk), .CD(n162), .Q(count[18])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i18.GSR = "ENABLED";
    FD1S3IX count_24__i17 (.D(n113), .CK(clk), .CD(n162), .Q(count[17])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i17.GSR = "ENABLED";
    FD1S3IX count_24__i16 (.D(n114), .CK(clk), .CD(n162), .Q(count[16])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i16.GSR = "ENABLED";
    FD1S3IX count_24__i15 (.D(n115), .CK(clk), .CD(n162), .Q(count[15])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i15.GSR = "ENABLED";
    FD1S3IX count_24__i14 (.D(n116), .CK(clk), .CD(n162), .Q(count[14])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i14.GSR = "ENABLED";
    FD1S3IX count_24__i13 (.D(n117), .CK(clk), .CD(n162), .Q(count[13])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i13.GSR = "ENABLED";
    FD1S3IX count_24__i12 (.D(n118), .CK(clk), .CD(n162), .Q(count[12])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i12.GSR = "ENABLED";
    FD1S3IX count_24__i11 (.D(n119), .CK(clk), .CD(n162), .Q(count[11])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i11.GSR = "ENABLED";
    FD1S3IX count_24__i10 (.D(n120), .CK(clk), .CD(n162), .Q(count[10])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i10.GSR = "ENABLED";
    FD1S3IX count_24__i9 (.D(n121), .CK(clk), .CD(n162), .Q(count[9])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i9.GSR = "ENABLED";
    FD1S3IX count_24__i8 (.D(n122), .CK(clk), .CD(n162), .Q(count[8])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i8.GSR = "ENABLED";
    FD1S3IX count_24__i7 (.D(n123), .CK(clk), .CD(n162), .Q(count[7])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i7.GSR = "ENABLED";
    FD1S3IX count_24__i6 (.D(n124), .CK(clk), .CD(n162), .Q(count[6])) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i6.GSR = "ENABLED";
    FD1S3IX count_24__i5 (.D(n125), .CK(clk), .CD(n162), .Q(n20)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i5.GSR = "ENABLED";
    FD1S3IX count_24__i4 (.D(n126), .CK(clk), .CD(n162), .Q(n21)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i4.GSR = "ENABLED";
    FD1S3IX count_24__i3 (.D(n127), .CK(clk), .CD(n162), .Q(n22)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i3.GSR = "ENABLED";
    FD1S3IX count_24__i2 (.D(n128), .CK(clk), .CD(n162), .Q(n23)) /* synthesis syn_use_carry_chain=1 */ ;   // c:/users/joseph martin/enccount/blink.vhd(30[14:19])
    defparam count_24__i2.GSR = "ENABLED";
    IB led2_c_pad (.I(inp), .O(led2_c_c));   // c:/users/joseph martin/enccount/blink.vhd(8[52:55])
    VLO i1 (.Z(GND_net));
    
endmodule
//
// Verilog Description of module PUR
// module not written out since it is a black-box. 
//

//
// Verilog Description of module TSALL
// module not written out since it is a black-box. 
//

