#include<iostream>
#include<string>
using namespace std;
int compare(string &num1,string &num2);
string &add(string &num1,string &num2,string &result);
string &minu(string &num1,string &num2,string &result);
int main()
{  
	string num1,num2,result,temp;
	cin>>num1>>num2;
	if(num1[0]=='-'&&num2[0]=='-')                      //两个负数
	{
		num1.erase(0,1);
		num2.erase(0,1);
		result.push_back('-');
		add(num1,num2,result);
	}
	else if((num1[0]!='-'&&num2[0]=='-')||(num2[0]!='-'&&num1[0]=='-'))            //一正一负，比较绝对值大小确定结果正负号
	{
		if(num2[0]=='-')
		    num2.erase(0,1);
		else
		{
			num1.erase(0,1);
			temp=num1;
			num1=num2;
			num2=temp;
		}
		int m=compare(num1,num2);
		if(m==0)
		{
			result.push_back('-');
			minu(num2,num1,result);
		}
		else if(m==1)
			minu(num1,num2,result);
		else                                                 //两数相等输出
			result.push_back('0');
	}
	else
		add(num1,num2,result);
	cout<<result<<endl;

	return 0;	
}

int compare(string &num1,string &num2)                        //比较绝对值大小
{
	if(num1.size()<num2.size())
		return 0;
	else if(num1.size()>num2.size())
		return 1;
	else
	{
		for(int i=0;i<num1.size();i++)
		{
			if(num1[i]<num2[i])
				return 0;
			else if(num1[i]>num2[i])
				return 1;
		}
		return 3;
	}
}
string &add(string &num1,string &num2,string &result)
{
	string temp;
	int m1=num1.size();
	int m2=num2.size();
	int m=m1>=m2?m2:m1;
	int flag=0,num;
	for(int i=0;i<m1&&i<m2;i++)
	{
        num=(num1[m1-1-i]-'0')+(num2[m2-1-i]-'0')+flag;
		if(num>=10)
		{
			flag=1;
		   temp.push_back(num%10+'0');
		}
		else
		{
			temp.push_back(num+'0');
			flag=0;
		}
	}
	if(m1>m2)
	{
		for(int i=m1-1-m;i>=0;i--)
		{
			num=(num1[i]-'0')+flag;
			if(num>=10)
			{
				temp.push_back(num%10+'0');
			   	flag=1;
			}
			else
			{
				temp.push_back(num+'0');
				flag=0;
			}
		}
	}
	else if(m1==m2)                                        //两数位数相同时，第一位是否要进位
	{
		if(flag==1)
			temp.push_back('1');
	}
	else
	{
		for(int i=m2-1-m;i>=0;i--)
		{
			num=(num2[i]-'0')+flag;
			if(num>=10)
			{
				temp.push_back(num%10+'0');
			   	flag=1;
			}
			else
			{
				temp.push_back(num+'0');
				flag=0;
			}
		}
	}
	int n=temp.size();
	char c;
    for(int i=0;i<n/2;i++)
	{
         c=temp[i];
		 temp[i]=temp[n-1-i];
		 temp[n-1-i]=c;
	}
	
	result.append(temp);
	return result;
}
string &minu(string &num1,string &num2,string &result)       //num1的位数肯定大于等于num2的位数！
{
	string temp;
	int m1=num1.size();
	int m2=num2.size();
	int flag=0,num;
	for(int i=0;i<m2;i++)                                         //不够减要借位
	{
		num=num1[m1-1-i]-num2[m2-1-i]-flag;
		if(num<0)
		{
			flag=1;
		    temp.push_back(num+10+'0');
		}
		else
		{
			temp.push_back(num+'0');
			flag=0;
		}

	}
	if(m1>m2)
	{
		for(int i=m1-1-m2;i>=0;i--)
		{
			num=(num1[i]-'0')-flag;
			if(num<0)
			{
				temp.push_back(num+10+'0');
			   	flag=1;
			}
			else
			{
				temp.push_back(num+'0');
				flag=0;
			}
		}
	}
	int n=temp.size();
	char c;
    for(int i=0;i<n/2;i++)                      
	{
         c=temp[i];
		 temp[i]=temp[n-1-i];
		 temp[n-1-i]=c;
	}
	int pos=0;                                 //要去掉数前面的0
	for(int i=0;i<n;i++)
	{
		if(temp[i]=='0')
			pos++;
		else
			break;
	}
	temp.erase(0,pos);
	result.append(temp);

	return result;
}