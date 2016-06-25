#include<iostream>
using namespace std;
void panduan(int,int,int,const int&,const int&);
int main(int argc,char *argv[])
{
	int m,s,t;
	cin>>m>>s>>t;
	if(s==0)
	{
		cout<<"YES 0"<<endl;
		return 0;
	}
	if(t<=m/10)         //魔法无限也不够
	{
		cout<<"No"<<" "<<60*t<<endl;
		return 0;
	}
	if((m/10)*60>=s)        //初始魔法足够飞出去了
	{
		cout<<"Yes"<<" "<<s/60+1<<endl;
		return 0;
	}
	int s1=s,t1=t;
	s=s-(m/10)*60;    //才开始先把魔法用到不能用，应为魔法够的时候用魔法快
	t=t-m/10;
	m=m%10;
	panduan(m,s,t,s1,t1);
	return 0;
}
void panduan(int m,int s,int t,const int &s1,const int &t1 )    //一秒一秒判断
{
	cout<<s<<"*"<<t<<"*"<<m<<endl;
	if(s<=0)
	{
		cout<<"Yes"<<" "<<t1-t<<endl;
		return;
	}
	if(t<=0)
	{
		cout<<"No"<<" "<<s1-s<<endl;
		return;
	} 
	if(m>=10)      //魔法值大于直接用技能
	{
		m-=10;
		s-=60;
		t--;
	}
	else if(s<=17)  //可以直接出就直接出
	{
		s-=17;
		t--;
	}		
	else 
	{
		int t2,m1;
		if((10-m)%4==0)        //计算需要几秒才能有魔法飞
			t2=(10-m)/4;
		else
			t2=(10-m)/4+1;
		if(t<7&&t2>2)            //时间剩余小于秒而且魔法回复时间大于则直接走比较快。
		{            //如果时间大于秒则可以恢复两次魔法，即使初始值小于使用魔法走的比较远
			s-=17;
			t--;
		}
		else if(t2+1<=t&&s>17*(t2+1))     //总时间够停下回复魔法
		{
			t--;
			m+=4;
		}
		else        //虽然魔法速度快，但是时间不够
		{
			t--;
			s-=17;
		}
	}
	panduan(m,s,t,s1,t1);	
}