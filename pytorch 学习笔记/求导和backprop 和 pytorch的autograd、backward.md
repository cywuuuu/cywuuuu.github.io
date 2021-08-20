# 求导与backprop

Reverse-mode differentiation, on the other hand, starts at an output of the graph and moves towards the beginning. At each node, it merges all paths which originated at that node.

![img](http://colah.github.io/posts/2015-08-Backprop/img/chain-backward-greek.png)

Forward-mode differentiation tracks how one input affects every node. Reverse-mode differentiation tracks how every node affects one output.

Below, the graph has the derivative on each edge labeled.

![img](http://colah.github.io/posts/2015-08-Backprop/img/tree-eval-derivs.png)

**自底向上的计算图**

What if we do reverse-mode differentiation from ee down? This gives us the derivative of ee with respect to every node:

![img](http://colah.github.io/posts/2015-08-Backprop/img/tree-backprop.png)

一对多的求导图 自顶向下

For this graph, that’s only a factor of two speed up, but **imagine a function with a million inputs and one output**. Forward-mode differentiation would require us to go through the graph a million times to get the derivatives. Reverse-mode differentiation can get them all in one fell swoop! A speed up of a factor of a million is pretty nice!

想象神经网络就是一张计算图， 每一次梯度下降 都是loss 自顶向下求出 对于 权重wij 这么多层计算图的导数， 每层的偏导 * 学习率 就是 权重变化的方向

### 那么， 对于 backward（）, autograd一个反向求梯度的利器呢？

最后得到的Tensor执行自身的backward()函数，此时之前参与运算并生成当前Tensor的叶子（leaf）Tensor将会保存其梯度在叶子Tensor的grad属性中。backward()函数接受参数，表示在特定位置求梯度值，该参数应和调用backward()函数的Tensor的维度相同，或者是可broadcast的维度。默认为torch.tensor(1)，也就是在当前梯度为标量1的位置求叶子Tensor的梯度。
默认同一个运算得到的Tensor仅能进行一次backward()。再次运算得到的Tesnor，可以再次进行backward()。
当多个Tensor从相同的源Tensor运算得到，这些运算得到的Tensor的backwards()方法将向源Tensor的grad属性中进行数值累加。

------------------------------------------------
首先说一下叶子Tensor，这是我为了方便理解起的名字。例如我们的模型是这样的：

首先创建Tensor x1，w1和w2。
x2 = x1 * w1。
y = x2 * w2。
L = Y - y。
只要维度相协调，上述各个Tensor目前不必指定维度。实际上上述模型可以看做一个非常简单的神经网络，如下图所示。**w1, w2 L的计算图哦**

![img](https://img-blog.csdn.net/20180716093607419?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2h1eWFveXU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

x1，x2是神经网络的中间层，y是我们的输出层，Y是真值，L是我们的loss。w1和w2是对应于x1和x2的weight。通常我们会把x1，x2，y，w1和w2使用PyTorch的Tensor进行表示。L也可以用Tensor表示，可能与其他Tensor的维度都不同。在上述模型中，x1，w1和w2就是我所谓的叶子Tensor。

在PyTorch中，我们把上述模型描述出来。

 ```py

import torch
import numpy as np

x1 = torch.from_numpy( 2*np.ones((2, 2), dtype=np.float32) )
x1.requires_grad_(True)
w1 = torch.from_numpy( 5*np.ones((2, 2), dtype=np.float32) )
w1.requires_grad_(True)
print("x1 =", x1)
print("w1 =", w1)

x2 = x1 * w1
w2 = torch.from_numpy( 6*np.ones((2,2), dtype=np.float32) )
w2.requires_grad_(True)
print("x2 =", x2)
print("w2 =", w2)

y = x2 * w2
Y = torch.from_numpy( 10*np.ones((2,2), dtype=np.float32) )
print("y =", y)
print("Y =", Y)

L = Y - y
print("L =", L)
 ```



为了更明确说明BP的过程，写出该模型的数学表达式和梯度表达式

![img](https://img-blog.csdn.net/20180716111252870?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2h1eWFveXU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)



计算得出的梯度值分别为x1.grad，w1.grad和w2.grad。其他Tensor的grad属性是None。

backward()函数的第一个参数，在PyTorch的文档上解释的比较晦涩。该参数名为gradient，我理解这个参数在我上述的模型上表示

![img](https://img-blog.csdn.net/20180716111829163?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2h1eWFveXU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

也就是element全为1的Tensor。为何这样设计，这样设计的意图可以理解为当我们不知道L关于y的函数表示，但知道L关于y的梯度时，我们可以通过

```python
y.backward(-1 * torch.ones(2, 2, dtype=torch.float))
```

来完成BP过程。注意，y.backward()的第一个参数，即是L关于y的梯度的值。

通常情况下对于L为标量的情况，使用L.backward()时，不指定任何参数，PyTorch会使用维度相协调的全1Tensor作为参数。对于L为高于1维的情况，需要明确指定backward()的第一个参数。

执行完L.backward()函数后，x1，w1和w2的grad属性会得到更新。更新是“累加”的。所谓累加，举例说明，即当有另外一种定义好的L2是通过对x1的运算得到的，那么L2.backward()执行后梯度结果将累加到x1.grad中。
## 



