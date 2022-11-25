#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//int main()
//{
//	int arr[10] = { 1,2,3 };//不完全初始化，剩下的元素默认初始化为0
//	char arr1[5] = { 'a','b','c' };
//	char arr4[] = "abcdef";
//	printf("%d\n", sizeof(arr4));
//	//sizeof 计算arr4所占空间的大小
//	//7个元素- char 7*1 = 7
//	printf("%d\n", strlen(arr4));
//	//strlen 求字符串长度-'\0'之前的字符个数
//	//[a b c d e f \0]    '\0'之前有6个字符
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));//4
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//随机值，不知道什么时候会遇到'\0'
//	return 0;
//}

//一维数组
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%c\n", arr[3]);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//	return 0;
//
//}

//int arr[][4] = { { {1,2,3,4},{5,6,7,8} } };//二维数组定义可以省略行数，不能省略列数
//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 4;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//二维数组的地址
int main()
{
	int arr[3][4] = { {1,2,3},{4,5} };
	int i = 0;
	int j = 0;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 4;j++)
		{
			printf("arr[%d][%d]=%p ", i,j,&arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}