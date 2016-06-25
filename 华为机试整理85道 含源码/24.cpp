#include<stdio.h>
#include<string.h>

int main()
{
	char c[200]={'\0'};
	scanf("%s",&c);
	int n,i,j;
	int len=strlen(c);
	scanf("%d",&n);
	for(i=1;i<=len;i++)
	{
		j=i%n;
		printf("%c",c[i-1]);
		if(j==0) 
			printf("\n");
	}
	if(j!=0)
	for(i=j+1;i<=n;i++)
		printf("0");
	return 0;
}
