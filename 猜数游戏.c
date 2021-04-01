#include<stdio.h>
int main(void)
{
	int n = 5, a;
	printf("猜一个数");
	do
	{
		printf("\n请输入你猜的数：");
		scanf_s("%d", &a);
		if (a > n)
			printf("太大\n");
		else if (a < n)
			printf("太小\n");
	} while (a != n);
		printf("猜中了\n");
}