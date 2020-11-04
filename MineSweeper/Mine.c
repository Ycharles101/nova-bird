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
	//��ʼ���ϲ��ͼ
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			sMap[row][col] = '*';
		}
	}
	//��ʼ�����׵�ͼ,�Ƚ�����λ�ó�ʼ��Ϊ0���������λ�÷�����ס�1��
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			mMAP[row][col] = '0';
		}
	}
	int count = 0;
	//��10�����λ�õ���
	
	while (count<numOfMine)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		//У�飬������괦�����ף���ô���½���ѭ��
		if (mMAP[row][col] != '0')
		{
			continue;
		}
		mMAP[row][col] = '1';
		count++;
	}
}
//��ӡ��ͼ
void print(char sMap[ROW][COL])
{
	printf("   һһһһһһһһһһһһһһһһһһ\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("%d  ", row);
		printf("|");
		for (int col = 0; col < COL; col++)
		{
			printf(" %c |", sMap[row][col]);
		}
		printf("\n");
		printf("   һһһһһһһһһһһһһһһһһһ\n");
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
//���㵱ǰλ����Χ�ж�����
void update(char sMap[ROW][COL],char mMap[ROW][COL],int row,int col)
{

	int count = 0;
	for (int i = row - 1; i < row + 1; i++)
	{
		for (int j = col - 1; j < col + 1; j++)
		{
			//�����Խ����ף��������ٴν���ѭ��
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
	
	// ��ʱ count ������Ѿ������ row, col ��Χ�˸����ӵ�����
	// ��������д�� sMap �м���. 
	// ��Ҫ������ count ת�ɶ�Ӧ���ַ�
	sMap[row][col] = count + '0';
}
//��Ϸ������
void game()
{
	int mineCount = 0;
	while (1)
	{
		// 1. ������ͼ����ʼ��. (������ͼ)
		char showMap[ROW][COL] = { 0 };
		char mineMap[ROW][COL] = { 0 };
		init(showMap, mineMap);
		while (1)
		{
		// 2. ��ӡ��ͼ
		  print(showMap);
		 //print(mineMap);
		
			// 3. �����ȡ��������Ҫ����λ�õ�����, ��У��
			int row = 0;
			int col = 0;
			input(showMap, &row, &col);
			// 4. �ж���λ�õ������Ƿ��ǵ���. ����ǵ���, ֱ�� GameOver
			if (showMap[row][col] == '1')
			{
				printf("Game Over\n");
				print(mineMap);
				break;
			}
		// 5. ������ǵ���, ͳ�Ƶ�ǰλ����Χ�׵ĸ���, ����ʾ����ͼ��. 

			update(showMap, mineMap, row, col);
			// 6. �ж���Ϸ�Ƿ�ʤ��
			//    �����߼����жϵ�ǰ�ǲ��ǰ����в����׵�λ�ö�������

			mineCount++;
			if (mineCount == ROW * COL - numOfMine)
			{
				printf("congratulations��You win!\n");
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