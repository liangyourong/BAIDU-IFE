#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define N 5
using namespace std;
int main()
{
	int Height[N];
	int dmin;
	int H1,H2;
	int i,j,temp;

	printf("请输入一组身高在170到190之间的数据（共5个）:\n");
	for(int k=0;k<N;k++)
		scanf("%d",&Height[k]);
	printf("\n");
	sort(Height,Height+N);
	H1=Height[0];
	H2=Height[1];
	dmin=H2-H1;
	for(int m=2;m<N;m++)
	{
		if(Height[m]-Height[m-1]<=dmin)
		{
			H1=Height[m-1];
			H2=Height[m];
			dmin=Height[m]-Height[m-1];
		}
	}
	printf("身高差最小的两个身高为:\n");
	printf("%d,%d\n",H1,H2);
	return 0;
}