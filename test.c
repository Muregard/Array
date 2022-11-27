#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("***** 1.play  0.exit*****\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS];//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS];//����Ų�����׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');//'0'
	InitBoard(show, ROWS, COLS, '*');//'*'

	//��ӡ����
	DisplayBoard(mine, ROW, COL);//ֻ��ӡ9*9
	DisplayBoard(show, ROW, COL);;//ֻ��ӡ9*9

	//������
	SetMine(mine, ROW, COL);

	//������
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);

	return 0;
}