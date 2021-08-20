# hello everyone

# code here

## now here

```py
import numpy as np
import numpy.testing as npt
import pandas as pd
from statsmodels.tsa.base.tsa_model import TimeSeriesModel
from statsmodels.tools.testing import assert_equal, assert_raises
from datetime import datetime


def test_pandas_nodates_index():

    data = [988, 819, 964]
    dates = ['a', 'b', 'c']
    s = pd.Series(data, index=dates)

    # TODO: Remove this, this is now valid
    # npt.assert_raises(ValueError, TimeSeriesModel, s)

    # Test with a non-date index that doesn't raise an exception because it
    # can be coerced into a nanosecond DatetimeIndex
    # (This test doesn't make sense for Numpy < 1.7 since they don't have
    # nanosecond support)
    # (This test also doesn't make sense for Pandas < 0.14 since we don't
    # support nanosecond index in Pandas < 0.14)
    try:
        # Check for Numpy < 1.7
        pd.to_offset('N')
    except:
        pass
    else:
        data = [988, 819, 964]
        # index=pd.date_range('1970-01-01', periods=3, freq='QS')
        index = pd.to_datetime([100, 101, 102])
        s = pd.Series(data, index=index)

        actual_str = (index[0].strftime('%Y-%m-%d %H:%M:%S.%f') +
                      str(index[0].value))
        assert_equal(actual_str, '1970-01-01 00:00:00.000000100')
        mod = TimeSeriesModel(s)
        start, end, out_of_sample, _ = mod._get_prediction_index(0, 4)
        assert_equal(len(mod.data.predict_dates), 5)

def test_predict_freq():
    # test that predicted dates have same frequency
    x = np.arange(1,36.)

    # there's a bug in pandas up to 0.10.2 for YearBegin
    #dates = date_range("1972-4-1", "2007-4-1", freq="AS-APR")
    dates = pd.date_range("1972-4-30", "2006-4-30", freq="A-APR")
    series = pd.Series(x, index=dates)
    model = TimeSeriesModel(series)
    #npt.assert_(model.data.freq == "AS-APR")
    assert_equal(model._index.freqstr, "A-APR")

    start, end, out_of_sample, _ = (
        model._get_prediction_index("2006-4-30", "2016-4-30"))

    predict_dates = model.data.predict_dates

    #expected_dates = date_range("2006-12-31", "2016-12-31",
    #                            freq="AS-APR")
    expected_dates = pd.date_range("2006-4-30", "2016-4-30", freq="A-APR")
    assert_equal(predict_dates, expected_dates)
    #ptesting.assert_series_equal(predict_dates, expected_dates)


def test_keyerror_start_date():
    x = np.arange(1,36.)

    # there's a bug in pandas up to 0.10.2 for YearBegin
    #dates = date_range("1972-4-1", "2007-4-1", freq="AS-APR")
    dates = pd.date_range("1972-4-30", "2006-4-30", freq="A-APR")
    series = pd.Series(x, index=dates)
    model = TimeSeriesModel(series)

    npt.assert_raises(KeyError, model._get_prediction_index, "1970-4-30", None)

def test_period_index():
    # test 1285

    dates = pd.PeriodIndex(start="1/1/1990", periods=20, freq="M")
    x = np.arange(1, 21.)

    model = TimeSeriesModel(pd.Series(x, index=dates))
    assert_equal(model._index.freqstr, "M")
    model = TimeSeriesModel(pd.Series(x, index=dates))
    npt.assert_(model.data.freq == "M")

def test_pandas_dates():

    data = [988, 819, 964]
    dates = ['2016-01-01 12:00:00', '2016-02-01 12:00:00', '2016-03-01 12:00:00']

    datetime_dates = pd.to_datetime(dates)

    result = pd.Series(data=data, index=datetime_dates, name='price')
    df = pd.DataFrame(data={'price': data}, index=pd.DatetimeIndex(dates, freq='MS'))

    model = TimeSeriesModel(df['price'])

    assert_equal(model.data.dates, result.index)

def test_get_predict_start_end():
    index = pd.DatetimeIndex(start='1970-01-01', end='1990-01-01', freq='AS')
    endog = pd.Series(np.zeros(10), index[:10])
    model = TimeSeriesModel(endog)

    predict_starts = [1, '1971-01-01', datetime(1971, 1, 1), index[1]]
    predict_ends = [20, '1990-01-01', datetime(1990, 1, 1), index[-1]]

    desired = (1, 9, 11)
    for start in predict_starts:
        for end in predict_ends:
            assert_equal(model._get_prediction_index(start, end)[:3], desired)

```

