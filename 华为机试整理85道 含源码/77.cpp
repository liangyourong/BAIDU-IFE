#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{   
	int n,s,e;
	cin>>n;
	int a[101][201]={0};           //数组容量的选择，考虑第n排的计算，纵标要+2
	a[1][100]=1;
	for(int i=2;i<=n;i++)
	{   
		s=100-i+1;
		e=100+i-1;
		for(int j=s;j<=e;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
	}
	s=100-n+1;
	e=100+n-1;
	for(int i=s;i<=e;i++)
	{
		if(a[n][i]%2==0)
		{
			cout<<i-s+1<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;	 
	return 0;
}