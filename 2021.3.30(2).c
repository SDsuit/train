#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int ret = 1;
	int n = 0;
	scanf("%d", &n);
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		ret = i * ret;
	}
	printf("%d", ret);
		return 0;
}