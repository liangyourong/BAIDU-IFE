#include<iostream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;
int main(int argc,char *argv[])
{   
	string str;
	char *temp[3];
	for(int i=0;i<3;i++)
		temp[i]=new char[5];
	getline(cin,str);
	int s=str.size(),n=0,pos=0;
	for(int i=0;i<s;i++)
	{
		if(isspace(str[i]))
		{   
			temp[n][pos]='\0';
			pos=0;
			n++;
		}
		else
			temp[n][pos++]=str[i];
	}
	temp[n][pos]='\0';
	int y,m,d,days=0;
	y=atoi(temp[0]);
	m=atoi(temp[1]);
	d=atoi(temp[2]);
	if(m<1||m>12)
		return 0;
	if(d<1||d>31)
		return 0;
	for(int i=1990;i<y;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
			days+=366;
		else
			days+=365;

	}
	for(int i=1;i<m;i++)
	{
		if(1==i||3==i||5==i||7==i||8==i||10==i||12==i)
			days+=31;
		else if(4==i||6==i||9==i||11==i)
			days+=30;
		else if((y%4==0&&y%100!=0)||y%400==0)
			days+=29;
		else
			days+=28;
	}
	days+=(d-1);
	int flag;
	flag=days%6;
	if(flag>=0&&flag<=2)
		cout<<"Fishing"<<endl;
	else
		cout<<"Netting"<<endl;
	for(int i=0;i<3;i++)
		delete []temp[i];
	return 0;
}