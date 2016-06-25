#include<iostream>
#include<string>
#include<vector>
using namespace std;
int qishui(int);
int main(int argc,char *argv[])
{
	vector<int> num;
	int m;
	cin>>m;
	while(m>0)
	{
		num.push_back(qishui(m));
		cin>>m;
	}
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<" ";
	cout<<endl;
	return 0;
}
int qishui(int m)
{
	int num=0,n,b;
	while(m>=3)
	{
		n=m/3;
		b=m%3;
		num+=n;
		m=n+b;
	}
	if(m==2)
		num++;
	return num;
}