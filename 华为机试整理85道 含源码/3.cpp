/*
3、操作系统任务调度问题。操作系统任务分为系统任务和用户任务两种。其中，
系统任务的优先级 < 50，用户任务的优先级 >= 50且 <= 255。优先级大于255的为非法任务，应予以剔除。
现有一任务队列task[]，长度为n，task中的元素值表示任务的优先级，数值越小，优先级越高。 
函数scheduler实现如下功能：
将task[] 中的任务按照系统任务、用户任务依次存放到 system_task[] 数组和 user_task[] 数组中 
（数组中元素的值是任务在task[] 数组中的下标），并且优先级高的任务排在前面，数组元素为-1表示结束。
例如：
task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99}    
system_task[] = {0, 3, 1, 7, -1}    
user_task[]  =  {4, 8, 2, 6, -1}
接口函数：
void scheduler(int task[], int n, int system_task[], int user_task[])
*/
#include <iostream>
using namespace std;

typedef struct TASKNODE
{
	int index;
	int value;
}Task_node;

void scheduler(int task[], int n, int system_task[], int user_task[])
{
	Task_node *task_list = new Task_node[n*sizeof(Task_node)];
	Task_node temp;
	int i,j,k;
	for(i = 0;i < n;i++)
	{
		task_list[i].index = i;
		task_list[i].value = task[i];
	}

	//根据优先级排序.
	for(i = 0;i < n-1;i++)
	{
		for(j = i+1;j < n;j++)
		{
			if(task_list[j].value < task_list[i].value)//前者优先级高.
			{
				temp = task_list[i];
				task_list[i] = task_list[j];
				task_list[j] = temp;
			}
		}
	}
	//将任务序号分类存入数组.
	j = k = 0;
	for(i = 0;i < n;i++)
	{
		if(task_list[i].value >= 0 && task_list[i].value < 50)
		{
			system_task[j++] = task_list[i].index;
		}
		else if(task_list[i].value >= 50 && task_list[i].value <= 255)
		{
			user_task[k++] = task_list[i].index;
		}
		else
			continue;
	}
	system_task[j] = -1;
	user_task[k] = -1;

	delete [] task_list;

	//输出归类结果.
	for(int m = 0;m <= j;m++)
		cout << system_task[m] << " ";
	cout << endl;

	for(int m1 = 0;m1 <= k;m1++)
		cout << user_task[m1] << " ";


}

int main()
{
	int task[] = {0,30,155,1,80,300,170,40,99};
	int system_task[10];
	int user_task[10];
	scheduler(task, 9, system_task, user_task);

	return 0;
}