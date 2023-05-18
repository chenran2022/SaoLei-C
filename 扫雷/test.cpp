#include "game.h"


void game()
{
	char mine[ROWS][COLS] = {};
	char show[ROWS][COLS] = {};
	//初始化扫雷
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//打印扫雷
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//布置雷
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//排查雷
	findmine(mine, show, ROW, COL);
}
void menu()
{
	printf("**********************************************\n");
	printf("**********1.进入游戏     0.退出游戏***********\n");
	printf("**********************************************\n");
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏成功\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入\n");
			break;
		}
		}
	} while (input);
	return 0;
}