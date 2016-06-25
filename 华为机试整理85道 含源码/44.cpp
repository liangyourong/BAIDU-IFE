#include <iostream>
using namespace std;
int MaxY(int a,int b)
{
 int min, max;
 max=a>b?a:b;
 min=a<b?a:b;
 if(max%min==0)
  return min;
 else
 return MaxY(min,max%min);
} 
int main()
{
 int a,b;
 int MAXY =0,MINB=0;
 cout<<"输入两个整数,用空格或回车键分隔:";
 cin>>a>>b;
 MAXY = MaxY(a,b);
 MINB = a*b/MAXY;
 cout<<"这两个整数的最大公约数为:"<<MAXY<<endl;
 cout<<"这两个整数的最小公倍数为:"<<MINB<<endl;
 return 0;
}