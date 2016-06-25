#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[11][11]={"zero","one","two","three","four","five","six","seven","eight","nine","double"};
	char temp[11], c=' ';
	int i,j,f,d=0;
	printf("请输入单词，单词间以空格隔开，以回车代表输入结束\n");
	while(c!='\n')
	{
		scanf("%s%c",&temp,&c);
		f=0;
		for(j=0;j<11;j++)
		{
			if(!strcmp(temp,a[j])&&j<10)
			{
				printf("%d",j);
				f=1;
				if(d==1)
				{
					printf("%d",j);
					d=0;
				}
			}
			else if(!strcmp(temp,a[j])&&j==10)
			{
				d=1;
				f=1;
			}
		}
		if(f==0)
			break;
	}
	if(d==1||f==0)
		printf("error\n");
	printf("\n");
	return 0;
}
