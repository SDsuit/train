#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int min = 560;
	double h = 0;
	int s = 0;
	h = min / 60.0;
	s = min * 60;
	printf("%lf %d", h, s);
	return 0;
}
