### 关于 CPU输出序列检测 推荐一个好用的测试数据构造方法（只是抛砖引玉希望大佬提出更多自动化测试方法帮助大家debug）





CPU输出序列检测真是太阴间了（呜呜估计是我菜），本人因为一个错误被卡了好久，给的testbench也都过了，然鹅根本找不到bug好嘛！！debug起来根本不知道如何下手好嘛！有木有什么方法可以帮助我们快速构造一些测试数据呢？

emmm我用的是正则表达式的方法随机生成的测试数据，希望对大家有帮助。

首先关于正则表达式的编写，不熟悉的同学可以试试https://regexr.com/
这个网站，还可以学习一下

然后呢，我采用的是python的xeger帮助我们随机生成满足正则表达式，
首先装一下xeger
```python
pip install xeger
```
然后可以借助https://regexr.com/写出我们的表达式
```
\^([0-9]{1,4})@[0-9a-f]{8}: *\$([0-9]{1,4}) *<= *[0-9a-f]{8}#
```

```python
from xeger import Xeger
_x = Xeger()
for i in range(0, 16):
    test_str = _x.xeger("\^([0-9]{1,4})@[0-9a-f]{8}: *\$([0-9]{1,4}) *<= *[0-9a-f]{8}#")
    for item in test_str:
        print("#2 char = \"{}\";".format(item))
    i = i + 1
    print("//"+test_str)

```
然后就有测试数据啦（还有木有更多测式方法啊，求大佬指点我！！！

![image.png](http://10.212.27.185:9199/cscore-image/20373456/e031afc9-48d8-41c2-9d9f-9f5cbf6379d9/image.png)