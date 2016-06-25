#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}

int meili(const string &str)
{   
	int a[26]={0};
	int len=0,pos;
	for(int i=0;i<str.size();i++)
	{
		if(isupper(str[i]))
			pos=str[i]-65;
		else
			pos=str[i]-97;
		a[pos]++;
	}
	sort(a,a+26,cmp);
	for(int i=0;a[i]!=0;i++)
	{
		len+=(26-i)*a[i];
	}
	return len;
}
int main(int argc,char *argv[])
{   
	int n;
	cin>>n;
	int *len=new int[n];
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		len[i]=meili(str);
	}
	for(int i=0;i<n;i++)
		cout<<len[i]<<endl;
	delete []len;
	return 0;
}