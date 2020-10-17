//#include<stdio.h>
//#include<windows.h>
//
//
//int main()
//{
//	int arr[]={ 1,2,3,4,5,6,7,8,9,10};//升序排列
//	int left = 0;
//	int right = (sizeof(arr) / sizeof(arr[0])-1);
//	int mid = 0;
//	int i = 11;
//	while (left <= right){
//		mid = (left + right) / 2;
//		if (arr[mid] == i){
//			printf("找到了，他的下标是：%d", mid);
//			break;
//		}
//		else if (arr[mid] > i)
//		{
//			right = mid - 1;//右边减小1
//		}
//		else{
//			left = mid + 1;//左边增大1
//		}
//	}
//	 if(left > right){
//		printf("没有找到\n");
//	}
//	system("pause");
//	return 0;
//
//}