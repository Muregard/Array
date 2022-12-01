#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//1.冒泡排序

//2.
//实现函数init()初始化数组为全0
//实现函数print()打印数组的每个元素
//实现函数reverse()完成数组的逆置

//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int temp = 0;
//	while (left < right)
//	{
//		temp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//
//	//完成数组的逆置
//	reverse(arr, sz);
//	print(arr, sz);
//
//	//初始化为全0
//	init(arr, sz);
//	print(arr, sz);
//
//
//
//	return 0;
//}

//3.将数组A和数组B的内容进行交换(数组一样大)

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void exchange(int* arr1, int* arr2,int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		int temp = 0;
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}

	int* temp = 0;
	temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}

int main()
{
	int arr1[] = {1,3,5,7,9};
	int arr2[] = {2,4,6,8,10};
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print(arr1, sz);
	print(arr2, sz);

	//实现交换
	exchange(arr1, arr2,sz);

	//打印交换后结果
	print(arr1, sz);
	print(arr2, sz);
	return 0;
}

//4.三子棋