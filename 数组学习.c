#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//int main()
//{
//	int arr[10] = { 1,2,3 };//����ȫ��ʼ����ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0
//	char arr1[5] = { 'a','b','c' };
//	char arr4[] = "abcdef";
//	printf("%d\n", sizeof(arr4));
//	//sizeof ����arr4��ռ�ռ�Ĵ�С
//	//7��Ԫ��- char 7*1 = 7
//	printf("%d\n", strlen(arr4));
//	//strlen ���ַ�������-'\0'֮ǰ���ַ�����
//	//[a b c d e f \0]    '\0'֮ǰ��6���ַ�
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));//4
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//���ֵ����֪��ʲôʱ�������'\0'
//	return 0;
//}

//һά����
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

//int arr[][4] = { { {1,2,3,4},{5,6,7,8} } };//��ά���鶨�����ʡ������������ʡ������
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

//��ά����ĵ�ַ
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