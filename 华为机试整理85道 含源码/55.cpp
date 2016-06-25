#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{ 
	string str;
	cin>>str;
	int flag;
	int num[5],m=0;
	for(int i=0;i<str.size()&&m<5;i++)
	{
		if(str[i]>='2'&&str[i]<='9')
			num[m++]=str[i]-'0';
		else if(str[i]=='1'&&str[i+1]=='0')
		{
			num[m++]=10;
			i++;
		}
		else if(str[i]=='J'||str[i]=='j')
			num[m++]=11;
		else if(str[i]=='Q'||str[i]=='q')
			num[m++]=12;
		else if(str[i]=='K'||str[i]=='k')
			num[m++]=13;
		else if(str[i]=='A'||str[i]=='a')
			num[m++]=14;
		else
		{
			cout<<"输入错误"<<endl;
			return 0;
		}
	}
	qsort(num,5,sizeof(int),cmp);
	if(num[0]==num[3]||num[1]==num[4])
		flag=1;
	else if((num[0]==num[2]&&num[3]==num[4])||(num[2]==num[4]&&num[0]==num[1]))
		flag=2;
	else if((num[0]==num[2]&&num[3]!=num[4])||(num[2]==num[4]&&num[0]!=num[1])||num[1]==num[3])
		flag=3;
	else if((num[0]==num[1]&&num[2]==num[3])||(num[0]==num[1]&&num[3]==num[4])||(num[1]==num[2]&&num[3]==num[4]))
		flag=4;
	else if(num[0]==num[1]||num[1]==num[2]||num[2]==num[3]||num[3]==num[4])
		flag=7;
	else if(num[4]-num[0]==4)
		flag=5;
	else
		flag=6;
	cout<<flag<<endl;
	return 0;	
}