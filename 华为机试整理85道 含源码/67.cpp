#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
bool is_dev(string str)
{
	int m=str.size();
	if(m>20)
		return false;
	for(int i=0;i<m;i++)
	{
		if(!isalnum(str[i]))
			return false;
	}
	return true;
}

bool is_user(string str)
{
	int m=str.size();
	if(m!=8)
		return false;
	for(int i=0;i<m;i++)
		if(!isdigit(str[i]))
			return false;
	return true;
}
int main(int argc,char *argv[])
{   
	vector<string> dev,ud_dev,users,u_and_dev;
	vector<string>::iterator iter,iter1;
	int a,b,c,d;
	string dev1,user,d_u;
	cin>>a>>b>>c>>d;
	for(int i=0;i<a;i++)
	{
		cin>>dev1;
		iter=find(dev.begin(),dev.end(),dev1);
		if(!is_dev(dev1)||iter!=dev.end())                //dev名称合法，没有重复添加
			cout<<"add computers error"<<dev1<<endl;
		else
			dev.push_back(dev1);
	}
	for(int i=0;i<b;i++)
	{
		cin>>dev1;
		iter=find(dev.begin(),dev.end(),dev1);
		if(iter==dev.end())                               //dev在设备列表里
			cout<<"remove computers error:"<<dev1<<endl;
		else
			dev.erase(iter);
	}
	for(int i=0;i<c;i++)
	{
		cin>>dev1>>user;
		iter=find(dev.begin(),dev.end(),dev1);
		iter1=find(ud_dev.begin(),ud_dev.end(),dev1);
		if(!is_user(user)||iter==dev.end()||iter1!=ud_dev.end())    //用户名合法，dev在设备列表里，dev没重复添加
			cout<<"assign computer error:"<<dev1<<"_"<<user<<endl;
		else
		{
			ud_dev.push_back(dev1);
			iter=find(users.begin(),users.end(),user);
			if(iter==users.end())
				users.push_back(user);
			d_u=user+"_"+dev1;
			u_and_dev.push_back(d_u);	
		}
	}
	for(int i=0;i<d;i++)
	{
		cin>>dev1>>user;
		d_u=user+"_"+dev1;
		iter=find(ud_dev.begin(),ud_dev.end(),dev1);
		iter1=find(u_and_dev.begin(),u_and_dev.end(),d_u);
		if(iter1==u_and_dev.end())                            //dev-user在对应关系列表里
			cout<<"remover computer from worker error:"<<dev1<<"_"<<user<<endl;
		else
		{
			u_and_dev.erase(iter1);
			ud_dev.erase(iter);
		}
	}
	sort(ud_dev.begin(),ud_dev.end());
	sort(users.begin(),users.end());
	cout<<ud_dev.size()<<endl;
	for(int i=0;i<users.size();i++)            //先按员工号
		for(int j=0;j<ud_dev.size();j++)       //再按设备号
		{
			d_u=users[i]+"_"+ud_dev[j];       //u_and_dev里寻找
			iter=find(u_and_dev.begin(),u_and_dev.end(),d_u);
			if(iter!=u_and_dev.end())
			{
				cout<<(*iter)<<endl;           //输出对应关系
				u_and_dev.erase(iter);
			}
		}
		return 0;
}