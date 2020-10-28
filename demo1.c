//#include<stdio.h>
//#include<windows.h>
//#include<math.h>//调用数学函数中的平方
////打印100-200之间的素数
//
//void primenumber(int n);
//int main(){
//	int num = 0;
//	for (num = 101; num < 200; num += 2){
//		primenumber(num);//调用函数
//	}
//	system("pause");
//	return 0;
//}
//void primenumber(int n){
//	int i = 0;
//	for (i = 2;i<=sqrt(n);i++){//从2开始循环遍历比较看看存不存在可以整除的数字，如果都不能整除则视为是素数
//		if (n%i == 0){
//			break;
//		}	
//	}
//	if (i>sqrt(n)){//如果不在循环内说明是一个素数并打印
//		printf("%d\t", n);
//	}
//}