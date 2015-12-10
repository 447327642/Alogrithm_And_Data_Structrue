#include<iostream>
using namespace std;

class Base
{
public:
	Base() {
		cout << "none argument !!" << endl;
	}
	Base(int x1) : x(x1) {
		cout<<"Base x1"<<endl;
	}
	virtual ~Base() {};

	virtual void func(int x) {
		cout << "Base : " << x << endl;
	}
private:
	int x;
};

class Derive : public Base
{
public:
	Derive () : Base(100) {}
	virtual ~Derive () {}

	//�ô�������Base��func������
	void func(int x) {
		cout << "Derive : " << x << endl;
	};

private:
	int dint;
};

int main()
{
	Derive derive;
	Derive::Base(2);      //::��ʾ�����ڼ�ȷ���ĵ��ã����Ƕ���ĵ��ã��ʿ��Ա���ͨ����
	// derive.Base();          //�����������ʾ���ܼ̳и���Ĺ��캯�����Ա���һ����䣻
	derive.func(2);         //�����ɱ���ͨ������ʾ�ܼ̳и������ͨ��Ա������
	Base &pBase = derive;
	pBase.func(1);
	return 0;
}
