#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convert(char *input,char* output)
{
	if(input==NULL)
		return;
	char temp='\0';
	int len_input=strlen(input);
	int i;
	int flag=0;

	for(i=0;i<len_input;i++)
	{
		if(input[i]!=temp)
		{
			output[i]=(input[i]-'a'+1)%26+'a';
			temp=input[i];
			flag=1;
		}
		else
		{
			if(flag==1)
			{
				output[i]=(input[i]-'a'+2)%26+'a';
				temp=input[i];
				flag=0;
			}
			else
			{
				output[i]=(input[i]-'a'+1)%26+'a';
				temp=input[i];
				flag=1;
			}
		}
	}
	output[i]='\0';
}

void main()
{
	char *input="aahckljfeddsswnossgr";
	char output[256];
	convert(input,output);
	printf("%s\n",output);
}