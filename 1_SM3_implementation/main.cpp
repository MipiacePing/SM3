
#include "mysm3.h"



int main(int argc, char* argv[])
{
    string input_str = "Hello World";
    SM3(input_str);

    getline(cin,input_str); //使用getline获取输入（字符串格式），防止cin遇到空格被打断；
    SM3(input_str);

    printf("\n");
}