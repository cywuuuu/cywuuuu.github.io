**1 tensor.clone()**

> `clone`(*memory_format=torch.preserve_format*)→ Tensor

返回tensor的拷贝，返回的新tensor和原来的tensor具有同样的大小和数据类型。

- 原tensor的requires_grad=True

clone()返回的tensor是中间节点，梯度会流向原tensor，即返回的tensor的梯度会叠加在原tensor上

```python3
>>> import torch
>>> a = torch.tensor(1.0, requires_grad=True)
>>> b = a.clone()
>>> id(a), id(b)  # a和b不是同一个对象
(140191154302240, 140191145593424)
>>> a.data_ptr(), b.data_ptr()  # 也不指向同一块内存地址
(94724518544960, 94724519185792)
>>> a.requires_grad, b.requires_grad  # 但b的requires_grad属性和a的一样，同样是True
(True, True)
>>> c = a * 2
>>> c.backward()
>>> a.grad
tensor(2.)
>>> d = b * 3
>>> d.backward()
>>> b.grad  # b的梯度值为None，因为是中间节点，梯度值不会被保存
>>> a.grad  # b的梯度叠加在a上
tensor(5.)
```

- 原tensor的requires_grad=False

```python3
>>> import torch
>>> a = torch.tensor(1.0)
>>> b = a.clone()
>>> id(a), id(b)  # a和b不是同一个对象
(140191169099168, 140191154762208)
>>> a.data_ptr(), b.data_ptr()  # 也不指向同一块内存地址
(94724519502912, 94724519533952)
>>> a.requires_grad, b.requires_grad  # 但b的requires_grad属性和a的一样，同样是False
(False, False)
>>> b.requires_grad_()
>>> c = b * 2
>>> c.backward()
>>> b.grad
tensor(2.)
>>> a.grad  # None
```

**2 tensor.detach()**

> `detach`()

从计算图中脱离出来。

返回一个新的tensor，新的tensor和原来的tensor共享数据内存，但不涉及梯度计算，即requires_grad=False。修改其中一个tensor的值，另一个也会改变，因为是共享同一块内存，但如果对其中一个tensor执行某些内置操作，则会报错，例如resize_、resize_as_、set_、transpose_。

```python3
>>> import torch
>>> a = torch.rand((3, 4), requires_grad=True)
>>> b = a.detach()
>>> id(a), id(b)  # a和b不是同一个对象了
(140191157657504, 140191161442944)
>>> a.data_ptr(), b.data_ptr()  # 但指向同一块内存地址
(94724518609856, 94724518609856)
>>> a.requires_grad, b.requires_grad  # b的requires_grad为False
(True, False)
>>> b[0][0] = 1
>>> a[0][0]  # 修改b的值，a的值也会改变
tensor(1., grad_fn=<SelectBackward>)
>>> b.resize_((4, 3))  # 报错
RuntimeError: set_sizes_contiguous is not allowed on a Tensor created from .data or .detach().
```

**3. tensor.clone().detach() 还是 tensor.detach().clone()**

两者的结果是一样的，即返回的tensor和原tensor在梯度上或者数据上没有任何关系，一般用前者。