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
	int count = 10;
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

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.�����Ų�����
	//2.������괦�ǲ�����
	//(1) ����  - game over
	//(2)������ - ͳ��������Χ�м����� - ���Ų鵽��������Χ���������洢��show����,��Ϸ����
	printf("������Ҫ�Ų������:>");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d%d", &x, &y);//x-(1,9), y-(1-9)

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("BOOM! game over\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵�����£�ͳ��x,y������Χ�м�����
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}
}