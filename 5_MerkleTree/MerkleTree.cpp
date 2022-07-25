/************************************************************************
 文件名: MerklrTree.cpp
 日期：2022/7/15
 作者：zzp
 描述：MerklrTree类函数的具体定义
**************************************************************************/
#include"MerkleTree.h"

// 无参数构造函数
MerkleTree::MerkleTree()
{
    ROOT = INSERT = NULL;
    leafnum = 0;
}
// 带参数构造函数，直接传入data指针，本质就是调用了update
MerkleTree::MerkleTree(const uchar* data, int len)
{
    ROOT = INSERT = NULL;
    leafnum = 0;
    update_data(data, len);
}
//析构函数,删除指针
MerkleTree::~MerkleTree()
{
    delete ROOT;
    delete INSERT;
}

/**
 * 中序遍历,然后树形打印
 * @param root 根节点
 * @return 中序遍历节点数组
 */
void MerkleTree::print_merkletree() //中序遍历后树状打印
{
    vector<Node*> res;
    stack<Node*> st;
    Node* cur = ROOT;
    while (cur != NULL || st.size())
    {
        while (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        res.push_back(cur);
        cur = cur->right;
    }

    auto tmp = ROOT;
    string template_str; //模板string，表示每行打印string的长度
    int location = 0;
    std::unordered_map<Node*, int> first_locations;//存储节点对应在本行string中的首位置
    for (auto& i : res) {
        location = template_str.size();
        template_str += to_string(*(uint*)i->hash) + "...";
        first_locations[i] = location;
    }
    for (auto& i : template_str)i = ' ';//把模板全部置为空格方便后续使用
    //层序遍历
    std::queue<Node*> q;
    q.push(ROOT);
    while (q.size())
    {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        std::string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            cur_loc = first_locations[node];
            std::string num_str = to_string(*(uint*)node->hash & 0xffff) + "...";
            if (node->left) {
                q.push(node->left);
                int first_loc = first_locations[node->left] + 1;
                tmp_str2[first_loc++] = '/';
                while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';
            }
            //中间,对应位置打印节点值（有可能为多位数）
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
            if (node->right) {
                q.push(node->right);
                int last_loc = first_locations[node->right] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //打印两行
        std::cout << tmp_str1 << std::endl;
        std::cout << tmp_str2 << std::endl;
    }
}

/**
 * 将data的信息更新到当前二叉树上
 * @param data 任意大小数据块指针
 * @call    insert
 */
void MerkleTree::update_data(const uchar* data, int len)
{
    int tmp = 0;
    int bytelen = BLOCK_SIZE;
    while (len > 0)
    {
        Node* newnode = new Node;
        if (len < BLOCK_SIZE)
        {
            bytelen = len & (BLOCK_SIZE - 1);
        }
        SM3((uchar*)data + tmp, bytelen, newnode->hash);
        insert(newnode);    //借助另一个函数，比较简洁
        tmp += BLOCK_SIZE;
        len -= BLOCK_SIZE;
    }
}

/**
 * 将新节点插入到当前二叉树中
 * @param  newnode 新节点指针
 * @caller update_date
 * @call   forward_update
 */
void MerkleTree::insert(Node* newnode)
{
#ifdef DEBUG
    cout << "Insert block's hash:" << endl;
    print_Hashvalue(newnode->hash, SM3_OUTLEN);
    cout << endl;
#endif // DEBUG

    if (leafnum == 0)
    {
        ROOT = INSERT = newnode;
    }
    else {
        Node* tmpnode = new Node;
        //将两个节点的HASH值合并求HASH，这里的hash运算用的是自己写的，如果速度不够，记得改成openssl的
        uchar input[SM3_OUTLEN * 2];
        memcpy(input, INSERT->hash, SM3_OUTLEN);
        memcpy(input + SM3_OUTLEN, newnode->hash, SM3_OUTLEN);

        SM3(input, SM3_OUTLEN * 2, tmpnode->hash);
        if (INSERT->father == NULL)  //此时只有一个ROOT
        {
            //插入一定会多出一个小二叉树结构，设置该结构内的父子节点
            INSERT->father = newnode->father = tmpnode;
            tmpnode->left = INSERT;
            tmpnode->right = newnode;

            //注意此时的INSERT不用改变
            INSERT->bro = newnode;
            ROOT = tmpnode;
        }
        else {                      //此时至少有一个二叉树结构
           //修改上对下的左右孩子指针，指向新建立的tmpnode   
            if (INSERT->father != NULL)
            {
                if (INSERT == INSERT->father->left)
                    INSERT->father->left = tmpnode;
                else
                    INSERT->father->right = tmpnode;

                tmpnode->father = INSERT->father;
            }

            INSERT->father = newnode->father = tmpnode;
            tmpnode->left = INSERT;
            tmpnode->right = newnode;

            newnode->bro = INSERT->bro; //设置兄弟指针，主要是为了确定下一个被插入的叶子节点
            INSERT->bro = newnode;
            INSERT = newnode->bro;
            //如果设置完指针后发现下一个被插入的是NULL，那么说明到达了本层的最右，此时应该是一棵完全平衡二叉树
            if (INSERT == NULL)
            {
                INSERT = ROOT;
                while (INSERT->left != NULL)
                    INSERT = INSERT->left;
            }
        }
        forward_update(newnode->father);    //只有一个ROOT的时候就不用更新了，要不然会传过去NULL
    }
    leafnum++;
#ifdef DEBUG
    cout << "Insert No." << leafnum - 1 << " node, print MerkleTree:" << endl;
    print_merkletree();
    cout << endl;
#endif // DEBUG
}

/**
 * 新节点插入到当前二叉树后，向前更新二叉树的值
 * @param  insert_node 插入的节点
 * @caller insert
 */
void MerkleTree::forward_update(Node* insert_node)
{
    while (insert_node != ROOT)
    {
        Node* tmp;
        uchar input[SM3_OUTLEN * 2];
        if (insert_node == insert_node->father->left)
        {
            tmp = insert_node->father->right;
            memcpy(input, insert_node->hash, SM3_OUTLEN);
            memcpy(input + SM3_OUTLEN, tmp->hash, SM3_OUTLEN);
        }
        else {
            tmp = insert_node->father->left;
            memcpy(input, tmp->hash, SM3_OUTLEN);
            memcpy(input + SM3_OUTLEN, insert_node->hash, SM3_OUTLEN);
        }
        insert_node = insert_node->father;
        SM3(input, SM3_OUTLEN * 2, insert_node->hash);
    }
}

/*
    获取某个hash值的验证路径
*/
vector<Node*> MerkleTree::get_verify_path(uchar hashvalue[SM3_OUTLEN])
{
    vector<Node*> path;
    Node* tmp = ROOT;
    while (tmp->left != NULL)
    {
        tmp = tmp->left;      //利用bro指针，直接向右遍历寻找
    }
    while (true)
    {
        if (!memcmp(tmp->hash, hashvalue, SM3_OUTLEN)) //如果相等会返回0
            break;
        if (tmp->bro == NULL)
        {
            //cout<<"The hash isn't in the MerkleTree"<<endl;
            return path;  //返回空的vector
        }
        tmp = tmp->bro;
    }
    //如果运行至此，说明此时的tmp就是我们要验证的node
    path.push_back(tmp);
    while (tmp->father != NULL)
    {
        if (tmp == tmp->father->left)
        {
            path.push_back(tmp->father->right);
        }
        else {
            path.push_back(tmp->father->left);
        }
        tmp = tmp->father;
    }
    return path;
}

/*
    验证某个Block的数据在不在MerkleTree中
*/
int MerkleTree::verify(const uchar block[BLOCK_SIZE])
{
    uchar hashvalue[SM3_OUTLEN];
    SM3((uchar*)block, BLOCK_SIZE, hashvalue);
#ifdef DEBUG
    cout << "verify's hash:" << endl;
    print_Hashvalue(hashvalue, SM3_OUTLEN);
    cout << endl;
#endif // DEBUG

    if (leafnum == 1)
    {
        if (!memcmp(ROOT->hash, hashvalue, SM3_OUTLEN))
            return 0;
        else
            return 1;
    }
    vector<Node*> path = get_verify_path(hashvalue);
    if (path.empty())    //如果是个空的，说明没有找到对应，节点，节点不存在，返回1
    {
        return 1;
    }
    Node* verify_node = path[0];
    uchar input[SM3_OUTLEN * 2];
    uchar output[SM3_OUTLEN];
    for (int i = 1; i < path.size(); i++)
    {
        if (verify_node == verify_node->father->left) //要区分左右子树，因为拼接的时候会有不同。
        {
            memcpy(input, verify_node->hash, SM3_OUTLEN);
            memcpy(input + SM3_OUTLEN, path[i]->hash, SM3_OUTLEN);

        }
        else {
            memcpy(input, path[i]->hash, SM3_OUTLEN);
            memcpy(input + SM3_OUTLEN, verify_node->hash, SM3_OUTLEN);
        }
        SM3(input, SM3_OUTLEN * 2, output);
#ifdef DEBUG
        cout << "SM3 input:" << endl;
        print_Hashvalue(input, SM3_OUTLEN * 2);

        print_Hashvalue(verify_node->father->hash, SM3_OUTLEN);

        print_Hashvalue(output, SM3_OUTLEN);
#endif // DEBUG
        //犯蠢了，之前在if的括号后加了分号，导致语句失效，固定return 1，艹
        if (memcmp(verify_node->father->hash, output, (int)SM3_OUTLEN / 2))
            return 1;
        verify_node = verify_node->father;
    }
    if (verify_node == ROOT)
        return 0;
    else
        return 1;
}