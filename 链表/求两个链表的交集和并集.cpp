/*
����������Ľ����Ͳ���.���磺
a�����ֵΪ��10 20 30 40 50 60
b�����ֵΪ��10 15 30 50 55 60 75 98
����Ϊ��10 30 50 60
����Ϊ��10 15 2030 40 50 55 60 75 98
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int datatype;
typedef struct ListNode {
    datatype data;
    ListNode *next;
} ListNode, *linklist;

void print(linklist head)
{
	if(head==NULL){
		puts("����Ϊ�գ�");
		return;
	}
    puts("������Ϊ��");
    linklist p=head->next;
    while(p) {
        printf("%-d -> ",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
linklist creat()
{
    linklist head,s,p;
    datatype x;
    head=p=(linklist)malloc(sizeof(ListNode));
    printf("�������������ݣ���0Ϊ������־��\n");
    scanf("%d",&x);
    while(x) {
        s=(linklist)malloc(sizeof(ListNode));
        s->data=x;
        p->next=s;
        p=s;
        scanf("%d",&x);
    }
    p->next=NULL;
    return head;
}
linklist jiaoji(linklist head1,linklist head2)//���������ϵĽ���
{
    linklist p,q,head,r,pre,s;
    head=r=(linklist)malloc(sizeof(ListNode));
    p=head1->next;
    while(p) {
        q=head2->next;
        while(q) {
            if(p->data==q->data) {
                s=(linklist)malloc(sizeof(ListNode));
                s->data=p->data;
                r->next=s;
                r=s;
                break;
            }
            q=q->next;
        }
        p=p->next;
    }
    r->next=NULL;
    return head;
}
linklist bingji(linklist head1,linklist head2)
{
    linklist p,q,head,r,pre,s;
    datatype flag;
    head=r=(linklist)malloc(sizeof(ListNode));
    p=head1->next;
    while(p) {
        flag=0;
        q=head2->next;
        while(q) {
            if(p->data==q->data) {
                flag=1;
                break;
            }
            q=q->next;
        }
        if(flag==0) {
            s=(linklist)malloc(sizeof(ListNode));
            s->data=p->data;
            r->next=s;
            r=s;
        }
        p=p->next;
    }
    r->next=head2->next;
    return head;
}

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
	}else{
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
int main()
{
    linklist head1,head2,head3;
    head1=creat();
    print(head1);
    head2=creat();
    print(head2);
    head2->next = head1->next;
    ListNode node = findFirstCommonNode(head1,head2);
    printf("����������Ϊ:%d\n",node.data);
    print(node.next);
    //head3=bingji(head1,head2);
    //print(head3);
    return 0;
}
