## SM3 from openssl



openssl中，有关SM3的实现是套用了Hash函数的模板，即MD结构的函数，使用宏函数来减少函数调用。

其中有关SM3的个性函数都在sm3local.h中给了声明

