#include<iostream>   
#include<string.h>   
#include<algorithm> //这个是调用sort函数必须的头文件     
using namespace std;   
int arr[31];   
int main()   
{   
	for (int i=0;i<=29;i++) cin>>arr[i];   
	sort(arr,arr+30); //从小到大排序     
	//从最小的开始装框，直到装满了为止。   
	int sum=0,i;   
	for (i=0;i<=29;i++)   
	{   
		if (sum+arr[i]>100) break; //如果不能装了就立刻停下来   
		sum=sum+arr[i]; //否则就把这个也装进去   
	}   
	//程序跳出的那个位置的i，就是我们一共装了的数量，如果全部都装了，则i=30   
	cout<<i<<endl;   
} 