#include<iostream>
#include<string>
using namespace std;
int getnum(int m,int n)
{
	if(m==1||n==1)
		return 1;
	/*if(n==0||m==0)
	return 0;*/
	if(m<n)
		return getnum(m,m);
	if(m>n)
		return getnum(m,n-1)+getnum(m-n,n);
	if(m==n)
		return 1+getnum(m,n-1);

}
int main(int argc,char *argv[])
{
	int m,n;
	cin>>m>>n;
	int num=getnum(m,n);
	cout<<num<<endl;
	return 0;
}