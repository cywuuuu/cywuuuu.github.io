### **使用样例**

导出中断处理程序，命令如下：

```
java -jar E:\Mars4_5.jar a db mc CompactDataAtZero dump 0x00004180-0x00004ffc HexText E:\code_handler.txt E:\source.txt
```

解析：

- `E:\Mars4_5.jar` 是 MARS 的文件路径

- `a db mc CompactDataAtZero dump` 这些参数的功能请自行查阅帮助文档

- `0x00004180-0x00004ffc` 是需要导出的地址范围

- `HexText` 表示导出的是 16 进制码

- `E:\code_handler.txt` 是 16 进制码输出文件路径

- `E:\source.txt` 是源文件路径

同学们请根据自己文件路径和需要将上述部分根据自己的情况进行更改，如果想进一步了解 Mars 的命令行操作，请参考 MARS 官方文档中 MARS -> Command 部分。如果同学们有兴趣可以尝试编写 bat 脚本文件，免去每次导出都要敲一串命令行指令的痛苦，这部分留作自学内容，请大家自行上网搜集资料进行学习。

### 编写.bat脚本

