#include<iostream>
#include<string>
using namespace std;

static int r,c;
int tra(string *p,int **visit,int a,int b)
{
	visit[a][b]=1;
	if(p[a][b]=='#')
		return 0;
	if(p[a][b]=='H')
		return 1;
	if(a-1>=0&&visit[a-1][b]==0&&tra(p,visit,a-1,b)==1)
		return 1;
	if(a+1<r&&visit[a+1][b]==0&&tra(p,visit,a+1,b)==1)
		return 1;
	if(b-1>=0&&visit[a][b-1]==0&&tra(p,visit,a,b-1)==1)
		return 1;
	if(b+1<c&&visit[a][b+1]==0&&tra(p,visit,a,b+1)==1)
		return 1;
	return 0;

}


int main(int argc,char *argv[])
{

	cin>>r>>c;
	string *p=new string[r];
	int **visit=new int*[r];
	for(int i=0;i<r;i++)
	{
		cin>>p[i];
		visit[i]=new int[c];
	}
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visit[i][j]=0;
	int flag=0,m;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(p[i][j]=='B')
			{
				m=tra(p,visit,i,j);
				flag=1;
				break;
			}

		}
		if(1==flag)
			break;
	}
	if(m==1)
		cout<<"Y"<<endl;
	else
		cout<<"N"<<endl;
	delete []p;
	for(int i=0;i<r;i++)
		delete []visit[i];
	return 0;
}