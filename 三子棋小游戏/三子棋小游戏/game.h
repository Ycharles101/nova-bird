#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 3
#define COL 3

int menu()
{
	printf("**********************************\n");
	printf("*****  ��ӭ����������С��Ϸ  *****\n");
	printf("*****       1.��ʼ��Ϸ       *****\n");
	printf("*****       2.�˳���Ϸ       *****\n");
	printf("**********************************\n");
	printf("��ѡ��");
	int x = 0;
	scanf("%d", &x);
	return x;
}
//��ʼ������
void init(char str[ROW][COL])
{
	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++)
	//	{
	//		str[i][j] = ' ';
	//	}
	//}
	memset(str,' ',ROW*COL);
}
//��ӡ����
void print(char str[ROW][COL])
{
	printf("+---+---+---+\n");
	for (int i = 0; i < ROW; i++) {
		printf("| %c | %c | %c |\n", str[i][0],
			str[i][1], str[i][2]);
		printf("+---+---+---+\n");
	}
}
//�������
void playerMove(char str[ROW][COL])
{
	//�����������λ��
	while (1)
	{
		printf("������(��ΧΪ0~2)��\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//����������곬����Χ������ʾ�����½���ѭ��
		if (row<0 || row>ROW - 1 || col<0 || col>COL - 1)
		{
			printf("�������̷�Χ���������������λ�ã�\n");
			continue;
		}
		//����������괦�����ӣ�����ʾ�����½���ѭ��
		if (str[row][col] != ' ')
		{
			printf("��λ���������ӣ����������룺\n");
			continue;
		}
		str[row][col] = 'x';
		break;
	}
}
//�˻�����
void RobotMove(char str[ROW][COL])
{
	while (1)
	{
		int row, col;
		//����ȡ������3�����ֵ
		row = rand() % ROW;
		col = rand() % COL;
		//������괦�����ӣ������½���ѭ��
		if (str[row][col] != ' ')
		{
			continue;
		}
		str[row][col] = 'o';
		break;
	}
}
//�ж�ʤ��
char isWin(char str[ROW][COL])
{
	//�ж�һ��Ԫ���Ƿ���ȣ�������򷵻����ǵĹ�ֵͬ
	for (int i = 0; i < ROW; i++)
	{
		if (str[i][0] != ' '&&str[i][0] == str[i][1] && str[i][0] == str[i][2])
		{
			return str[i][0];
		}
	}
	//�ж�һ��Ԫ���Ƿ���ȣ�������򷵻����ǵĹ�ֵͬ
	for (int j = 0; j < ROW; j++)
	{
		if (str[0][j] == str[1][j] && str[0][j] == str[2][j])
		{
			return str[0][j];
		}
	}
	//�ж������Խ����ϵ�Ԫ���Ƿ���ȣ�������򷵻����ǵĹ�ֵͬ
	if (str[0][0] != ' '&&str[0][0] == str[1][1] && str[0][0] == str[2][2])
	{
		return str[0][0];
	}
	if (str[0][2] != ' '&&str[0][2] == str[0][1] && str[0][2] == str[2][0])
	{
		return str[0][2];
	}
	//�ж������Ƿ��п�λ������У����ؿո���Ϸ���������û�У�����һ��������ĸ����Ϸ�Ժ;ֽ���
	int flag = isFull(str);
	if (flag == 1)
		return 'l';
	else if (flag == 0)
		return ' ';
}
//�ж������Ƿ��п�λ
int isFull(char str[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (str[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
