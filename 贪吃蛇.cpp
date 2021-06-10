/*
   1.数据的分析：基本数据成员分析
   2.过程的分析：函数分析
   3.主函数
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>  //报错，装图形插件
#include<conio.h>
#include<time.h>   //随机函数种子
/*
坐标属性
蛇属性
食物属性
*/
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;
//蛇的属性
struct Snake
{
	int num;   //蛇的节数
	MYPOINT xy[100];   //蛇最多有一百节
	char postion;   //方向
}snake;
//食物的属性
struct Food
{
	MYPOINT fdxy;     //食物的x和y坐标
	int eatgrade;        //吃了食物有多少分
	int flag;    //食物是否存在
}food;
HWND hwnd = NULL;     //表示主窗口
//把方向枚举出来
//小键盘，键码值
enum movPostion { right = 72, left = 75, down = 77, up = 80 };
/*

初始化蛇：      initsnake
画蛇：          drawsnake
移动蛇：        movesnake
按键处理：      keyDown
初始化食物：    initfood
画食物：        drawFood
吃食物：        eatFood
蛇什么时候挂掉：snakeDie
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
	srand((unsigned int)time(NULL));   //随机函数种子
	hwnd = initgraph(640, 480);
	setbkcolor(WHITE);   //设置窗口颜色为白色
	cleardevice();     //如果颜色没变，刷新一下
	initsnake();
	
	while (1)
	{
		cleardevice();     //如果颜色没变，刷新一下
		if (food.flag == 0)
		{
			
			initFood();
		}
		drawFood();
		drawsnake();     //画蛇
		if (snakeDie())
		{
			break;
		}
		eatFood();
		showGrade();
		movesnake();
		//只有按键的时候接受按键
		//keyDown
		while (_kbhit())
		{
			keyDown();
		}
		Sleep(200);
	}


	getchar();   //防止闪屏
	closegraph();
	return 0;
}
//蛇的主模块
void initsnake()
{
	//把前三节的属性表示出来--->初始化数据过程
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.num = 3;
	snake.postion = right;     //初始化方向往右边走
	food.flag = 0;
	food.eatgrade = 0;
}
void drawsnake()
{
	for (int i = 0;i < snake.num;i++)
	{
		setlinecolor(BLACK);   //矩形边框线的颜色为黑色
		setfillcolor(GREEN);
		//画矩形
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
void movesnake()
{
	//除了第一节之外，后面每一节都是前面一节的坐标
	for (int i = snake.num - 1;i > 0;i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	//第一节的处理
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
//食物随机出现
//怎么产生食物？
void initFood()
{
	//为什么要拆开写：防止蛇吃不到食物
	food.fdxy.x = rand() % 65*10;
	food.fdxy.y = rand() % 48*10;
	food.flag = 1;    //食物存在
	//如果食物出现在蛇身上
	for (int i = 0;i < snake.num;i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			//如果食物坐标与蛇坐标重合，重新产生食物
			food.fdxy.x = rand() % 65 * 10;
			food.fdxy.y = rand() % 48 * 10;
		}
	}
}
void drawFood()
{
	setlinecolor(BLACK);     //矩形边框线的颜色为黑色
	setfillcolor(GREEN);
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
void eatFood()
{
	//1.蛇变长了
	//2.食物要重新生成
	//3.分数要增加
	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;
	}
}
//蛇死亡时，就是游戏结束时
int snakeDie()
{
	if (snake.xy[0].x > 640 || snake.xy[0].x < 0 || snake.xy[0].y>480 || snake.xy[0].y < 0)
	{
		outtextxy(200, 200, "你撞墙了！");
		MessageBox(hwnd, "GameOver!", "撞墙警告"，MB_OK);
		return 1;    //返回1表示游戏结束
	}
	//蛇撞到自己
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(200, 200, "你撞了自己！");
			MessageBox(hwnd, "GameOver!", "自杀警告"，MB_OK);
			return 1;    //返回1表示游戏结束
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
	outtextxy(580-20, 20, "分数：");
	outtextxy(580 + 50-20, 20, grade);
}