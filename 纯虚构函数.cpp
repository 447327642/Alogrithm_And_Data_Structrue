#include<iostream>
using namespace std;
class A
{
public:					//����Ͳ���protected��
	virtual ~A()=0    //����Ȼ�Ǹ����麯��������Ҳ���Ա�ʵ��
	{ //����﷨�ܺú�ǿ����ȫ��Ϊ��ʵ����ӿ����Ū���﷨�ɣ�
		cout<<" A: ~A()"<<endl;
	}
};
class B : public A
{
};
int main(int argc, char* argv[])
{
	B* p =new B;
	delete  p;
	A* p2 =new B;
	delete  p2;            //���õ��ı����������ˣ���Ϊ��ʱA������������public
	return 0;
}
//result��
/*
 A: ~A()
 A: ~A()
*/
