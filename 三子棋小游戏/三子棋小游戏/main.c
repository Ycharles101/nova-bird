#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
// ��Ϸ����
// 1. �������̲���ʼ��
// 2. ��ӡ����
// 3. �������(���������������ķ�ʽ������)
// 4. �ж�ʤ����ϵ
// 5. ��������(���λ������) 
// 6. �ж�ʤ����ϵ
// �ص� 2 ����ִ��
void game()
{
	char chessBoard[ROW][COL] = { 0 };//��������
	init(chessBoard);//��ʼ������
	//�ж�ʤ����ϵ��־λ
	char flag = ' ';
	while (1)
	{
		//��ӡ����
		print(chessBoard);
		//�������
		playerMove(chessBoard);
		//�ж�ʤ��
		flag = isWin(chessBoard);
		if (flag != ' ')
			break;
		//�˻�����
		RobotMove(chessBoard);
		//�ж�ʤ��
		if (flag != ' ')
			break;
	}
	if (flag == 'x')
		printf("��ϲ������ʤ����\n");
	else if (flag == 'o')
		printf("���ź��������ˡ�\n");
	else
		printf("�;֣�\n");
}

int main()
{
	//���������
	srand(time(0));
	while (1)
	{
		int choice = menu();
		if (choice == 1)
			game();
		else if (choice == 2)
		{
			printf("�ټ�����\n");
			break;
		}
		else
		{
			printf("��������ȷѡ�\n");
			continue;
		}
	}
	return 0;
	system("pause");
}