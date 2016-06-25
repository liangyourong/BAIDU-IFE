#include<iostream>                  //本题还可以用暴力解法，从1开始判断所有数，直到遇到第n个丑数
using namespace std;
int min(int a,int b,int c)
{
	if(a>=b)
		a=b;
	return a>=c?c:a;
}
int main()
{  
	int n,num;
	cin>>n;
	if(n<1||n>500)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int *p=new int[n];
	int pos2=0,pos3=0,pos5=0;
	p[0]=1;
	for(int i=1;i<n;i++)      
	{
		p[i]=min(2*p[pos2],3*p[pos3],5*p[pos5]);           //寻找丑数，丑数乘以2，3，5还是丑数
		if(p[i]==2*p[pos2])
			pos2++;
		if(p[i]==3*p[pos3])
			pos3++;
		if(p[i]==5*p[pos5])
			pos5++;
	}
	cout<<p[n-1]<<endl;
	delete []p;
	return 0;	
}