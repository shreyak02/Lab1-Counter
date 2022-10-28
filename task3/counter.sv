module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic             clk,    // clock
    input logic             rst,    // reset
    input logic             en,     // counter enable
    output logic  [WIDTH-1:0] value,  // reset the counting value
    output logic [WIDTH-1:0] count   // counter output
    //           [7:0] (WIDTH-1)=7
);

always_ff @ (posedge clk)
    if (rst) count <= {WIDTH{1'b0}};
    else    count <= count + {{WIDTH-1{1'b0}}, en}; //{} and , means concatenate     

always_ff @ (posedge clk)
    if (!rst && !en) count <= count - {{WIDTH-1{1'b0}},1};

always_ff @ (posedge clk)
    if(en) count <=value;
endmodule

//challenge - if en=0 want to decrement (count down)

//file name and module name must be the same
//number of bits in the counter is specified with WIDTH parameter
//always_ff @ (posedge clk) specifies a clocked circuit
// <= is a non block assignment which should only be used within an always_ff block
//{WIDTH{1’b0}} in line 12 uses the concatenation operator { } to form WIDTH bits of ‘0’
//WIDTH-1 creates 7 bits of '0' and if enable=1 then LSB becomes 1
