//����1:����
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node *next;
}LinkList;

LinkList *create(int n)
{
	LinkList *p,*q,*head;
	int i=1;
	p=(LinkList*)malloc(sizeof(LinkList));
	p->data=i;
	head=p;

	for(i=1;i<=n;i++)
	{
		q=(LinkList*)malloc(sizeof(LinkList));
		q->data=i+1;
		p->next=q;
		p=q;
	}
	p->next=head;  //ʹ����β��������ͷ���γ�ѭ������
	return head;
	free(p);
	p=NULL;
	free(q);
	q=NULL;
}

void deletefun(LinkList *L,int m)
{
	LinkList *p,*q,*temp;
	int i;
	p=L;

	while(p->next!=p)
	{
		for(i=1;i<m;i++)
		{
			q=p;
			p=p->next;
		}
		printf("%5d",p->data);
		temp=p;
		q->next=p->next;
		p=p->next;
		free(temp);
	}
	printf("%5d\n",p->data);
}

int main()
{
	int n=7,m=3;//��ʱn=7,m=3
	LinkList *head1;
	head1=create(n);
	deletefun(head1,m);
	return 0;
}
//����2:���鷨
#include<iostream>
using namespace std;
void Joseph(int n, int m, int s);
int main()
{
	Joseph(9,3,1);
	return 0;
}
void Joseph(int n, int m, int s)
{
	int i,j,w;
	int s1 = s;
	int a[100] = {0};
	for(i = 0; i < n; i++) //��n���˵���ŷ�������a[]�У�
	{
		a[i] = i + 1;
	}
	for(i = n; i>= 2; i--)
	{
		s1 = (s1+m-1)%i; //s1ÿ�γ�Ȧ�˵�λ��
		if(s1 == 0) //���s1����0����˵��Ҫ��ʼ�������������һ����
		{
			s1 = i; //�Ѵ�ʱ����i��ֵ����s1
		}
		w = a[s1-1]; //��ÿ�γ�Ȧ�˵���Ÿ���w
		for(j = s1; j < i; j++)
		{
			a[j-1] = a[j];
		}
		a[i-1] = w; //��ÿ�γ�Ȧ�˵���Ÿ���������i��λ����
	}
	for(int k = n-1; k >= 0; k--)
		cout<<a[k]<<" ";
	cout<<endl;
}