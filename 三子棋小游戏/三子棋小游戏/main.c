#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// ��Ϸ����
// 1. �������̲���ʼ��
// 2. ��ӡ����
// 3. �������(���������������ķ�ʽ������)
// 4. �ж�ʤ����ϵ
// 5. ��������(���λ������) 
// 6. �ж�ʤ����ϵ
// �ص� 2 ����ִ��

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