
#include<stdio.h>
#include<windows.h>
//实现函数init() 初始化数组为全0
void init(int arr[], int len){
	for (int i = 0; i < len; i++){
		arr[i] = 0;
	}

}
//实现print()  打印数组的每个元素
void print(int arr[], int len){
	//遍历输出
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
}
//实现reverse()  函数完成数组元素的逆置。
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
	//建立一个整型数组
	int arr[] = { 1,2,3,4,5,6,7 };
	//求出数组长度
	int len = sizeof(arr) / sizeof(arr[0]);
	//初始化数组
	//init(arr, len);
	//数组元素的逆置
	reverse(arr, len);
	//打印函数print
	print(arr, len);
	system("pause");
	return 0;
}