#include<iostream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{   
	//freopen("打牌.txt","r",stdin);
	string a,b;
    int n=0,num,flag;
	int f[100];
	char ch;
	while(cin>>a>>b)
	{
		int m=b.size();
		num=1;
		flag=0;
		ch=b[0];
		if(m<=4)
		{
			for(int i=0;i<a.size();i++)
			{
				if(a[i]>b[0]&&a[i]==ch)
				{
					num++;
					if(num==m)
					{
						f[n++]=1;
						flag=1;
					    break;
					}
				}
				else if(a[i]>b[0]&&a[i]>ch)
				{
					ch=a[i];
					num=1;
				}
			}
			if(flag==0)
				f[n++]=0;
		}
		else 
		{
			for(int i=0;i<=a.size()-5;i++)
			{
				if(a[i]>b[0]&&(a[i+1]==a[i]+1&&a[i+2]==a[i]+2&&a[i+3]==a[i]+3&&a[i+4]==a[i]+4))
				{
					f[n++]=1;
					flag=1;
					break;
				}
			}
			if(flag==0)
				f[n++]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}