#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void search(char **p,bool **visit,const string &w,int pos,int n,int m,int s,int e);
int main()
{  
	//freopen("mi.txt","r",stdin);
	int n,m,pos=0;
	cin>>n>>m;
	string w;
	cin>>w;
	char **p=new char*[n];
	bool **visit=new bool*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new char[m];
		visit[i]=new bool[m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>p[i][j];
			visit[i][j]=false;
		}
		for(int i=0;i<n;i++)                 //寻找首字母（考虑有多个符合）
		{
			for(int j=0;j<m;j++)
			{
				if(p[i][j]==w[pos])
				{
					visit[i][j]=true;
					search(p,visit,w,pos+1,n,m,i,j);	
				}
			}

		}

		cout<<"NO"<<endl;
		for(int i=0;i<n;i++)
		{
			delete []p[i];
			delete []visit[i];
		}
		return 0;	
}

void search(char **p,bool **visit,const string &w,int pos,int n,int m,int s,int e)
{

	if(pos==w.size())              //终止条件不能为x==尾字母，因为单词中字母可能重复
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			delete []p[i];
			delete []visit[i];
		}
		exit(0);
	}                                                        //四个方向寻找

	if(s-1>=0&&visit[s-1][e]==false&&p[s-1][e]==w[pos])
	{
		visit[s-1][e]=true;
		search(p,visit,w,pos+1,n,m,s-1,e);
	}
	if(e-1>=0&&visit[s][e-1]==false&&p[s][e-1]==w[pos])
	{
		visit[s][e-1]=true;
		search(p,visit,w,pos+1,n,m,s,e-1);
	}
	if(s+1<n&&visit[s+1][e]==false&&p[s+1][e]==w[pos])
	{
		visit[s+1][e]=true;
		search(p,visit,w,pos+1,n,m,s+1,e);
	}
	if(e+1<m&&visit[s][e+1]==false&&p[s][e+1]==w[pos])
	{
		visit[s][e+1]=true;
		search(p,visit,w,pos+1,n,m,s,e+1);
	}
	else
		return ;

}