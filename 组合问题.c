/*����
* 202010420203
* �������
*/
#include<stdio.h>
int N = 1;
void print(int a[], int n)/*���ú���*/
{
	printf("%d:", N++);/*���*/
	for (int i = 0;i < n;i++)/*ѭ��*/
		printf("%2d", a[i]);
	putchar('\n');
}
void swap(int *a, int  *b)
{
	int t = a;a = b;b = t;
}//����
void reverse(int a[], int i, int j)
{
	while (i < j)
	{
		swap(a[i++], a[j--]);
	}
}//�ߵ�
f(int a[], int n)
{
	for (int i = 0;i < n - 1;i++)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}
void main()
{
	int* a, i, j, m, n;
	printf("n,m=");
	scanf_s("%d%d",&n,&m);
	for (i = 0;i < n;i++)
		a[i] = i + 1;
	i = m - 1;while (i)
	{
		if (i + 1 == m && f(a, m))
		{
			print(a, m);
		}
		for (j = n - 1;j > i;j--)
			if (a[j] > a[i])break;
		swap(a[i], a[j]);
		reverse(a, i + 1, n - 1);
	}
}