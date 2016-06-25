#include<iostream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{   
	int ma,mb;
	cout << "请输入数组a的长度：";
	cin>>ma;
	cout << "请输入数组b的长度：";
	cin>>mb;
	int *a=new int[ma];
	int *b=new int[mb];
	int *visit=new int[mb];
	int *c=new int[ma+mb];
	cout << "请输入数组a:";
	for(int i=0;i<ma;i++)
		cin>>a[i];
	cout << "请输入数组b:";
	for(int i=0;i<mb;i++)
	{
		cin>>b[i];
		visit[i]=0;
	}
	cout << "数组啊a,b的异集为：";
	int m=0,flag;
	for(int i=0;i<ma;i++)
	{
		flag=0;
		for(int j=0;j<mb;j++)
		{
			if(a[i]==b[j])
			{
				visit[j]=1;
				flag=1;
				break;
			}	
		}
		if(0==flag)
				c[m++]=a[i];

	}
	for(int i=0;i<mb;i++)
	{
		if(0==visit[i])
			c[m++]=b[i];
	}
	if(m==0)
		cout<<endl;
	else
	{
		for(int i=0;i<m;i++)
		cout<<c[i]<<" ";
	}
	delete []visit;
	delete []c;
	delete []a;
	delete []b;
	return 0;
}