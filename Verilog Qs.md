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

##### 错位赋值小技巧

```verilog
module top_module( 
    input [99:0] in,
    output [98:0] out_both,
    output [99:1] out_any,
    output [99:0] out_different );
    assign out_both[98:0] = in[99:1] & in[98:0];
    assign out_any[99:1] = in[99:1] | in[98:0];
    assign out_different[99:0] = {in[0], in[99:1]} ^ in[99:0];
endmodule
```




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

##### always case

```verilog
always @(*) begin     // This is a combinational circuit
    case (in)
        
      1'b1: begin 
      	out = 1'b1;// begin-end if >1 statement
            end
        
      1'b0: out = 1'b0;
        
      default: out = 1'bx;
        
    endcase// 注意！！endcase！！！
end
```

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

## Q7 about latches

> 在很多地方都能看到，verilog中if与case语句必须完整，即if要加上else,case后要加上default语句，以防止latches的发生

2.2 If statement latches
设计电路时，必须首先考虑电路:

我想要这个逻辑门
我想要一个具有这些输入并产生这些输出的组合逻辑块
我想要一组组合的逻辑后跟一组触发器(flip-flops)
一定不要做的是先编写代码，然后希望它生成正确的电路。

If (cpu_overheated) then shut_off_computer = 1;
If (~arrived) then keep_driving = ~gas_tank_empty;
语法正确的代码不一定会导致电路合理（组合逻辑+触发器）。通常的原因是：“在您指定的情况以外的情况下会发生什么？”。 Verilog的答案是：保持输出不变。

这种“保持输出不变”的行为意味着需要记住当前状态，从而产生一个锁存器。组合逻辑（例如逻辑门）无法记住任何状态。

注意警告：Warning (10240): ... inferring latch(es)" messages.
除非有意使用闩锁，否则它几乎总是表示错误。在所有条件下，组合回路必须为所有输出分配一个值。这通常意味着您总是需要else子句或分配给输出的默认值。

**question:**
以下代码包含创建闩锁latch的不正确行为。试修复错误，以便仅在计算机确实过热时才关闭计算机，并在到达目的地或需要加油时停止驾驶。

```verilog
always @(*) begin
    if (cpu_overheated)
       shut_off_computer = 1;
end

always @(*) begin
    if (~arrived)
       keep_driving = ~gas_tank_empty;
end
```

比如 当第一次cpu_overheat = 1 时 shut off 

但当 cpu_overheat ⬇ 下降时， shut off 仍然 = 1

#### avoid latches && less typing => defualt value

