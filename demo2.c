#include<stdio.h>
#include<windows.h>
//������A�е����ݺ�����B�е����ݽ��н���
void change(int arr1[], int arr2[], int len){
	for (int i = 0; i < len; i++){
		int tmp = arr1[i];
	    arr1[i] = arr2[i];
	    arr2[i] = tmp;
	}
}

int main(){
	//������������
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 5, 6, 7, 8 };
	//������鳤��
	int len = sizeof(arr1)/ sizeof(arr1[0]);
	//��תǰ
	printf("��תǰ\n ");
	for (int i = 0; i < len; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n ");
	for (int i = 0; i < len; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n ");
	//��������
	change(arr1, arr2, len);
	//��ת��
	printf("��ת��\n ");
			for (int i = 0; i < len; i++){
				printf("%d ", arr1[i]);
			}
			printf("\n ");
			for (int i = 0; i < len; i++){
				printf("%d ", arr2[i]);
			}
			system("pause");
			return 0;
}