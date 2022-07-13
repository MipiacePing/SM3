
## 1：SM3 implementation 实现
### 参考
  1.  SM3国家标准：http://c.gb688.cn/bzgk/gb/showGb?type=online&hcno=45B1A67F20F3BF339211C391E9278F5E
  2.  openssl sm3实现：https://github.com/openssl/openssl/search?q=sm3

### 主要实现特点
  1.  使用了大量宏函数，减少传统函数调用，但是没有openssl那么极端，比较易读
  2.  最外层使用C++ string作为接口，比较方便
  3.  注释全

### 文件说明

1. main.cpp    处理输入，可以去掉注释，cin一个string

2. mysm3.h     头文件，也包括一些宏函数

3. mysm3.cpp   SM3的主要流程函数

4. CMakeLists.txt  随便写的，比较简单，但能用

5. build/      为了cmake单独搞的一个文件夹，放一些make文件，没什么现实作用

   

### 运行说明：

- 代码环境是Windows WSL，因此用的是g++，生成的是Linux ELF可执行文件
- 在SM3_implementation 目录下，直接make就可以得到SM3可执行文件