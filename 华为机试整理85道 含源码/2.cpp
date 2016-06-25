#include<iostream>   
#include<string.h>   
#include<algorithm> //这个是调用sort函数必须的头文件     
using namespace std;   
int arr[10];   
int cal(int x) //计算一个数字各个位上的和   
{   
	int ans=0;   
	while (x!=0)   
	{   
		ans+=x%10;   
		x/=10;   
	}   
	return ans;
}   
int cmp(int i,int j)   
{   
	if (cal(i)!=cal(j)) //如果两个数字各个位上的和不相同，则按照各个位上的和来排序   
	{   
		return cal(i)<cal(j);   
	}   
	else  //否则，即两个数各个位上的和相等，则按照数字本身来排序     
	{   
		return  i<j;   
	}   
}   
int main()   
{   
	for (int i=0;i<=9;i++) cin>>arr[i];   
	sort(arr,arr+10,cmp);   
	for (int i=0;i<=9;i++)   
	{   
		cout<<arr[i];   
		if (i!=9) cout<<' '; //如果不是最后一个数字，则需要在两个数字中间输出一个空格。   
	}   
	cout<<endl;   
	//PS：最后一个输出的后面一定要跟回车符而不是空格符     
}   