#include<stdio.h>
int main(void)
{
	long ge, shi, qian, wan, x;
	printf("请输入一个五位数：");
	scanf_s("%ld", &x);
	wan = x / 10000;
	qian = x % 10000 / 1000;
	shi = x % 100 / 10;
	ge = x % 10;
	if (ge == wan && shi == qian)
		printf("\n这个数是回文数\n");
	else
		printf("\n这个数不是回文数\n");
}