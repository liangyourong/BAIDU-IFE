#include<iostream>
using namespace std;
void nishi(int **p,int **v,int a,int b,int n,int m);
int main(int argc,char *argv[])
{
	int n,m;
	cout << "请输入二维数组的行、列数：";
	cin>>n>>m;
	cout << "请按照索引顺序输入二维数元素：";
	int **p=new int*[n];
	int **v=new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[m];
		v[i]=new int[m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>p[i][j];
			v[i][j]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(v[i][j]==0)            //一次逆时针还有剩余进行下一次
				{   
					v[i][j]=1;
					nishi(p,v,i,j,n,m);
				}
			}
			for(int i=0;i<n;i++)
			{
				delete []p[i];
				delete []v[i];
			}
			return 0;
}
void nishi(int **p,int **visit,int a,int b,int n,int m)
{
	int pos1=a,pos2=b;;
	cout<<p[a][b]<<" ";
	for(int i=a+1;i<n;i++)
	{  
		if(visit[i][b]==0)
		{
			cout<<p[i][b]<<" ";
			visit[i][b]=1;
			pos1=i;
		}
	}
	for(int i=b+1;i<m;i++)
	{
		if(visit[pos1][i]==0)
		{
			cout<<p[pos1][i]<<" ";
			visit[pos1][i]=1;
			pos2=i;
		}
	}
	for(int i=pos1-1;i>=0;i--)
	{
		if(visit[i][pos2]==0)
		{
			cout<<p[i][pos2]<<" ";
			visit[i][pos2]=1;
		}
	}
	for(int i=pos2-1;i>=0;i--)
	{
		if(visit[a][i]==0)
		{
			cout<<p[a][i]<<" ";
			visit[a][i]=1;
		}
	}
	return;
}