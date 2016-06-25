#include <stdio.h>
#include <string.h>

void huiwen(char str[])
{
	int i,len,k=1;
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-i-1])  //str一般结尾处有\0，所以需要-1
		{
			k=0;
			break;
		}
	}
	if(k==0)
		printf("%s 不是一个回文数\n",str);
	else
		printf("%s 是一个回文数\n",str);
}
void main()
{       
	char str[100] = {0};     
	printf("Input a string：\n");        /*提示输入Input a string：*/
	scanf("%s", str);                  /*scan()函数输入一个字符串：*/
	huiwen(str);
}