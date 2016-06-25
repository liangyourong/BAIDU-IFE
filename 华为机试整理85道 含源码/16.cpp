#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  

void my_word(char input[],char output[])  
{  
	char *p;  
	char *temp;  
	char *word[10];  
	int len_input=strlen(input);  
	int i,j;  
	char except[] = ",";  
	char *blank = " ";  
	i=0;   
	for (i=0;i<len_input;i++)  
	{  
		if (input[i]<'A' || (input[i]>'Z'&&input[i]<'a') || input[i]>'z')  
		{  
			input[i]=',';  
		}  
	}  

	j=0;  
	/*保存取出的单词*/  
	p= strtok(input,except);  
	while(NULL!=p)  
	{  
		word[j++]=p;  
		p= strtok(NULL,except);  
	}  
	for(i=0;i<5;i++)
		printf("%s",word[i]);
	/*对单词按照长度降序排序，冒泡法*/  
	for (i=0;i<5;i++)  
	{  
		for (j=1;j<5-i;j++)  
		{  
			if(strlen(word[j-1])<strlen(word[j]))  
			{  
				temp=word[j];  
				word[j]=word[j-1];  
				word[j-1]=temp;  
			}  
		}  

	}  
	/*删除相同单词*/  
	for (i=0;i<5;i++)  
	{  
		for(j=i+1;j<5;j++)  
		{  
			if(strcmp(word[i],word[j])==0)  
				word[j]="\0";  
		}  
	}  
	/*将单词连接起来输出*/  
	for (j=0;j<5;j++)  
	{  
		if (0==j)  
		{  
			strncpy(output,word[j],strlen(word[j])+1);  
		}  
		else  
		{  
			strcat(output,blank);  
			strcat(output,word[j]);  
		}  
	}  
	return ;  
}  
int main()  
{  

	char input[] ="some local buses, some1234123drivers";  
	printf("筛选之前的字符串:%s\n",input);
	char output[30];  
	my_word(input,output);  
	printf("筛选之后的字符串:%s",output);  
	printf("\n");  
	return 0;  
}  