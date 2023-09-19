#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<windows.h>
#include<conio.h>

#define WIDE 60
#define HIGH 20

void init_ui()
{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

typedef struct _body
{
	int x;
	int y;
}BODY;

typedef struct snake
{
	BODY list[WIDE * HIGH];
	int size; //�ߵĴ�С
	BODY food;
	COORD coord;
	int dx;
	int dy;
	int score;

}SNAKE;

void init_food(SNAKE* snake)
{
	srand((unsigned)time(NULL)); //ʳ������
	
	snake->food.x = rand() % WIDE;
	snake->food.y = rand() % HIGH;
}


void init_snake(SNAKE* snake)
{
	snake->list[0].x = WIDE / 2;
	snake->list[0].y = HIGH / 2; //��ͷ����

	snake->list[1].x = WIDE / 2 - 1;
	snake->list[1].y = HIGH / 2; //��β����

	snake->size = 2; //�����С

	init_food(snake);

	snake->dx = 1; //���ƶ�����
	snake->dy = 0;

	snake->score = 0;

}

void show_ui(SNAKE* snake)
{ 
	//��ʾ��(�����ߵ�λ��)��ʳ��
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		if (0 == i)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}

	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");


}

void move_snake(SNAKE* snake)
{
	for (int i = snake->size - 1; i > 0; i--)//����
	{
		snake->list[i] = snake->list[i - 1];
	}
	//��ͷ
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
}

void control_snake(SNAKE* snake)
{
	char key = 0;
	while (_kbhit())
	{
		key = _getch;
	}
	switch (key)
	{
	case 'a':
		snake->dx = -1;
		snake->dy = 0;
		break;
	case 's':
		snake->dx = 0;
		snake->dy = 1;
		break;
	case 'd':
		snake->dx = 1;
		snake->dy = 0;
		break;
	case 'w':
		snake->dx = 0;
		snake->dy = -1;
		break;
	}
}

void game_over(SNAKE* snake)
{
	snake->coord.X = 25;
	snake->coord.Y = 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	
	printf("��Ϸ�����ˣ��÷�Ϊ��%d\n", snake->score);
	Sleep(3000);
	exit(0);
}

void snake_eat_body(SNAKE* snake)
{
	for (int i = 1; i < snake->size; i++)
	{
		if (snake->list[0].x == snake->list[i].x &&
			snake->list[0].y == snake->list[i].y)
		{
			game_over(snake);
		}

	}
}

void snake_eat_food(SNAKE* snake)
{
	if (snake->list[0].x == snake->food.x &&
		snake->list[0].y == snake->food.y)
	{
		init_food(snake);
		snake->size++;

		snake->score += 10;
	}
}

void start_game(SNAKE* snake)
{
	while (snake->list[0].x<60 && snake->list[0].x >= 0 && 
		snake->list[0].y < 20 && snake->list[0].y >= 0)
	{
		control_snake(snake);
		move_snake(snake);
		system("cls");
		show_ui(snake);
		snake_eat_body(snake);
		snake_eat_food(snake);

		Sleep(500);
	}
	game_over(snake);
}

int main()
{
	//init_ui();
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	init_snake(snake); //��ʼ����
	show_ui(snake);
	start_game(snake);
	

	system("pause");
	return 0;
}