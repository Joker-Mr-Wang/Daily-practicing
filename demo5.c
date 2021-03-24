#define _crt_secure_no_warnings
#include<stdio.h>
#include<windows.h>
void print(int num){
	if (num < 10){
		printf("%d\n", num);
	}
	else{
		print(num / 10);
		
		printf("%d\n", num % 10);
	}
}
int main(){
	printf("请输入你所需需要的数字：\n");
	int num=0;
	scanf("%d", &num);
   print(num);
	system("pause");
		return 0;
}
