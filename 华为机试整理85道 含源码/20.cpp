#include <stdio.h>
#include <string.h>

void str_replace(char *str_src,char *str_find,char *str_rpl);

int main ()
{
	char str[100]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str_find[]="RST";
	char str_rpl[]="ggg";
	str_replace(str,str_find,str_rpl);
	//puts(str);
	return 0;
}

void str_replace(char *str_src,char *str_find,char *str_rpl)
{
	char temp[100];
	int n=strlen(str_find);
	char *p;
	p=str_rpl;
	char *q=temp;
	while(*str_src)
	{
		if(strncmp(str_src,str_find,n)==0)
		{
			while(*p)
			{*q=*p;
			q++;
			p++;}
			p=str_rpl;
			str_src+=n-1;
		}
		else
		{*q=*str_src;
		q++;}
		str_src++;
	}

	*q='\0';
	puts(temp);
	strcpy(str_src,temp);
} 