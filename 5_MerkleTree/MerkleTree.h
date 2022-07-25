/************************************************************************
 文件名: MerklrTree.h
 日期：2022/7/15 
 作者：zzp
 描述：文件包含MerklrTree的类描述，类函数中有构建、添加、删除、验证数据块是否存在等函数接口
**************************************************************************/
#pragma once
#include "mysm3.h"
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<string>
//一个data block大小为256byte，这个值越小，block越多，树也越深，最好可以根据总的数据量，动态调整
#define BLOCK_SIZE 1024  

//#define DEBUG 1 

// MerkleTree的节点结构体，因为不知道树有多大，所以这里用链表
struct Node
{
    uchar hash[SM3_OUTLEN];
    Node* left;     //左孩子
    Node* right;    //右孩子
    Node* father;   //父指针
    Node* bro;      //兄弟指针
    Node(){         //构造函数，new的时候直接赋初始值
        left = right = father = bro = NULL; 
    }
};


class MerkleTree
{
private:
    Node* ROOT;         //树根
    int leafnum;        //叶子节点总数
    Node* INSERT;       //记录当前MerkleTree可以插入新node的位置
public:
    MerkleTree();
    MerkleTree(const uchar* data, int len);
    ~MerkleTree();

    void update_data(const uchar* datablock,int len);  
    void insert(Node* newnode);
    void forward_update(Node* insert_node);
    int verify(const uchar block[BLOCK_SIZE]); 
    void print_merkletree();
    vector<Node*> get_verify_path(uchar hashvalue[SM3_OUTLEN]);
};

