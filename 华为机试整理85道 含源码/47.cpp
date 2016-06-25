#include<stdio.h>

void bubblesort(int arr[])
{
	int i,j,temp;
	for(i=0;i<10;i++)
		for(j=0;j<9-i&&arr[j]>arr[j+1];j++)
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
}

int GetPassLine(int a[])
{
	bubblesort(a);
	if(a[0]>=60)
		return 60;
	else
		return (((int)a[4]/10)*10);
}

int main()
{
	int a[10]={0};
	int result;
	printf("请随机输入10个成绩（0-100）：\n");
	scanf("%d%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
	printf("\n");
	result=GetPassLine(a);
	if(result >= 60)
		result = 60; 
	printf("及格线为:%d\n",result);
	return 1;
}