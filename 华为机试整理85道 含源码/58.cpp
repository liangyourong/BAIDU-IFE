#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(int argc,char *argv[])
{   
	string key,str,str1,result;
	int m;
	cin>>key>>str;
	for(int i=0;i<key.size();i++)        //字典全转化为大写
	{   
		key[i]=toupper(key[i]);
		m=str1.find(key[i]);
		if(m<0)
			str1.push_back(key[i]);
	}
	while(str1.size()<26)
	{
		for(int i=65;i<=90;i++)
		{
			m=str1.find(i);
			if(m<0)
				str1.push_back(i);
		}
	}
	int pos;
	char c;
	cout<<str1<<endl;
	for(int i=0;i<str.size();i++)
	{
		if(isupper(str[i]))           //根据要加密的字符大小写分类讨论
		{
			pos=str[i]-65;
			c=str1[pos];
			if(islower(c))
				c=toupper(c);
			result.push_back(c);
		}
		else
		{
			pos=str[i]-97;
			c=str1[pos];
			if(isupper(c))
				c=tolower(c);
			result.push_back(c);
		}		
	}
	cout<<result<<endl;
	return 0;
}s