#include<stdio.h>
int main(void)
{
	long ge, shi, qian, wan, x;
	printf("������һ����λ����");
	scanf_s("%ld", &x);
	wan = x / 10000;
	qian = x % 10000 / 1000;
	shi = x % 100 / 10;
	ge = x % 10;
	if (ge == wan && shi == qian)
		printf("\n������ǻ�����\n");
	else
		printf("\n��������ǻ�����\n");
}