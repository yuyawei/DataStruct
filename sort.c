#include <stdio.h>
#include <stdbool.h>

void Swap(int *a, int *b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

/* 交换排序 */
void bubble_sort0(int *a, size_t n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j <= n; j++)
			if(a[i] > a[j])
				Swap(&a[i], &a[j]);
}

/* 冒泡排序 */
void bubble_sort1(int *a, size_t n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; i++)
		for(j = n-2; j >= i; j--)
			if(a[j] > a[j+1])
				Swap(&a[j], &a[j+1]);
}

/* 冒泡排序优化 */
void bubble_sort2(int *a, size_t n)
{
	int i;
	int j;
	bool flag = true;
	for(i = 0; i < n - 1 && flag; i++)
	{
		bool flag = false;
		for(j = n-2; j >= i; j--)
		{
			if(a[j] > a[j+1])
			{
				Swap(&a[j], &a[j+1]);
				flag = true;
			}
		}
	}
}

/* 选择排序 */
void select_sort(int *a, size_t n)
{
	int i;
	int j;
	int min;

	for(i = 0; i <= n-1; i++)
	{
		min = i;
		for(j = i+1; j <= n; j++)
		{
			if(a[min] > a[j]) min = j;
		}
		if(i != min)
		{
			Swap(&a[i], &a[min]);
		}
			
	}
}

/* 直接插入排序 */   /* 调试 */
void insert_sort(int *a, size_t n)
{
	int i;
	int j;
	int temp;

	for(i = 1; i <= n-1; i++)
	{
		if(a[i] < a[i-1])
		{
			temp = a[i];
			for(j = i-1; a[j] > temp; j--)
				a[j+1] = a[j];
			a[j+1] = temp;
		}	
	}
}

int main(void)
{
	int arr[]= {9,1,5,8,3,7,4,6,2,10,-1,0,1};
	insert_sort(arr, sizeof(arr)/sizeof(arr[0]));
	int i;
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%d ", arr[i]);

	return 0;
}
