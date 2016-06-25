#include<stdio.h>
#define M 20

int main()
{
	int a[M];
	int i,j,s,temp;
	int sort[M],t=0;
	char c=' ';
	i=0;
	while(c!='\n')
	{
		scanf("%d%c",&temp,&c);
		a[i++]=temp;
	}
	scanf("%d",&s);
	for(j=0;j<i;j++)
	{
		temp=a[j];
		if(temp%100==s)
		{
			sort[t++]=a[j];
		}
		else
			temp/=10;
	}
	for(i=0;i<t-1;i++)
		for(j=0;j<t-i-1;j++)
		{
			if(sort[j]>sort[j+1])
			{
				temp=sort[j+1];
				sort[j+1]=sort[j];
				sort[j]=temp;
			}
		}
		for(i=0;i<t;i++)
			printf("%d ",sort[i]);
		printf("\n");
		return 0;
}
