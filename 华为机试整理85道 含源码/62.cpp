#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
	int num,s,m,h,d;
	cin>>num;
	s=num%60;
	num/=60;
	m=num%60;
	num/=60;
	h=num%24;
	d=num/24;
	cout<<d/100<<d%100/10<<d%10<<":"<<h/10<<h%10<<":"<<m/10<<m%10<<":"
		<<s/10<<s%10<<endl;     //关键在于最后怎么显示 
	return 0;
}