To avoid creating latches, all outputs must be assigned a value in all possible conditions (See also [always_if2](https://hdlbits.01xz.net/wiki/always_if2)). Simply having a `default` case is not enough. You must assign a value to all four outputs in all four cases and the default case. This can involve a lot of unnecessary typing. **One easy way around this is to assign a "default value" to the outputs *before* the case statement:**

```verilog
always @(*) begin
    up = 1'b0; down = 1'b0; left = 1'b0; right = 1'b0;// *** 不能连等！！！ ***
    case (scancode)
        ... // Set to 1 as necessary.
    endcase //default的内容没有时 就不要写！！ default：空 是不允许的哦
end
```

This style of code ***ensures the outputs are assigned a value (of 0) in all possible cases unless the case statement overrides the assignment.*** This also means that a `default:` case item becomes unnecessary.

## Q8 二进制 与多进制表示法

![1630142863334](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630142863334.png)

> ```verilog
> // synthesis verilog_input_version verilog_2001
> module top_module (
>     input [7:0] in,
>     output reg [2:0] pos  );
>     always @(*) begin
>         casez(in) //********caseZZZZZZ!!!!!!!
>             8'bzzzzzzz1: pos = 0;
>             8'bzzzzzz10: pos = 1;
>             8'bzzzzz100: pos = 2;
>             8'bzzzz1000: pos = 3;
>             8'bzzz10000: pos = 4;
>             8'bzz100000: pos = 5;
>             8'bz1000000: pos = 6;
>             8'b10000000: pos = 7;
>             default: pos = 0;
>         endcase
>     end
>         
> endmodule
> ```

##### 关于wire 中数据unsigned 比大小 可以直接 > <

e.g.

```verilog
module top_module (
    input [7:0] a, b, c, d,
    output [7:0] min);//
	
    assign min = ((a < b ? a : b) < (c < d ? c : d)) ? (a < b ? a : b) : (c < d ? c : d);
    // assign intermediate_result1 = compare? true: false;
	//观察小于号 作用 于wire上
endmodule
```

## Q9 运算符 与 for语句

### 一元  多位自我 运算符

The *reduction* operators can do AND, OR, and XOR of the bits of a vector, producing one bit of output:

```
& a[3:0]     // AND: a[3]&a[2]&a[1]&a[0]. Equivalent to (a[3:0] == 4'hf)
| b[3:0]     // OR:  b[3]|b[2]|b[1]|b[0]. Equivalent to (b[3:0] != 4'h0)
^ c[2:0]     // XOR: c[2]^c[1]^c[0]
```

***These are unary operators that have only one operand (similar to the NOT operators ! and ~).*** You can also invert the outputs of these to create NAND, NOR, and XNOR gates, e.g., `(~& d[7:0])`.

![1630163511729](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630163511729.png)

#### 认清异或门

### 两种for循环的写法

> ###     **A for loop (in a combinational always block or generate block) would be useful here. I would prefer a combinational always block in this case because module instantiations (which require generate blocks) aren't needed.**

```verilog
module top_module( 
    input [99:0] in,
    output [99:0] out
);
always@(*)begin
    for(int i = 0; i <= 99; i++)begin// i++也可以哦
        out[i] = in[99 - i];// 没有{}只有begin end
    end
end

/* 
//the second way
generate
    genvar i;
    for(i = 0; i <= 99; i = i + 1)begin:reverse
        assign out[i] = in[99 - i];//!!! need assign
    end
endgenerate
*/
endmodule
//这里大家注意，第二种方法在generate中使用for循环的时候，一定要在begin后面起一个名字，如本模块中的reverse。
```

generate-for只针对于module、reg、net、assign、always、parameter、function、initial、task等语句或者模块，而for只针对于非例化的循环。

generate-for语句：
**1、generate-for语句必须用genvar关键字定义for的索引变量；**
**2、for的内容必须用begin end块包起来，哪怕只有一句；**
**3、begin end块必须起个名字**

在开始仿真前，仿真器会对生成块中代码进行确立展开，展开后的仿真代码中生成变量genvar不复存在。

------------------------------------------------

## Q10 MULTIPLEXER 的 多种写法

#### 2 way

![1630222449731](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630222449731.png)

#### 256 way（邪道表示法，vector 下标为变量的选择器）

- > **Vector indices can be variable**, as long as the synthesizer can figure out that the width of the bits being selected is constant. In particular, selecting one bit out of a vector using a variable index will work.

```verilog
module top_module( 
    input [255:0] in,
    input [7:0] sel,
    output out );
    assign out = in[sel];
endmodule
```



```verilog
module top_module (
	input [1023:0] in,
	input [7:0] sel,
	output [3:0] out
);
// We can't part-select multiple bits without an error, but we can select one bit at a time,
// four times, then concatenate them together.
assign out = {in[sel*4+3], in[sel*4+2], in[sel*4+1], in[sel*4+0]};

// !!!Alternatively, "indexed vector part select" works better, but has an unfamiliar syntax:
// assign out = in[sel*4 +: 4];		// Select starting at index "sel*4", then select a total width of 4 bits with increasing (+:) index number.
// assign out = in[sel*4+3 -: 4];	// Select starting at index "sel*4+3", then select a total width of 4 bits with decreasing (-:) index number.
// Note: The width (4 in this case) must be constant.
endmodule;
```



##### 更邪道的方法

> **// !!!Alternatively, "indexed vector part select" works better, but has an unfamiliar syntax:**
> **// assign out = in[sel*4 +: 4];		// Select starting at index "sel*4", then select a total width of 4 bits with increasing (+:) index number.**
> **// assign out = in[sel*4+3 -: 4];	// Select starting at index "sel*4+3", then select a total width of 4 bits with decreasing (-:) index number.**
> **// Note: The width (4 in this case) must be constant.**

## Q10.5 关于数值表示的一点想法

```verilog
module top_module( 
    input [15:0] a, b, c, d, e, f, g, h, i,
    input [3:0] sel,
    output [15:0] out );
    always @(*) begin
        case(sel)
            0: out = a;// can it be translated? 
            1: out = b;
            2: out = c;
            3: out = d;
            4: out = e;
            5'd5: out = f;//这里的位数永远指的二进制的位数
            5'd6: out = g;
            5'd7: out = h;
            5'd8: out = i;
            default: out = {16{1'b1}};
        endcase
    end

endmodule
```

