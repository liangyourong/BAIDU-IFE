//方法1:链表法
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
	p->next=head;  //使链表尾连接链表头，形成循环链表
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
	int n=7,m=3;//此时n=7,m=3
	LinkList *head1;
	head1=create(n);
	deletefun(head1,m);
	return 0;
}
//方法2:数组法
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
	for(i = 0; i < n; i++) //把n个人的序号放入数组a[]中；
	{
		a[i] = i + 1;
	}
	for(i = n; i>= 2; i--)
	{
		s1 = (s1+m-1)%i; //s1每次出圈人的位置
		if(s1 == 0) //如果s1等于0，则说明要开始报数的人是最后一个人
		{
			s1 = i; //把此时变量i的值赋给s1
		}
		w = a[s1-1]; //把每次出圈人的序号赋给w
		for(j = s1; j < i; j++)
		{
			a[j-1] = a[j];
		}
		a[i-1] = w; //把每次出圈人的序号赋给倒数第i个位置上
	}
	for(int k = n-1; k >= 0; k--)
		cout<<a[k]<<" ";
	cout<<endl;
}