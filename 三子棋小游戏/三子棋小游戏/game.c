#include"game.h"
#define ROW 3
#define COL 3
void game()
{
	char chessBoard[ROW][COL] = { 0 };//创建棋盘
	init(chessBoard);//初始化棋盘
	//判断胜负关系标志位
	char flag = ' ';
	while (1)
	{
		//打印棋盘
		print(chessBoard);
		//玩家落子
		playerMove(chessBoard);
		//判断胜负
		flag = isWin(chessBoard);
		if (flag != ' ')
			break;
		//人机落子
		RobotMove(chessBoard);
		//判断胜负
		if (flag != ' ')
			break;
	}
	if (flag == 'x')
		printf("恭喜你获得了胜利！\n");
	else if (flag == 'o')
		printf("很遗憾，你输了。\n");
	else
		printf("和局！\n");
}