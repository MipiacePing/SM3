## 4_SM3_LenExtenAttack



**Attack Outline:**

- if you konw Hash(M) for unknown message where $M = M1||padding$ (M is after padding)
- we can get $Hash(M') = Hash(M1||padding||M3)$  for any block M3



**Code implementation:**

- 对任意M1，先得到padding后的字节串 $M = M1||padding$，然后计算$H=SM3(M)$，
- 对任意M3，计算$SM3(M||M3)$和 $H' = SM3(M3)$ where $IV_0 = H$，是否相等。



**注意事项：**

​		计算$H' = SM3(M3)$ where $IV_0 = H$ 的时候，注意此时的状态，不仅要修改IV，还要将已压缩的字节置成正确的值，也就是要计算，$M1||padding$的长度，最后对M3的padding，len也是算上前面的len，极易出错，相当恶心。