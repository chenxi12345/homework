#include<stdio.h>
int main(void)
{
	int n;
	printf("������һ����ݣ�");
	scanf_s("%d", &n);
	printf("\n");
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
		printf("%d��������", n);
	else
		printf("%d�겻������", n);
}