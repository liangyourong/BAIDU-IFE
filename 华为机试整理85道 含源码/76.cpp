#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
{

	int a,b,c,flag=1;
	char str[33];
	cin>>a>>b;
	int visit[10000]={0};                  //除数的范围设定
	string num,temp;
	if((a<0&&b>0)||(a>0&&b<0))           //正负判断！！
	{
		num.push_back('-');
		a=abs(a);
		b=abs(b);
	}
	else
	{
		a=abs(a);
		b=abs(b);
	}
	c=a/b;
	a=a%b;
	_itoa_s(c,str,10);    //商先存入
	num.append(str);
	if(a==0)           //商为整数，直接输出
	{
		cout<<num<<endl;
		return 0;
	}
	num.push_back('.');           //余数不为，下面*10操作只考虑个位数了
	while(visit[a]==0)          //余数相等说明开始循环
	{ 
		visit[a]=1;	              //出现过的余数情况
		a=a*10;		
		temp.push_back(a/b+'0');     //存入商，肯定小于10
		a=a%b;                       //新余数
		if(a==0)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
		num.append(temp);
	else
	{
		num.push_back('(');
		num.append(temp);
		num.push_back(')');
	}
	cout<<num<<endl;

	return 0;
}