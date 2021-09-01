# 在PyTorch中in-place operation的含义

in-place operation在pytorch中是指改变一个tensor的值的时候，不经过复制操作，而是直接在原来的内存上改变它的值。可以把它成为原地操作符。

在pytorch中经常加后缀“_”来代表原地in-place operation，比如说.add_() 或者.scatter()。python里面的+=，*=也是in-place operation。

下面是正常的加操作,执行结束加操作之后x的值没有发生变化：

```python
import torch
x=torch.rand(2) #tensor([0.8284, 0.5539])
print(x)
y=torch.rand(2)
print(x+y)      #tensor([1.0250, 0.7891])
print(x)        #tensor([0.8284, 0.5539])
```

下面是原地操作，执行之后改变了原来变量的值：

```python
import torch
x=torch.rand(2) #tensor([0.8284, 0.5539])
print(x)
y=torch.rand(2)
x.add_(y)
print(x)        #tensor([1.1610, 1.3789])
```

在官方问文档中由这一段话：

> 如果你使用了in-place operation而没有报错的话，那么你可以确定你的梯度计算是正确的。

