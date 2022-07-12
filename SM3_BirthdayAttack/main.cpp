#include "BirthdayAttack.h"
#define F(x,c) (x*x)
int Collisionlen = 16;

int Pollard_Rho(uint image,unsigned char* H,uint c,uint* preiamge) //H = SM3(image) 
{
    uint m1 = rand();
    uint m2 = m1;
    while(true)
    {
        m1 = F(m1,c);
        m2 = F(F(m2,c),c);
        if(m2==m1)
            return 1;
        uint tmp = m2-m1;
        string input = to_string(tmp).c_str();
        unsigned char output[SM3_OUTLEN];
        SM3_str(input,output);
        if(!memcmp(H,output,Collisionlen/8) && tmp!=image)
        {
            *preiamge = tmp;
            cout << "SM3("<<input<<"):";
            print_Hashvalue(output,SM3_OUTLEN);
            return 0;
        }
    }
}
void  PreimageAttack(uint image)
{
    uint preimage;
    string image_input=to_string(image);
    unsigned char image_output[SM3_OUTLEN];
    SM3_str(image_input,image_output);
    SM3((unsigned char*)image_input.c_str(),4,image_output);
    cout << "SM3("<<image_input<<"):";
    print_Hashvalue(image_output,SM3_OUTLEN);

    uint c = rand();
    while(Pollard_Rho(image,image_output,c,&preimage))
    {
        c = rand();
    }
    cout<<"通过生日攻击，找到原像："<<image<<"的一个碰撞"<<preimage<<"，哈希值的前"<<Collisionlen<<"bit相同"<<endl;
}

int main()
{
    // //生成一个随机数寻找一个原像，因为int 32bit，所以Hash的前16bit一定存在碰撞
    // cout<<"输入要碰撞的比特位数（8的倍数,请不要大于32,默认16bit）"<<endl;
    // cin>>Collisionlen;
    // if(Collisionlen&0b111)
    //     Collisionlen = 16;
    srand(time(NULL));
    unsigned int image = rand();
    PreimageAttack(image);
    return 0;
}
