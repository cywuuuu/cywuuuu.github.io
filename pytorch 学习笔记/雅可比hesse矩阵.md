### 一、雅可比（Jacobi）矩阵

对于函数Rn –>Rm

![[公式]](https://www.zhihu.com/equation?tex=y%3Df%28x%29)

其中，![[公式]](https://www.zhihu.com/equation?tex=x%3D%28x_1%3Bx_2%2C...%3Bx_n%29),![[公式]](https://www.zhihu.com/equation?tex=y%3D%28y_1%3By_2%3B...%3By_m%29) 则Jacobi矩阵为：

![[公式]](https://www.zhihu.com/equation?tex=J%3D+++++++%0A++++++%5Cbegin%7Bpmatrix%7D%0A++++++%5Cfrac%7B%5Cpartial+y_1%7D%7B%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+y_1%7D%7B%5Cpartial+x_2%7D+%26+%5Cfrac%7B%5Cpartial+y_1%7D%7B%5Cpartial+x_3%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+y_1%7D%7B%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cfrac%7B%5Cpartial+y_2%7D%7B%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+y_2%7D%7B%5Cpartial+x_2%7D+%26+%5Cfrac%7B%5Cpartial+y_2%7D%7B%5Cpartial+x_3%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+y_2%7D%7B%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cvdots+%26+%5Cvdots+%26+%5Cvdots+%26+%5Cddots+%26+%5Cvdots+%5C%5C%0A++++++%5Cfrac%7B%5Cpartial+y_m%7D%7B%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+y_m%7D%7B%5Cpartial+x_2%7D+%26+%5Cfrac%7B%5Cpartial+y_m%7D%7B%5Cpartial+x_3%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+y_m%7D%7B%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cend%7Bpmatrix%7D)

如果函数在一点![[公式]](https://www.zhihu.com/equation?tex=p)处可微，则Jacobi矩阵为函数在这一点处的最优线性逼近，即， ![[公式]](https://www.zhihu.com/equation?tex=f%28x%29%5Capprox+f%28p%29%2BJ%28p%29%28x-p%29)

### 二、海塞（Hessan）矩阵

对于函数![[公式]](https://www.zhihu.com/equation?tex=f%28x%29)[Rn->R1],其中，![[公式]](https://www.zhihu.com/equation?tex=x%3D%28x_1%3Bx_2%3Bx_3%2C...%3Bx_n%29),其Hessan 矩阵为：

![[公式]](https://www.zhihu.com/equation?tex=H%3D+++++++%0A++++++%5Cbegin%7Bpmatrix%7D%0A++++++%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_1%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_1%5Cpartial+x_2%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_1%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_2%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_2%5Cpartial+x_2%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_2%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cvdots+%26+%5Cvdots+%26+%5Cddots+%26+%5Cvdots+%5C%5C%0A++++++%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_n%5Cpartial+x_1%7D+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_n%5Cpartial+x_2%7D+%26+%5Ccdots+%26+%5Cfrac%7B%5Cpartial+f%7D%7B%5Cpartial+x_n%5Cpartial+x_n%7D+%5C%5C%0A++++++%5Cend%7Bpmatrix%7D)

Hessan matrix和Jacobi matrix关系：

![[公式]](https://www.zhihu.com/equation?tex=H_f%3DJ%28%5Cnabla+f%5ET%29)

**稍微写一下就好**

当Hessan matrix正定时，在这一点取极小值；

当Hessan matrix负定时，在这一点取极大值；

# 再论hesse 和 jacobi

Hesse 矩阵常被应用于牛顿法解决的大规模优化问题(后面会介绍)，主要形式如下：

![img](https://img2018.cnblogs.com/i-beta/1627600/202002/1627600-20200204110408282-244896156.png)

当 f(x) 为二次函数时，梯度以及 Hesse 矩阵很容易求得。二次函数可以写成下列形式：

![img](http://latex.codecogs.com/gif.latex?f(x)=%5Cfrac%7B1%7D%7B2%7Dx%5ETAx%20+%20b%5ETx+c)

其中 x为列向量，A 是 n 阶对称矩阵，b 是 n 维列向量， c 是常数。**f(x) 梯度是 Ax+b, Hesse 矩阵等于 A**



a) 如果 f(x) 是一个标量函数，那么雅克比矩阵是一个向量，等于 f(x) 的梯度， Hesse 矩阵是一个二维矩阵。如果 f(x) 是一个向量值函数，那么Jacobi 矩阵是一个二维矩阵，Hesse 矩阵是一个三维矩阵。

b) **梯度是 Jacobian 矩阵的特例（Rm->R1），梯度的 jacobian 矩阵就是 Hesse 矩阵（一阶偏导与二阶偏导的关系）。**