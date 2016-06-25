#include<stdio.h>
#include<string.h>
int a[50];
bool f[50]={0};
int find(int w, int s)
{
	if(w==0)
		return 1;//刚好递归结束
	if(w<0 || w>0&&s==0)
		return 0;
	if(find(w-a[s-1],s-1))
	{
		f[s-1]=1;
		return 1;
	}
	return find(w,s-1);//继续递归
}
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	if(find(n,m))
	{
		for(i=0;i<m;i++)
			printf("%d",f[i]);
	}
	else
		printf("No\n");
	return 0;
}