#include<stdio.h>
#include<string.h>
int main()
{
	char s[800]={'\0'};
	scanf("%s",&s);
	int len=strlen(s);
	int i,left=0,right=0;
	int a[50],k=0,flag=1;
	for(i=0;i<len;i++)
	{
		if(s[i]=='(')
		{
			left++;
			a[k]=1;
			k++;
		}
		else if(s[i]==')')
		{
			right++;
			if(a[k-1]==1&&k>0)
			{
				a[k-1]=0;
				k--;
			}
			else
				flag=0;
		}
		if((i==2&&s[i]!='(')||(i==len-1&&s[i]!=')'))
			flag=0;
	}
	if(a[0]==0&&flag!=0)
		printf("RIGHT");
	else
		printf("WRONG");
	printf("%d %d\n",left,right);
	return 0;
}
