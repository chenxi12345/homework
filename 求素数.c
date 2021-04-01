/*#include<stdio.h>
int main(void)
{
	int i, j;
	int n = 0;
	for (int i = 100;i <= 200;i++)
	{
		j = 2;
		while (i % j != 0)
			j++;
		if (i == j)
		{
			printf("%d\t", i);
			n++;
			if (n % 8 == 0)
				printf("\n");
		}
	}
	printf("\n");
}*/
#include<stdio.h>
int main(void)
{
	int i, j, n,m;
	int m = 0;
	printf("请输入一个数：");
	scanf_s("%d", &n);
	printf("\n");
	for (i = 2;i <= sqrt(n);i++)
	{
		j = 2;
		while (i % j != 0)
			j++;
	}
	printf("\n");
}