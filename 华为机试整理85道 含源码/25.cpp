#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *num="323324423343";
	int a[10]={0};
	int len=strlen(num);
	int i,j,temp,count=0,maxnum=0;

	for(i=0;i<len;i++)
	{
		temp=num[i]-'0';
		a[temp]++;
	}
	int temp1=a[0];
	for(j=0;j<10;j++)
	{
		if(a[j]!=0)
		{
			count++;
			temp1=(temp1>a[j])?temp1:a[j];
		}
	}
	printf("出现次数最多的数字为:%d\n",count);
	printf("出现的次数:%d\n",temp1);
	return 0;
}