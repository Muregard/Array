#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ------\n");
	//��ӡ�к�
	for (i = 0;i <= col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------ɨ����Ϸ------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		int count = get_mine_count(mine, x, y);
		if (count == 0)
		{
			show[x][y] = ' ';

			int i = 0;
			for (i = x - 1;i <= x + 1;i++)
			{
				int j = 0;
				for (j = y - 1;j <= y + 1;j++)
				{
					if (show[i][j] == '*')
					{
						expand(mine, show, i, j, win);
					}
				}
			}
		}
		else
		{
			show[x][y] = count + '0';
		}
		(*win)++;
	}
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.�����Ų�����
	//2.������괦�ǲ�����
	//(1) ����  - game over
	//(2)������ - ͳ��������Χ�м����� - ���Ų鵽��������Χ���������洢��show����,��Ϸ����

	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col-EASY_COUNT)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d%d", &x, &y);//x-(1,9), y-(1-9)

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("-----���ź���ը����ը�ˣ�-----\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else
				{
					expand(mine, show, x, y, &win);

					////�����׵�����£�ͳ��x,y������Χ�м�����
					//int count = get_mine_count(mine, x, y);
					//show[x][y] = count + '0';
					////��ʾ�Ų����������Χ�׵���Ϣ
					system("cls");
					DisplayBoard(show, row, col);

				}
			}
			else
			{
				printf("������һ���Ų飬����������\n");
			}	
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		DisplayBoard(mine, row, col);
		printf("-----��ϲ�㣬���׳ɹ���-----\n");
	}
}



