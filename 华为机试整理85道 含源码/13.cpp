#include <stdio.h>
#include<string.h>
#include<malloc.h>

void stringZip(const char *p_str, long len, char *p_outstr)
{
	int count=1;
	for(int i=0;i<len;i++)
	{
		if(p_str[i]==p_str[i+1])
		{
			count++;
		}
		else
		{
			if(count>1)
			{
				*p_outstr++ = count +'0';
				*p_outstr++ =p_str[i];
			}
			else
			{
				*p_outstr++ =p_str[i];
			}
			count = 1;//注意其位置
		}
	}
	*p_outstr = '\0';
}

void main()
{
	char *str = "xxxyyyyyyz";
	printf("压缩之前的字符串为：%s\n",str);
	int len = strlen(str);
	char * outstr = (char*)malloc(len*sizeof(char));
	stringZip(str,len,outstr);
	printf("压缩之后的字符串为：%s\n",outstr);
	free(outstr);
	outstr = NULL;
}
