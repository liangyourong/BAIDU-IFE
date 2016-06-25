#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{   
	//freopen("liantong.txt","r",stdin);
	int n,m,s,e;
	char flag;
	cin>>n>>m;
	int **a=new int*[n];
	int *visit=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];                
		visit[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i!=j)
				a[i][j]=0;
			else
				a[i][j]=1;
		}
		for(int i=0;i<m;i++)
		{
			cin>>s>>e;
			a[s-1][e-1]=1;              //注意题目要求下标是1到n！
			a[e-1][s-1]=1;              //注意是无向图，初始和删除都要考虑双边！
		}
		int q;
		cin>>q;
		char *re=new char[q];
		int c=0;
		for(int i=0;i<q;i++)
		{
			cin>>flag;
			cin>>s>>e;
			if('D'==flag)
			{
				a[s-1][e-1]=0;
				a[e-1][s-1]=0;
			}
			else
			{
				if(1==a[s-1][e-1])
					re[c++]='C';
				else
					re[c++]='D';
			}
		}
		for(int i=0;i<c;i++)
			cout<<re[i]<<endl;
		for(int i=0;i<n;i++)
			delete []a[i];
		delete []visit;
		delete []re;
		return 0;
}