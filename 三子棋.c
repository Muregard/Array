#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//棋盘初始化函数实现
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			board[i][j] =' ';	
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//   |   |   
		//---|---|---
		int j = 0;
		for (j = 0;j < col;j++)
		{
			//1.打印一行数据
			printf(" %c ",  board[i][j]);
			if (j < col - 1)//用if语句，控制不用打印最后一列的|
				printf("|");
			
		}
		printf("\n");

		//2，打印分割行
		if (i < row - 1)//用if语句，控制不用打印最后一行的---|---|--- 
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if(j<col-1)//用if语句，控制最后一列的|不用打印
				printf("|");
			}
			printf("\n");

		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row && y>= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//横三相同
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三相同
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[0][j];
		}
	}
	//两条对角线三相同
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'T';
	}
	return 'C';

}

//返回1表示棋盘满了
//返回0表示棋盘未满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}