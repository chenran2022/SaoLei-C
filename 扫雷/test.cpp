#include "game.h"


void game()
{
	char mine[ROWS][COLS] = {};
	char show[ROWS][COLS] = {};
	//��ʼ��ɨ��
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//��ӡɨ��
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//�Ų���
	findmine(mine, show, ROW, COL);
}
void menu()
{
	printf("**********************************************\n");
	printf("**********1.������Ϸ     0.�˳���Ϸ***********\n");
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
			printf("�˳���Ϸ�ɹ�\n");
			break;
		}
		default:
		{
			printf("�����������������\n");
			break;
		}
		}
	} while (input);
	return 0;
}