#include <iostream>
using namespace std;
int fun(int num);
int main()
{
	int num;
	cout<<"Please enter a integer:\n";
	cin>>num;
	cout<<fun(num)<<endl;
	return 0;
}
int fun(int num)
{
	int count = 0;
	int i = 0;
	while (num)
	{
		if (num & 1)
		{
			count++;
		}
		num = num >> 1;
		i++;
	}
	return (i-count);
}