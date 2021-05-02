#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num;
	int count=0;
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == (num >> i & 1))
			count++;
	}
	printf("%d", count);
	return 0;
}