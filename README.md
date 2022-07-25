# SM3

**对应仓库：**https://github.com/MipiacePing/SM3

- ✅Project: **implement**  and try to optimize SM3
- ✅Project: implement the  **birthday** **attack** of reduced SM3
- ✅Project: implement the **Rho** method of reduced SM3
- ✅Project: implement **length extension attack** for SM3
- ✅Project: implement **MerkleTree** following RFC6962



## 3:	SM3 Rho环路攻击

![image](img src="https://user-images.githubusercontent.com/105496872/178673803-84228df7-2e3b-4035-a780-5f0d13ddaeaf.png" style="zoom:40%;")


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



**result：**

​	**24bit**的碰撞，随机数的影响还是比较大的，有些跑不出来，有些很快

![image](https://user-images.githubusercontent.com/105496872/178882731-9669b3e9-469c-4990-960c-0b2505310462.png)






## 4_SM3_LenExtenAttack



**Attack Outline:**

- if you konw Hash(M) for unknown message where $M = M1||padding$ (M is after padding)
- we can get $Hash(M') = Hash(M1||padding||M3)$  for any block M3



**Code implementation:**

- 对任意M1，先得到padding后的字节串 $M = M1||padding$，然后计算$H=SM3(M)$，
- 对任意M3，计算$SM3(M||M3)$和 $H' = SM3(M3)$ where $IV_0 = H$，是否相等。
- result：

**result**

![image](https://user-images.githubusercontent.com/105496872/178882908-845e381f-7df6-4163-9bfe-10e2a9b98b1b.png)


