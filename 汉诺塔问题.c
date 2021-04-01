#include<stdio.h>
void Hanoi(int, char, char, char);
int n = 0;
int main(void)
{
	int n;
	printf("请输入盘子个数：");
	scanf_s("%d", &n);
	printf("==========================\n");
	Hanoi(n, 'A', 'B', 'C');
	printf("==========================\n");
}
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		printf("step%3d:%c-->%c\n", n++, a, c);
	else
	{
		Hanoi(n - 1, a, c, b);
		printf("step%3d:%c-->%c\n", n++, a, c);
		Hanoi(n - 1, b, a, c);
	}
}