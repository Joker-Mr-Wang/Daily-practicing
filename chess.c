#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<time.h>

//三子棋游戏
#define MAX_ROW 3//宏定义行数,列数,方便后续进行修改
#define MAX_COL 3

//一·创建一个游戏菜单
//菜单函数
int menu(){
	printf("========================\n");
	printf(" 1. 开始游戏\n");
	printf(" 0. 结束游戏\n");
	printf("========================\n");
	printf(" 请输入您的选择: ");
	int num = -1;
	scanf("%d", &num);;//利用键盘输入选项	
	return num;//将选项值返回到主函数中进行判断
}
//二·游戏内容
//棋盘初始化
void init(char chessBoard[MAX_ROW][MAX_COL]) {
	// 把数组中的每个元素都设为 “空格”
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
}
//打印棋盘
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
//玩家落子“x”
void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1){
		    printf("请输入你要下棋的坐标（ROW COL）");
			int row = 0;
		    int col = 0;
			scanf("%d %d", &row, &col);
			//对落子进行判断
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
				// 输入越界让玩家重新输入. 
				printf("您的坐标不在合法范围内 [0, 2]\n");
					continue;
			}
			// 校验玩家落子位置是否已经有子了. 
			if (chessBoard[row][col] != ' ') {
				printf("您的坐标位置已经有子了!\n");
				continue;
			}
			//最终落子
			chessBoard[row][col] = 'x';
			break;
	}
}

//电脑落子“o”
void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1){
		int row = rand() % MAX_ROW;//设置随机数让棋子落在棋盘内
		int col = rand() % MAX_COL;
		//对落子进行判断
		// 校验玩家落子位置是否已经有子了. 
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		//最终落子
		chessBoard[row][col] = 'o';
		break;
	}
}

//判断棋盘是否有剩余空间
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// 找空格？如果找不到就是满了返回1：找到了则说明未满返回0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				// 找到了
				return 0;
			}
		}
	}
	//未找到
	return 1;
}
//判断是否胜利
char isWin(char chessBoard[MAX_ROW][MAX_COL]) {
	// 'x' 表示玩家获胜
	// 'o' 表示电脑获胜
	// ' ' 表示胜负未分
	// 'q' 表示和棋

	// 判定是否行相等
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '//行不都等于“ ”
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	// 判定是否列相等
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	// 判定两个对角线是否相等
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];//主对角线相等
	}
	if (chessBoard[2][0] != ' '
		&& chessBoard[2][0] == chessBoard[1][1]
		&& chessBoard[2][0] == chessBoard[0][2]) {
		return chessBoard[2][0];//副对角线相等
	}
	// 判定是否和棋看棋盘中是否有剩余空间？有剩余继续：无剩余则为和棋
	if (isFull(chessBoard)) {
		return 'q';
	}
	//若游戏未结束则继续游戏
	return ' ';
}


//游戏函数
void game(){
	
	//1创建一个3x3的棋盘
	int chessBoard[MAX_ROW][MAX_COL] = { 0 };
	//2初始化棋盘
	init(chessBoard);
	char winner = ' ';
	while (1){
		//3将棋盘进行打印
		printChessBoard(chessBoard);
		//4玩家落子
	    playerMove(chessBoard);
		//5判断是否胜利
		winner = isWin(chessBoard);
		//如果未结束则继续游戏
		if (winner != ' ') {
			break;
		}
		//7电脑落子
		computerMove(chessBoard);
		//8判断是否胜利
		winner = isWin(chessBoard);
		//如果未结束则继续游戏
		if (winner != ' ') {
			break;
		}
		//循环操作3直至游戏结束
	}
	printChessBoard(chessBoard);
	//胜利条件判断
	if (winner == 'x') {
		printf("恭喜您, 您赢了!\n");
	}
	else if (winner == 'o') {
		printf("很遗憾, 您连人机下不过!\n");
	}
	else {
		printf("很遗憾, 您和人机五五开!\n");
	}
		}


int main(){
	srand((unsigned int)time(0));//用时间设置一个随机种子,将时间从 time_t 转成 unsigned int
	while (1){
		//一·创建一个游戏菜单
		int choice = menu();//菜单函数
		if (choice == 1){
			game();//游戏函数
		}
       else if (choice == 0) {
	        printf("goodbye!\n");
	        break;
		}
	   else{
		   printf("您输入的有误请重新输入\n");
	   }
	}
	system("pause");
	return 0;
}