#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int delete_sub_str(const char *str,const char *sub_str,char *result)
{
	assert(str != NULL && sub_str != NULL);
	const char *p,*q;
	char *t,*temp;
	p = str;
	q = sub_str;
	t = result;
	int n,count = 0;
	n = strlen(q);
	temp = (char *)malloc(n+1);
	memset(temp,0x00,n+1);
	while(*p)
	{
		memcpy(temp,p,n);
		if(strcmp(temp,q) == 0 )
		{
			count++;
			memset(temp,0x00,n+1);
			p = p + n;
		}
		else
		{	
			*t = *p;
			p++;
			t++;
			memset(temp,0x00,n+1);
		}	
	}
	free(temp);
	return count;
}
void main()
{
	char s[100] = {'\0'};
	int num = delete_sub_str("123abc12de234fg1hi34j123k","123",s);
	printf("The number of sub_str is %d\r\n",num);
	printf("The result string is %s\r\n",s);
}