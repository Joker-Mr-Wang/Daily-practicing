#include<stdio.h>
#include<windows.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
int main(){
	//�����������Ǯ��money������price����ˮ��ƿ��sum,��ƿemptyBottle
	int money = 0, price = 0, sum = 0,emptyBottle=0;
	money = 20;
	price = 1;
	sum = money / price;//��һ�κȵ�������
	emptyBottle = sum ;//��ƿ��
	while (emptyBottle >= 2){//����ƿ�����ڵ���2ʱ���һ�����
		sum += emptyBottle / 2;//��������������
		emptyBottle = (emptyBottle / 2)+emptyBottle%2;
		//����Ϊż������ƿ��Ϊ��ƿ����һ��
		//����Ϊ��������ƿ��Ϊһ���1
	}
	printf("һ�����Ժ�%dƿ��ˮ\n", sum);
	system("pause");
	return 0;
}
