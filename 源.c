#include<stdio.h>
int main(void)
{
	int n;
	printf("请输入一个年份：");
	scanf_s("%d", &n);
	printf("\n");
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
		printf("%d年是闰年", n);
	else
		printf("%d年不是闰年", n);
}