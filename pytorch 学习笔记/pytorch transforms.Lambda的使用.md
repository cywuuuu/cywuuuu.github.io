# pytorch transforms.Lambda的使用

当你想要对图像设置transforms策略时，如：

```
from torchvision import transforms as T

normalize = T.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
data_transforms = {
    'train': T.Compose([
        T.RandomResizedCrop(224),  # 从图片中心截取
        T.RandomHorizontalFlip(),  # 随机水平翻转给定的PIL.Image,翻转概率为0.5
        T.ToTensor(),  # 转成Tensor格式，大小范围为[0,1]
        normalize
    ]),

    'val': T.Compose([
        T.Resize(256),  # 重新设定大小
        T.CenterCrop(224),
        T.ToTensor(),
        normalize
    ]),
}
```

但是有时官方提供的方法并不能够满足你的需要，这时候你就需要自定义自己的transform策略

方法就是使用transforms.Lambda

举例说明：

比如当我们想要截取图像，但并不想在随机位置截取，而是希望在一个自己指定的位置去截取

那么你就需要自定义一个截取函数,然后使用transforms.Lambda去封装它即可,如：

```
# coding:utf-8
from torchvision import transforms as T

def __crop(img, pos, size):
    """
    :param img: 输入的图像
    :param pos: 图像截取的位置,类型为元组，包含(x, y)
    :param size: 图像截取的大小
    :return: 返回截取后的图像
    """
    ow, oh = img.size
    x1, y1 = pos
    tw = th = size
    # 有足够的大小截取
    # img.crop坐标表示 (left, upper, right, lower)
    if (ow > tw or oh > th):
        return img.crop((x1, y1, x1+tw, y1+th))
    return img

# 然后使用transforms.Lambda封装其为transforms策略
# 然后定义新的transforms为
normalize = T.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
data_transforms = T.Compose([
    T.Lambda(lambda img: __crop(img, (5,5), 224)),
    T.RandomHorizontalFlip(),  # 随机水平翻转给定的PIL.Image,翻转概率为0.5
    T.ToTensor(),  # 转成Tensor格式，大小范围为[0,1]
    normalize
])
```