#include <stdio.h>  
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
void DivideString(const char *pInputStr, long lInputLen, char *pOutputStr)  
{  

	int cnt;  
	const char *p=pInputStr;
	while(*p!=NULL)  
	{  
		if(*p!=' ')  
		{   cnt = 0;  
		*pOutputStr++ = *p++;  
		}  
		else  
		{   cnt++;  
		p++;  
		if(cnt==1)    
			*pOutputStr++ = ',';  

		}         
	}  
	*pOutputStr++ = ',';  
	*pOutputStr = '\0';  
}  

void main()  
{  
	char *str = "abc def  gh i    d";  
	long len = strlen(str);  
	char *outstr = (char*)malloc(sizeof(str));  
	//char outstr[100];  
	DivideString(str,len,outstr);  
	printf("%s",outstr);  
	printf("\n");  
}  
