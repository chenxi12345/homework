#include<stdio.h>//�ļ�������Ҫ
#include<stdlib.h>//system����Ҫ��
#define FilePath"counter.dat"//�����ļ���λ�ã����Ը���ʵ���������
int readCounter(char* path);//���ļ��ж�ȡ�������еĴ���
//����ǰ�������еĴ���д���ļ�
void writeCounter(int count, char* path);
int main(void)
{
	int count = 0;//��ʱ���������ڼ��㵱ǰ�������еĴ���
	//���ļ��ж�ȡ���ݣ������㵱ǰ�������еĴ���
	count = readCounter(FilePath) + 1;
	printf("�ó��������У�%d��\n", count);
	printf("-----------------------------------\n");
	printf("���潫���д���д��������ļ�(counter.dat)����\n"��;
	writeCounter(count, FilePath);//����ǰ�������еĴ���д���ļ�
	printf("д���ļ�������\n");
	printf("�������н�����\n");
	printf("-----------------------------------\n");
	system("pause");//������ͣ
}
int readCounter(char* path)
{
	FILE* fp;//�ļ�ָ��
	int count;
	//�Զ��ķ�ʽ���ļ��������һ�����У�����0
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("û�м������ļ���counter.dat���������д���ʱ���½����ļ���\n");
		return 0;
	}
	fscanf_s(fp, "%d", &count);//��ȡ���ݵ�count
	fclose(fp);//�ر��ļ�
	return count;//�������д���
}
//�����������д���д���ļ�
void writeCounter(int count, char* path)
{
	FILE* fp;
	if ((fp = fopen(path, "w")) == NULL)//��д��ʽ��
	{
		printf("�޷������������ļ���\n");
		return;
	}
	fprintf(fp, "%d", count);//д�����ݵ��ļ���
	fclose(fp);//�ر��ļ�
}