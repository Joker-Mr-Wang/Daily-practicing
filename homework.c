//#include<stdio.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//int main(){
//	int a[3];
//	//输入数值
//	printf("请输入三个数：\n");
//	scanf("%d %d %d", &a[0], &a[1], &a[2]);
//	int num = sizeof(a) / sizeof(a[0]);//数组长度
//	//冒泡排序
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
//	//遍历输出
//	printf("从大到小顺序为：");
//	for (i = 0; i < num; i++){
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}