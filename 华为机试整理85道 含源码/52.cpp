#include<iostream>
using namespace std;
int main()
{
	int n,S_num=0,T_num=0;
	cout << "n=";
	cin>>n;
	char ch;
	getchar();
	for(int i=0;i < n;i++)
	{
		while(1)
		{
			ch=getchar();
			if(ch=='\n')
				break;
			if(ch=='s'||ch=='S')
				S_num++;
			if(ch=='t'||ch=='T')
				T_num++;
		}
	}
	if(S_num>T_num)
		cout<<"English\n";
	else
		cout<<"Deutsch\n";
	return 0;
}