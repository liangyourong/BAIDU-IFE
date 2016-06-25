#include "stdio.h"
#include "stdlib.h"
#include<malloc.h>

typedef struct Node{
	int value;
	Node* next;
}LinkList;

void Converse(LinkList* pPre,LinkList* pCur) 
{ //链表逆转
	LinkList* p = NULL;
	LinkList* pNext = NULL;
	p = pPre->next;
	LinkList* p1  = NULL;
	if(pCur!=NULL)
		pNext = pCur->next;

	while( p!=pNext)
	{
		p1 = p->next;
		p->next = pPre;
		pPre = p;
		p = p1;
	}
}

int main()
{   
	int count = 0, k,i=0,j=0,flag = 1,length=0,groups = 0;
	printf("请输入k:");
	scanf("%d",&k);
	LinkList* pPre = (LinkList*)malloc(sizeof(LinkList));
	LinkList* pCur = (LinkList*)malloc(sizeof(LinkList));
	LinkList* pNext = (LinkList*)malloc(sizeof(LinkList));
	LinkList* head = NULL;
    LinkList* pTempTail = NULL; //指向逆转之后的尾部
	LinkList* pTempHead = NULL; 

	pCur->value = 1;
	pPre = pCur;    //创建初始链表
	for(i=2;i<=6;i++) {
		LinkList* node = (LinkList*)malloc(sizeof(LinkList));
		node->value = i;
		pCur->next = node;
		pCur = node;
	}
	pCur->next = NULL;//最后一定要置NULL，c++中用new则无须置NULL
	
	pCur = pPre;
	while(pCur!=NULL) 
	{
		length++;
		pCur = pCur->next;
	}
	i=0;
	groups = length/k; //分成K段
	pCur = pPre;
	while(i<=groups) 
	{
		count = 0;
		while(count<k-1 && i<groups) 
		{
			pCur = pCur->next;
			count++;
		}
			
		if(i<groups) 
		{
			pNext = pCur->next;
			pTempHead = pCur;   /*没做翻转之前的头部,变成了翻转之后的尾部*/
			if(flag == 0) 
			{
				pTempTail->next = pTempHead;
			}
			pTempTail = pPre;
			Converse(pPre,pCur);
			//pTempTail = pPre;
			if(flag==1)
			{
				head = pCur;
				flag = 0;
			}
			pCur = pNext;
		}
		else
		{
			pTempTail->next = pNext;
		}
		pPre = pCur;
		i++;
	}
	

	pCur = head;

	while(j<length) {
		j++;
		printf("%d",pCur->value);
		pCur = pCur->next;
	}
	printf("\n");
	return 0;
}