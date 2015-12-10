#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

int maxlen;
int maxindex;
char visit[256];
void output(const char * arr);
/* LNRS ��̬�滮 + hash ��¼�±� */
int dp[100];
void LNRS_dp_hash(const char * arr, int size=0) {
	if(size==0)
		size = strlen(arr);
    memset(visit, -1, sizeof(visit)); //visit������-1��ʱ���������ַ�û���ڼ�����
    memset(dp, 0, sizeof(dp));
    maxlen = maxindex = 0;
    dp[0] = 1;
    visit[arr[0]] = 0;
    for(int i = 1; i < size; ++i) {
        if(visit[arr[i]] == -1) { //��ʾarr[i]����ַ���ǰ������
            dp[i] = dp[i-1] + 1;
            visit[arr[i]] = i; /* ��¼�ַ��±� */
        } else {
            dp[i] = i - visit[arr[i]];
        }
        if(dp[i] > maxlen) {
            maxlen = dp[i];
            maxindex = i + 1 - maxlen;
        }
    }
    output(arr);
}
/* LNRS ��̬�滮+hash��ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)�㷨*/
void LNRS_dp_hash_ultimate(const char * arr, int size=0) {
	if(size==0)
		size = strlen(arr);
    memset(visit, -1, sizeof(visit));
    maxlen = maxindex = 0;
    visit[arr[0]] = 0;
    int curlen = 1;
    for(int i = 1; i < size; ++i) {
        if(visit[arr[i]] == -1) {
            ++curlen;
            visit[arr[i]] = i; /* ��¼�ַ��±� */
        } else {
            curlen = i - visit[arr[i]];
        }
        if(curlen > maxlen) {
            maxlen = curlen;
            maxindex = i + 1 - maxlen;
        }
    }
    output(arr);
}

void output(const char* arr)
{
	for(int i=0;i<maxlen;++i)
		cout<<arr[i+maxindex];
	cout<<endl;
}

int main()
{
	LNRS_dp_hash_ultimate("123453678");
	return 0;
}
