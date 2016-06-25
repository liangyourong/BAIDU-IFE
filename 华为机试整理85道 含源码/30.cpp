#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int array_compare(int len1, int array1[], int len2, int array2[])
{
	int count=0;
	for( ;len1>=0&&len2>=0 ;len1--,len2--)
	{
		if(array1[len1-1]==array2[len2-1])
		{
			count++;
		}	
	}
	return count;
}
int main()
{
	int result=0;
	int array1[]={1,3,5};
	int len1=3;
	int array2[]={77,12,1,3,5};
	int len2=5;
	result=array_compare( len1, array1,  len2, array2); 
	printf("the result is %d\n", result);
}