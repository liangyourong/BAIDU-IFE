#include <iostream>
using namespace std;
int find(int a[],int len);
void main()
{
	int a[]={1,2,3,5,7,8,16};
	int len=sizeof(a)/sizeof(int);
	cout << "符合条件的有：";
	cout<<"共"<< find(a,len) << "个"<<endl;
}
int find(int a[],int len)
{
	int i;
	int count=0;
	for(i=0;i<len;i++)
	{
		if(0==(a[i]&(a[i]-1)))
		{
			cout << a[i] << " ";
			count++;
		}
	}
	cout << endl;
	return count;
}