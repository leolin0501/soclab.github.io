// SPDX-FileCopyrightText: 2020 Efabless Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// SPDX-License-Identifier: Apache-2.0

//`default_nettype none
`default_nettype wire
/*
 *-------------------------------------------------------------
 *
 * user_proj_example
 *
 * This is an example of a (trivially simple) user project,
 * showing how the user project can connect to the logic
 * analyzer, the wishbone bus, and the I/O pads.
 *
 * This project generates an integer count, which is output
 * on the user area GPIO pads (digital output only).  The
 * wishbone connection allows the project to be controlled
 * (start and stop) from the management SoC program.
 *
 * See the testbenches in directory "mprj_counter" for the
 * example programs that drive this user project.  The three
 * testbenches are "io_ports", "la_test1", and "la_test2".
 *
 *-------------------------------------------------------------
 */
`define MPRJ_IO_PADS_1 19	/* number of user GPIO pads on user1 side */
`define MPRJ_IO_PADS_2 19	/* number of user GPIO pads on user2 side */
`define MPRJ_IO_PADS (`MPRJ_IO_PADS_1 + `MPRJ_IO_PADS_2)

module user_proj_example #(
    parameter BITS = 32,
    parameter DELAYS=10
)(
`ifdef USE_POWER_PINS
    inout vccd1,	// User area 1 1.8V supply
    inout vssd1,	// User area 1 digital ground
`endif

    // Wishbone Slave ports (WB MI A)
    input wb_clk_i,
    input wb_rst_i,
    input wbs_stb_i,
    input wbs_cyc_i,
    input wbs_we_i,
    input [3:0] wbs_sel_i,
    input [31:0] wbs_dat_i,
    input [31:0] wbs_adr_i,
    output reg wbs_ack_o,
    output [31:0] wbs_dat_o,

    // Logic Analyzer Signals
    input  [127:0] la_data_in,
    output [127:0] la_data_out,
    input  [127:0] la_oenb,

    // IOs
    input  [`MPRJ_IO_PADS-1:0] io_in,
    output [`MPRJ_IO_PADS-1:0] io_out,
    output [`MPRJ_IO_PADS-1:0] io_oeb,

    // IRQ
    output [2:0] irq
);


   wire [`MPRJ_IO_PADS-1:0] io_in;
   wire [`MPRJ_IO_PADS-1:0] io_out;
   wire [`MPRJ_IO_PADS-1:0] io_oeb;

   wire [31:0] Do0; //output to BRAM

   
   assign wbs_dat_o = (cnt == 4'd12) ? Do0 : 0; //ready transport data from Slave to Master 

   reg [3:0] cnt; //for counting
   always @(posedge wb_clk_i or posedge wb_rst_i) begin
      if (wb_rst_i) begin
         cnt <= 4'd1; //initialize counter
      end else if (wbs_cyc_i == 1 && cnt == 4'd12) begin
         cnt <= 4'd1; //already count 12 and WB is trigger, initialize counting
      end else if (wbs_cyc_i == 1 && cnt != 4'd12) begin
         cnt <= cnt + 4'd1; //not count 12 yet, but WB is trigger, keep counting
      end
   end

   always @(cnt) begin
      wbs_ack_o = (cnt == 4'd12) ? 1 : 0; // wbs_ack_o = 1 meant mission access
   end



   wire [3:0] we;
   assign we = (cnt>=4'd10) ? {4{wbs_we_i}} : 0; //when count over 10, pretrigger whrite enable and try to let data on time.

   bram user_bram (
     .CLK(wb_clk_i),
     .WE0(we),
     .EN0(~wb_rst_i),
     .Di0(wbs_dat_i),
     .Do0(Do0),
     .A0(wbs_adr_i)
   );

   

endmodule