#include<iostream>
#include<string>
using namespace std;
int compare(string num1,string num2,int &n1,int &n2)
{
	int m1=num1.size(),m2=num2.size(),flag=1;
	for(int i=0;i<m1;i++)
	{
		if(num1[i]=='.')
		{
			n1=i;
			flag=0;
			break;
		}
		if(i==m1-1)
			n1=m1;

	}
	flag=1;
	for(int i=0;i<m2;i++)
	{
		if(num2[i]=='.')
		{
			n2=i;
			flag=0;
			break;
		}
		if(i==m2-1)
			n2=m2;
	}
	if(n1>n2)                                 //比较整数部分
		return 1;
	else if(n1<n2)
		return 0;
	else 
	{
		for(int i=0;i<num1.size()&&i<num2.size();i++)             //整数部分相同，比较小数部分
		{
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return 0; 
		}	
		if(m1>m2)                               //考虑到最后为0时，小数位数多也说不定相等
		{
			for(int i=m2;i<m1;i++)
			{
				if(num1[i]!='0')
					return 1;
			}
			return 2;
		}
		else if(m1<m2)
		{
			for(int i=m1;i<m2;i++)
			{
				if(num2[i]!='0')
					return 1;
			}
			return 2;
		}
		else
			return 2;
	}
}
string minu(string num1,string num2,int &n1,int &n2)
{
	string temp;
	int flag=0;
	int m1=num1.size();
	int m2=num2.size();
	int s1,s2;
	if(m1==n1)                   //考虑数字中有没有小数点
		s1=0;
	else
		s1=m1-n1-1;
	if(m2==n2)
		s2=0;
	else
		s2=m2-n2-1;
	if(s1>s2)                      //补0使两个数小数部分位数相同
	{
		if(s2==0)
			num2.push_back('.');
		num2.append(s1-s2,'0');
	}
	else if(s1<s2)
	{
		if(s1==0)
			num1.push_back('.');
		num1.append(s2-s1,'0');

	}
	m1=num1.size();
	m2=num2.size();
	int d;
	for(int i=0;i<m1&&i<m2;i++)
	{   
		if(num1[m1-i-1]=='.')                      //遇到小数点跳过，小数点入字符串
		{
			temp.push_back('.');
			continue;
		}
		d=num1[m1-1-i]-num2[m2-1-i]-flag;
		if(d<0)
		{
			temp.push_back(d+10+'0');
			flag=1;
		}
		else
		{
			temp.push_back(d+'0');
			flag=0;
		}
	}
	if(m1>m2)
	{
		for(int i=m1-m2-1;i>=0;i--)
		{
			d=num1[i]-'0'-flag;                   //（-'0'）没有约掉，不要丢了
			if(d<0)
			{
				temp.push_back(d+10+'0');
				flag=1;
			}
			else
			{
				temp.push_back(d+'0');
				flag=0;
			}
		}
	}
	int len=temp.size();
	for(int i=len-1;i>=0;i--)                //去掉小数点前多余的0，必须从尾开始删
	{
		if(temp[i]=='0')
			temp.erase(i);
		else if(temp[i]=='.')
			temp.push_back('0');
		else
			break;
	}
	char c;
	len=temp.size();                          //倒序
	for(int i=0;i<len/2;i++)
	{
		c=temp[i];
		temp[i]=temp[len-1-i];
		temp[len-1-i]=c;
	}
	for(int i=len-1;i>=0;i--)                      //去掉小最后后多余的0和多余的小数点‘.’
	{
		if(temp[i]=='0'||temp[i]=='.')
			temp.erase(i);                      //只能从后开始删尾，因i是递减
		else
			break;
	}
	return temp;

}
int main()
{  
	string num1,num2,result;
	int n1,n2;
	cout << "请依次输入减数和被减数：";
	cin>>num1>>num2;
	int m=compare(num1,num2,n1,n2);
	cout << "结果是：";
	if(m==0)
	{
		result.push_back('-');
		result.append(minu(num2,num1,n2,n1));
	}
	else if(m==1)
		result.append(minu(num1,num2,n1,n2));
	else
		result="0";
	cout<<result<<endl;
	return 0;	
}