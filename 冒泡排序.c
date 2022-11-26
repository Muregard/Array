#define _CRT_SECURE_NO_WARNINGS 1
void bubble_sort(int arr[], int n)
{
	//确定冒泡排序的趟数
	int i = 0;
	int tmp = 0;
	for (i = 0;i < n - 1;i++)//0-8,一共9趟
	{
		int flag = 1;//假设只一趟需要排序的数据已经有序
		//每一趟冒泡排序
		int j = 0;
		for (j = 0;j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//本趟需要排序的数据并不完全有序
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

//数组名
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };


	//printf("%p\n", arr);//数组名一般代表首元素的地址
	//printf("%p\n", &arr[0]);
	//printf("%d\n", *arr);
	//return 0;

	//两个特殊情况
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", sz);
	//1.sizeof(数组名)，计算整个数组的大小，sizeof内部单独放一个数组名，数组名表述整个数组
	//2.&数组名，取出的是数组的地址。&数组名，数组名表示整个数组

//}