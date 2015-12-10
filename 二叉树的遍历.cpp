#include<iostream>
#include<stack>   //STL
#include<queue>
using namespace std;
//124##57##8##3#6##
class Tree {
    char data;
    Tree *leftChild;
    Tree *rightChild;
public:
    Tree()
    {
        leftChild = rightChild = NULL;
    }
    ~Tree() {};

    static void CreateTree(Tree* &node);
    static void destroyTree(Tree* &node);
    //��Ա����
    //�ݹ�ı���������
    void PreOrderVisit(Tree *T);
    void InOrderVisit(Tree *T);
    void LastOrderVisit(Tree *T);
    void LevelOrderVisit();
    //�ǵݹ�ĵ��ö�����
    void NoRecursivePreVisit();
    void NoRecursiveInVisit();
    void NoRecursiveLastVisit();
    //�����������
    static int getDepth(const Tree *T);
    //�Ҹ������ֵ�ĸ��ڵ�
    static char findParent(const Tree *bt, char x) {
        if(bt==NULL || bt->leftChild==NULL && bt->rightChild==NULL)//�ҵ��ս���Ҷ�ڵ�
            return 0;
        if(bt->leftChild && bt->leftChild->data==x
                || bt->rightChild && bt->rightChild->data==x)
            return bt->data;//�����ǰ���������ĸ���ֱ�ӷ���
        char pa = findParent(bt->leftChild,x);//��������
        if(pa==0) //���������û�ҵ�����ȥ��������
            pa = findParent(bt->rightChild,x);
        return pa;
    }
    //��ʾ���ڵ�
    static void showParent(const Tree *bt, char x) {
    	char pa = findParent(bt,x);
        if(pa==0)
            cout<<"node "<<x<<" have no parent!"<<endl;
        else
            cout<<"the parent of "<<x<<" is "<<pa<<endl;
    }
};

//������
void Tree::CreateTree(Tree* &node)
{
    char temp;
    static unsigned cur_size = 0;
    if(cur_size==0)
        cout<<"������ڵ������(#��ʾ��)��"<<endl;
    cin>>temp;
    if(temp=='#') {
        node = NULL;
    } else {
        node = new Tree;
        node->data = temp;
        cur_size++;
        CreateTree(node->leftChild);
        CreateTree(node->rightChild);
    }
}

void Tree::destroyTree(Tree* &node)
{
    if(node->leftChild!=NULL)
        destroyTree(node->leftChild);
    if(node->rightChild!=NULL)
        destroyTree(node->rightChild);
    delete node;
    node = NULL;
}
//���������
void Tree::PreOrderVisit(Tree *T)
{
    if(T!=NULL) {
        cout<<T->data<<"  ";
        PreOrderVisit(T->leftChild);
        PreOrderVisit(T->rightChild);
    }
}
//���������
void Tree::InOrderVisit(Tree *T)
{
    if(T!=NULL) {
        InOrderVisit(T->leftChild);
        cout<<T->data<<"  ";
        InOrderVisit(T->rightChild);
    }
}
//���������
void Tree::LastOrderVisit(Tree *T)
{
    if(T!=NULL) {
        LastOrderVisit(T->leftChild);
        LastOrderVisit(T->rightChild);
        cout<<T->data<<"  ";
    }

}
//��α��������ǵݹ�
void Tree::LevelOrderVisit()
{
    queue<Tree *>Q;
    Q.push(this);
    Tree *temp=NULL;
    while(!Q.empty()) {
        temp=Q.front();
        cout<<temp->data<<"  ";
        Q.pop();
        if(temp->leftChild)
            Q.push(temp->leftChild);
        if(temp->rightChild)
            Q.push(temp->rightChild);
    }
}
//�ǵݹ��������
void Tree::NoRecursivePreVisit()
{
    stack<Tree *>S;  //�����������ڵ��ջ
    Tree *p = this;
    while(!S.empty() || p!=NULL) {
        if(p!=NULL) { //p�ǿ�
            S.push(p);
            cout<<p->data<<"  ";
            p = p->leftChild;
        } else {
            p = S.top();
            S.pop();
            p = p->rightChild;
        }
    }
}
//�ǵݹ��������
void Tree::NoRecursiveInVisit()
{
    stack<Tree *>S;  //�����������ڵ��ջ
    Tree *p = this;
    while(!S.empty() || p!=NULL) {
        if(p!=NULL) { //p�ǿ�
            S.push(p);
            p = p->leftChild;
        } else {
            p = S.top();
            S.pop();
            cout<<p->data<<"  ";
            p = p->rightChild;
        }
    }
}
//�ǵݹ�������
void Tree::NoRecursiveLastVisit()
{
    stack<Tree *>S;
    Tree *p = this;
    Tree *p_visited = NULL;
    while(!S.empty() || p!=NULL) {
        while(p!=NULL) {
            S.push(p);
            p = p->leftChild;
        }
        p=S.top();
        if(p->rightChild==NULL || p->rightChild==p_visited) {
            cout<<p->data<<"  ";
            p_visited = p;
            p = NULL;
            S.pop();
        } else
            p=p->rightChild;
    }
    cout<<endl;
}
int Tree::getDepth(const Tree *T)
{
    if(T==NULL)
        return 0;
    return 1+max(getDepth(T->leftChild),getDepth(T->rightChild));
}
//	124##57##8##3#6##
int main()
{
    Tree* mytree = NULL;
    while(1) {
        Tree::CreateTree(mytree);
        cout<<"��������ǣ�"<<Tree::getDepth(mytree)<<endl;
        cout<<"�������"<<endl;
        mytree->PreOrderVisit(mytree);
        cout<<endl;
        cout<<"�������"<<endl;
        mytree->InOrderVisit(mytree);
        cout<<endl;
        cout<<"�������"<<endl;
        mytree->LastOrderVisit(mytree);
        cout<<endl;
        cout<<"��α���"<<endl;
        mytree->LevelOrderVisit();
        cout<<endl<<endl;
        cout<<"�ǵݹ��������"<<endl;
        mytree->NoRecursivePreVisit();
        cout<<endl;
        cout<<"�ǵݹ��������"<<endl;
        mytree->NoRecursiveInVisit();
        cout<<endl;
        cout<<"�ǵݹ�������"<<endl;
        mytree->NoRecursiveLastVisit();
        for(char c='1'; c<'9'; c++)
            Tree::showParent(mytree,c);

        Tree::destroyTree(mytree);
        cout<<endl;
    }
    cin.get();
    return 0;
}
