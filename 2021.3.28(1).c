#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char ch = 0;
	int ret = 0;
	char password[20] = { 0 };
	printf("请输入密码:>");
	scanf("%s", password);
	printf("请确认(Y/N):>");
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret == 'Y')
		printf("确认成功\n");
	else
		printf("取消确认\n");
	return 0;
}