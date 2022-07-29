## 项目说明 -- SM3 Rho环路攻击

✅Project: implement the  **birthday** **attack** of reduced SM3

​	可以对**前24bit**进行Rho环路攻击



## 运行说明

**开发环境**：Windows WSL（Ubuntu18.04）

**默认执行环境**：Linux

**代码引用：**  无

**运行方式：**

- linux：`$: ./a.out`  



## 文件说明

- main.cpp	主要函数，通过产生随机数字，作为字符串string计算hash值，然后通过Pollard_Rho方法，找到碰撞原像，碰撞的bit长度通过全局变量定义
- Makefile     O2优化，因为初始是随机数的原因，也比较看运气，一般不会超过20s



## 运行截图：

<img src="https://user-images.githubusercontent.com/105496872/180821011-9006fd42-2888-4c24-b3c6-f7f7592f9f40.png" width="500" height="225"/>


## SM3 Rho环路攻击原理

<img src="https://user-images.githubusercontent.com/105496872/180820806-9caab990-d38a-4658-84cc-072ea8c34006.png" width="430" height="100"/>

​	原理很简单，我们只需要从一个初始值出发，不断计算SM3值，就可能成环（前n bit），在代码中可以参考Floyd判环法：

```c++
代码简述：
x=rand()
h1 = SM3(x)
h2 = SM3(h1)
while(true)
    h1=SM3(h1)
    h2=SM3(SM3(h2)) //计算两次，因为如果成环，那么两倍速一定能追上一倍速的
    if h1 == h2:
        break
```

​		
