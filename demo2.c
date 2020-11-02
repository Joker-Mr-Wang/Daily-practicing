#include<stdio.h>
#include<windows.h>
//将数组A中的内容和数组B中的内容进行交换
void change(int arr1[], int arr2[], int len){
	for (int i = 0; i < len; i++){
		int tmp = arr1[i];
	    arr1[i] = arr2[i];
	    arr2[i] = tmp;
	}
}

int main(){
	//创建两个数组
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 5, 6, 7, 8 };
	//求出数组长度
	int len = sizeof(arr1)/ sizeof(arr1[0]);
	//翻转前
	printf("反转前\n ");
	for (int i = 0; i < len; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n ");
	for (int i = 0; i < len; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n ");
	//交换函数
	change(arr1, arr2, len);
	//反转后
	printf("反转后\n ");
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