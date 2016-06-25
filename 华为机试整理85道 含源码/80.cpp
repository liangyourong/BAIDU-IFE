#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
int verifyIDCard(char *);
int main()
{  
	char input[100];
	cin.getline(input,100);
	int m=verifyIDCard(input);
	cout<<m<<endl;
	return 0;	
}
int verifyIDCard(char input[])
{
	int m=strlen(input);
	if(m!=18)
		return 1;
	for(int i=0;i<17;i++)
		if(!isdigit(input[i]))
			return 2;
	if(!isdigit(input[17])&&input[17]!='x')
		return 3;
	int year=(input[6]-'0')*1000+(input[7]-'0')*100+(input[8]-'0')*10+(input[9]-'0');
	if(year<1900||year>2100)
		return 4;
	int month=(input[10]-'0')*10+(input[11]-'0');
	if(month<1||month>12)
		return 5;
	int day=(input[12]-'0')*10+(input[13]-'0');
	if(day<1||day>31)
		return 6;
	if(day==31&&(month==4||month==6||month==9||month==11))
		return 6;
	if(day>=30&&month==2)
		return 6;
	if(day==29&&month==2&&(year%4!=0||(year%100==0&&year%400!=0)))
		return 6;
	return 0;
}