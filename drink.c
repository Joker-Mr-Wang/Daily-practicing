#include<stdio.h>
#include<windows.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
int main(){
	//定义变量：总钱数money，单价price，汽水总瓶数sum,空瓶emptyBottle
	int money = 0, price = 0, sum = 0,emptyBottle=0;
	money = 20;
	price = 1;
	sum = money / price;//第一次喝的饮料数
	emptyBottle = sum ;//空瓶数
	while (emptyBottle >= 2){//当空瓶数大于等于2时，兑换饮料
		sum += emptyBottle / 2;//将饮料总数增加
		emptyBottle = (emptyBottle / 2)+emptyBottle%2;
		//（若为偶数）空瓶数为总瓶数的一半
		//（若为奇数）空瓶数为一半加1
	}
	printf("一共可以喝%d瓶汽水\n", sum);
	system("pause");
	return 0;
}
