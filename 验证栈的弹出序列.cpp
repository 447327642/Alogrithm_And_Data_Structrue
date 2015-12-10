#include<iostream>
#include<stack>
using namespace std;

bool isValidPopOrder(const char *pPush,const char *pPop)
{
    if(pPush==NULL && pPop==NULL)
        return 0;
    stack<char> sta;
    while(*pPop!='\0') {
        if(!sta.empty() && sta.top()==*pPop) {
            sta.pop();
            ++pPop;
        } else if(*pPush=='\0')
            return 0;
        else {
            sta.push(*pPush);
            ++pPush;
        }
    }
    return 1;
}

int main()
{
    char push[128],pop[128];
    while(1) {
        cout<<"��������ջ����: ";
        cin>>push;
        cout<<"�������ջ����: ";
        cin>>pop;
        if(isValidPopOrder(push,pop))
            cout<<"��ջ������ȷ!"<<endl;
        else
            cout<<"Error:��ջ���в���ȷ!"<<endl;
		cin.clear();
		cin.sync();
    }
    return 0;
}