```java
BufferedWriter out = null;  
try {  
    out = new BufferedWriter(new FileWriter(”filename”, true));  
    out.write(”aString”);  
} catch (IOException e) {  
    // error processing code  
} finally {  
    if (out != null) {  
        out.close();  
    }  
}
```

```c++

#include <iostream>
#include <string.h>
#define ll long long
#define max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
ll dirx[8] = {1,1,-1,-1,2,2,-2,-2};
ll diry[8] = {2,-2,2,-2,1,-1,1,-1};
ll dp[80][80];
ll vis[80][80];
int main(int argc, char** argv) {
	int m,n;
	int a,b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	vis[a][b] = 1;
	for(int i = 0; i <= 7; i++)
	{
		if(a+dirx[i] <= n && a+dirx[i] >= 0 && b+diry[i] >= 0&& b + diry[i] <= m)
		vis[a+dirx[i]][b+diry[i]] = 1;
	}	

	for(int i = 0; i <= n; i++)
	{
		if(vis[i][0] == 1) break;
		dp[i][0] = 1;
	}
	for(int i = 0; i <= m; i++)
	{
		if(vis[0][i] == 1) break; 
		dp[0][i] = 1;
	} //如果边上为0 后面边上就一直是0了 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(vis[i][j]) dp[i][j] = 0;
			else
			dp[i][j] = dp[i-1][j] + dp [i][j-1];
		
		}
	
	printf("%lld\n",dp[n][m]);
		
	
	return 0;
}/*
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#define MAXN 110
bool b[MAXN][MAXN];
long long a[MAXN][MAXN];
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x,y;
using namespace std;
int main(){
	cin>>n>>m>>x>>y;
	memset(b,0,sizeof(b));
	b[x][y]=1;
	for(int i=0;i<=7;i++){
		 if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m){
		 	b[x+dx[i]][y+dy[i]]=1;
		 }
	}
	int k=0;
	while(!b[k][0]&&k<=n){
		a[k++][0]=1;
	}
	int l=0;
	while(!b[0][l]&&l<=m){
		a[0][l++]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]){
				a[i][j]=0;  //g[i][j]=1
			}
			else{
				a[i][j]=a[i-1][j]+a[i][j-1];  //i>0且j>0且g[i][j]=0
			}
		}
	}
	cout<<a[n][m];
	return 0;
}*/
```



# **you know i am sad**

**sad**

sad

## **==haha==**

~~bushi~~

*you know fuck*

*==**you are**==*

> hello 
>
> but >

---

***

![==喵喵喵！！==](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fc-ssl.duitang.com%2Fuploads%2Fitem%2F202004%2F21%2F20200421143248_hakrf.thumb.1000_0.jpg&refer=http%3A%2F%2Fc-ssl.duitang.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1630240083&t=3b7f58a009d8283f6813c72798bf0315)

