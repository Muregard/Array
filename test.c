#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//1.ð������

//2.
//ʵ�ֺ���init()��ʼ������Ϊȫ0
//ʵ�ֺ���print()��ӡ�����ÿ��Ԫ��
//ʵ�ֺ���reverse()������������

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
//	//������������
//	reverse(arr, sz);
//	print(arr, sz);
//
//	//��ʼ��Ϊȫ0
//	init(arr, sz);
//	print(arr, sz);
//
//
//
//	return 0;
//}

//3.������A������B�����ݽ��н���(����һ����)

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

	//ʵ�ֽ���
	exchange(arr1, arr2,sz);

	//��ӡ��������
	print(arr1, sz);
	print(arr2, sz);
	return 0;
}

//4.������