#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<windows.h>

int main()
{
	int i = 0;
	int j = 0;
	printf("������������");
	scanf("%d %d" ,&i , &j);
	
		while(i>j) {
			int res=i%j;
		
			if (res==0){
				printf("��С��Լ��Ϊ��%d",j);
				break;
		}
			j--;
	}
		while (i<j) {
			int res = j%i;
			
			if (res == 0){
				printf("��С��Լ��Ϊ��%d", i);
				break;
			}
			i--;
		}
	system("pause");
	return 0;
}