#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<time.h>

//��������Ϸ
#define MAX_ROW 3//�궨������,����,������������޸�
#define MAX_COL 3

//һ������һ����Ϸ�˵�
//�˵�����
int menu(){
	printf("========================\n");
	printf(" 1. ��ʼ��Ϸ\n");
	printf(" 0. ������Ϸ\n");
	printf("========================\n");
	printf(" ����������ѡ��: ");
	int num = -1;
	scanf("%d", &num);;//���ü�������ѡ��	
	return num;//��ѡ��ֵ���ص��������н����ж�
}
//������Ϸ����
//���̳�ʼ��
void init(char chessBoard[MAX_ROW][MAX_COL]) {
	// �������е�ÿ��Ԫ�ض���Ϊ ���ո�
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
}
//��ӡ����
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
//������ӡ�x��
void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1){
		    printf("��������Ҫ��������꣨ROW COL��");
			int row = 0;
		    int col = 0;
			scanf("%d %d", &row, &col);
			//�����ӽ����ж�
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
				// ����Խ���������������. 
				printf("�������겻�ںϷ���Χ�� [0, 2]\n");
					continue;
			}
			// У���������λ���Ƿ��Ѿ�������. 
			if (chessBoard[row][col] != ' ') {
				printf("��������λ���Ѿ�������!\n");
				continue;
			}
			//��������
			chessBoard[row][col] = 'x';
			break;
	}
}

//�������ӡ�o��
void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1){
		int row = rand() % MAX_ROW;//�������������������������
		int col = rand() % MAX_COL;
		//�����ӽ����ж�
		// У���������λ���Ƿ��Ѿ�������. 
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		//��������
		chessBoard[row][col] = 'o';
		break;
	}
}

//�ж������Ƿ���ʣ��ռ�
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// �ҿո�����Ҳ����������˷���1���ҵ�����˵��δ������0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				// �ҵ���
				return 0;
			}
		}
	}
	//δ�ҵ�
	return 1;
}
//�ж��Ƿ�ʤ��
char isWin(char chessBoard[MAX_ROW][MAX_COL]) {
	// 'x' ��ʾ��һ�ʤ
	// 'o' ��ʾ���Ի�ʤ
	// ' ' ��ʾʤ��δ��
	// 'q' ��ʾ����

	// �ж��Ƿ������
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '//�в������ڡ� ��
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	// �ж��Ƿ������
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	// �ж������Խ����Ƿ����
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];//���Խ������
	}
	if (chessBoard[2][0] != ' '
		&& chessBoard[2][0] == chessBoard[1][1]
		&& chessBoard[2][0] == chessBoard[0][2]) {
		return chessBoard[2][0];//���Խ������
	}
	// �ж��Ƿ���忴�������Ƿ���ʣ��ռ䣿��ʣ���������ʣ����Ϊ����
	if (isFull(chessBoard)) {
		return 'q';
	}
	//����Ϸδ�����������Ϸ
	return ' ';
}


//��Ϸ����
void game(){
	
	//1����һ��3x3������
	int chessBoard[MAX_ROW][MAX_COL] = { 0 };
	//2��ʼ������
	init(chessBoard);
	char winner = ' ';
	while (1){
		//3�����̽��д�ӡ
		printChessBoard(chessBoard);
		//4�������
	    playerMove(chessBoard);
		//5�ж��Ƿ�ʤ��
		winner = isWin(chessBoard);
		//���δ�����������Ϸ
		if (winner != ' ') {
			break;
		}
		//7��������
		computerMove(chessBoard);
		//8�ж��Ƿ�ʤ��
		winner = isWin(chessBoard);
		//���δ�����������Ϸ
		if (winner != ' ') {
			break;
		}
		//ѭ������3ֱ����Ϸ����
	}
	printChessBoard(chessBoard);
	//ʤ�������ж�
	if (winner == 'x') {
		printf("��ϲ��, ��Ӯ��!\n");
	}
	else if (winner == 'o') {
		printf("���ź�, �����˻��²���!\n");
	}
	else {
		printf("���ź�, �����˻����忪!\n");
	}
		}


int main(){
	srand((unsigned int)time(0));//��ʱ������һ���������,��ʱ��� time_t ת�� unsigned int
	while (1){
		//һ������һ����Ϸ�˵�
		int choice = menu();//�˵�����
		if (choice == 1){
			game();//��Ϸ����
		}
       else if (choice == 0) {
	        printf("goodbye!\n");
	        break;
		}
	   else{
		   printf("���������������������\n");
	   }
	}
	system("pause");
	return 0;
}