//#include<stdio.h>
//#include<windows.h>
////��������ַ���
//char * StrReversal(char* str){
//
//
//		if (strlen(str) < 2) {
//			return str;
//		}
//		char ch = *str;
//		int len = strlen(str) - 1;
//		*str = *(str + len); //�����һ��λ�õ����ݸ�ֵ����ʼλ��
//		*(str + len) = '\0'; //�ѵ�ǰ�����һ���ַ������滻Ϊ\0
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