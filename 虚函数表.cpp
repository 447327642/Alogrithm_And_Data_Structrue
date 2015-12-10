#include<iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
	virtual ~Base(){}
};
class Base2 {
public:
	virtual void f() { cout << "Base::f" << endl; }
};

class Derived :  public Base{
public:
	void g() {
		cout<<"Derived::g"<<endl;
	}
	int getA(){
		return a;
	}
	virtual ~Derived(){}
private:
	int a;
};
//���ؼ̳�ʱ��ӵ�������麯����ָ��
class Derived2 :public Base2,Base{
public:
	void g() {
		cout<<"Derived::g"<<endl;
	}
};

int main()
{
	Base2 b2;
	cout<<sizeof(Base)<<" "<<sizeof(Base2)<<" "
		<<sizeof(Derived)<<" "<<sizeof(Derived2)<<endl;
	typedef void(*Fun)(void);

	Derived d;
	Base &b = d;
	cout<<sizeof(b)<<sizeof(d)<<endl;
	Fun pFun = NULL;

	cout << "�麯�����ַ��" << (int*)(&b) << endl;

	cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;

	// Invoke the first virtual function

	pFun = (Fun)*((int*)*(int*)(&b)+0); // Base::f()
	pFun();

	pFun = (Fun)*((int*)*(int*)(&b)+1); // Base::g()
	pFun();

	pFun = (Fun)*((int*)*(int*)(&b)+2); // Base::h()
	pFun();

	*((int*)(&b)+1) = 555;
	cout<<d.getA()<<endl;
	return 0;
}
