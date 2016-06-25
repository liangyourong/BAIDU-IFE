#include <stdio.h>
#include<string.h>
#include<malloc.h>
void stringFilter(const char *p_str, long len, char *p_outstr)
{
	int array[256]={0}; 
	const char *tmp = p_str;
	for(int j=0;j<len;j++)
	{
		if(array[tmp[j]]==0)
			*p_outstr++= tmp[j];
		array[tmp[j]]++;
	}
	*p_outstr = '\0';
}

void main()
{
	char  *str = "abacacde";
	int len = strlen(str);	
	char * outstr = (char *)malloc(len*sizeof(char));
	stringFilter(str,len,outstr);
	printf("%s\n",outstr);
	free(outstr);
	outstr = NULL;
}