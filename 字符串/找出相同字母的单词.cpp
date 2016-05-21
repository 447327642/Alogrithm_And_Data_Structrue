/************************************************************************
����ʵ�ֶ�һ���ļ��е����е��ʽ��д����ҳ�������ͬ��ĸ��ϵĵ��ʡ�
��ʵӦ����һ����ĵ��ʱ���д���
1.������ÿ��������Ҫ����ģ��������ܱ�ʶ�������ĸ���
2.��ʵ�Դ���һ���ֵ�ĵ��ʱ�Ƚ�������
3.�����õġ��㷨4����վ�ϵ����ݣ�wordlist��2MB��һ���ļ�
/************************************************************************/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <ctime>
using namespace std;
//��stl�㷨���sort�����γ�signature
string sortIt(string str)
{
    sort(str.begin(), str.end());
    return str;
}
int main()
{
    string filename;
    ifstream fin;
    do {
        cout << "Please input the file path: ";
        getline(cin, filename);
        fin.open(filename.c_str());
        if (fin.is_open())
            break;
        cout << "can't open the file,please try again!" << endl;
    } while (1);

    string word;
    map<string, set<string> > myTree;
    clock_t t1 = clock();
    while (fin >> word) //�����ٶ�Լ48��/��
        myTree[sortIt(word)].insert(word);
    fin.close();
    cout << "time elapsed: " << clock() - t1 << "ms, press enter to show all:\n";
    cin.get();
    for (auto& it : myTree) {
        cout << it.first << ":\t";
        for (auto& set_it : it.second)
            cout << set_it << "\t";
        cout << endl;
    }
    cin.get();
    return 0;
};
