//交换排序1:冒泡法
#include<iostream>
using namespace std;
void BubbleSort(int a[],int length)
{
	int temp=0;
	for(int i=0;i<length-1;i++)
		for(int j=0;j<length-1-i;j++)
		{
			if(a[j]>a[j+1])
			{temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
} 

//交换排序2:快速排序:从数列中挑出一个元素，称为"基准"（pivot）。
//重新排叙述列，所有元素比基准值小的摆放在基准前面，所有元素比基
//准值大的摆在基准的后面（相同的数可以到任ㄧ边）。在这个分割之后，
//该基准是它的最后位置。这个称为分割（partition）操作。递回地（recursive）
//把小于之元素的子数列和大于之元素的子数列排序。递回的最底部情形，是数列的
//大小是零或一，也就使永远都已经被排序好了。虽然一直递回下去，但是这个算法
//总会结束，因为在每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。
int Partition(int *array, int low, int high)
{
	int pivot_val = array[low];
	int temp;
	while (low < high)
	{
		while (low < high && array[high] >= pivot_val)
		{
			--high;
		} temp =
			array[low];
		array[low] = array[high];
		array[high] = temp;
		while (low < high && array[low] <= pivot_val)
		{
			++low;
		} temp =
			array[high];
		array[high] = array[low];
		array[low] = temp;
	} return low;
}
void _QuickSort(int *array, int low, int high)
{
	int pivot_loc;
	if (low < high)
	{
		pivot_loc = Partition(array, low, high);
		_QuickSort(array, low, pivot_loc - 1);
		_QuickSort(array, pivot_loc + 1, high);
	}
}
void QuickSort(int *array, int length)
{
	_QuickSort(array, 0, length - 1);
}
//选择排序:直接选择排序:首先在未排序序列中找到最小元素，存放到排序序列的起
//始位置，然后，再从剩余未排序元素中继续寻找最小元素，然后放到排序序列末尾。
//以此类推，直到所有元素均排序完毕。
void SimpleSelectionSort(int a[],int length)
{
	int minnum=0,i=0,j=0,temp=0;
	for(i=0;i<length-1;i++)
	{minnum=i;
	for(j=i;j<length;j++)
	{
		if(a[j]<a[minnum])
			minnum=j;
	}
	temp=a[i];
	a[i]=a[minnum];
	a[minnum]=temp;
	}
}
//插入排序1:简单插入排序: 它的工作原理是通过构建有序序列，对于未排序数据，
//在已排序序列中从后向前扫描，找到相应位置并插入。
//插入排序在实现上，通常采用in-place 排序（即只需用到O(1)的额外空间的排序），
//因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提
//供插入空间。
void StraightInsertionSort(int a[],int length)
{
	int temp=0,i=0,j=0;
	for(i=1;i<length;i++)
	{
		temp = a[i];//把i 之前的大于a[i]的元素往后移
		for(j = i - 1; j >= 0 && temp < a[j]; j--)//这边之所以从i - 1 以后--是避免数据被覆盖丢失
		{
			a[j+1] = a[j];
		} a[j+1] =temp;//在合适位置安放a[i]
	}
}
//插入排序2: 二分法查找插入排序
//如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的树
//目。该算法可以认为是插入排序的一个变种，称为二分查找排序。折半插入排序所
//需附加存储空间和直接插入排序相同，从时间上比较，折半插入排序仅减少了关键
//字间的比较次数，而记录的移动次数不变。
//其实就是二分法查找与插入排序的一个结合，在已排好的字符串中用二分法查找出
//那个最合适的插入位置（找到的一般是比a[i]小的，即将离其最近的一个下标n），
//插入位置就是n+1
void BinaryInsertionSort(int *array, int length)
{
	int i, j;
	int temp;
	int low, high, mid;
	for (i = 1; i < length; i++)
	{
		temp = array[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp < array[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= high + 1; j--)
		{
			array[j+1] = array[j];
		}
		array[high+1] = temp;
	}
}
//插入排序3：希尔排序：先取一个小于n的整数d1作为第一个增量，把文件的全部
//记录分成d1个组。所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直
//接插人排序；然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量
//dt=1(dt<dt-1<…<d2<d1)，即所有记录放在同一组中进行直接插入排序为止。
void ShellInsert(int *array, int length, int dk)
{
	int i, j;
	int temp;
	for (i = dk; i < length; i++)
	{
		temp = array[i];
		for (j = i - dk; j >= 0 && temp < array[j]; j -= dk)
		{
			array[j+dk] = array[j];
		} array[j+dk] =
			temp;
	}
}
void ShellSort(int *array, int length, int *gap, int count)
{
	int i;
	for (i = count - 1; i >= 0; i--)
	{
		ShellInsert(array, length, gap[i]);
	}
}
void shellSort(int a[],int length)
{
	int gap[] = {1,2,3,5,8,13,21,34,55,89};
	ShellSort(a,length,gap,9);
}
//合并排序：归并操作(merge)，也叫归并算法，指的是将两个已经排序的序列合并成
//一个序列的操作。归并操作的工作原理如下：
//1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列。
//2.设定两个指针，最初位置为别为两个已经排序序列的起始位置。
//3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到
//下一位置。
//4.重复步骤直到某一指针达到序列尾。
//5.将另一序列剩下的所有元素直接复制到合并序列尾。
//归并排序具体工作原理如下（假设序列共有n个元素）：
//1.将序列每相邻两个数字进行归并操作（merge），形成floor(n / 2)个序列，排序
//后每个序列包含两个元素。
//2.将上述序列再次归并，形成floor(n / 4)个序列，每个序列包含四个元素。
//3.重复步骤，直到所有元素排序完毕。
void Merge(int array[], int first, int mid, int last)
{
	int i, j = 0;
	int begin1 = first, end1 = mid, begin2 = mid + 1, end2 = last;
	int *temp = (int *)malloc((last - first + 1) * sizeof(int));
	if (!temp)
	{
		fprintf(stderr, "\n 内存分配失败，程序将强制退出！\n");
		getchar();
		exit(1);
	}
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] < array[begin2])
		{
			temp[j++] = array[begin1]; begin1++;
		}
		else
		{
			temp[j++] = array[begin2]; begin2++;
		}
	}
	while (begin1 <= end1)
	{
		temp[j++] = array[begin1++];
	}
	while(begin2 <= end2)
	{
		temp[j++] = array[begin2++];
	}
	for (i = 0; i < (last - first + 1); i++)
	{
		array[first + i] = temp[i];
	}
	free(temp);
}

void _MergeSort(int *array, int first, int last)
{
	int mid;
	if (first < last)
	{
		mid = (first + last) / 2;
		_MergeSort(array, first, mid);
		_MergeSort(array, mid + 1, last);
		Merge(array, first, mid, last);
	}
}

void MergeSort(int *array, int length)
{
	_MergeSort(array, 0, length - 1);
}
void main()
{
	int a[7]={5,6,3,7,4,2,1};
	//BubbleSort(a,7);
	//QuickSort(a,7);
	//SimpleSelectionSort(a,7);
	//StraightInsertionSort(a,7);
	//BinaryInsertionSort(a,7);
	//shellSort(a,7);
	//MergeSort(a,7);
	for(int i=0;i<7;i++)
		cout<<a[i];
	cout <<endl;
}