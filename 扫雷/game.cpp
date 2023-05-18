#include"game.h"


// 初始化棋盘
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("----------扫雷游戏--------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
			printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);	//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏--------\n");
}
//布置雷
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int i = rand()%9+1;
		int j = rand()%9+1;
		if(board[i][j]=='0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}
//排查雷
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
	//int i,j;
	//for (i = -1; i <= 1; i++)
	//{
	//	for (j = -1; j <= 1; j++)
	//	{
	//		mine[x][y] += mine[x + i][y + j];
	//	}
	//}
	//return mine[x][y] - 10*'0';//这里是字符相加减，返回的是ASCILL值,'数字’-‘0’=数字
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	printf("请输入想要排查雷的坐标->");
	while(win< ROW * COL - EASY_COUNT)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你已si亡\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				//统计周围有几个雷
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';//字符'0'的ASCILL值为48，依次递增+1.数字+‘0’=‘数字’！！！
				//显示排查周围有几个雷
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			//getchar();
			printf("输入错误,请重新输入->\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("恭喜你，成功了！\n");
		displayboard(mine, ROW, COL);
	}
}
