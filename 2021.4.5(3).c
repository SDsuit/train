#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int binary_search(int arr[],int k,int sz)
{
	int mid = 0;
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (k > arr[mid])
			left = mid + 1;
		else if (k < arr[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 14,23,35,46,52,63,76,84,92,101 };
	int k = 76;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k, sz);
		if (ret == -1)
			printf("找不到指定的数字");
		else
			printf("找到了，下标为:%d \n", ret);
	return 0;
}