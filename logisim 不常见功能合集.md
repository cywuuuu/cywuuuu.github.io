



### logisim 不常见功能合集

#### counter

      ##### pin

![1631341054396](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631341054396.png)



​     **!!!Q的下面还有一个  a    single-bit output carry**

​      ![1631341084102](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631341084102.png)



##### attribute

When the counter reaches this value, **the next increment wraps        the counter back to 0**; 

and **if it is at 0, then a decrement will wrap the counter around back to its maximum value.**     

![1631341408869](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631341408869.png)



#### bit finder（找数器）

![1631451554091](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631451554091.png)

> 
>
> 如果在搜索所需值时找到既不是 0 也不是 1 的值（该位可能是浮动的或错误值），则两个输出都将完全由错误位组成。请注意，这仅在找到所需位之前遇到有问题的位时才会发生：对于输入 x1010100，如果需要最低阶 1，则输出仍为 2；但是如果组件的类型指示搜索最高阶 1 或最高阶 0，我们将得到错误值，因为在比最高阶 0 或最高阶位高的位中存在错误位1.
>
> 引脚
> 南边（输出，位宽 1）
> 如果找到所需位，则为 1，如果所有输入位都是所需位的相反数数，则为 0，如果在所需位之前找到非 0、非 1 值，则为错误值。 
>
> 

### bit adder(数1器)

![1631452380522](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1631452380522.png)

#### negator

计算输入的补码否定。 这种否定是通过将所有低位位保持到最低位 1 并对其上的所有位求补来执行的。
如果要否定的值恰好是最小的负值，那么它的否定（不能以二进制补码形式表示）仍然是最小的负值。 

## 8. 学会做全面测试

请确认你提交的电路中不包含任何红色的连线，并且能够通过你自己构造的测试。如果你设计的电路使用二进制补码输入，请务必测试正、负数两种情况。

你构造的测试点至少应包括：正数+正数、正数+负数、负数+负数、负数+正数，另外不要忘记 0。

- Pull Behavior：是否增加上，下拉电阻。对于输入引脚，该属性指定应如何处理来自父级电路的浮空值。
  - unchanged：浮空值将作为浮动值发送至父级电路中；
  - pull up：浮空值在被送入父级电路之前被转换为 1；
  - pull down：浮空值在被送到父级电路之前被转换为 0。

![img](https://d.buaa.edu.cn/http/77726476706e69737468656265737421f3e44293353526526b0988e29d51367b9787/tutorial/logisim/logisim-6/assets/logisim_6_6_8.png?vpn-1)

- High Duration/Low Duration：这里的含义是高点平与低电平的持续时间，例如，如果选择 High Duration 为 2 tick，则在一个周期内，高点平持续 2/3 周期，低电平持续 1/3 周期。在我们的实验中，默认选择 1 tick 即可。
- Numeric Type：表示数据的数据种类，可选择的有，二进制的补码形式和无符号类型。

注意：请大家在使用该器件的时候，一定要明确所需要的比较数据的类型，否则会出现难以查找的错误。



1、算术左移-逻辑左移

算术左移和逻辑左移一样都是右边补0： 比如 00101011 

算术左移一位:01010110 

逻辑左移一位:01010110 

对于二进制的数值来说左移n位等于原来的数值乘以2的n次方 

比如00011010十进制是26，左移两位后是01101000转成十进制是104恰好是26的4倍。 

ps：这种倍数关系只适用于左移后被舍弃的高位不含1的情况，否则会溢出。

2、算术右移，逻辑右移

逻辑右移很简单，只要将二进制数整体右移，左边补0即可 

如10101101逻辑右移一位为01010110 

算术右移符号位要一起移动，并且在左边补上符号位，也就是如果符号位是1就补1符号位是0就补0 

比如：11100算术右移一位为11110（符号位1跟着一起移动并且左边补了1） 