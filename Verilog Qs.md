## Verilog Qs

### Q1 关于dff延时触发器

![1629958876471](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629958876471.png)

dff仅在上升沿读入数据并在短时间内 令 q = d（q改变）, 但第二个dff在同一上升沿时，仅能将最初未改变的q读取并在同一段时间 同步到q， 这就导致了类似与流水线一节一节的延时性， eg， 第一个dff保留着最新的数据， 第二个dff保留上一次的数据。。。依次类推

![1631102186082](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631102186082.png)

mux是多到一，选一路

dmx是一到多中的一， 把1的数据放在其中一个对应输出中

decd是一到多，亮起二进制对应的灯但是传不了数据，而且没有数据输入端口

### Q 1.5 RSlatch

![1631096330036](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631096330036.png)

点亮下方1   可以使对角线点亮，同端熄灭，

然而关闭下方   却没有任何作用，

同理对于上面

#### Q1.7 logisim RAM ROM的数据导入一行一个

![1631144608212](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631144608212.png)

第一种情况对应的结果如上图，Logisim的文件输入是一行一个十六进制数输入进去，当输入进去的数据超过两位十六进制的表示范围时，Logisim会对其进行截断处理。上图中文件里第1、2、4、5行分别是0x01、0x10、0x10、0x01，对应存储器中的位置都是正确的，但第3行内容是0x100，超过了表示范围，截断后是0x00
### Q2 关于always等语法

```
1.always@后面内容是敏感变量，always@(*)里面的敏感变量为*，意思是说敏感变量由综合器根据always里面的输入变量自动添加，不用自己考虑。 2.如果没有@，那就是不会满足特定条件才执行，而是执行完一次后立马执行下一次，一直重复执行，比如testbench里面产生50Mhz的时钟就(假设时间尺度是1ns）可以写成 always #20 CLK_50Mhz = ～CLK_50Mhz
```

#### and wall 在 clk == 0 时 隔离了上方输出与下方输入（下方输入全部无效）

![1630408545389](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630408545389.png)

![1630408629831](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630408629831.png)

#### clk为正时，下方输入有效

![1630408874115](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630408874115.png)

![1630408893773](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630408893773.png)

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

#### always块既可以是边沿敏感的，也可以是电平敏感的，

A正确。上面的讲解提到已经提到了always块建模时序逻辑和组合逻辑的两种常用方法，B正确。在多个always块中对同一个变量进行赋值的代码是不可综合的，C错误。

## initial 块

`initial` 块后面紧跟的语句或顺序语句块在硬件仿真开始时就会运行，且仅会运行一次，一般用于对 `reg` 型变量的取值进行初始化。`initial` 块通常仅用于仿真，是**不可综合的**。下面的代码用于给寄存器 `a` 赋初始值 `0`：

```verilog
reg a;

initial begin
    a = 0;
end
```

#### always与initial进阶练习（不会开始的always @(*)）

“秋冬之交在即，此乃祭祖之期。”小孔同学刚结束快乐的暑假，开始紧张刺激的计组学习了。可是现在有一个选择摆在他的面前，大家可以告诉他应该怎么选择吗？

仔细阅读下列代码：

