#include<iostream>
using namespace std;
struct {
	char c;
	int a;
	char c2;
	//double d;
}st1;
struct {
	char c;
	char c2;
	int i;
	short a;
	char c3;
	short a2;
}st2;
#pragma pack(push) //�������״̬
#pragma pack(4)//�趨Ϊ4�ֽڶ���
struct test
{
    char m1;
    double m4;
    int m3;
    char c2;
};
#pragma pack(pop)//�ָ�����״̬
int main()
{
	cout<<"sizeof(st1)="<<sizeof(st1)<<endl;
	cout<<"sizeof(st2)="<<sizeof(st2)<<endl;
	cout<<"sizeof(test)="<<sizeof(test)<<endl;
	return 0;
}
