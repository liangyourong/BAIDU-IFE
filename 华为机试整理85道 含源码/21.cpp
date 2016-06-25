#include <stdio.h>

int main()
{
	char str1[20]={"Hello "}, str2[20]={"World"};
	char *p=str1, *q=str2;

	while( *p ) p++;
	while( *q ) 
	{
		*p = *q;
		p++;
		q++;
	}
	*p = '\0';
	printf("%s\n", str1);

	return 0;
}