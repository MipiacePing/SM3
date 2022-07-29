## 项目说明

✅Project: implement **MerkleTree** following RFC6962

​	

## 运行说明

**开发环境**：Windows WSL（Ubuntu18.04）

**默认执行环境**：Linux/Windows

**代码引用：** 无

**运行方式：**

- **linux:**        `$: ./build/MerkleTree`  
- **whindows:**  双击 ./build/*.exe



## 文件说明

- build/ 	里面有Makefile和可执行文件；
- build/MerkleTree  ELF可执行文件，linux下执行；
- build/MerkleTree_vs.exe  PE可执行文件，数据量比较大的时候测试；
- build/MerkleTree_debug.exe  PE可执行文件，测试量小可以看到很多打印信息；

- main.cpp	函数中有测试代码，可以调整测试的数据量，数据量较小时，可以将MerkleTree.h中的`#define DEBUG`解除注释，可以看到完整的代码流程；
- MerkleTree.h    MerkleTree的类声明；
- MerkleTree.cpp    MerkleTree的类函数定义；
- mySM3.h    使用的之前写的SM3作为hash函数；
- mySM3.cpp     使用的之前写的SM3作为hash函数



## 完整REAME（附截图）

https://github.com/MipiacePing/SM3/blob/master/5_MerkleTree/README.pdf