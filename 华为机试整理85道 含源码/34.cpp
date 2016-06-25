#include <iostream>
#include <algorithm>
using namespace std;
void fun(int input[3][4], const int m, const int n, int output[4]);
int main()
{
	int input[3][4] = { {21,48,86,92},
	{10,23,12,69},
	{46,78,49,13}};
	int output[4]={0};
	fun(input, 3, 4, output);
	cout<<"原二维数组是："<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"每列最小值是："<<endl;
	for (int k=0; k<4; k++)
	{
		cout<<output[k]<<" ";
	}
	cout << endl;
	sort(output,output+4);
	cout <<"二维数组的最小值是：" << output[0];
	cout<<endl;
	return 0;
}
void fun(int input[3][4], const int m, const int n, int output[4])
{
	int i = 0;
	int j = 0;
	for (i=0; i<n; i++)
	{
		output[i] = input[0][i];
		for (j=0; j<m; j++)
		{
			if (output[i] > input[j][i])
			{
				output[i] = input[j][i];
			}
		}
	}
}