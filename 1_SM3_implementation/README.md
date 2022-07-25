## 项目说明

✅Project: **implement**  and try to optimize SM3

​	最快可以对64byte数据，**1s做170w+ 次SM3计算**



## 运行说明

**开发环境**：Windows WSL（Ubuntu18.04）

**默认执行环境**：Linux/Windows

**运行方式：**

- linux：`$: ./SM3`  
- Windows：双击exe文件



## 主要文件说明：

- main.cpp	速度测试、也支持手动输入string串进行SM3压缩

- mysm3.h    算法实现过程的各种宏定义和函数声明

- mysm3cpp SM3算法函数定义

- Makefile     CMake生成，linux下可以编译出ELF可执行文件

- SM3             ELF可执行文件，O2优化，速度最快，对64byte数据，可以做170w+/s SM3运算

- SM3_x64_release.exe  PE可执行文件，速度较快的一种，对64byte数据，可以做150w+/s SM3运算

- SM3_x64_release.exe  PE可执行文件，速度最慢，对64byte数据，可以做120w+/s SM3运算

  

## SM3 implementation 实现

### 参考
  1.  SM3国家标准：http://c.gb688.cn/bzgk/gb/showGb?type=online&hcno=45B1A67F20F3BF339211C391E9278F5E
  2.  openssl sm3实现：https://github.com/openssl/openssl/search?q=sm3

### 主要实现特点
  1.  使用了宏函数，减少传统函数调用，但是没有openssl那么极端，比较易读
  2.  最外层使用C++ string作为接口，比较方便
  3.  纯手写，注释全



## 运行截图：

