#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[50]={0};
	int i,n;

	printf("��������������ĳ���(1~50)��");
	scanf("%d",&n);

		printf("���������������Ԫ�أ�");
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);	
	}

	int min_num=num[0];
	int max_num=num[0];
	for(int j=0;j<n;j++)
	{
		if(max_num<num[j])
			max_num=num[j];
		else if(min_num>num[j])
			min_num=num[j];
	}
	int sum=min_num+max_num;
	printf("�������������Сֵ֮�ͣ�%d\n",sum);
	return 0;
}
