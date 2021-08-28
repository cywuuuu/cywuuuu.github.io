## Verilog Qs

### Q1 关于dff延时触发器

![1629958876471](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629958876471.png)

dff仅在上升沿读入数据并在短时间内 令 q = d（q改变）, 但第二个dff在同一上升沿时，仅能将最初未改变的q读取并在同一段时间 同步到q， 这就导致了类似与流水线一节一节的延时性， eg， 第一个dff保留着最新的数据， 第二个dff保留上一次的数据。。。依次类推

### Q2 关于always等语法

```
1.always@后面内容是敏感变量，always@(*)里面的敏感变量为*，意思是说敏感变量由综合器根据always里面的输入变量自动添加，不用自己考虑。 2.如果没有@，那就是不会满足特定条件才执行，而是执行完一次后立马执行下一次，一直重复执行，比如testbench里面产生50Mhz的时钟就(假设时间尺度是1ns）可以写成 always #20 CLK_50Mhz = ～CLK_50Mhz
```



一般always@(*)是指里面的语句是组合逻辑的。*代替了敏感变量。
而一般时序逻辑要写成always@(posedge clk or negedge rst)//[时钟信号](https://www.baidu.com/s?wd=时钟信号&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)clk上升沿或者[复位信号](https://www.baidu.com/s?wd=复位信号&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)rst下降沿的时候执行always块内的代码。

### Q3 关于赋值、module、 创建变量的语法

！区分操作 ！分开操作！

1. 创建变量操作 wire [31:0\](类型)aaa [\](个数)

2. 赋值操作 assign连续赋值，赋值的变量可以是wire型也可以是reg型

3. module aaaa (, , , ) //output 也在里面
4. 表达式有前后之分{，}



module add1 ( input a, input b, input cin,   output sum, output cout );

assign sum = a\^b\^cin;
assign cout = (a & b) || (a & cin) || (b & cin);


endmodule
------------------------------------------------

### Q4 代码中遇到的语法问题

```verilog
module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
    wire [31:0]bb = b ^ {32{sub}}; //注意 不能自己连自己 所以有bb 类型写前面
    wire lo2hi;
    wire [15:0] lo;
    wire [15:0] hi;
    add16 low (.a(a[15:0]), .b(bb[15:0]), .sum(lo), .cin(sub), .cout(lo2hi));
    add16 high (.a(a[31:16]), .b(bb[31:16]), .sum(hi), .cin(lo2hi), .cout());
    assign sum = {hi,lo};
endmodule

```



## Q5 always blocks

 1.1 Combinational
Combinational always blocks等同于赋值语句，因此总可以用两种方式表示组合电路，使用哪种选择主要是哪种语法更方便的问题。

程序块内部代码的语法与外部代码不同。程序块具有更丰富的语句集（例如if-then，case），不能包含连续的赋值，但是还引入了许多新的非直观的错误处理方式。

例如，assign和combinational always block描述了同一电路。两者都创建相同的组合逻辑块。每当任何输入（右侧）更改值时，两者都将重新计算输出：

```verilog
assign out1 = a & b | c ^ d;
always @(*) out2 = a & b | c ^ d;
对于combinational always blocks，请始终使用灵敏度列表（*）
```



明确列出信号很容易出错（如果您错过了一个信号），并且在硬件综合中会被忽略。如果您明确指定了灵敏度列表并错过了信号，则合成的硬件仍会像指定(*)了一样运行，但是模拟不会与硬件的行为匹配。

关于wire vs. reg的注释：assign语句的左侧必须为网络类型（例如，wire），而过程赋值的左侧（始终在块中）必须为变量类型（例如reg）。这些类型（wire与reg）与合成的硬件无关，而仅仅是Verilog用作硬件仿真语言时留下的语法。

For hardware synthesis, there are two types of `always` blocks that are relevant:

- Combinational: `always @(*)`
- Clocked: `always @(posedge clk)`

Clocked always blocks create a blob of combinational logic just like combinational always blocks, but also creates a set of flip-flops (or "registers") at the output of the blob of combinational logic. Instead of the outputs of the blob of logic being visible immediately, the outputs are visible only immediately after the next (posedge clk).

## Q6 Assignments

#### Blocking vs. Non-Blocking Assignment

There are three types of assignments in Verilog:

- **Continuous** assignments (`assign x = y;`). Can only be used when **not** inside a procedure ("always block").
- Procedural **blocking** assignment: (`x = y;`). Can only be used inside a procedure.
- Procedural **non-blocking** assignment: (`x <= y;`). Can only be used inside a procedure.

> *In a **combinational** always block, use **blocking** assignments.*
>
> *In a **clocked** always block, use **non-blocking** assignments. *

*A full understanding of why is not particularly useful for hardware design and requires a good understanding of how Verilog simulators keep track of events. Not following this rule results in extremely hard to find errors that are both non-deterministic and differ between simulation and synthesized hardware.*

![1630117892881](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630117892881.png)

![1630118541362](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630118541362.png)