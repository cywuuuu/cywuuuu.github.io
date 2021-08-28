## **1. CNN时间复杂度**

即模型的运算次数，可用 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BFLOPs%7D+) 衡量，也就是浮点运算次数（FLoating-point OPerations）。



> **1.1 单个卷积层的时间复杂度**

![[公式]](https://www.zhihu.com/equation?tex=%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Ctextbf%7BTime%7D+%5Csim+O%28M%5E2+%5Ccdot+K%5E2+%5Ccdot+C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%29%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad)

- ![[公式]](https://www.zhihu.com/equation?tex=M) 每个卷积核**输出**特征图 ![[公式]](https://www.zhihu.com/equation?tex=%28Feature~%5Ccolor%7Bred%7D%7BM%7Dap%29) 的边长

- ![[公式]](https://www.zhihu.com/equation?tex=K) 每个卷积核 ![[公式]](https://www.zhihu.com/equation?tex=%28%5Ccolor%7Bred%7D%7BK%7Dernel%29) 的边长

- ![[公式]](https://www.zhihu.com/equation?tex=C_%7Bin%7D) 每个卷积核的通道数，也即输入通道数，也即上一层的输出通道数。

- ![[公式]](https://www.zhihu.com/equation?tex=C_%7Bout%7D) 本卷积层具有的卷积核个数，也即输出通道数。

- ##### 可见，每个卷积层的时间复杂度由输出特征图面积  【被操作面积】、卷积核面积  【卷积要针对每一个卷积核的元素计算一下】[一次操作 ^一层**(conv)**卷积核==>一层的输出^]、[共Cin*共卷积层 次操作]输入和输出通道数  完全决定。

- 其中，**输出**特征图尺寸本身又由**输入**矩阵尺寸 ![[公式]](https://www.zhihu.com/equation?tex=X) 、卷积核尺寸 ![[公式]](https://www.zhihu.com/equation?tex=K) 、![[公式]](https://www.zhihu.com/equation?tex=Padding)、 ![[公式]](https://www.zhihu.com/equation?tex=Stride) 这四个参数所决定，表示如下：

![[公式]](https://www.zhihu.com/equation?tex=%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad+M+%3D+%28X+-+K+%2B+2+%2A+Padding%29+%2F+Stride+%2B+1+%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad)

- 注1：为了简化表达式中的变量个数，这里统一假设输入和卷积核的形状都是正方形。
- 注2：严格来讲每层应该还包含 1 个 ![[公式]](https://www.zhihu.com/equation?tex=Bias) 参数，这里为了简洁就省略了。



> **1.2 卷积神经网络整体的时间复杂度**

![[公式]](https://www.zhihu.com/equation?tex=%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad+%5Ctextbf%7BTime%7D+%5Csim+O%5CBigg%28%5Csum_%7Bl%3D1%7D%5E%7BD%7D+M_l%5E2+%5Ccdot+K_l%5E2+%5Ccdot+C_%7Bl-1%7D+%5Ccdot+C_%7Bl%7D%5CBigg%29+%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad)

- ![[公式]](https://www.zhihu.com/equation?tex=D) 神经网络所具有的卷积层数，也即**网络的深度**。
- ![[公式]](https://www.zhihu.com/equation?tex=l) 神经网络第 ![[公式]](https://www.zhihu.com/equation?tex=l) 个卷积层
- ![[公式]](https://www.zhihu.com/equation?tex=C_l) 神经网络第 ![[公式]](https://www.zhihu.com/equation?tex=l) 个卷积层的输出通道数 ![[公式]](https://www.zhihu.com/equation?tex=C_%7Bout%7D) ，也即该层的卷积核个数。
- 对于第 ![[公式]](https://www.zhihu.com/equation?tex=l) 个卷积层而言，其输入通道数 ![[公式]](https://www.zhihu.com/equation?tex=C_%7Bin%7D) 就是第 ![[公式]](https://www.zhihu.com/equation?tex=%28l+-+1%29) 个卷积层的输出通道数。
- 可见，CNN整体的时间复杂度并不神秘，只是所有卷积层的时间复杂度累加而已。
- 简而言之，层内连乘，层间累加。



> **示例：用 Numpy 手动简单实现二维卷积**

假设 Stride = 1, Padding = 0, img 和 kernel 都是 np.ndarray.

```numpy
def conv2d(img, kernel):
    height, width, in_channels = img.shape
    kernel_height, kernel_width, in_channels, out_channels = kernel.shape
    out_height = height - kernel_height + 1
    out_width = width - kernel_width + 1
    feature_maps = np.zeros(shape=(out_height, out_width, out_channels))
    for oc in range(out_channels):              # Iterate out_channels (# of kernels)
        for h in range(out_height):             # Iterate out_height
            for w in range(out_width):          # Iterate out_width
                for ic in range(in_channels):   # Iterate in_channels
                    patch = img[h: h + kernel_height, w: w + kernel_width, ic]
                    feature_maps[h, w, oc] += np.sum(patch * kernel[:, :, ic, oc])

    return feature_maps
```

------

## **2. 空间复杂度**

空间复杂度（访存量），严格来讲包括两部分：总参数量 + 各层输出特征图。

- **参数量**：模型所有带参数的层的权重参数总量（即**模型体积**，下式第一个求和表达式）
- **特征图**：模型在实时运行过程中每层所计算出的输出特征图大小（下式第二个求和表达式）

![[公式]](https://www.zhihu.com/equation?tex=%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad+%5Ctextbf%7BSpace%7D+%5Csim+O%5CBigg%28%5Csum_%7Bl%3D1%7D%5E%7BD%7D+K_l%5E2+%5Ccdot+C_%7Bl-1%7D+%5Ccdot+C_%7Bl%7D+%2B+%5Csum_%7Bl%3D1%7D%5E%7BD%7D+M%5E2+%5Ccdot+C_l+%5CBigg%29+%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad)

- 总参数量只与卷积核的尺寸 ![[公式]](https://www.zhihu.com/equation?tex=K) 、通道数 ![[公式]](https://www.zhihu.com/equation?tex=C) 、层数 ![[公式]](https://www.zhihu.com/equation?tex=D) 相关，而**与输入数据的大小无关**。
- 输出特征图的空间占用比较容易，就是其空间尺寸 ![[公式]](https://www.zhihu.com/equation?tex=M%5E2) 和通道数 ![[公式]](https://www.zhihu.com/equation?tex=C) 的连乘。
- 注：实际上有些层（例如 ReLU）其实是可以通过原位运算完成的，此时就不用统计输出特征图这一项了。

------

## **3. 复杂度对模型的影响**

- 时间复杂度决定了模型的训练/预测时间。如果复杂度过高，则会导致模型训练和预测耗费大量时间，既无法快速的验证想法和改善模型，也无法做到快速的预测。
- 空间复杂度决定了模型的参数数量。由于维度诅咒的限制，模型的参数越多，训练模型所需的数据量就越大，而现实生活中的数据集通常不会太大，这会导致模型的训练更容易过尼合。
- 当我们需要裁剪模型时，由于卷积核的空间尺寸通常已经很小（3x3），而网络的深度又与模型的表征能力紧密相关，不宜过多削减，因此模型裁剪通常最先下手的地方就是通道数。

------

## **4. Inception 系列模型是如何优化复杂度的**

通过五个小例子说明模型的演进过程中是如何优化复杂度的。



> **4.1** ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BInceptionV1%7D) **中的 ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+1) 卷积降维同时优化时间复杂度和空间复杂度**

![img](https://pic3.zhimg.com/80/v2-fa9848abb41f45ffb1781f9761f73a82_720w.jpg)（图像被压缩的惨不忍睹...）

- InceptionV1 借鉴了 Network in Network 的思想，在一个 Inception Module 中构造了四个并行的不同尺寸的卷积/池化模块（上图左），有效的提升了网络的宽度。但是这么做也造成了网络的时间和空间复杂度的激增。对策就是添加 1 x 1 卷积（上图右红色模块）将输入通道数先降到一个较低的值，再进行真正的卷积。
- 以 InceptionV1 论文中的 (3b) 模块为例（可以点击上图看超级精美的大图），输入尺寸为 ![[公式]](https://www.zhihu.com/equation?tex=28+%5Ctimes+28+%5Ctimes+256)， ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+1) 卷积核 ![[公式]](https://www.zhihu.com/equation?tex=128) 个， ![[公式]](https://www.zhihu.com/equation?tex=3+%5Ctimes+3) 卷积核 ![[公式]](https://www.zhihu.com/equation?tex=192) 个， ![[公式]](https://www.zhihu.com/equation?tex=5+%5Ctimes+5) 卷积核 ![[公式]](https://www.zhihu.com/equation?tex=96) 个，卷积核一律采用 Same Padding 确保输出不改变尺寸。
- 在 ![[公式]](https://www.zhihu.com/equation?tex=3+%5Ctimes+3) 卷积分支上加入 ![[公式]](https://www.zhihu.com/equation?tex=64) 个 ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+1) 卷积前后的时间复杂度对比如下式：

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BBefore%7D%5Cquad+28%5E2+%5Ccdot+3%5E2+%5Ccdot+%5Ccolor%7Bblue%7D%7B256%7D+%5Ccdot+%5Ccolor%7Bblue%7D%7B192%7D+%3D+3.5+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad%5C%5C%5B2ex%5D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BAfter%7D+%5Cquad~~+28%5E2+%5Ccdot+1%5E2+%5Ccdot+%5Ccolor%7Bblue%7D%7B256%7D+%5Ccdot+%5Ccolor%7Bred%7D%7B64%7D+%2B+28%5E2+%5Ccdot+3%5E2+%5Ccdot+%5Ccolor%7Bred%7D%7B64%7D+%5Ccdot+%5Ccolor%7Bblue%7D%7B192%7D+%3D+1+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad+%5Cend%7Baligned%7D)

- 同理，在 ![[公式]](https://www.zhihu.com/equation?tex=5+%5Ctimes+5) 卷积分支上加入 ![[公式]](https://www.zhihu.com/equation?tex=64) 个 ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+1) 卷积前后的时间复杂度对比如下式：

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BBefore%7D%5Cquad+28%5E2+%5Ccdot+5%5E2+%5Ccdot+%5Ccolor%7Bblue%7D%7B256%7D+%5Ccdot+%5Ccolor%7Bblue%7D%7B96%7D+%3D+4.8+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad%5C%5C%5B2ex%5D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BAfter%7D+%5Cquad~~+28%5E2+%5Ccdot+1%5E2+%5Ccdot+%5Ccolor%7Bblue%7D%7B256%7D+%5Ccdot+%5Ccolor%7Bred%7D%7B64%7D+%2B+28%5E2+%5Ccdot+5%5E2+%5Ccdot+%5Ccolor%7Bred%7D%7B64%7D+%5Ccdot+%5Ccolor%7Bblue%7D%7B96%7D+%3D+1.3+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad+%5Cend%7Baligned%7D)

==大channel层后快速conv小channel小kernel[大kernel对小channel, 大channel 对小kernel]==

- 可见，使用 ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+1) 卷积降维可以降低时间复杂度3倍以上。该层完整的运算量可以在论文中查到，为 300 M，即 ![[公式]](https://www.zhihu.com/equation?tex=3+%5Ctimes+10%5E8) 。
- 另一方面，我们同样可以简单分析一下这一层参数量在使用 1 x 1 卷积前后的变化。可以看到，由于 1 x 1 卷积的添加，3 x 3 和 5 x 5 卷积核的参数量得以降低 4 倍，因此本层的参数量从 1000 K 降低到 300 K 左右。

![[公式]](https://www.zhihu.com/equation?tex=%5Cquad%5Cquad%5Cquad+%5Ctextbf%7BBefore%7D+%5Cbegin%7Bcases%7D+1%5E2+%5Ccdot+256+%5Ccdot+128+%5C%5C%5B1ex%5D+3%5E2+%5Ccdot+%5Ccolor%7Bred%7D%7B256%7D+%5Ccdot+192+%5C%5C%5B1ex%5D+5%5E2+%5Ccdot+%5Ccolor%7Bred%7D%7B256%7D+%5Ccdot+96+%5Cend%7Bcases%7D+%5Cquad%5CLongrightarrow%5Cquad+%5Ctextbf%7BAfter%7D+%5Cbegin%7Bcases%7D+1%5E2+%5Ccdot+256+%5Ccdot+128+%5C%5C%5B1ex%5D+1%5E2+%5Ccdot+256+%5Ccdot+64+%5C%5C%5B1ex%5D+3%5E2+%5Ccdot+%5Ccolor%7Bgreen%7D%7B64%7D+%5Ccdot+192+%5C%5C%5B1ex%5D+1%5E2+%5Ccdot+256+%5Ccdot+64+%5C%5C%5B1ex%5D+5%5E2+%5Ccdot+%5Ccolor%7Bgreen%7D%7B64%7D+%5Ccdot+96+%5C%5C%5B1ex%5D+1%5E2+%5Ccdot+256+%5Ccdot+64+%5Cend%7Bcases%7D+%5Cquad%5Cquad%5Cquad)



> **4.2 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BInceptionV1%7D) 中使用** ![[公式]](https://www.zhihu.com/equation?tex=GAP) **代替** ![[公式]](https://www.zhihu.com/equation?tex=Flatten)

- 全连接层可以视为一种特殊的卷积层，其卷积核尺寸 ![[公式]](https://www.zhihu.com/equation?tex=K) 与输入矩阵尺寸 ![[公式]](https://www.zhihu.com/equation?tex=X) 一模一样。每个卷积核的输出特征图是一个标量点，即 ![[公式]](https://www.zhihu.com/equation?tex=M+%3D+1) 。复杂度分析如下：

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%26%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Ctextbf%7BTime%7D+%5Csim+O%281%5E2+%5Ccdot+X%5E2+%5Ccdot+C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%29%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5C%5C%5B2ex%5D+%26%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Ctextbf%7BSpace%7D+%5Csim+O%28X%5E2+%5Ccdot+C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%29%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad+%5Cend%7Baligned%7D)

- 可见，与真正的卷积层不同，**全连接层的空间复杂度与输入数据的尺寸密切相关**。因此如果输入图像尺寸越大，模型的体积也就会越大，这显然是不可接受的。例如早期的VGG系列模型，其 90% 的参数都耗费在全连接层上。
- InceptionV1 中使用的**全局平均池化 GAP** 改善了这个问题。由于每个卷积核输出的特征图在经过全局平均池化后都会直接精炼成一个标量点，因此全连接层的复杂度不再与输入图像尺寸有关，运算量和参数数量都得以大规模削减。复杂度分析如下：

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%26%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Ctextbf%7BTime%7D+%5Csim+O%28C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%29%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5C%5C%5B2ex%5D+%26%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Ctextbf%7BSpace%7D+%5Csim+O%28C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%29%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad%5Cquad+%5Cend%7Baligned%7D)



> **4.3 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BInceptionV2%7D) 中使用两个 ![[公式]](https://www.zhihu.com/equation?tex=3+%5Ctimes+3) 卷积级联替代 ![[公式]](https://www.zhihu.com/equation?tex=5+%5Ctimes+5+) 卷积分支**

![img](https://pic2.zhimg.com/80/v2-9dcf7fa713df2a53cd016482daf9473d_720w.jpg)感受野不变

- 根据上面提到的二维卷积输入输出尺寸关系公式，可知：对于同一个输入尺寸，单个 ![[公式]](https://www.zhihu.com/equation?tex=5+%5Ctimes+5) 卷积的输出与两个 ![[公式]](https://www.zhihu.com/equation?tex=3+%5Ctimes+3) 卷积级联输出的尺寸完全一样，即感受野相同。
- 同样根据上面提到的复杂度分析公式，可知：这种替换能够非常有效的降低时间和空间复杂度。我们可以把辛辛苦苦省出来的这些复杂度用来提升模型的深度和宽度，使得我们的模型能够在复杂度不变的前提下，具有更大的容量，爽爽的。
- 同样以 InceptionV1 里的 (3b) 模块为例，替换前后的 ![[公式]](https://www.zhihu.com/equation?tex=5+%5Ctimes+5) 卷积分支复杂度如下：

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BBefore%7D%5Cquad+28%5E2+%5Ccdot+1%5E2+%5Ccdot+256+%5Ccdot+64+%2B+28%5E2+%5Ccdot+%5Ccolor%7Bgreen%7D%7B5%7D%5E2+%5Ccdot+64+%5Ccdot+96+%3D+1.3+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad%5C%5C%5B2ex%5D+%5Cquad%5Cquad%5Cquad+%26%5Ctextbf%7BAfter%7D+%5Cquad~~+28%5E2+%5Ccdot+1%5E2+%5Ccdot+256+%5Ccdot+64+%2B+28%5E2+%5Ccdot+%5Ccolor%7Bgreen%7D%7B3%7D%5E2+%5Ccdot+64+%5Ccdot+96+%5Ccdot+%5Ccolor%7Bred%7D%7B2%7D+%3D+1.0+%5Ctimes+10%5E8+%5Cquad%5Cquad%5Cquad+%5Cend%7Baligned%7D)



> **4.4 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BInceptionV3%7D) 中使用 ![[公式]](https://www.zhihu.com/equation?tex=N+%5Ctimes+1) 与 ![[公式]](https://www.zhihu.com/equation?tex=1+%5Ctimes+N) 卷积级联替代 ![[公式]](https://www.zhihu.com/equation?tex=N+%5Ctimes+N+) 卷积**

![img](https://pic1.zhimg.com/80/v2-a3268d3a2d9900c1951d6f9abc73bd3c_720w.jpg)

- InceptionV3 中提出了卷积的 Factorization，在确保感受野不变的前提下进一步简化。
- 复杂度的改善同理可得，不再赘述。



> **4.5 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BXception%7D) 中使用 ![[公式]](https://www.zhihu.com/equation?tex=%5Ctextbf%7BDepth-wise+Separable+Convolution%7D)**

![img](https://pic1.zhimg.com/80/v2-d43ffd34f3949f6d4ca5b8c79e4fe8a4_720w.jpg)

- 我们之前讨论的都是标准卷积运算，每个卷积核都对**输入的所有通道**进行卷积。
- Xception 模型挑战了这个思维定势，它让每个卷积核只负责**输入的某一个通道**，这就是所谓的 Depth-wise Separable Convolution。
- 从输入通道的视角看，标准卷积中每个输入通道都会被所有卷积核蹂躏一遍，而 Xception 中每个输入通道只会被对应的一个卷积核扫描，降低了模型的冗余度。
- **标准卷积与可分离卷积的时间复杂度对比**：可以看到本质上是把连乘转化成为相加。

![[公式]](https://www.zhihu.com/equation?tex=%5Cbegin%7Baligned%7D+%5Ctextbf%7BStandard+Convolution%7D+%5Cquad+%7BTime%7D+%26%5Csim+O%5CBig%28M%5E2+%5Ccdot+K%5E2+%5Ccdot+C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%5CBig%29%5C%5C%5B3ex%5D+%5Ctextbf%7BDepth-wise+Separable+Convolution%7D+%5Cquad+%7BTime%7D+%26%5Csim+O%5CBig%28M%5E2+%5Ccdot+K%5E2+%5Ccdot+C_%7Bin%7D+%2B+M%5E2+%5Ccdot+C_%7Bin%7D+%5Ccdot+C_%7Bout%7D%5CBig%29+%5Cend%7Baligned%7D)

------

## **5. 总结**

通过上面的推导和经典模型的案例分析，我们可以清楚的看到其实很多创新点都是围绕模型复杂度的优化展开的，其基本逻辑就是乘变加。模型的优化换来了更少的运算次数和更少的参数数量，一方面促使我们能够构建**更轻更快**的模型（例如MobileNet），一方面促使我们能够构建**更深更宽**的网络（例如Xception），提升模型的容量，**打败各种大怪兽，欧耶~**