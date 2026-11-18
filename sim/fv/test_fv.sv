module test_fv;
    logic clk;
    logic rst_n;
    logic [3:0] counter;
    
    always_ff @(posedge clk) begin
        if (!rst_n)
            counter <= 4'h0;
        else
            counter <= counter + 1;
    end
    
    initial begin
        clk = 0;
        rst_n = 0;
        #20 rst_n = 1;
    end
    
    always_ff @(posedge clk) begin
        if (rst_n)
            $assert(counter < 16);
    end
endmodule