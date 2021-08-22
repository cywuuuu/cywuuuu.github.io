# sicp 笔记

###  heron法 （recursion）

![1628757758221](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628757758221.png)

### procedure data combination

![1628757835531](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628757835531.png)

### lisp 中的 区分 字符用作abstraction 还是字符代表procedure

![1628757776465](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628757776465.png)

### 高阶过程 用 不动点求根号x

![1628757740135](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628757740135.png)

![1628759108128](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628759108128.png)

![1628820848375](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628820848375.png)

λ(x) (….) 产生一个匿名的（λ为临时名字，x为函数的参数，…为具体过程函数f）的过程，该过程可作为参数传递

![1628821227176](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628821227176.png)



![1628822486219](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628822486219.png)

![1628822386369](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628822386369.png)

![1628822429412](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628822429412.png)

## 复合数据（glue）

数据层次 系统 通过抽象的 组合和析取形成封装好的层级

![1628902806935](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628902806935.png)

![1628902285216](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628902285216.png)

|          | segment     |         |
| -------- | ----------- | ------- |
| make-seg | seg-start   | seg-end |
|          | **vectors** |         |
| make     | x           | y       |

#### 观察底层con的做法

**发现数据con的本质正是 glue的过程procedure**

![1628902820618](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628902820618.png)

## list 和 高阶过程map、foreach

![1628905634557](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628905634557.png)

![1628905861076](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628905861076.png)

![1628906731443](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628906731443.png)

