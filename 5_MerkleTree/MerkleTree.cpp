/************************************************************************
 �ļ���: MerklrTree.cpp
 ���ڣ�2022/7/15
 ���ߣ�zzp
 ������MerklrTree�ຯ���ľ��嶨��
**************************************************************************/
#include"MerkleTree.h"

// �޲������캯��
MerkleTree::MerkleTree()
{
    ROOT = INSERT = NULL;
    leafnum = 0;
}
// ���������캯����ֱ�Ӵ���dataָ�룬���ʾ��ǵ�����update
MerkleTree::MerkleTree(const uchar* data, int len)
{
    ROOT = INSERT = NULL;
    leafnum = 0;
    update_data(data, len);
}
//��������,ɾ��ָ��
MerkleTree::~MerkleTree()
{
    delete ROOT;
    delete INSERT;
}

/**
 * �������,Ȼ�����δ�ӡ
 * @param root ���ڵ�
 * @return ��������ڵ�����
 */
void MerkleTree::print_merkletree() //�����������״��ӡ
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
    string template_str; //ģ��string����ʾÿ�д�ӡstring�ĳ���
    int location = 0;
    std::unordered_map<Node*, int> first_locations;//�洢�ڵ��Ӧ�ڱ���string�е���λ��
    for (auto& i : res) {
        location = template_str.size();
        template_str += to_string(*(uint*)i->hash) + "...";
        first_locations[i] = location;
    }
    for (auto& i : template_str)i = ' ';//��ģ��ȫ����Ϊ�ո񷽱����ʹ��
    //�������
    std::queue<Node*> q;
    q.push(ROOT);
    while (q.size())
    {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        std::string tmp_str1 = template_str, tmp_str2 = template_str;//1Ϊ�ڵ������У�2Ϊ����һ��
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
            //�м�,��Ӧλ�ô�ӡ�ڵ�ֵ���п���Ϊ��λ����
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //�ұߣ���������Һ��ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'\'���ڵ�һ�в���'_'
            if (node->right) {
                q.push(node->right);
                int last_loc = first_locations[node->right] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //��ӡ����
        std::cout << tmp_str1 << std::endl;
        std::cout << tmp_str2 << std::endl;
    }
}

/**
 * ��data����Ϣ���µ���ǰ��������
 * @param data �����С���ݿ�ָ��
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
        insert(newnode);    //������һ���������Ƚϼ��
        tmp += BLOCK_SIZE;
        len -= BLOCK_SIZE;
    }
}

/**
 * ���½ڵ���뵽��ǰ��������
 * @param  newnode �½ڵ�ָ��
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
        //�������ڵ��HASHֵ�ϲ���HASH�������hash�����õ����Լ�д�ģ�����ٶȲ������ǵøĳ�openssl��
        uchar input[SM3_OUTLEN * 2];
        memcpy(input, INSERT->hash, SM3_OUTLEN);
        memcpy(input + SM3_OUTLEN, newnode->hash, SM3_OUTLEN);

        SM3(input, SM3_OUTLEN * 2, tmpnode->hash);
        if (INSERT->father == NULL)  //��ʱֻ��һ��ROOT
        {
            //����һ������һ��С�������ṹ�����øýṹ�ڵĸ��ӽڵ�
            INSERT->father = newnode->father = tmpnode;
            tmpnode->left = INSERT;
            tmpnode->right = newnode;

            //ע���ʱ��INSERT���øı�
            INSERT->bro = newnode;
            ROOT = tmpnode;
        }
        else {                      //��ʱ������һ���������ṹ
           //�޸��϶��µ����Һ���ָ�룬ָ���½�����tmpnode   
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

            newnode->bro = INSERT->bro; //�����ֵ�ָ�룬��Ҫ��Ϊ��ȷ����һ���������Ҷ�ӽڵ�
            INSERT->bro = newnode;
            INSERT = newnode->bro;
            //���������ָ�������һ�����������NULL����ô˵�������˱�������ң���ʱӦ����һ����ȫƽ�������
            if (INSERT == NULL)
            {
                INSERT = ROOT;
                while (INSERT->left != NULL)
                    INSERT = INSERT->left;
            }
        }
        forward_update(newnode->father);    //ֻ��һ��ROOT��ʱ��Ͳ��ø����ˣ�Ҫ��Ȼ�ᴫ��ȥNULL
    }
    leafnum++;
#ifdef DEBUG
    cout << "Insert No." << leafnum - 1 << " node, print MerkleTree:" << endl;
    print_merkletree();
    cout << endl;
#endif // DEBUG
}

/**
 * �½ڵ���뵽��ǰ����������ǰ���¶�������ֵ
 * @param  insert_node ����Ľڵ�
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
    ��ȡĳ��hashֵ����֤·��
*/
vector<Node*> MerkleTree::get_verify_path(uchar hashvalue[SM3_OUTLEN])
{
    vector<Node*> path;
    Node* tmp = ROOT;
    while (tmp->left != NULL)
    {
        tmp = tmp->left;      //����broָ�룬ֱ�����ұ���Ѱ��
    }
    while (true)
    {
        if (!memcmp(tmp->hash, hashvalue, SM3_OUTLEN)) //�����Ȼ᷵��0
            break;
        if (tmp->bro == NULL)
        {
            //cout<<"The hash isn't in the MerkleTree"<<endl;
            return path;  //���ؿյ�vector
        }
        tmp = tmp->bro;
    }
    //����������ˣ�˵����ʱ��tmp��������Ҫ��֤��node
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
    ��֤ĳ��Block�������ڲ���MerkleTree��
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
    if (path.empty())    //����Ǹ��յģ�˵��û���ҵ���Ӧ���ڵ㣬�ڵ㲻���ڣ�����1
    {
        return 1;
    }
    Node* verify_node = path[0];
    uchar input[SM3_OUTLEN * 2];
    uchar output[SM3_OUTLEN];
    for (int i = 1; i < path.size(); i++)
    {
        if (verify_node == verify_node->father->left) //Ҫ����������������Ϊƴ�ӵ�ʱ����в�ͬ��
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
        //�����ˣ�֮ǰ��if�����ź���˷ֺţ��������ʧЧ���̶�return 1��ܳ
        if (memcmp(verify_node->father->hash, output, (int)SM3_OUTLEN / 2))
            return 1;
        verify_node = verify_node->father;
    }
    if (verify_node == ROOT)
        return 0;
    else
        return 1;
}