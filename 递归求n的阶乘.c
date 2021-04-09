#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fac2(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac2(n - 1);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fac2(n);
	printf("%d", ret);
	return 0;
}