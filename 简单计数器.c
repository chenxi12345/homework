#include<stdio.h>//文件处理需要
#include<stdlib.h>//system（需要）
#define FilePath"counter.dat"//数据文件的位置，可以根据实际情况更改
int readCounter(char* path);//从文件中读取程序运行的次数
//将当前程序运行的次数写入文件
void writeCounter(int count, char* path);
int main(void)
{
	int count = 0;//临时变量，用于计算当前程序运行的次数
	//从文件中读取数据，并计算当前程序运行的次数
	count = readCounter(FilePath) + 1;
	printf("该程序已运行：%d次\n", count);
	printf("-----------------------------------\n");
	printf("下面将运行次数写入计数器文件(counter.dat)……\n"）;
	writeCounter(count, FilePath);//将当前程序运行的次数写入文件
	printf("写入文件结束！\n");
	printf("程序运行结束！\n");
	printf("-----------------------------------\n");
	system("pause");//程序暂停
}
int readCounter(char* path)
{
	FILE* fp;//文件指针
	int count;
	//以读的方式打开文件，如果第一次运行，返回0
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("没有计数器文件：counter.dat，保存运行次数时将新建该文件！\n");
		return 0;
	}
	fscanf_s(fp, "%d", &count);//读取数据到count
	fclose(fp);//关闭文件
	return count;//返回运行次数
}
//将当程序运行次数写入文件
void writeCounter(int count, char* path)
{
	FILE* fp;
	if ((fp = fopen(path, "w")) == NULL)//以写方式打开
	{
		printf("无法创建计数器文件！\n");
		return;
	}
	fprintf(fp, "%d", count);//写入数据到文件中
	fclose(fp);//关闭文件
}