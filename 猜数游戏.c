#include<stdio.h>
int main(void)
{
	int n = 5, a;
	printf("��һ����");
	do
	{
		printf("\n��������µ�����");
		scanf_s("%d", &a);
		if (a > n)
			printf("̫��\n");
		else if (a < n)
			printf("̫С\n");
	} while (a != n);
		printf("������\n");
}