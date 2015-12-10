//������Ӵ�����̬�滮ʵ��
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getLCSLength(const string &s, const string &t) {
    vector<vector<string> >num(s.length(),vector<string>(t.length()));
    int maxlen = 0;
    string lcs = "" ;
    for(int i=0; i<s.length(); i++)
        for (int j=0; j<t.length(); j++)
            if(s[i]==t[j]) {
                if (i==0||j==0)
                    num[i][j] = s[i];
                else
                    num[i][j] = num[i-1][j-1] + s[i];
                if(num[i][j].length()>maxlen) {
                    maxlen = num[i][j].length();
                    lcs = num[i][j];
                } else if(num[i][j].length()==maxlen)
                    lcs += "\n" + num[i][j];
            }
    return lcs;
}

int main() {
    string s,t;
    cout<<"�������ַ���s: ";
    cin>>s;
    cout<<"�������ַ���t: ";
    cin>>t;
    cout<<endl<<"������Ӵ�Ϊ:"<<endl;
    cout<<getLCSLength(s,t)<<endl;
    return 0;
}
