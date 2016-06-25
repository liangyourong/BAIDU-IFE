#include<stdio.h>
#include<string.h>
#include<iostream>
#include<conio.h>
#define N 5
using namespace std;
int cal_score(int score[], int judge_type[], int n) 
{
	int expert=0;
int dazhong=0;
	int zongfen=0;
	int i;
	int number=0;
	
	for(i=0;i<N;i++)
	{
		if(judge_type[i]==1)
		{
			expert=expert+score[i];
			number++;
		}
		else dazhong=dazhong+score[i];
	}
	if(number==N)
	{
		zongfen=(int)(expert/N);
	}
	else
{
		expert=(int)(expert/number);
		dazhong=(int)(dazhong/(N-number));
		zongfen=int(0.6*expert+0.4*dazhong);
	}
	return zongfen;
}
int main()
{
	int score[N];
	int judge_type[N];
	int numberlast=0;
	int i;
	printf("please input the %d score:\n",N);
	for(i=0;i<N;i++)
		scanf("%d",&score[i]);
	printf("please input the level(1:expert,2:dazhong)\n");
	for(i=0;i<N;i++)
		scanf("%d",&judge_type[i]);
	numberlast=cal_score(score,judge_type,N);
	printf("the last score is %d\n",numberlast);
	return 0;
}