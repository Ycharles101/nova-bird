#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define numOfMine 10
int menu()
{
	printf("*********************************************\n");
	printf("******   Welcome to the MineSweeper!   ******\n");
	printf("******           1.Play Game.          ******\n");
	printf("******           2.Exit.               ******\n");
	printf("*********************************************\n");
	int choice;
	scanf("%d", &choice);
	printf("========================\n");
	return choice;
}
void init(char sMap[ROW][COL],char mMAP[ROW][COL])
{	
	//初始化上层地图
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			sMap[row][col] = '*';
		}
	}
	//初始化地雷地图,先将所有位置初始化为0，再在随机位置放入地雷“1”
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			mMAP[row][col] = '0';
		}
	}
	int count = 0;
	//埋10个随机位置的雷
	
	while (count<numOfMine)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		//校验，如果坐标处已有雷，那么重新进入循环
		if (mMAP[row][col] != '0')
		{
			continue;
		}
		mMAP[row][col] = '1';
		count++;
	}
}
//打印地图
void print(char sMap[ROW][COL])
{
	printf("   一一一一一一一一一一一一一一一一一一\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("%d  ", row);
		printf("|");
		for (int col = 0; col < COL; col++)
		{
			printf(" %c |", sMap[row][col]);
		}
		printf("\n");
		printf("   一一一一一一一一一一一一一一一一一一\n");
	}

}
void input(char sMap[ROW][COL],int *row,int *col)
{

	while (1)
	{
		printf("\nPlease input location coordinates(0~9):   ");
		scanf("%d %d", row, col);
		if (*row<0 || *row>ROW || *col<0 || *col>COL)
		{
			printf("\nError! Out of range, please re-input.\n");
			printf("==========================================\n");

			continue;
		}
		if (sMap[*row][*col] != '*')
		{
			printf("\nThe location is occupied, please re-input.\n");
			printf("==========================================\n");
			continue;
		}
		break;
	}
}
//计算当前位置周围有多少雷
void update(char sMap[ROW][COL],char mMap[ROW][COL],int row,int col)
{

	int count = 0;
	for (int i = row - 1; i < row + 1; i++)
	{
		for (int j = col - 1; j < col + 1; j++)
		{
			//如果有越界的雷，跳过并再次进入循环
			if (row<0 || row>ROW || col<0 || col>COL)
			{
				continue;
			}
			if (mMap[i][j] == '1')
			{
				count++;
			}
		}
	
	}
	
	// 此时 count 里面就已经存好了 row, col 周围八个格子的雷数
	// 把这个结果写到 sMap 中即可. 
	// 需要把数字 count 转成对应的字符
	sMap[row][col] = count + '0';
}
//游戏主程序
void game()
{
	int mineCount = 0;
	while (1)
	{
		// 1. 创建地图并初始化. (两个地图)
		char showMap[ROW][COL] = { 0 };
		char mineMap[ROW][COL] = { 0 };
		init(showMap, mineMap);
		while (1)
		{
		// 2. 打印地图
		  print(showMap);
		 //print(mineMap);
		
			// 3. 程序读取玩家输入的要翻开位置的坐标, 并校验
			int row = 0;
			int col = 0;
			input(showMap, &row, &col);
			// 4. 判定该位置的坐标是否是地雷. 如果是地雷, 直接 GameOver
			if (showMap[row][col] == '1')
			{
				printf("Game Over\n");
				print(mineMap);
				break;
			}
		// 5. 如果不是地雷, 统计当前位置周围雷的个数, 并显示到地图上. 

			update(showMap, mineMap, row, col);
			// 6. 判定游戏是否胜利
			//    核心逻辑是判断当前是不是把所有不是雷的位置都翻开了

			mineCount++;
			if (mineCount == ROW * COL - numOfMine)
			{
				printf("congratulations！You win!\n");
				break;
			}
		}	
	}
}
int main()
{
	srand((unsigned int)(0));
	while (1)
	{

		int choice = menu();
		if (choice == 1)
		{
			game();
		}
		else if (choice == 2)
		{
			printf("Bye Bye!\n");
			break;
		}
		else
			printf("Input error! Please try again.\n");

	}
	return 0;
}