[hello](https://www.bilibili.com/video/BV1hJ411X75X?from=search&seid=9287205727793624875)

- mulu1
- hello
- bastard

1. pig
2. pipi
3. haha

| nihao     | haha | shasha |
| --------- | ---- | ------ |
| ==hsd==   |      | iasjid |
| *hdusa*   |      |        |
| **hshad** |      |        |

# [Markdown快速入门（typora）](https://www.cnblogs.com/liulia/p/14767877.html)



# Markdown快速入门（typora）

## 1、代码块:

~~~java
// 代码块语法
```Java(语言类型)
```shell
~~~

**1.1.java代码块**

```java
public class HelloWorld {
    public static void main(String []args) {
        System.out.println("Hello,World!");
    }
}
```

**1.2.shell脚本代码块**

```shell
# !/bin/bash  # 脚本生成一个 100 以内的随机数,提示用户猜数字,根据用户的输入,提示用户猜对了,
# 猜小了或猜大了,直至用户猜对脚本结束。
# RANDOM 为系统自带的系统变量,值为 0‐32767的随机数
# 使用取余算法将随机数变为 1‐100 的随机数num=$[RANDOM%100+1]echo "$num" 
# 使用 read 提示用户猜数字
# 使用 if 判断用户猜数字的大小关系:‐eq(等于),‐ne(不等于),‐gt(大于),‐ge(大于等于),
# ‐lt(小于),‐le(小于等于)

while :
  do     
    read -p "计算机生成了一个 1‐100 的随机数,你猜: " cai    
    if [ $cai -eq $num ]    
    then        
        echo "恭喜,猜对了"           
        exit        
    elif [ $cai -gt $num ]       
    then            
        echo "Oops,猜大了"         
    else            
        echo "Oops,猜小了"     
    fi
  done
```

## 2、标题：

```java
// 标题语法

# 1级标题
## 2级标题
### 3级标题
#### 4级标题
##### 5级标题
###### 6级标题
    
！**注意：'#'与标题之间需要空格隔开**
```

# 1级标题

## 2级标题

### 3级标题

#### 4级标题

##### 5级标题

###### 6级标题

## 3、字体：

```shell
// 加粗
**你好，世界**

// 代码高亮显示
==Hello,World!==

// 删除线
~~被删除的文字~~

// 斜体
*斜体*
```

// 加粗
**你好，世界**

// 代码高亮显示
Hello,World!

// 删除线
被删除的文字

// 斜体
*斜体*

## 4、引用：

```python
// 引用语法
>作责：爱因斯坦
>>作责：爱因斯坦
>>>作责：爱因斯坦

！！！几个尖括号就代表前面有几条竖线。
```

// 引用语法

> 作责：爱因斯坦
>
> > 作责：爱因斯坦
> >
> > > 作责：爱因斯坦

## 5、分割线：

```scala
// 分割线
方式一：
---

方式二(此分割线相比方式一较粗，效果如下)：
***
```

**5.1.方式一的分割线**

------

**5.2.方式二的分割线**

------

## 6、图片插入：

```java
// 在线图片/本地图片
![图片名称](/dir/.../..) --图片插入方式(路径为：在线图片连接/本地图片绝对路径)
```

![demo](https://www.cnblogs.com/images/logo.svg?v=R9M0WmLAIPVydmdzE2keuvnjl-bPR7_35oHqtiBzGsM)

## 7、超链接：

```python
// 超链接语法
[超链接名称](超链接地址)
```

// 超链接语法

[恒亮的博客园]([恒亮 - 博客园 (cnblogs.com)](https://www.cnblogs.com/liulia/))

## 8、列表：

```python
// 无序列表
- 无序列表1
- 无序列表2
- 无序列表3

// 有序列表
1. 有序列表1
2. 有序列表2
2. 有序列表3

！**注意：列表符和列表名称之间有空格**
```

// 无序列表

- 无序列表1
- 无序列表2
- 无序列表3

// 有序列表

1. 有序列表1
2. 有序列表2
3. 有序列表3

## 9、表格：

```python
右键->插入->表格
```

| 姓名 | 语文 | 数学 |
| ---- | ---- | ---- |
| 张三 | 88   | 99   |
| 李四 | 99   | 100  |

## 10、快捷键：

```python
// 1.Ctrl + Shift + 1(F1下面的按键) => 调出文件及大纲栏

// 2.Ctrl + / => 将编辑笔记转换为Markdown编辑语言
```

![1628059734894](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1628059734894.png)