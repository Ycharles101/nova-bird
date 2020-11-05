#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 游戏流程
// 1. 创建棋盘并初始化
// 2. 打印棋盘
// 3. 玩家落子(玩家输入行列坐标的方式来落子)
// 4. 判定胜负关系
// 5. 电脑落子(随机位置落子) 
// 6. 判定胜负关系
// 回到 2 继续执行

int main()
{
	//随机数种子
	srand(time(0));
	while (1)
	{
		int choice = menu();
		if (choice == 1)
			game();
		else if (choice == 2)
		{
			printf("再见不送\n");
			break;
		}
		else
		{
			printf("请输入正确选项！\n");
			continue;
		}
	}
	return 0;
	system("pause");
}