#include<iostream>
#include<cmath>
using namespace std;
int main(int argc,char *argv[])
{   
	int m,sq,mid,s;
	cin>>m;
	sq=pow((double)m,3);
	mid=sq/m;
	if(m%2==1) 
		s=mid-(m/2)*2;
	else
		s=mid-1-((m-1)/2)*2;
	for(int i=0;i<m-1;i++)
		cout<<s+2*i<<"+";
	cout<<s+2*(m-1)<<endl;
	return 0;
}