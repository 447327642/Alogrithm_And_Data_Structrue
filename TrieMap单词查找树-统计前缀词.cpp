#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

class TrieMap {
public:
    TrieMap();
    virtual ~TrieMap();
    //����[]���������map, unorder_map�����ӿ�һ��
    void push( const string& strKey );
    int getCountByPrefix(const string &prefix);
    int operator[](const string &prefix);
protected:
    typedef struct Node {
        char ch;  //��ǰ���洢���ַ�
        Node *Children[58] ;  //ÿ���ڵ������58���ӽڵ�
        int num; //�Դ�Ϊǰ׺�ʵĸ���
        Node(char _ch=0,int n=0)
        {
            ch = _ch;
            memset( Children , 0 , sizeof( Children ) ) ;
            num = n;
        }
    } Node;
    Node * m_pRoot ;// �����ڵ�
    void deleteNode(Node * pNode); //ɾ��һ����㼰���ӽڵ�
};

TrieMap::TrieMap()
{
    m_pRoot = new Node() ;
}

TrieMap::~TrieMap()
{
    deleteNode(m_pRoot);
}
//ɾ���ڵ㼰���ӽڵ�
void TrieMap::deleteNode(Node * pNode)
{
    if(pNode==NULL)
        return;
    for (int i = 0; i < 58; ++i) {
        if (pNode->Children[i] != 0) {
            deleteNode(pNode->Children[i]) ;
            pNode->Children[i] = 0;
        }
    }
    delete pNode;
    pNode = 0;
}
//����һ����¼
void TrieMap::push(const string& strKey)
{
    Node * pNode = m_pRoot;
    // �������߲�����·��
    for ( size_t i = 0 , sz = strKey.size() ; i < sz ; ++i ) {
        Node *&child = pNode->Children[strKey[i]-'A'];
        pNode = child;
        if (child == 0)
            pNode = child = new Node(strKey[i],1);
        else
            ++pNode->num;
    }
}
//������ĳ��ǰ׺��ʼ�ĵ�����
int TrieMap::getCountByPrefix(const string &prefix)
{
    Node *pNode = m_pRoot;
    for(size_t i = 0, sz = prefix.size() ; i < sz ; ++i) {
        pNode = pNode->Children[prefix[i]-'A'];
        if(pNode==NULL)
            return 0;
    }
    return pNode->num;
}

int TrieMap::operator[](const string &prefix)
{
    return getCountByPrefix(prefix);
}

int main()
{
    int n,m;
    TrieMap myTrie ;
    string word;
    cin>>n;
    while(n--) {
        cin>>word;
        myTrie.push(word);
    }
    cin>>m;
    while(m--) {
        cin>>word;
        cout<<myTrie[word]<<endl;
    }

    return 0;
}
