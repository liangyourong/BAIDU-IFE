#include<iostream>
#include<string>
using namespace std;
int compare(const string &num1,const string &num2)               //比较大小，确定符号
{
	int m1=num1.size();
	int m2=num2.size();
	if(m1>m2)
		return 1;
	else if(m1<m2)
		return 0;
	else
	{
		for(int i=0;i<m1;i++)
		{
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return 0;
		}
	}
	return 2;
}
string minu(string &num1,string &num2)
{
	int flag=0,del;
	string num;
	int m1=num1.size();
	int m2=num2.size();
	for(int i=0;i<m2;i++)
	{
		del=num1[m1-1-i]-num2[m2-1-i]-flag;
		if(del<0)
		{
			num.push_back(del+10+'0');
			flag=1;
		}
		else
		{
			num.push_back(del+'0');
			flag=0;
		}
	}
	if(m1>m2)                                          //m1>=m2
	{
		for(int i=m1-m2-1;i>=0;i--)
		{
			del=num1[i]-'0'-flag;
			if(del<0)
			{
				num.push_back(del+10+'0');
				flag=1;
			}
			else
			{
				num.push_back(del+'0');
				flag=0;
			}
		}
	}
	int m=num.size(),f=0;
	for(int i=m-1;i>=0;i--)                             //找出结尾的个数（反过来是开头）
	{
		if(num[i]=='0')
			f++;
		else
			break;
	}
	if(f>0)
		num.erase(m-f);                   //去掉结尾的
	m=num.size();
	char c;
	for(int i=0;i<m/2;i++)                         //颠倒顺序，成为结果数
	{
		c=num[i];
		num[i]=num[m-1-i];
		num[m-1-i]=c;
	}
	return num;
}
int main()
{  
	string num1,num2,num;
	cin>>num1>>num2;
	int m=compare(num1,num2);
	if(m==2)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else if(m==1)
		num=minu(num1,num2);
	else 
	{
		num.push_back('-');
		num.append(minu(num2,num1));                 //负数是追加结果，先加负号
	}
	cout<<num<<endl;
	return 0;	
}