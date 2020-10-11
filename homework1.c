#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	int i = 0;
	for (i = 1; i <= 100; i++){
		if ((i % 3) == 0){
			printf("%d ", i);
			
		}
		else
		{
			continue;
		}
	}
	system("pause");
	return 0;
}