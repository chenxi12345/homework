/*方静
* 202010420203
* 全排列问题
*/
#include<stdio.h>
void fun(int, int);
int main(void)
{
	void fun(int m, int a[]);
	int a[3] = { 1,2,3 };
	fun(0, a);
	return 0;
}
void fun(int m, int a[])
{
	int i;
	if (m >= 3)
	{
		for (i = 0;i < 3;i++)
			printf("%d", a[i]);
		printf("\n");
	}
	else
	{
		for (i = m;i < 3;i++)
		{
			int k = a[m];
			a[m] = a[i];
			a[i] = k;
			fun(m + 1, a);
		}
	}
}