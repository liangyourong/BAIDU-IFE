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
 cout<<"������������,�ÿո��س����ָ�:";
 cin>>a>>b;
 MAXY = MaxY(a,b);
 MINB = a*b/MAXY;
 cout<<"���������������Լ��Ϊ:"<<MAXY<<endl;
 cout<<"��������������С������Ϊ:"<<MINB<<endl;
 return 0;
}