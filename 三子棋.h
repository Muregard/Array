#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//需要能返回四种结果
//1.玩家赢 '*'
//2.电脑赢 '#'
//3.平局   'T'
//4.继续   'C'
char IsWin(char board[ROW][COL],int row,int col);

//判断棋盘是否已满
int IsFull(char board[ROW][COL], int row, int col);