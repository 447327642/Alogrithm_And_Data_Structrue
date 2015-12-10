/******************************************************************
��������:�����������������ҳ����ǵĵ�һ�������ڵ���غϲ��ֵĳ��ȡ�
����Ľڵ㶨������:
struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

˼·:
������������й������,��ô�ù������֮������н�㶼���غϵ�,���һ������Ȼ���غϵġ����,�����ж����������ǲ������غϵĲ���,ֻ��Ҫ�ж����һ����㡣�������β�����һ����,˵�������غ�;������������û�й����Ľ�㡣

�������˼·��,˳�������������β����ʱ��,���ǲ��ܱ�֤������������ͬʱ����β��㡣������Ϊ���������ȿ��ܲ�һ���������Ǽ���һ���������һ����s�����,�������ڳ��������ϱ���s�����,֮����ͬʱ������������,��ʱ���ܱ�֤��������ͬʱ����β�ڵ��ˡ�������������ӵ�һ��������㿪ʼ�������β���,��һ�������غϵġ����,���ǿ϶�Ҳ��ͬʱ�����һ�������ġ������ڱ����У���һ����ͬ�Ľ����ǵ�һ�������Ľ�㡣
******************************************************************/
#include<stdio.h>
typedef struct ListNode {
	int key;
	ListNode* next;
}ListNode;
//����һ��������ͣ�ֵ��ʾ����������,ָ���ʾ��һ���������
ListNode findFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1==NULL || pHead2==NULL)
		return {0};
	ListNode *pFast = pHead1, *pSlow = pHead2, *pSync = NULL, *pSlowLast = NULL;
	while(pFast->next!=NULL && pSlow->next!=NULL){
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	//ĳ����������β���
	if(pFast->next==NULL){	//����1����
		pSlowLast = pFast;	//��¼����������һ�����
		pSync = pSlow;
		pFast = pHead2;		//��¼������
		pSlow = pHead1;		//��¼������
	}else{ //����2����
		pSlowLast = pSlow;	//��¼����������һ�����
		pSync = pFast;
		pFast = pHead1;		//��¼������
		pSlow = pHead2;		//��¼������
	}
	while(pSync->next!=NULL){
		pSync = pSync->next;
		pFast = pFast->next;
	}
	if(pSync!=pSlowLast)	//���һ����㲻ͬ,��û�й������
		return {0};
	while(pFast!=pSlow){
		pFast = pFast->next;
		pSlow = pSlow->next;
	}//����һ���Ѿ��ҵ��������
	unsigned length = 1;	//��¼������㳤��
	while(pSlow!=pSlowLast){
		pSlow = pSlow->next;
		++length;
	}
	return {length,pFast};
}
