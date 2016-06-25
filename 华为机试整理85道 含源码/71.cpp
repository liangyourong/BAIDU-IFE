#include<iostream>
using namespace std;
int choice(int *d,int *visit,int n);
int main(int argc,char *argv[])
{   
	int n,m,v,s,e,min;
	cin>>n>>m>>v;
	int **a=new int*[n];
	int *visit=new int[n];
	int *d=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];                 //这个地方老是犯错，是n不是i！！！！
		visit[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i!=j)
				a[i][j]=65535;
			else
				a[i][j]=0;
		}
		for(int i=0;i<m;i++)
		{   
			cin>>s>>e;
			a[s][e]=1;
		}
		for(int i=0;i<n;i++)
			d[i]=a[v][i];
		visit[v]=1;
		for(int i=1;i<n;i++)
		{
			min=choice(d,visit,n);
			visit[min]=1;
			for(int j=0;j<n;j++)
			{
				if(visit[j]==0&&d[min]+a[min][j]<a[v][j])
					d[j]=d[min]+a[min][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i!=v&&d[i]<65535)
				cout<<d[i]<<endl;
			else if(i==v)
				continue;
			else
				cout<<"-1"<<endl;
		}
		for(int i=0;i<n;i++)
			delete []a[i];
		delete []d;
		delete []visit;
		return 0;
}

int choice(int *d,int *visit,int n)
{
	int min=65536,pos;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0&&d[i]<min)
		{
			min=d[i];
			pos=i;
		}
	}
	return pos;
}