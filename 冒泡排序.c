#define _CRT_SECURE_NO_WARNINGS 1
void bubble_sort(int arr[], int n)
{
	//ȷ��ð�����������
	int i = 0;
	int tmp = 0;
	for (i = 0;i < n - 1;i++)//0-8,һ��9��
	{
		int flag = 1;//����ֻһ����Ҫ����������Ѿ�����
		//ÿһ��ð������
		int j = 0;
		for (j = 0;j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//������Ҫ��������ݲ�����ȫ����
			}
		}
		if (flag == 1)
		{
			break;
		}

	}
}
int main()
{
	int i = 0;
	int arr[] = { 9,1,2,3,4,5,6,7,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//������
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };


	//printf("%p\n", arr);//������һ�������Ԫ�صĵ�ַ
	//printf("%p\n", &arr[0]);
	//printf("%d\n", *arr);
	//return 0;

	//�����������
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", sz);
	//1.sizeof(������)��������������Ĵ�С��sizeof�ڲ�������һ����������������������������
	//2.&��������ȡ����������ĵ�ַ��&����������������ʾ��������

//}