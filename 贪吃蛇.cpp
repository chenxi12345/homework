/*
   1.���ݵķ������������ݳ�Ա����
   2.���̵ķ�������������
   3.������
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>  //����װͼ�β��
#include<conio.h>
#include<time.h>   //�����������
/*
��������
������
ʳ������
*/
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;
//�ߵ�����
struct Snake
{
	int num;   //�ߵĽ���
	MYPOINT xy[100];   //�������һ�ٽ�
	char postion;   //����
}snake;
//ʳ�������
struct Food
{
	MYPOINT fdxy;     //ʳ���x��y����
	int eatgrade;        //����ʳ���ж��ٷ�
	int flag;    //ʳ���Ƿ����
}food;
HWND hwnd = NULL;     //��ʾ������
//�ѷ���ö�ٳ���
//С���̣�����ֵ
enum movPostion { right = 72, left = 75, down = 77, up = 80 };
/*

��ʼ���ߣ�      initsnake
���ߣ�          drawsnake
�ƶ��ߣ�        movesnake
��������      keyDown
��ʼ��ʳ�    initfood
��ʳ�        drawFood
��ʳ�        eatFood
��ʲôʱ��ҵ���snakeDie
*/
void initsnake();
void drawsnake();
void movesnake();
void keyDown();
void initFood();
void drawFood();
void eatFood();
int snakeDie();
void showGrade();

int main()
{
	srand((unsigned int)time(NULL));   //�����������
	hwnd = initgraph(640, 480);
	setbkcolor(WHITE);   //���ô�����ɫΪ��ɫ
	cleardevice();     //�����ɫû�䣬ˢ��һ��
	initsnake();
	
	while (1)
	{
		cleardevice();     //�����ɫû�䣬ˢ��һ��
		if (food.flag == 0)
		{
			
			initFood();
		}
		drawFood();
		drawsnake();     //����
		if (snakeDie())
		{
			break;
		}
		eatFood();
		showGrade();
		movesnake();
		//ֻ�а�����ʱ����ܰ���
		//keyDown
		while (_kbhit())
		{
			keyDown();
		}
		Sleep(200);
	}


	getchar();   //��ֹ����
	closegraph();
	return 0;
}
//�ߵ���ģ��
void initsnake()
{
	//��ǰ���ڵ����Ա�ʾ����--->��ʼ�����ݹ���
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.num = 3;
	snake.postion = right;     //��ʼ���������ұ���
	food.flag = 0;
	food.eatgrade = 0;
}
void drawsnake()
{
	for (int i = 0;i < snake.num;i++)
	{
		setlinecolor(BLACK);   //���α߿��ߵ���ɫΪ��ɫ
		setfillcolor(GREEN);
		//������
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
void movesnake()
{
	//���˵�һ��֮�⣬����ÿһ�ڶ���ǰ��һ�ڵ�����
	for (int i = snake.num - 1;i > 0;i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	//��һ�ڵĴ���
	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	default:
		break;
	}

}
void keyDown()
{
	char userKey = 0;
	userKey = _getch();
	switch (userKey)
	{
	case right:
		if (snake.postion != down)
			snake.postion = up;
		break;
	case left:
		if (snake.postion != right)
			snake.postion = left;
		break;
	case down:
		if (snake.postion != left)
			snake.postion = right;
		break;
	case up:
		if (snake.postion != up)
			snake.postion = down;
		break;
	default:
		break;
	}
}
//ʳ���������
//��ô����ʳ�
void initFood()
{
	//ΪʲôҪ��д����ֹ�߳Բ���ʳ��
	food.fdxy.x = rand() % 65*10;
	food.fdxy.y = rand() % 48*10;
	food.flag = 1;    //ʳ�����
	//���ʳ�������������
	for (int i = 0;i < snake.num;i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			//���ʳ���������������غϣ����²���ʳ��
			food.fdxy.x = rand() % 65 * 10;
			food.fdxy.y = rand() % 48 * 10;
		}
	}
}
void drawFood()
{
	setlinecolor(BLACK);     //���α߿��ߵ���ɫΪ��ɫ
	setfillcolor(GREEN);
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
void eatFood()
{
	//1.�߱䳤��
	//2.ʳ��Ҫ��������
	//3.����Ҫ����
	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;
	}
}
//������ʱ��������Ϸ����ʱ
int snakeDie()
{
	if (snake.xy[0].x > 640 || snake.xy[0].x < 0 || snake.xy[0].y>480 || snake.xy[0].y < 0)
	{
		outtextxy(200, 200, "��ײǽ�ˣ�");
		MessageBox(hwnd, "GameOver!", "ײǽ����"��MB_OK);
		return 1;    //����1��ʾ��Ϸ����
	}
	//��ײ���Լ�
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(200, 200, "��ײ���Լ���");
			MessageBox(hwnd, "GameOver!", "��ɱ����"��MB_OK);
			return 1;    //����1��ʾ��Ϸ����
		}
	}
	return 0;
}
void showGrade()
{
	char grade[100] = "";
	sprintf(grade, "%d", food.eatgrade);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(580-20, 20, "������");
	outtextxy(580 + 50-20, 20, grade);
}