![4.3.5.3.png](http://10.212.27.185:9199/cscore-image/zhongshuzhang/be3a5858-77b9-4bf8-8e80-fbc0d2a4b4b6/4.3.5.3.png)

判断：当clk和reset信号都处于下降沿时，mem会被清零。

答案：错误

**注意，always @(*) 表示的是触发条件是always引导的顺序块中所有驱动信号的变化，而不是本模块所有信号的变化。该always块中向mem赋值的是0，是常量，因此这一always块始终不会被触发**

## Q6 Assignments

#### 未驱动的不能拿来连线assign

未被驱动的wire型变量可以理解为一段没有连接任何信号的导线，它和其他导线相连是没有意义的

#### Blocking vs. Non-Blocking Assignment

There are three types of assignments in Verilog:

- **Continuous** assignments (`assign x = y;`). Can only be used when **not** inside a procedure ("always block").

- Procedural **blocking** assignment: (`x = y;`). Can only be used inside a procedure.

- Procedural **non-blocking** assignment: (`x <= y;`). Can only be used inside a procedure.

  ### 

> 
>
> *In a **combinational** always block, use **blocking** assignments.*
>
> *In a **clocked** always block, use **non-blocking** assignments. *

### 分析always @ (posedge clk)中的阻塞与非阻塞语句

- ==**(非阻塞的会 并行赋值，并且时间层次分明 )**==

- 阻塞的会 执行完一个赋值， 然后执行下一个赋值，但这都是一瞬间的事， 赋值在一瞬间是顺着下来赋值的，缺少了时序的隔断

  ![1631516551851](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631516551851.png)

  
  
  

#### =会在always块之前运行, <=可以视为和always块并行运行，且本次不对always块中的<=的所有右值产生影响

**如果你在ISim中进行试验就会发现，testbench中=和<=在时钟上升沿的临界状态下，行为是不同的。假如赋值和always块在同一个时钟上升沿发生，=会在always块之前运行，从而影响alway块的赋值；<=可以视为和always块并行运行，且本次不对always块中的<=的所有右值产生影响。**

> 改为 <= 后， in的值会在调用的uut上升沿来临时（后）赋值， 自然会无法影响本上升沿的情况，相比于=在上升沿来前一丢丢赋值，当个上升沿就起到作用；<=会比 = 慢上一拍
>
> ![1631518043780](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631518043780.png)
>
> 本题较为细致地考察了阻塞赋值与非阻塞赋值的区别。
>
> 首先观察原有的代码，buffer模块中的always块采用了非阻塞赋值，而题目中强调了“外部需要保证in恰好在clk的每个上升沿变化”，那么正确的运行方式应当是：当clk上升沿的瞬间，in的值也发生改变，但在always块中参与运算的是旧的in值，即所谓的“本次不对always块中的<=的所有右值产生影响”。那么旧的in值给到buffer，旧的buffer的值给到out，以此out应当落后in两个时钟周期。
>
> 但上述正确运行过程的前提是，“本次不对always块中的<=的所有右值产生影响”，这一前提的保证是，外部的in变化与clk上升沿同时发生，而在原有的代码中，test bench中initial块的赋值都是阻塞赋值，在10ns时刻是clk的上升沿，同时是in信号的阻塞赋值变化，而阻塞赋值是要先于always块执行的，于是in的值先更新，在buffer模块的always块中in使用了新值，out只落后in一个时钟周期。
>
> 题目要求只修改test bench中的代码，那么将initial块中的阻塞赋值改为非阻塞即可，非阻塞赋值并不改变always块中的旧值，可以使out落后in两个时钟周期，而最少的修改只需要将in后来变化时的赋值方式修改即可，即第32、34、36行的阻塞赋值改为非阻塞赋值。

A full understanding of why is not particularly useful for hardware design and requires a good understanding of how Verilog simulators keep track of events. Not following this rule results in extremely hard to find errors that are both non-deterministic and differ between simulation and synthesized hardware.*

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

#### 运算符们

- 逻辑右移运算符 `>>` 与算术右移运算符 `>>>`

  它们的区别主要在于前者在最高位**补 0**，而后者在最高位**补符号位**。

- 相等比较运算符 `==` 与 `===` 和 `!=` 与 `!==`

  `==` 和 `!=` 可能由于不定值 `x` 和高阻值 `z` 的出现导致结果为**不定值 x**，而 `===` 和 `!==` 的结果一定是**确定的 0 或 1**（`x` 与 `z` 也参与比较）。

- 阻塞赋值 `=` 和非阻塞赋值 `<=`

  不同于 `assign` 语句，这两种赋值方式被称为过程赋值，通常出现在 `initial` 和 `always` 块中，**为 reg 型变量赋值**。这种赋值类似 C 语言中的赋值，不同于 `assign` 语句，赋值仅会在一个时刻执行。由于 Verilog 描述硬件的特性，Verilog程序内会有大量的并行，因而产生了这两种赋值方式。这两种赋值方式的详细区别我们会在之后的小节内介绍，这里暂时只需记住一点：为了写出正确、可综合的程序，**在描述时序逻辑时要使用非阻塞式赋值 <=** 。

  *16’hf000 >> 4 = ？ 答案：16’h0f00*

  ***$signed(16’hf000) >>> 4 = ？ 答案：16’hff00***

  ***逻辑右移：高位补0即可；算术右移：在高位补符号位。***

  ***注意上面算术右移的写法，Verilog中表示有符号数需要加 $signed()。***


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

#### ==**for语句和while语句不可以直接出现在语句块之外。**==

#### ==**for语句和while语句既可以用于建模组合逻辑，也可以用来建模时序逻辑。**==

###### 时序逻辑 popcount

![1631503243208](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631503243208.png)

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

### Q 11 quartusII综合报错（Error (10028): Can't resolve multiple constant drivers for net ）

出现这个错误的原因在于，在不同的always逻辑块中，对同一个reg变量进行了赋值。

在多个alwasy逻辑块同时并行工作的时候，会出现冲突。!==解决的办法就是，对于一个变量，只在一个always块中，进行赋值。==!

### Q12 时间控制语句

时间控制语句通常出现在测试模块中，用来产生符合我们期望变化的测试信号，比如每隔 5 个时间单位变更一次信号等。这个语句通过关键字 `#` 实现延时，格式为 **#时间**，当延时语句出现在顺序块中时它后面的语句会在延时完毕后继续执行。举例如下：

#### ==# 先延迟 再执行==

```verilog
#3;  // 延迟 3 个时间单位
#5 b = a;   
// b 为 reg 型，延迟 5 个时间单位后执行赋值语句
always #5 clk = ~clk;   
// 每过 5 个时间单位触发一次，
//时钟信号反转，时钟周期为 10 个时间单位
assign #5 b = a; 
//b 为 wire 型，将表达式右边的值延时 5 个时间单位后赋给 b
```

#### ==# 各模块的并行性==

#### Q 13 有符号数的处理方法

在 Verilog HDL 中，`wire`、`reg` 等数据类型**默认都是无符号的**。当你希望做符号数的操作时，你需要使用 **$signed()**。

下面我们通过一个比较器的例子进行详细说明：

![img](http://cscore.buaa.edu.cn/tutorial/verilog/verilog-3/assets/verilog-signed1.png)

我们希望程序实现比较 a, b 大小的功能，若 a > b，res 输出 1，否则输出 0，下面进行测试。

![img](http://cscore.buaa.edu.cn/tutorial/verilog/verilog-3/assets/verilog-signed2.png)

我们初始化 a = 4，b = 1，100ns 后 b 变为 -1。期望的结果是 res 始终为 1。下面是波形：

![img](http://cscore.buaa.edu.cn/tutorial/verilog/verilog-3/assets/verilog-signed3.png)

可以看到 100ns 后，res 输出变为了 0，与预期不符。其原因在于比较时 Verilog 将 a 和 b 默认视为无符号数，-1 会被认为是 15(`4'b1111`)。

将比较代码修改为 `assign res = $signed(a) > $signed(b);`，程序即可达到预期结果。

值得一提的是，在对无符号数和符号数同时操作时，Verilog 会自动地做数据类型匹配，**将符号数向无符号数转化**。同样使用上面的例子，将代码修改为 `assign res = a > $signed(b);`，这样得到的结果仍然是错误的，因为在执行 `a > $signed(b)` 时，a 是无符号数，b 是符号数，Verilog 默认向无符号类型转化，得到的结果仍是无符号数的比较结果。

此外，对于**移位运算符，其右侧的operand总是被视为无符号数(位移的位数总是一个正数)，并且不会对运算结果的符号性产生任何影响**。结果的符号由运算符左侧的operand和表达式的其余部分共同决定。

希望大家可以通过编写测试代码并进行 ISE 仿真来掌握符号数的使用方法，这在后期 CPU 的功能实现过程中将有重要的作用。

#### 负数以补码储存，却被当作无符号使用

负数在存储时确实会以补码形式存储，但使用时仍然被当作无符号数。Verilog中想要使用有符号数必须添加$signed()

#### Q14 宏定义的简单使用

类似 C 语言，Verilog HDL 也提供了编译预处理指令。下面我们对其中的宏定义部分作一简要介绍。

在 Verilog HDL 语言中，为了和一般的语句相区别，编译预处理命令**以符号 `（反引号，backtick）开头**（位于主键盘左上角，其对应的上键盘字符为 `~`。注意这个符号不同于单引号）。这些预处理命令的有效作用范围为定义命令之后到本文结束或到其他命令定义替代该命令之处。

宏定义用一个指定的标识符(即名字)来代表一个字符串，它的一般形式为：``define 标识符(宏名) 字符串(宏内容)`。它的作用是指定用标识符来代替字符串，在编译预处理时，把程序中该命令以后所有的标识符都替换成字符串。举例如下：

```verilog
`define WORDSIZE 8
// 省略模块定义
 reg[1:`WORDSIZE] data;
// 相当于定义 reg[1:8] data; 
```

注意，**引用宏名时也必须在宏名前加上符号 `**，以表明该名字是经过宏定义的名字。

# BASIC module

### 1.full_adder 

```verilog
module add1 ( input a, input b, input cin,   output sum, output cout );

assign sum = a^b^cin;// 模拟个位数一个一个1-》0-》1向上涨
assign cout = (a & b) || (a & cin) || (b & cin);
// Full adder module here
// 任意两个 为 1 则cout 为1
endmodule
//------------------******-----------------------

module top_module( 
    input [2:0] a, b,
    input cin,
    output [2:0] cout,
    output [2:0] sum );
    add1 zero (.a(a[0]), .b(b[0]), .cin(cin), .sum(sum[0]), .cout(cout[0]));
    add1 one (.a(a[1]), .b(b[1]), .cin(cout[0]), .sum(sum[1]), .cout(cout[1]));
    add1 two (.a(a[2]), .b(b[2]), .cin(cout[1]), .sum(sum[2]), .cout(cout[2]));
endmodule
module add1 ( input a, input b, input cin,   output sum, output cout );
    assign sum = a^b^cin;// 模拟个位数一个一个1-》0-》1向上涨
    assign cout = (a & b) || (a & cin) || (b & cin);
    // Full adder module here
    // 任意两个 为 1 则cout 为1
endmodule
```

### 2.可以直接对vector使用 a+b

```
module top_module( 
    input [99:0] a, b,
    input cin,
    output cout,
    output [99:0] sum );
    assign {cout, sum[99:0]} = a + b + cin;
endmodule 
```

### 3.关于同步复位和异步复位

一、特点：
   同步复位：顾名思义，同步复位就是指复位信号只有在时钟上升沿到来时，才能有效。否则，无法完成对系统的复位工作。用Verilog描述如下：

```
            always @ (posedge clk) begin
                  if (!Rst_n)
                    ...
            end
```

   异步复位：它是指无论时钟沿是否到来，只要复位信号有效，就对系统进行复位。用Verilog描述如下：

```
            always @ (posedge clk,negedge Rst_n) begin
                   if (!Rst_n)
                      ...
            end
```

二、各自的优缺点：
    1、总的来说，同步复位的优点大概有3条：
       a、有利于仿真器的仿真。
       b、可以使所设计的系统成为100%的同步时序电路，这便大大有利于时序分析，而且综合出来的fmax一般较高。
       c、因为他只有在时钟有效电平到来时才有效，所以可以滤除高于时钟频率的毛刺。
       他的缺点也有不少，主要有以下几条：
       a、复位信号的有效时长必须大于时钟周期，才能真正被系统识别并完成复位任务。同时还要考虑，诸如：clk skew,组合逻辑路径延时,复位延时等因素。
       b、由于大多数的逻辑器件的目标库内的DFF都只有异步复位端口，所以，倘若采用同步复位的话，综合器就会在寄存器的数据输入端口插入组合逻辑，这样就会耗费较多的逻辑资源。
    2、对于异步复位来说，他的优点也有三条，都是相对应的：
       a、大多数目标器件库的dff都有异步复位端口，因此采用异步复位可以节省资源。
       b、设计相对简单。
       c、异步复位信号识别方便，而且可以很方便的使用FPGA的全局复位端口GSR。
       缺点：
       a、在复位信号释放(release)的时候容易出现问题。具体就是说：倘若复位释放时恰恰在时钟有效沿附近，就很容易使寄存器输出出现亚稳态，从而导致亚稳态。
       b、复位信号容易受到毛刺的影响。
三、总结：
    所以说，一般都推荐使用异步复位，同步释放的方式，而且复位信号低电平有效。这样就可以两全其美了。

```
always @(posedge clk or negedge rst_n)

​         if(!rst_n) b <= 1'b0;

​         else b <= a;
```

### 4. Dual-edge triggered flip-flop（双沿检测）    

```verilog
module top_module (
    input clk,
    input d,
    output q
);
    reg q_d1;
    reg q_d2;
always@(posedge clk)begin
    q_d1 <= d ^ q_d2;
end
always@(negedge clk)begin
    q_d2 <= d ^ q_d1;
end

assign q = q_d1 ^ q_d2;
    endmodule
```

```verilog
//second way
module top_module (
    input clk,
    input d,
    output q
);
    reg q_d1;
    reg q_d2;
always@(posedge clk)begin
    q_d1 <= d;
end

always@(negedge clk)begin
    q_d2 <= d;
end

assign q = clk ? q_d1 : q_d2;
endmodule
```


这道题是重点，大家注意，对于双沿检测，一定不能使用always@(posedge clk or negedge clk)begin这种方式，这种方式是不可综合的，应该用图中的方法一。但是对于第二种方法，虽然这道题是正确的，但是博主亲测在modelsim和vivado中仿真会产生毛刺，不建议大家用，对于这部分逻辑大家应该清楚。

![1630293326985](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630293326985.png)





### 5.计数器

做一个1000clk的计时器

```verilog
module top_module (
    input clk,
    input reset,
    output OneHertz,
    output [2:0] c_enable
); //
wire[3:0]	one, ten, hundred;

    assign c_enable = {one == 4'd9 && ten == 4'd9, one == 4'd9, 1'b1};//
assign OneHertz = (one == 4'd9 && ten == 4'd9 && hundred == 4'd9);
 // enable == 1 时 counter 动一下
bcdcount counter0 (clk, reset, c_enable[0], one);
bcdcount counter1 (clk, reset, c_enable[1], ten);
bcdcount counter2 (clk, reset, c_enable[2], hundred);
endmodule
```

##### 12h clock

```verilog
module top_module(
    input clk,
    input reset,
    input ena,
    output pm,
    output [7:0] hh,
    output [7:0] mm,
    output [7:0] ss); 
    wire mcin,hcin,pmt;
	counter60 seconds(clk, reset, ena, ss, mcin);
	counter60 minutes(clk, reset, mcin, mm, hcin);
	counter12 hours(clk, reset, hcin&mcin, hh, pmt);
    always@(posedge clk)begin
    if(reset)pm <= 1'b0;
    else if(pmt)pm <= ~pm;
    else pm <= pm;
    end

endmodule

module counter12 (input clk, input reset, input ena, output [7:0] tim, output cout );
    always @(posedge clk)begin
        if(reset)	tim <= 8'b0001_0010;
    	else if(ena)begin
            if(tim == 8'b0001_0010)		tim <= 8'b0000_0001;
    		else if(tim[3:0] == 4'd9)begin
    			tim[7:4] <= tim[7:4] +1'b1;
    			tim[3:0] <= 4'b0;
    			end
    		else
    			tim[3:0] <= tim[3:0] +1'b1;
    	end
        
    end
    assign cout = (tim ==8'b0001_0001)&&(ena);
endmodule

module counter60 (input clk, input reset, input ena, output [7:0] tim, output cout );
always @(posedge clk)begin
	if(reset)
		tim <= 8'd0;
	else if(ena)begin
//if(bcd < 8'd59)
// bcd <= bcd + 1'b1;
		if(tim == 8'b0101_1001)
			tim <= 8'd0;
		else if(tim[3:0] == 4'd9)begin
			tim[7:4] <= tim[7:4] +1'b1;
			tim[3:0] <= 4'b0;
		end
		else
			tim[3:0] <= tim[3:0] +1'b1;
	end
end
assign cout = tim ==8'b0101_1001;
endmodule


```

### 6.位移寄存器

#### LFSR

[LFSR：线性反馈移位寄存器及其应用_庸手著文章-CSDN博客](https://blog.csdn.net/little_cats/article/details/104488780)

[线性反馈移位寄存器（LFSR）-非线性反馈移位寄存器的verilog实现（产生伪随机数）..._weixin_30449453的博客-CSDN博客](https://blog.csdn.net/weixin_30449453/article/details/96560705?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.essearch_pc_relevant&spm=1001.2101.3001.4242)

```
void lfsr3()
{
	unsigned int temp0, temp1, temp2;
	temp0 = ff0; //拷贝ff0
	temp1 = ff1; //拷贝ff1
	temp2 = ff2; //拷贝ff2
	ff0 = temp2;
	ff1 = temp0 ^ (0 * temp2);
	ff2 = temp1 ^ (1 * temp2);
}
```

![1630585690095](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630585690095.png)

#### 新的编程模式 ， 组合逻辑 与 时序分块 组合

```verilog
//新的编程模式 ， 组合逻辑 与 时序
module top_module(
    input clk,
    input reset,    // Active-high synchronous reset to 32'h1
    output [31:0] q
); 
    reg [31:0] q_next;
    always @ (*) begin 
        q_next = {q[0], q[31:1]};
        q_next[21] = q[0] ^ q[22];
        q_next[1] = q[0] ^ q[2];
        q_next[0] = q[0] ^ q[1];
    end 
    always @ (posedge clk) begin
        if(reset) q <= 32'h1;
        else q <= q_next;
    end
endmodule


```

### 7.interesting parts

#### CONWEY AUTOMATION SIMU

![1630654850696](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630654850696.png)

### 8.Simple FSM 1（asynchronous reset）

![Fsm1.png](https://hdlbits.01xz.net/mw/images/7/70/Fsm1.png)

```verilog
module top_module(
    input clk,
    input areset,    // Asynchronous reset to state B
    input in,
    output out);//  

    parameter A=0, B=1; // A, B 表示在哪个圈圈，parameter用数字区分名字 
    reg state, next_state;//state 当前状态 存储这 A 或B（0或1）

    always @(*) begin    // This is a combinational always block
        case (state) 
            A: begin
                if(in == 1'b1)next_state = A;
                else next_state = B;
            end
            B: begin
                if(in == 1'b1)next_state = B;
                else next_state = A;
            end
        endcase
        // State transition logic
    end

    always @(posedge clk, posedge areset) begin    // This is a sequential always block
        if(areset == 1) state <= B;
        else begin
            state <= next_state;
        end
        // State flip-flops with asynchronous reset
    end
	
    assign out = (state == A) ? 0 : 1;
    // Output logic
    // assign out = (state == ...);

endmodule
```

### 9. one-hot 编码 与  自动机

![1630673433760](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630673433760.png)

```verilog
module top_module(
    input in,
    input [3:0] state,
    output [3:0] next_state,
    output out); //
parameter A=0, B=1, C=2, D=3;
 // 把自动机的每一位看作单独的真值表
// State transition logic: Derive an equation for each state flip-flop.
    assign next_state[A] = state[A] & ~in | state[C] & ~in;// next_state[A] 就是 指 xxxx的第0位， 其取值（0或1）反映了next——state是A or 还是B还是CD等 
    // next_state[A] 为 1 当且仅当 
assign next_state[B] = state[A] & in | state[B] & in | state[D] & in;
assign next_state[C] = state[B] & ~in | state[D] & ~in;
assign next_state[D] = state[C] & in;
 
// Output logic: 
assign out = state[D];
endmodule;
```

### 10.设计自动机

![1630735685928](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630735685928.png)

1.按照输出的n个不同可能， 枚举n个状态

![1630756482667](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630756482667.png)

![1630759068731](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1630759068731.png)

2.写出状态转移关系 out = {fr1, fr2, fr3, dfr}

#### 注意事项

注意此处如果掉下去挖也没用， 

##### 自动机的状态转移优先级要搞清楚

```verilog
module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    input dig,
    output walk_left,
    output walk_right,
    output aaah,
    output digging ); 
    parameter WL = 0, WR = 1, DL = 2, DR = 3, FALL_L = 4, FALL_R = 5;
    reg [3:0] state, next_state;
    always @ (*) begin
        case(state)
            WL: 
            begin 
                if(ground == 0)  next_state = FALL_L;// 注意此处如果掉下去挖也没用， 自动机的状态转移优先级要搞清楚
                else if(dig) next_state = DL; 
                else if(bump_left) next_state = WR; 
                else if(!bump_left) next_state = WL;
            end
            WR:
            begin 
                if(ground == 0) next_state = FALL_R;
                else if(dig) next_state = DR; 
                else if(bump_right) next_state = WL; 
                else if(!bump_right) next_state = WR;
            end
            DL:
            begin
                if(ground == 1) next_state = DL;
                else  next_state = FALL_L;
            end
            DR:
            begin
                if(ground == 1) next_state = DR;
                else  next_state = FALL_R;
            end
            FALL_L: if(ground) next_state = WL;
            else next_state = FALL_L;
            FALL_R: if(ground) next_state = WR;
            else next_state = FALL_R;
            default: next_state = WL;
        endcase
    end
    
    always @ (posedge clk, posedge areset) begin
        if(areset) state <= WL;
        else state <= next_state ;
    end

    assign walk_left = (state == WL) ? 1 : 0;
    assign walk_right = (state == WR) ? 1 : 0;
    assign aaah = (state == FALL_R || state == FALL_L) ;
    assign digging = (state == DR || state == DL) ;
endmodule

```

