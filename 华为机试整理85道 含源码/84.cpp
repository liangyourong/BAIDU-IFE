#include<iostream>
#include<string>
#include<cctype>
using namespace std;
void caozuo(string temp,int &x,int &y)
{
	int m=temp.size();
	if(m!=3)
		return;
	if(temp[0]!='A'&&temp[0]!='S'&&temp[0]!='W'&&temp[0]!='D')
		return;
	if(!isdigit(temp[1])||!isdigit(temp[2]))
		return;
	int n=(temp[1]-'0')*10+(temp[2]-'0');
	if(temp[0]=='A')
		x-=n;
	else if(temp[0]=='S')
		y-=n;
	else if(temp[0]=='W')
		y+=n;
	else
		x+=n;
}
int main(int argc,char *argv[])
{   
	string str,temp;
	int x=0,y=0;
	getline(cin,str);
	int m=str.size();
	for(int i=0;i<m;i++)
	{  
		if(str[i]==';'||(i==m-1&&str[i]!=';'))   //不是用大写字母做判断条件时不用退格
		{   
			if(i==m-1&&str[i]!=';')
			{
				temp.push_back(str[i]);
			}
			caozuo(temp,x,y);
			temp.erase();
		}
		else
			temp.push_back(str[i]);
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
}