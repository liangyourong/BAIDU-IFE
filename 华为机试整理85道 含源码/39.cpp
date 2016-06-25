#include<iostream>
#include<string>
#include<cctype>
using namespace std;
struct node{
	char c;
	node *next;
};
struct node1{
	int a1;
	node1 *next;
};
int calculate(int,string);
int main()
{  
	int len;
	string expStr;
	cin>>expStr;
	len=expStr.size();
	int m=calculate(len,expStr);
	cout<<m<<endl;
	return 0;
}
int calculate(int len,string a)
{
	char *b=new char[len+1];
	node *top=NULL,*q,*p;
	int n=0;
	for(int i=0;i<len;i++)
	{
		if(isdigit(a[i]))
			b[n++]=a[i];
		else if(a[i]=='(')
		{
			p=new node;
			p->c=a[i];
			p->next=top;
			top=p;
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			while(top!=NULL)
			{
				if(top->c!='(')
				{
					b[n++]=top->c;
					q=top;
					top=top->next;
					delete q;
				}
				else
					break;
			}
			p=new node;
			p->c=a[i];
			p->next=top;
			top=p;
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			while(top!=NULL&&(top->c=='*'||top->c=='/'))
			{
				b[n++]=top->c;
				q=top;
				top=top->next;
				delete q;
			}
			p=new node;
			p->c=a[i];
			p->next=top;
			top=p;
		}
		else if(a[i]==')')
		{
			while(top->c!='(')
			{
				b[n++]=top->c;
				q=top;
				top=top->next;
				delete q;
			}
			q=top;
			top=top->next;
			delete q;
		}

	}
	while(top!=NULL)
	{
		b[n++]=top->c;
		q=top;
		top=top->next;
		delete q;
	}
	b[n]='\0';
	//cout<<b<<endl;
	node1 *p1,*top1=NULL,*q1;
	int num1,num2;
	for(int i=0;i<n;i++)
	{
		if(isdigit(b[i]))
		{
			p1=new node1;
			p1->a1=b[i]-'0';
			p1->next=top1;
			top1=p1;
		}
		else
		{
			q1=top1;
			top1=top1->next;
			num1=top1->a1;
			num2=q1->a1;
			delete q1;
			if(b[i]=='+')
				top1->a1=num1+num2;
			else if(b[i]=='-')
				top1->a1=num1-num2;
			else if(b[i]=='*')
				top1->a1=num1*num2;
			else
				top1->a1=num1/num2;
		}

	}
	int t=top1->a1;
	delete top1;
	delete []b;
	return t;
}