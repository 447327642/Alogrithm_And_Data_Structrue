#include<iostream>
#include<time.h>
#include<windows.h>
/*
  쳲���������
   H(1)=H(0)=1;
   H(N)= H(N-1)+H(N-2);
*/
using namespace std;

/* ��ͨ����ͨ�� */
int feibona(int ac)
{
    if (ac == 0|| ac ==1)  return 1;
    int f1 = 1, f2 = 1;
    for(int i=1;i<ac;++i)
	{
		f2 += f1;
		f1 = f2-f1;
	}
    return f2;//feibona(ac-1) +feibona(ac-2);
}

/* ʹ��Ԫ��� ��ȫ�ػ��� ��������*/
template <int N>
struct data {
    //����ö��
    enum { res = data<N - 1>::res + data<N - 2>::res };
};

template <>
struct data<1> {
    //����ö��
    enum { res = 1L };
};

template <>
struct data<0> {
    //����ö��
    enum { res = 1L };
};


int main(int argc, char * args[])
{
    time_t  a ,b;
    a = clock(); //��ʼ��¼ʱ��
    cout << data<46L>::res << endl;
    b = clock(); //��ʼ��¼ʱ��
    system("echo ����Ԫ��������ĵ�ʱ��");
    cout << (double)(b - a) / CLK_TCK<<"s"<<endl;
    a = clock();
    cout << feibona(46L) << endl;
    b = clock();
    system("echo ������ͨ���㷨�����ĵ�ʱ��");
    cout << (double)(b - a) / CLK_TCK << "s" << endl;
    cin.get();
    return 0;
}
