#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char str[100];
	printf("ÊäÈëÒ»×é×Ö·û´®£º\n");
	scanf("%s",&str);

	size_t len=strlen(str);
	int array[100];
	int count=0;
	for(unsigned int i=0;i<len;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			array[count++]=str[i]-'0';
	
	}
	array[count]='\0';
	int result=count;
	int min=array[0];
	int max=array[0];
	for(int j=0;j<count;j++)
	{
		if(max<array[j])
			max=array[j];
		else if(min>array[j])
			min=array[j];
	}
	for(int k=0;k<count;k++)
	{
		if(array[k]==min)
			result--;
		if(array[k]==max)
			result--;
	}
	printf("%d\n",result);
}