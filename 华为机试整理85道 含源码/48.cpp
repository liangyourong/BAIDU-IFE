#include<stdio.h>
#include<malloc.h>
int main()
{
	char a[100],c[100]={};
	gets(c);
	int i=0,j=0;;
	int flag=0;
	while(c[i]!=NULL&&flag==0)
	{
		switch(c[i])
		{
		case('('):
		case('['):
			a[j++]=c[i];break;
		case(')'):
			if(a[j-1]=='(')
			{
				a[j-1]='\0';
				j--;
			}
			else
				flag=1;
			break;
		case(']'):
			if(a[j-1]=='[')
			{
				a[j-1]='\0';
				j--;
			}
			else
				flag=1;
			break;

		}
		i++;
	}
	if(j!=0) flag=1;
	printf("%d\n",flag);
	return 0;
}