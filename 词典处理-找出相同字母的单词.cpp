/************************************************************************/
/* ����ʵ�ֶ�һ���ļ��е����е��ʽ��д����ҳ�������ͬ��ĸ��ϵĵ��ʡ���ʵӦ����һ����ĵ��ʱ���д���
�ô���ʱû�У����Ǿ��ú��档���׹����γ������п����ġ�
1.������ÿ��������Ҫ����ģ��������ܱ�ʶ�������ĸ���
2.��ʵ�Դ���һ���ֵ�ĵ��ʱ�Ƚ�������
3.�����õġ��㷨4����վ�ϵ����ݣ�wordlist��2MB��һ���ļ�
*/
/************************************************************************/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<map>
#include<ctime>
using namespace std;
//��stl�㷨���sort�����γ�signature��������Ķ�ѡһ
string sortIt(string str)
{
    sort(str.begin(),str.end());
    return str;
}
int main()
{
    string filename;
    ifstream fin;
    do{
		cout<<"Please input the file path: ";
		cin>>filename;
		fin.open(filename.c_str());
		if(fin.is_open())
			break;
		cout<<"can't open the file,please try again!"<<endl;
	}while(1);

    string word;
    map<string,set<string> > myTree;
    clock_t t1=clock();
    while(fin>>word) 	//�����ٶ�Լ48��/��
        myTree[sortIt(word)].insert(word);
    fin.close();
    cout<<"�������ݺ�ʱ: "<<clock()-t1<<endl<<"��enter�����������Ϣ..."<<endl;
    cin.get();cin.get();
    for(auto iter = myTree.begin(); iter!=myTree.end(); iter++) {
        cout<<(*iter).first<<":\t";
        for(auto set_iter = iter->second.begin(); set_iter!=iter->second.end(); set_iter++)
            cout<<*set_iter<<"\t";
        cout<<endl;
    }
    cin.get();
    return 0;
};
