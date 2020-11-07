//#include<stdio.h>
//#include<windows.h>
////逆序输出字符串
//char * StrReversal(char* str){
//
//
//		if (strlen(str) < 2) {
//			return str;
//		}
//		char ch = *str;
//		int len = strlen(str) - 1;
//		*str = *(str + len); //把最后一个位置的数据赋值给起始位置
//		*(str + len) = '\0'; //把当前的最后一个字符数据替换为\0
//
//		StrReversal(str + 1);
//		*(str + len) = ch;
//		return str;
//	}
//
//	
//	
//
//int main(){
//	char str[] = "abcdefg";
//	
//	printf("%s\n", StrReversal(str));
//	system("pause");
//	return 0;
//}