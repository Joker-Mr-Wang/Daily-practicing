//#include<stdio.h>
//#include<windows.h>
//
//
//int main()
//{
//	int arr[]={ 1,2,3,4,5,6,7,8,9,10};//��������
//	int left = 0;
//	int right = (sizeof(arr) / sizeof(arr[0])-1);
//	int mid = 0;
//	int i = 11;
//	while (left <= right){
//		mid = (left + right) / 2;
//		if (arr[mid] == i){
//			printf("�ҵ��ˣ������±��ǣ�%d", mid);
//			break;
//		}
//		else if (arr[mid] > i)
//		{
//			right = mid - 1;//�ұ߼�С1
//		}
//		else{
//			left = mid + 1;//�������1
//		}
//	}
//	 if(left > right){
//		printf("û���ҵ�\n");
//	}
//	system("pause");
//	return 0;
//
//}