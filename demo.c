
#include<stdio.h>
#include<windows.h>
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
void init(int arr[], int len){
	for (int i = 0; i < len; i++){
		arr[i] = 0;
	}

}
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
void print(int arr[], int len){
	//�������
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
}
//ʵ��reverse()  �����������Ԫ�ص����á�
void reverse(int arr[], int len){
	int start=0,end=0;
	for (start = 0, end = len - 1; start <end; start++, end--){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
	}

}
	////int i;
	////for (i = 0; i < len / 2; i++)
	////{
	////
	////	int temp = arr[i];
	////	arr[i] = arr[len - i - 1];
	////	arr[len - i - 1] = temp;
	////}
	


int main(){
	//����һ����������
	int arr[] = { 1,2,3,4,5,6,7 };
	//������鳤��
	int len = sizeof(arr) / sizeof(arr[0]);
	//��ʼ������
	//init(arr, len);
	//����Ԫ�ص�����
	reverse(arr, len);
	//��ӡ����print
	print(arr, len);
	system("pause");
	return 0;
}