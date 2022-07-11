# SM3

包含多个文件夹，有SM3实现，SM3生日攻击BirthdayAttack，SM3长度拓展攻击Length extension attack，SM3的Rho攻击


## 1：SM3 实现
### 参考
  1.  SM3国家标准：http://c.gb688.cn/bzgk/gb/showGb?type=online&hcno=45B1A67F20F3BF339211C391E9278F5E
  2.  openssl sm3实现：https://github.com/openssl/openssl/search?q=sm3

### 主要实现特点
  1.  使用了大量宏函数，减少传统函数调用，但是没有openssl那么极端，比较易读
  2.  最外层使用C++ string作为接口，比较方便
  3.  注释全


## 2：SM3生日攻击BirthdayAttack

