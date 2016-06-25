//��������1:ð�ݷ�
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

//��������2:��������:������������һ��Ԫ�أ���Ϊ"��׼"��pivot����
//�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�
//׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե��Ψ�ߣ���������ָ�֮��
//�û�׼���������λ�á������Ϊ�ָpartition���������ݻصأ�recursive��
//��С��֮Ԫ�ص������кʹ���֮Ԫ�ص����������򡣵ݻص���ײ����Σ������е�
//��С�����һ��Ҳ��ʹ��Զ���Ѿ���������ˡ���Ȼһֱ�ݻ���ȥ����������㷨
//�ܻ��������Ϊ��ÿ�εĵ�����iteration���У������ٻ��һ��Ԫ�ذڵ�������λ��ȥ��
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
//ѡ������:ֱ��ѡ������:������δ�����������ҵ���СԪ�أ���ŵ��������е���
//ʼλ�ã�Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����СԪ�أ�Ȼ��ŵ���������ĩβ��
//�Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�
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
//��������1:�򵥲�������: ���Ĺ���ԭ����ͨ�������������У�����δ�������ݣ�
//�������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣
//����������ʵ���ϣ�ͨ������in-place ���򣨼�ֻ���õ�O(1)�Ķ���ռ�����򣩣�
//����ڴӺ���ǰɨ������У���Ҫ������������Ԫ�������Ųλ��Ϊ����Ԫ����
//������ռ䡣
void StraightInsertionSort(int a[],int length)
{
	int temp=0,i=0,j=0;
	for(i=1;i<length;i++)
	{
		temp = a[i];//��i ֮ǰ�Ĵ���a[i]��Ԫ��������
		for(j = i - 1; j >= 0 && temp < a[j]; j--)//���֮���Դ�i - 1 �Ժ�--�Ǳ������ݱ����Ƕ�ʧ
		{
			a[j+1] = a[j];
		} a[j+1] =temp;//�ں���λ�ð���a[i]
	}
}
//��������2: ���ַ����Ҳ�������
//����Ƚϲ����Ĵ��۱Ƚ���������Ļ������Բ��ö��ֲ��ҷ������ٱȽϲ�������
//Ŀ�����㷨������Ϊ�ǲ��������һ�����֣���Ϊ���ֲ��������۰����������
//�踽�Ӵ洢�ռ��ֱ�Ӳ���������ͬ����ʱ���ϱȽϣ��۰��������������˹ؼ�
//�ּ�ıȽϴ���������¼���ƶ��������䡣
//��ʵ���Ƕ��ַ���������������һ����ϣ������źõ��ַ������ö��ַ����ҳ�
//�Ǹ�����ʵĲ���λ�ã��ҵ���һ���Ǳ�a[i]С�ģ��������������һ���±�n����
//����λ�þ���n+1
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
//��������3��ϣ��������ȡһ��С��n������d1��Ϊ��һ�����������ļ���ȫ��
//��¼�ֳ�d1���顣���о���Ϊd1�ı����ļ�¼����ͬһ�����С����ڸ����ڽ���ֱ
//�Ӳ�������Ȼ��ȡ�ڶ�������d2<d1�ظ������ķ��������ֱ����ȡ������
//dt=1(dt<dt-1<��<d2<d1)�������м�¼����ͬһ���н���ֱ�Ӳ�������Ϊֹ��
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
//�ϲ����򣺹鲢����(merge)��Ҳ�й鲢�㷨��ָ���ǽ������Ѿ���������кϲ���
//һ�����еĲ������鲢�����Ĺ���ԭ�����£�
//1.����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������С�
//2.�趨����ָ�룬���λ��Ϊ��Ϊ�����Ѿ��������е���ʼλ�á�
//3.�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽
//��һλ�á�
//4.�ظ�����ֱ��ĳһָ��ﵽ����β��
//5.����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
//�鲢������幤��ԭ�����£��������й���n��Ԫ�أ���
//1.������ÿ�����������ֽ��й鲢������merge�����γ�floor(n / 2)�����У�����
//��ÿ�����а�������Ԫ�ء�
//2.�����������ٴι鲢���γ�floor(n / 4)�����У�ÿ�����а����ĸ�Ԫ�ء�
//3.�ظ����裬ֱ������Ԫ��������ϡ�
void Merge(int array[], int first, int mid, int last)
{
	int i, j = 0;
	int begin1 = first, end1 = mid, begin2 = mid + 1, end2 = last;
	int *temp = (int *)malloc((last - first + 1) * sizeof(int));
	if (!temp)
	{
		fprintf(stderr, "\n �ڴ����ʧ�ܣ�����ǿ���˳���\n");
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