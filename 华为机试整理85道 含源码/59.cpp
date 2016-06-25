#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define LENGTH  13

int verifyMsisdn(char *inMsisdn)
{

	char *pchar=NULL;
	assert(inMsisdn!=NULL);
	if(LENGTH==strlen(inMsisdn))
	{
		if(('8'==*inMsisdn)&&(*(inMsisdn+1)=='6'))
		{
			while(*inMsisdn!='\0')
			{
				if((*inMsisdn>='0')&&(*inMsisdn<='9'))  //判断字符串全为数字
					inMsisdn++;
				else
					return 2 ; //return 会跳出被调用函数
			}
		}
		else
			return 3;
	}
	else
		return 1;
	return 0;
}

int main()
{
	char pchar[100]={};
	gets(pchar);
	int result;
	result =verifyMsisdn(pchar);
	printf("result is %d\n",result);
}