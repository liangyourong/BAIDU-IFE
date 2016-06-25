#include<iostream>
#include<string>
using namespace std;
char a[5][5];
void swap(int i,int j,int i1,int j1)
{
	char t;
	t=a[i][j];
	a[i][j]=a[i1][j1];
	a[i1][j1]=t;
}
int xiaochu()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])
				return 1;
		}
		for(int i=0;i<5;i++)
			for(int j=0;j<3;j++)
			{
				if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i])
					return 1;
			}
			return 0;
}
int main()
{  
	string str;
	cin>>str;
	int n=0,flag,min;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			a[i][j]=str[n++];
	for(int i=0;i<5;i++)            //从左到右，从上到下，第一个满足的编号最小，直接终止程序
		for(int j=0;j<5;j++)
		{
			if(j+1<5)
			{
				swap(i,j,i,j+1);
				flag=xiaochu();
				if(flag==1)
				{
					min=i*5+j+1;
					cout<<"YES"<<endl<<min<<endl;
					return 0;
				}
				swap(i,j,i,j+1);                //不符合时要交换回来，进行下次比较
			}
			if(i+1<5)
			{
				swap(i,j,i+1,j);
				flag=xiaochu();
				if(flag==1)
				{
					min=i*5+j+1;
					cout<<"YES"<<endl<<min<<endl;
					return 0;
				}
				swap(i,j,i+1,j);
			}

		}
		cout<<"NO"<<endl;
		return 0;	
}