
#include "mysm3.h"

int main(int argc, char* argv[])
{
    unsigned char output[SM3_OUTLEN];
    string input_str = "Hello World";
    //getline(cin,input); //使用getline获取输入（字符串格式），防止cin遇到空格被打断；
    //cout<<"Message: "<<input<<endl;
    unsigned char* input = (unsigned char*)input_str.c_str();
    SM3(input,input_str.length(),output);
    cout << "Hash:" << endl;
    for (int i = 0; i < 32; i++)
    {
        printf("%02x", output[i]); //注意要填充0,
    }
    printf("\n");
}