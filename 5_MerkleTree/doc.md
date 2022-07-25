## 项目说明

在SM3代码库中

✅Project: implement Merkle Tree following RFC6962

​	

## 运行说明

**开发环境**：Windows WSL（Ubuntu18.04）

**默认执行环境**：Linux/Windows

**运行方式：**在linux下，直接运行build/中的MerkleTree可执行文件，build/中也有VS编译的exe文件

`$: ./build/MerkleTree`  或 双击 MerkleTree_vs.exe



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



## 代码运行过程：

- **示例文件：**MerkleTree_debug.exe

- **环境：（Windows VS）**

- **参数说明**：减少了banchsize，添加了DEBUG的宏，方便打印东西

  

- **运行截图1：**

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220725181702715.png" alt="image-20220725181702715" style="zoom:60%;" />

- **截图解释**：

​		开头打印出了一些基本代码信息，包括预设的数据块大小，测试的数据块个数等，随后main函数调用randtest函数，随机生成数字充当我们的测试数据，随后new一个MerklTree类对象，动态建立MerkleTree，图中可以明显看出更新的方式，是**所有的叶子节点从左向右接收新节点**。



- **运行截图2：**

  <img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220725182103910.png" alt="image-20220725182103910" style="zoom:67%;" />

- **截图解释：**

  插入全部8个节点（编号0-7）后，打印完全形态的二叉树



- **运行截图3：**

  <img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220725212540490.png" alt="image-20220725212540490" style="zoom:60%;" />

- **截图解释：**

  主要看验证部分，我们验证了一下Block[4]，先遍历叶节点，确定Block[4]的hash在不在叶节点中，如果在的话，再调用函数获得他的验证路径，RFC6962中有对验证路径的说明。

  然后再修改一下Block[4]的数据，将其前一半置0，然后再去verify一下，可以在截图中看到，这次的验证是Failure！

  

## 原理：

​	Merkle树看起来非常像二叉树，其叶子节点上的值通常为数据块的哈希值，而非叶子节点上的值
![image](https://user-images.githubusercontent.com/105496872/179976862-411d5082-dad5-4862-9b46-555cf8711c08.png)



​	在构造Merkle树时，首先要对数据块计算哈希值，通常，选用SHA-256等哈希算法。但如果仅仅防止数据不是蓄意的损坏或篡改，可以改用一些安全性低但效率高的校验和算法，如CRC。然后将数据块计算的哈希值两两配对（如果是奇数个数，最后一个自己与自己配对），计算上一层哈希，再重复这个步骤，一直到计算出根哈希值。



### Hash List

​		在点对点网络中作数据传输的时候，会同时从多个机器上下载数据，为了校验数据的完整性，更好的办法是把大的文件分割成小的数据块（例如，把分割成2K为单位的数据块）。如果小块数据在传输过程中损坏了，那么只要重新下载这一快数据就行了，不用重新下载整个文件。

​		BT下载的时候，在下载真正数据之前，我们会先下载一个Hash List。同时，我们把每个小块数据的Hash值拼到一起，然后对这个长字符串再作一次Hash运算，这样就得到Hash列表的根Hash(Top Hash or Root Hash)。下载数据的时候，首先从可信的数据源得到正确的根Hash，使用root hash校验hash list 然后使用hash list 校验数据块。



![image-20220723223342965](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220723223342965.png)



### Merkle Tree

​		merkle tree 是一种泛化的hash list，hash list 可以看做树高为2的多叉merkle tree。有n个数据块，计算所有数据块hash值，然后相邻hash值再合并计算hash，直到计算到根hash，这样树高就为log(n)。

​		merkle tree的检索也就是对树的二分查找，时间是O(logn)，merkle tree的更新、插入和删除没有同一的标准，根据使用场景的不同，可以设计灵活的方法，既可以使用一些平衡树的方法（AVL树、红黑树等）也可以强行加树高，这在不同的场景下会有不同的应用。
