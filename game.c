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
	printf("------扫雷游戏------\n");
	//打印列号
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
	printf("------扫雷游戏------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
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
	//1.输入排查坐标
	//2.检查坐标处是不是雷
	//(1) 是雷  - game over
	//(2)不是雷 - 统计坐标周围有几个雷 - 将排查到该坐标周围的雷数量存储到show数组,游戏继续

	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col-EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);//x-(1,9), y-(1-9)

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("-----很遗憾，炸弹爆炸了！-----\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else
				{
					expand(mine, show, x, y, &win);

					////不是雷的情况下，统计x,y坐标周围有几个雷
					//int count = get_mine_count(mine, x, y);
					//show[x][y] = count + '0';
					////显示排查出该坐标周围雷的信息
					system("cls");
					DisplayBoard(show, row, col);

				}
			}
			else
			{
				printf("此坐标一杯排查，请重新输入\n");
			}	
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		DisplayBoard(mine, row, col);
		printf("-----恭喜你，排雷成功！-----\n");
	}
}



