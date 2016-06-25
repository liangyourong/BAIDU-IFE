#include<iostream>
using namespace std;
void main()
{
	int  i,n,a,sum,max,min;             
	//用i来做计数器，用n来做总数，sum就是总和，max即是最大数，
	//min即是最小数
	cout << "请输入要比较的数字的个数 n = "<<endl;
	cin >>n ;
	cout<<"请输入第1个数:" <<endl;
	cin >>a;                       
	min=a;                      //初始化各数
	max=a;
	sum=a;
	for( i=1;i<n;++i)            //循环应用
	{   
		cout << "请输入第"<<i+1<<"个数"<<endl;
		cin >> a;
		if(a>max)  {max=a;}
		if(a<min)  {min=a;}
		sum+=a;
	}

	cout <<"  最大数max = " << max <<  "  最小数min = "<< min <<endl;
	cout << "除去最大数和最小数的总和为sum = " << sum-max-min <<endl; 
	cout  <<"此时平均数" << (sum-max-min)/(n-2)<<endl;    //平均数是n-2个数的还是n个数的，你自己改吧

}