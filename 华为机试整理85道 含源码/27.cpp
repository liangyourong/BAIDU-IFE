
#include<stdio.h>
#include<string.h>
int main()
{
	int n,tmp=0;
	int flag=0;
	int a[10]={0};
	scanf("%d",&n);
	if(n<0)
	{
		flag = 1;
		n=-n;
	}
	while(n != 0)
	{
		if(a[n%10]==0)
		{
			tmp*=10;
			tmp+=n%10;
			a[n%10]=1;
		}
		n/=10;
	}
	if(flag==1)
		tmp=-tmp;
	printf("%d\n",tmp);
}

