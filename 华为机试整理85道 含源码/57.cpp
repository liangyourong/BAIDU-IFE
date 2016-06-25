#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int ip(const string,const string*,int);
int to_num(char*,int);
int main()
{  
	//freopen("ip.txt","r",stdin);
	string ip_addr,net_addr_array[10];
	cin>>ip_addr;
	int m=-1;
	while(cin>>net_addr_array[++m]);
	int n=ip(ip_addr,net_addr_array,m);
	cout<<n<<endl;
	return 0;	
}
int to_num(char num[],int m)
{
	int a=0;
	for(int i=0;i<m;i++)
	{
		a+=(num[i]-'0')*pow(10.0,m-1-i);
	}
	return a;
}
int ip(const string a,const string b[],int n)
{
	long long s1=0,s2=0,s3=0,s=0,pos=100;
	int m1=0,m2=0,p=3;
	char num[4];
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='.')
		{
			s1+=to_num(num,m1)*pow(256.0,p);
			p--;
			m1=0;
		}
		else
			num[m1++]=a[i];
	}
	s1+=to_num(num,m1);
	for(int j=0;j<n;j++)
	{
		m2=0;
		p=3;
		s2=0;
		for(int i=0;i<b[j].size();i++)
		{
			if(b[j][i]=='.')
			{
				s2+=to_num(num,m2)*pow(256.0,p);
				p--;
				m2=0;
			}
			else if(b[j][i]=='/')
			{
				s2+=to_num(num,m2);
				m2=0;
				p=3;
				s3=s2;
				s2=0;

			}
			else
				num[m2++]=b[j][i];
		}
		s2+=to_num(num,m2);
		//cout<<s1<<endl<<s2<<endl<<s3<<endl;
		if(((s1&s2)==s3)&&s2>s)
		{
			s=s2;
			pos=j;
		}
	}
	return pos;
}