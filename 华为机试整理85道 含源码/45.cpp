#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{   
	int n,num=0,p,m;
	int a,b,flag;
	cin>>n;
	cout << "0 1 ";
	for(int i=0;i<n;i++)           //n以内包不包含n看题目要求
	{
		m=i;
		flag=1;
		if(0==m||1==m)
			num++;
		else
		{
			p=m*m;
			while(m>0)
			{
				a=m%10;
				b=p%10;
				if(a!=b)
				{
					flag=0;
					break;
				}
				m/=10;
				p/=10;
			}
			if(flag==1)
			{
				cout << i << " ";
				num++;
			}
		}
	}
	cout << endl;
	cout<<num<<endl;
	return 0;
}