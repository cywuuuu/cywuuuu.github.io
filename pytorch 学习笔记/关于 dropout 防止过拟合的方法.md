# 关于 dropout 防止过拟合的方法

### 直观理解：

为了防止过拟合（主要是由于1 ）

![1629546822726](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629546822726.png)

我们采取 减去一些参数 wi， dropout（丢掉）的意义正在于此



### 具体感知与实现

![1629547337839](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629547337839.png)

d3 为 01的随机阵， 对应元素乘上a3层 即可以视为权重为0的权边不存在yeah

