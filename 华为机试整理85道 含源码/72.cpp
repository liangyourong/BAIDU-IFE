#include<iostream>
#include<string>
using namespace std;
int main()
{ 
    int n,a,b;
	cin>>n>>a>>b;
	int **r=new int*[n];
	int *visit=new int[n];
	int *que=new int[n];
	for(int i=0;i<n;i++)
	{
		r[i]=new int[n];
		visit[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>r[i][j];
	int top=-1,tail=-1,s,num=0;
	que[++tail]=a;
	visit[a]=1;
	while(top!=tail)
	{
         s=que[++top];           //出列一个
		 for(int i=0;i<n;i++)
		 {
			 if(r[s][i]==1&&visit[i]==0&&i!=b)     //连通性&&访问过没
			 {
				 que[++tail]=i;
				 visit[i]=1;
			 }
			 else if(r[s][i]==1&&i==b)      //到达b时，不需要对b进行操作，直接判断队列中下一个
				 num++;              //到达一次路线加1
		 }
	}
	cout<<num<<endl;
	delete []que;
    delete []visit;
	for(int i=0;i<n;i++)
		delete []r[i];
	return 0;
}