#include"game.h"
#define ROW 3
#define COL 3
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