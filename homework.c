//#include<stdio.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//int main(){
//	int a[3];
//	//������ֵ
//	printf("��������������\n");
//	scanf("%d %d %d", &a[0], &a[1], &a[2]);
//	int num = sizeof(a) / sizeof(a[0]);//���鳤��
//	//ð������
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num - 1; i++){
//		for (j = 0; j < num - 1 - i; j++){
//			if (a[j] < a[j + 1]){
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//	//�������
//	printf("�Ӵ�С˳��Ϊ��");
//	for (i = 0; i < num; i++){
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}