## AUC & ROC

![1629602650166](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629602650166.png)

（真阳性率） = 正确判断阳性/(正确判断阳性 + 错误判断为阴性 （实则为阳性、即漏诊、过于松弛）)   缺陷：当你全部诊断为阳性时真阳性率为1（忽略了）

![1629603859102](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629603859102.png)

假阳性率 = 错误判断为阳性（误诊、过于严苛，实则为阴性）/ (错误判断为阳性 + 正确判断为阴性)【即全部的阴性】    【误诊的阴性/全部的阴性】

![1629616479535](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629616479535.png)

![1629616509818](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629616509818.png)

![1629616520208](C:\Users\cyw\AppData\Roaming\Typora\typora-user-images\1629616520208.png)

==**对于同一个样本的每一个类别， 都可以和其他类划分开来，化为二分类问题，分别求出每个类别对应的roc曲线，求取每个auc值，可做进一步处理**==

