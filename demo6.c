
#include<stdio.h>
#include<windows.h>
//�ǵݹ���׳�
//int main(){
//	int i = 0;
//	int sum = 1;
//	for ( i = 1; i <= 5; i++){
//			sum=sum*i;
//	}
//	printf("%d", sum);
//	system("pause");
//	return 0;
//}
//�ݹ鷨
int factorial(int num){
	if (num == 1){
		return 1;
	}
	return num*factorial(num-1);
}
int main(){
	int sum=factorial(5);
	printf("5�Ľ׳�Ϊ��%d", sum);
	system("pause");
	return 0;
}