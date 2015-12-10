/*
��C++�У�obj��һ����Ķ���p��ָ��obj��ָ�룬���������и����ݳ�Աmem��
����obj.mem��p->mem��ʵ�ֺ�Ч������ʲô��ͬ��
���ǣ�ֻ��һ������²����ش���죬�����������������3��������
��1����obj ��һ������̳е�������Ķ���
��2����mem�Ǵ�����������������ĳ�Ա
��3����p�ǻ������͵�ָ��
*/

/*
�����������ӣ������������εļ̳���ϵ�У����û��virtual�̳У���ôD�о�������A��
��Աint a;�̳�������ʹ�õ�ʱ�򣬾ͻ��кܶ�����ԡ�������virtual�̳У���D�о�
ֻ��A�ĳ�Աint a;��һ�ݿ������ÿ�����������B��Ҳ��������C������һ�ݵ����Ŀ���
*/
#include<iostream>
using namespace std;

class A
{
public:
    int a;
};

class B : virtual public A
{
public:
   int b;
};

class C :virtual public A
{
public:
   int c;
};

class D : public B, public C
{
public:
   int d;
};

int main()
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	cout<<sizeof(C)<<endl;
	cout<<sizeof(D)<<endl;

	typedef void (*Fun)(void);
	int** pVtab = NULL;
    Fun pFun = NULL;

    D dd;

    pVtab = (int**)&dd;
    cout << "[0] D::B1::_vptr->" << endl;
    pFun = (Fun)pVtab[0][0];
    cout << "     [0] ";    pFun(); //D::f1();
    pFun = (Fun)pVtab[0][1];
    cout << "     [1] ";    pFun(); //B1::Bf1();
    pFun = (Fun)pVtab[0][2];
    cout << "     [2] ";    pFun(); //D::Df();
    pFun = (Fun)pVtab[0][3];
    cout << "     [3] ";
    cout << pFun << endl;

    //cout << pVtab[4][2] << endl;
    cout << "[1] = 0x";
    cout <<  (int*)((&dd)+1) <<endl; //????

    cout << "[2] B1::ib1 = ";
    cout << *((int*)(&dd)+2) <<endl; //B1::ib1
    cout << "[3] B1::cb1 = ";
    cout << (char)*((int*)(&dd)+3) << endl; //B1::cb1

    //---------------------
    cout << "[4] D::B2::_vptr->" << endl;
    pFun = (Fun)pVtab[4][0];
    cout << "     [0] ";    pFun(); //D::f2();
    pFun = (Fun)pVtab[4][1];
    cout << "     [1] ";    pFun(); //B2::Bf2();
    pFun = (Fun)pVtab[4][2];
    cout << "     [2] ";
    cout << pFun << endl;

    cout << "[5] = 0x";
    cout << *((int*)(&dd)+5) << endl; // ???

    cout << "[6] B2::ib2 = ";
    cout << (int)*((int*)(&dd)+6) <<endl; //B2::ib2
    cout << "[7] B2::cb2 = ";
    cout << (char)*((int*)(&dd)+7) << endl; //B2::cb2

    cout << "[8] D::id = ";
    cout << *((int*)(&dd)+8) << endl; //D::id
    cout << "[9] D::cd = ";
    cout << (char)*((int*)(&dd)+9) << endl;//D::cd

    cout << "[10]  = 0x";
    cout << (int*)*((int*)(&dd)+10) << endl;
    //---------------------
    cout << "[11] D::B::_vptr->" << endl;
    pFun = (Fun)pVtab[11][0];
    cout << "     [0] ";    pFun(); //D::f();
    pFun = (Fun)pVtab[11][1];
    cout << "     [1] ";    pFun(); //B::Bf();
    pFun = (Fun)pVtab[11][2];
    cout << "     [2] ";
    cout << pFun << endl;

    cout << "[12] B::ib = ";
    cout << *((int*)(&dd)+12) << endl; //B::ib
    cout << "[13] B::cb = ";
    cout << (char)*((int*)(&dd)+13) <<endl;//B::cb
}
//�ο���ַ��http://blog.csdn.net/jiangnanyouzi/article/details/3721091
