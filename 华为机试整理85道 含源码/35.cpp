#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int cmp1(const void* a,const void* b)
{
	return *(int*)b-*(int*)a;
}
int main()
{  
	int n,m1=0,m2=0,m=0;
	cin>>n;
	int *num=new int[n];
	int *ji=new int[n];
	int *ou=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		if(num[i]%2==1)
			ji[m1++]=num[i];
		else
			ou[m2++]=num[i];
	}
	qsort(ji,m1,sizeof(int),cmp);
	qsort(ou,m2,sizeof(int),cmp1);
	for(int i=0;i<m1&&i<m2;i++)
	{
		num[m++]=ji[i];
		num[m++]=ou[i];
	}
	if(m1>m2)
	{
		for(int i=m2;i<m1;i++)
			num[m++]=ji[i];
	}
	else
	{
		for(int i=m1;i<m2;i++)
			num[m++]=ou[i];
	}
	for(int i=0;i<m;i++)
		cout<<num[i]<<" ";
	delete []num;
	delete []ji;
	delete []ou;

	return 0;	
}