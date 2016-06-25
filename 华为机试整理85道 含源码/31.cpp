#include<stdio.h>
#include<string.h>
#include<conio.h>
void sort(int input[], int n, int output[])
{
	int i,j;
	int k=1;
	int temp;
	int med;
	for(i=0;i<n-1;i++)    //冒泡排序法
		for(j=0;j<n-i-1;j++)
			if(input[j]>input[j+1])
			{
				temp=input[j];input[j]=input[j+1];input[j+1]=temp;
			}
			if(n%2!=0)
			{
				for(i=0;i<n;i++)
					printf("%2d",input[i]);
				printf("\n");
				med=(n-1)/2;             //数列是从0开始计数的，所以不是（n+1）/2
				output[med]=input[n-1];  //数列是从0开始计数的
				for(i=1;i<=med;i++)
				{
					output[med-i]=input[n-1-k];
					output[med+i]=input[n-2-k];
					k=k+2;
				}
			}
			else
			{
				med=n/2;
				output[med]=input[n-1];
				for(i=1;i<=med-1;i++)
				{
					output[med-i]=input[n-1-k];
					output[med+i]=input[n-2-k];
					k=k+2;	
				}
				output[0]=input[0];				
			}	
			for(i=0;i<n;i++)
				printf("%2d",output[i]);
			printf("\n");
}
int main()
{
	int a[6]={3,6,1,9,7,8};
	int b[6]={0};
	for(int i=0;i<6;i++)
		printf("%2d",a[i]);
	printf("\n");
	sort(a,6,b);
	return 0;
}