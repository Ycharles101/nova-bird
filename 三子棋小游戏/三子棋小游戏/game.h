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
	printf("*****  欢迎来到三子棋小游戏  *****\n");
	printf("*****       1.开始游戏       *****\n");
	printf("*****       2.退出游戏       *****\n");
	printf("**********************************\n");
	printf("请选择：");
	int x = 0;
	scanf("%d", &x);
	return x;
}
//初始化棋盘
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
//打印棋盘
void print(char str[ROW][COL])
{
	printf("+---+---+---+\n");
	for (int i = 0; i < ROW; i++) {
		printf("| %c | %c | %c |\n", str[i][0],
			str[i][1], str[i][2]);
		printf("+---+---+---+\n");
	}
}
//玩家落子
void playerMove(char str[ROW][COL])
{
	//玩家输入下子位置
	while (1)
	{
		printf("请下子(范围为0~2)：\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//如果输入坐标超出范围，则提示并重新进入循环
		if (row<0 || row>ROW - 1 || col<0 || col>COL - 1)
		{
			printf("超出棋盘范围，请重新输入合适位置：\n");
			continue;
		}
		//如果输入坐标处已有子，则提示并重新进入循环
		if (str[row][col] != ' ')
		{
			printf("该位置已有棋子，请重新输入：\n");
			continue;
		}
		str[row][col] = 'x';
		break;
	}
}
//人机落子
void RobotMove(char str[ROW][COL])
{
	while (1)
	{
		int row, col;
		//行列取不大于3的随机值
		row = rand() % ROW;
		col = rand() % COL;
		//如果坐标处已有子，则重新进入循环
		if (str[row][col] != ' ')
		{
			continue;
		}
		str[row][col] = 'o';
		break;
	}
}
//判断胜负
char isWin(char str[ROW][COL])
{
	//判断一行元素是否相等，若相等则返回它们的共同值
	for (int i = 0; i < ROW; i++)
	{
		if (str[i][0] != ' '&&str[i][0] == str[i][1] && str[i][0] == str[i][2])
		{
			return str[i][0];
		}
	}
	//判断一列元素是否相等，若相等则返回它们的共同值
	for (int j = 0; j < ROW; j++)
	{
		if (str[0][j] == str[1][j] && str[0][j] == str[2][j])
		{
			return str[0][j];
		}
	}
	//判断两个对角线上的元素是否相等，若相等则返回它们的共同值
	if (str[0][0] != ' '&&str[0][0] == str[1][1] && str[0][0] == str[2][2])
	{
		return str[0][0];
	}
	if (str[0][2] != ' '&&str[0][2] == str[0][1] && str[0][2] == str[2][0])
	{
		return str[0][2];
	}
	//判断棋盘是否还有空位，如果有，返回空格，游戏继续；如果没有，返回一个任意字母，游戏以和局结束
	int flag = isFull(str);
	if (flag == 1)
		return 'l';
	else if (flag == 0)
		return ' ';
}
//判断棋盘是否还有空位
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
