## 项目说明 -- SM3_LenExtenAttack长度拓展攻击

✅Project: implement **length extension attack** for SM3

​	手动填充比特，调用自己写的接口也比较熟悉，长度拓展攻击还是比较容易的



## 运行说明

**开发环境**：Windows WSL（Ubuntu18.04）

**默认执行环境**：Linux

**代码引用：** 无

**运行方式：**

- linux：`$: ./a.out`  



## 文件说明

- main.cpp	主要函数，传入原始消息的Hash值，和其长度(如果不能确定原始消息长度，那么请先想办法获取)，然后传入拓展部分的M3，计算出SM3(M||padding||M3)的值，最后会打印出两个Hash值，可以看到完全一致。
- Makefile     O2优化



## 运行截图：

<img src="https://user-images.githubusercontent.com/105496872/180826064-c2a27034-2b74-45bb-8c51-383f656be07f.png" width="600" height="200"/>



## SM3_LenExtenAttack原理


**Attack Outline:**

- if you konw Hash(M) for unknown message where $M = M1||padding$ (M is after padding)
- we can get $Hash(M') = Hash(M1||padding||M3)$  for any block M3


**Code implementation:**

- 对任意M1，先得到padding后的字节串 $M = M1||padding$，然后计算$H=SM3(M)$，
- 对任意M3，计算$SM3(M||M3)$和 $H' = SM3(M3)$ where $IV_0 = H$，是否相等。


**注意事项：**

​		计算$H' = SM3(M3)$ where $IV_0 = H$ 的时候，注意此时的状态，不仅要修改IV，还要将已压缩的字节置成正确的值，也就是要计算，$M1||padding$的长度，最后对M3的padding，**len也是算上前面的len**，极易出错，相当恶心。
