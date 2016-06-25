#include <stdio.h>
void dice(int map_len, int* map, int* dice_val, int* output);

int main(void)
{
	int map_len = 15,  map[] = {9,1,9,9,9,2,9,9,9,9,9,9,9,9,9},  dice_val[] = {1,2,1,3,1};//4
	int a=0 , * output=&a;
	dice(map_len, map,  dice_val,  output);

	int map_len1 = 16,  map1[] = {9,9,9,9,9,1,9,3,9,9,2,9,9,9,9,9}, dice_val1[] = {2,1,4,1,6};//15
	int a1=0 , * output1=&a1;
	dice(map_len1, map1,  dice_val1,  output1);

	return 0;
}

void dice(int map_len, int* map, int* dice_val, int* output)
{
	int step=0, i;
	for(i=0; i<5; i++)
	{
		step = step + dice_val[i];
		if(step>=map_len - 1)
		{
			*output = map_len - 1;
			step = map_len - 1;
			break;
		}
		else if(map[step] == 1)
			i++;
		else if(map[step] == 2)
		{
			if(step>1)
				step = step - 2;
			else
				step = 0;
		}
		else if(map[step] == 3)
			step++;
	}
	*output = step;
	printf("the output is %d\n",*output);
}