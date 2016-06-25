#include<stdio.h>
#include<string.h>
#define WORD_MAX 100 //最大单词书
#define LETTER_MAX 500//最大字符数
#define WORD_LETTER_MAX 20//一个单词的最大字符数

void WordStat(const char * pInputStr, char * pOutputHotWord, char * pOutputColdWord)
{

	int i, j, k;
	char p[LETTER_MAX];
	for(i = 0; pInputStr[i] !='\0'; i++)
	{
		if( (pInputStr[i]>='A') && (pInputStr[i]<='Z') )//大写字母换小写,因为不区分单词大小，所以全变成小写便于统计
			p[i] = pInputStr[i] + 32;
		else if( (pInputStr[i] == ',') || (pInputStr[i] == '.') ) //使分隔符只有空格
			p[i] = ' ';
		else
			p[i] = pInputStr[i];
	}
	p[i] = '\0';
	//printf("%s\n",p); //验证p是否为大写变小写并且标点变空格后的数组

	char a[WORD_MAX][WORD_LETTER_MAX];//字符数组*a[100]不可以，因为未定义指针a[0]指向哪里就给指向的地方赋值了。
	i = 0;
	for(j = 0; p[i] != '\0'; j++)
	{
		for(k = 0; (p[i] != ' ') && (p[i] != '\0'); i++, k++)
			a[j][k] = p[i];

		a[j][k] = '\0'; 
		if(p[i] != '\0')   //英文文本中默认两个单词件至多有一个分隔符，所以内循环结束时遇到了空格；
			i++;
	}//指针数组的每一个元素指向一个单词
	//printf("%s\n",a[7]); //验证每个单词是否对应存到二维数组的每个行中。
	//printf("%d\n",j); //验证j是否为单词的个数

	int num = 0, max = 0, min = WORD_MAX;
	for(int m = 0; m < j; m++)
	{
		if(a[m][0] == '\0')
			continue;//如果有两个或者更多的空格的时候 二维数组的某一行可能只有'\0'一个元素，要跳过这种情况

		for(int n = 0; n < j; n++)
			if( strcmp(a[m] , a[n]) == 0 )  
				num++;//某单词出现次数
		//printf("%d\n",num);//验证每个单词出现的次数是否正确
		if(num > max)
		{
			max = num;
			strcpy(pOutputHotWord, a[m]);  //复制时会自动加'\0'
			//pOutputHotWord = a[m];为什么这样不可以？只有在子函数里可以打印出正确结果，在main函数里不能打印出正确结果。
		}
		if(num < min)
		{
			min = num;
			strcpy(pOutputColdWord, a[m]);
		}
		num = 0;
	}
}

int main(void)
{
	char p[] = " Hello world , i said hello world to the world";
	//char p[] = " Somebody like somebody, i do not like it";
	char a[WORD_LETTER_MAX];
	char b[WORD_LETTER_MAX];

	WordStat(p, a, b);
	printf("%s\n",a);
	printf("%s\n",b);

	return 0;
}