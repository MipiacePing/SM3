## 3:	SM3 Rho环路攻击

![image-20220713150915829](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220713150915829.png)

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

### 代码说明：

​		linux下直接make 然后./a.out，经过测试，24bit很容易跑出来，但是跟初始随机数关系很大，有时候几秒钟，有时候要几分钟，32bit很难跑出来。因为使用的memcmp函数作比较，因此只能以字节（8bit）为基本单位。

​		