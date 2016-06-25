#include<iostream>
#include<string>
using namespace std;

int main()
{  
	int n,num=0,m;
	cin>>n;
	for(int i=7;i<=n;i++)
	{
		if(i%7==0)
			num++;
		else 
		{   
			m=i;
			while(m>0)
			{
				if(m%10==7)
				{
					num++;
					break;
				}
				m/=10;
			}
		}
	}
	cout<<num<<endl;
	return 0;	
}