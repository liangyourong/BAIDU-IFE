#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void arithmetic(const char *input, long len, char *output)
{
	char s1[10];
	char s2[10];
	char s3[10];
	int cnt = 0;
	int len_input=strlen(input);
	for(int i=0;i<len_input;++i)
	{
		if(input[i]==' ')
			cnt++;
	}

	if(cnt!=2)
	{
		*output++ = '0';
		*output = '\0';
		return;
	}

	sscanf(input,"%s %s %s",s1,s2,s3);
	if(strlen(s2)!=1||(s2[0]!='+'&&s2[0]!='-'))
	{
		*output++ = '0';
		*output = '\0';
		return;

	}

	int len_s1=strlen(s1);
	int i=0;
	for(i=0;i<len_s1;i++)
	{
		if(s1[i]<'0'||s1[i]>'9')
		{
			*output++ = '0';
			*output = '\0';
			return;
		}
	}

	int len_s3=strlen(s3);
	for(i=0;i<len_s3;i++)
	{
		if(s3[i]<'0'||s3[i]>'9')
		{
			*output++ = '0';
			*output = '\0';
			return;
		}
	}

	int x = atoi(s1);
	int y = atoi(s3);
	if(s2[0]=='+')
	{
		int result = x+y;
		itoa(result,output,10);
	}
	else if(s2[0]=='-')
	{
		int result = x-y;
		itoa(result,output,10);
	}
	else
	{
		*output++ = '0';
		*output = '\0';
		return;

	}

}
void main()
{
	char str[10] = {};
	gets(str);
	char outstr[10];
	int len = strlen(str);
	arithmetic(str,len,outstr);
	printf("%s\n",outstr);	
}