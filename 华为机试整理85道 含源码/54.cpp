#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string name[10]={"wang fei","zhang man yu","zhang zhi yi","li li","li xiao man","li yu cun","yang ni","xiao tong","li lei","zhang san"};
int main()
{  
	string mname,temp;
	getline(cin,mname);
	int m=mname.size(),n,a,count=0,max=0,pos;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(isalpha(mname[j]))
			{
				n=name[i].find(mname[j]);
				a=temp.find(mname[j]);
				if(n>=0&&a<0)
				{
					count++;
					temp.push_back(mname[j]);
				}
			}  
		}
		if(count>max)
		{
			max=count;
			pos=i;
		}
		temp.erase();
		count=0;
	}
	cout<<name[pos]<<endl;
	return 0;	
}