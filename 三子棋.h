#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//��Ҫ�ܷ������ֽ��
//1.���Ӯ '*'
//2.����Ӯ '#'
//3.ƽ��   'T'
//4.����   'C'
char IsWin(char board[ROW][COL],int row,int col);

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);