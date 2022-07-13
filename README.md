# SM3

包含多个文件夹，有SM3实现，SM3生日攻击BirthdayAttack，SM3长度拓展攻击Length extension attack，SM3的Rho攻击


## 1：SM3 implementation 实现
### 参考
  1.  SM3国家标准：http://c.gb688.cn/bzgk/gb/showGb?type=online&hcno=45B1A67F20F3BF339211C391E9278F5E
  2.  openssl sm3实现：https://github.com/openssl/openssl/search?q=sm3

### 主要实现特点
  1.  使用了大量宏函数，减少传统函数调用，但是没有openssl那么极端，比较易读
  2.  最外层使用C++ string作为接口，比较方便
  3.  注释全
    4.  


## 2：SM3生日攻击BirthdayAttack

#### 利用生日攻击找n比特碰撞的原像

​		对于任意消息（这里只考虑数字字符串，其他字符串也可以转化到数字字符串）M，我们计算H=SM3(M)，如果我们只考虑前n比特（下文中的相等都是指前n比特），那么在前$0-2^{n}$范围内，至少存在一组碰撞的概率几乎是100%。

​		那么对于特定的消息M，如何利用生日攻击去找到这个碰撞像呢？

​		我们可以任取两个消息m1，m2，计算h=SM3(abs(M1-M2)，直到得到H= h

**算差的原因：**

​		假设存在M‘，有SM3(M)=SM3(M')，那么我们在前$2^n$比特范围内找到M'的概率是$\frac{1}{2^n}$，但是我们找两个数m1和m2，满足m1-m2 = M’的概率则是$\frac{C^2_{2^n}}{2^n}$，比如M‘ = 1234，那么1235-1=1234，,1236-2=1234,...总共有$C^2_{2^n}$组。这个比较类似素数检测中的Poll_rho算法。



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