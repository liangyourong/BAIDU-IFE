#include<iostream>
#include<string>
using namespace std;
string to_num(int m)
{
	string temp;
	while(m>0)
	{
		temp.push_back(m%10+'0');
		m/=10;
	}
	int n=temp.size();
	char t;
	for(int i=0;i<n/2;i++)
	{
		t=temp[i];
		temp[i]=temp[n-1-i];
		temp[n-1-i]=t;
	}
	return temp;
}
int main()
{  
	string str,temp,num;
	getline(cin,str);
	int m=1;
	int n=str.size();
	for(int i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
			m++;
		else 
		{
			temp.push_back(str[i]);
			if(m>1)
			{
				num=to_num(m);                  //要考虑吗>=10的情况
				temp.append(num);
				m=1;
			}
		}

	}
	temp.push_back(str[n-1]);
	if(m>1)
	{
		num=to_num(m);
		temp.append(num);
	}
	cout<<temp<<endl;
	return 0;	
}