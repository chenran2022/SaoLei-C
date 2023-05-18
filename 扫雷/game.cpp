#include"game.h"


// ��ʼ������
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
//��ӡ����
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("----------ɨ����Ϸ--------\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
			printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);	//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------ɨ����Ϸ--------\n");
}
//������
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
//�Ų���
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
	//return mine[x][y] - 10*'0';//�������ַ���Ӽ������ص���ASCILLֵ,'���֡�-��0��=����
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	printf("��������Ҫ�Ų��׵�����->");
	while(win< ROW * COL - EASY_COUNT)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź�������si��\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				//ͳ����Χ�м�����
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';//�ַ�'0'��ASCILLֵΪ48�����ε���+1.����+��0��=�����֡�������
				//��ʾ�Ų���Χ�м�����
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			//getchar();
			printf("�������,����������->\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("��ϲ�㣬�ɹ��ˣ�\n");
		displayboard(mine, ROW, COL);
	}
}
