#include<iostream>
#include<string>
using namespace std;
void display(int m)
{
	cout<<"+----------+"<<endl;
	int n=10-m/10;
	for(int i=0;i<n;i++)
		cout<<"|----------|"<<endl;
	for(int i=0;i<m/10;i++)
		cout<<"|++++++++++|"<<endl;
	cout<<"+----------+"<<endl;
	return;
}
int main()
{  
	int n;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	for(int i=0;i<n-1;i++)
	{
		display(p[i]);
		cout<<"==============="<<endl;
	}
	display(p[n-1]);
	delete []p;
	return 0;	
}