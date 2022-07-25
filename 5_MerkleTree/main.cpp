#include "MerkleTree.h"
#include<random>
#include<time.h>
using namespace std;

#define BanchSize 1000000  //测试的block的数量，每个block的大小都有定义,总数据量：BanchSize*BLOCK_SIZE
//#define PRINT 1

void verify(MerkleTree* MKT, uchar data[BLOCK_SIZE])
{
    if (MKT->verify(data))
    {
        cout << "Failure! This datacblock isn't in the MerkleTree" << endl;
    }else {
        cout << "Success! This datacblock is in the MerkleTree" << endl;
    }
}

void randomtest()
{
    cout << "\tMerkleTree written by zzp" << endl << endl;;
    cout << "Data Block Size = " <<BLOCK_SIZE<<" byte"<< endl;
    cout << "Banch Size Size = " << BanchSize << endl;
    cout << (BLOCK_SIZE* BanchSize)/(1024*1024) << "M byte data in total" << endl;
    cout << "Set DEBUG can print the whole MerkleTree(adjust in a small banchsize <=8)" << endl<<endl;
    if(BLOCK_SIZE%4!=0)
    {
        cout<<"BLOCK_SIZE必须是4的倍数"<<endl;
        exit(1);
    }
    MerkleTree* MKT = new MerkleTree; 

    uchar** banchpointer;
    banchpointer = (uchar**)malloc(sizeof(uchar*)*BanchSize);
    for(int i=0;i<BanchSize;i++)
    {  
        banchpointer[i] = (uchar*)malloc(BLOCK_SIZE);
        uint* tmp =(uint*)banchpointer[i];
        for(int j=0;j<BLOCK_SIZE/4;j++) //这里需要BLOCK_SIZE是4的倍数
        {
            tmp[j] = pow(rand(),2);   //直接用int填充
            //cout << tmp[j] << endl;
        }
    }
    for(int i=0;i<BanchSize;i++)
    {
        MKT->update_data(banchpointer[i],BLOCK_SIZE);   //把每个block都update到hash tree中
    }
    uchar verifydata[BLOCK_SIZE];
    int index = (int)BanchSize / 2;
#ifdef PRINT
    cout << "Print MerkleTree: " << endl;
    MKT->print_merkletree();
#endif // DEBUG
    
    memcpy(verifydata,banchpointer[index],BLOCK_SIZE);
    cout << "verify Block["<<index<<"]" << endl;
    verify(MKT,verifydata);
    cout << endl;
    cout << "memset Block["<<index<<"][0] - Block[" << index << "]["<< (int)BLOCK_SIZE / 2<<"] = 0,and verify:" << endl;
    memset(verifydata,0,(int)BLOCK_SIZE/2);
    verify(MKT,verifydata);
}



int main()
{
    srand(time(NULL));
    clock_t start, end;//定义clock_t变量
    start = clock();  //开始时间
    randomtest();
    end = clock();   //结束时间
    cout <<endl<< "Build a MerkleTree including " << BanchSize << " blocks and verify two blocks costs "
         << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}