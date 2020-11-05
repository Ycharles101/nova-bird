#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<string.h>
#define ROW 3
#define COL 3
int menu();
void init(char str[ROW][COL]);
void print(char str[ROW][COL]);
void playerMove(char str[ROW][COL]);
void RobotMove(char str[ROW][COL]);
char isWin(char str[ROW][COL]);
int isFull(char str[ROW][COL]);
