#include<iostream>
using namespace std;
int func(int a);
int main()
{
	int n;
	cout<<"enter:";
	cin>>n;
	cout<<func(n)<<endl;
}
int func(int a)
{
	int val=0;
	int temp;
	int i;
	int n=0;
	int b[100];
	while(a!=0)
	{
		temp=(a&1);
		b[n++]=temp;
		a=(a>>1);
	}
	for(i=0;i<n;i++)
		val=val*2+b[i];
	return val;
}