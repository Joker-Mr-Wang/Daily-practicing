#include<stdio.h>
#include<windows.h>

int main(){
	int LA[] = { 3, 5, 8, 11 };
	int LB[] = { 2, 6, 8, 9, 11, 15, 20 };
	int num = (sizeof(LA) / sizeof(LA[0])) + (sizeof(LB) / sizeof(LB[0]));
	printf("新数组所需长度：%d\n", num);//11;
	int LC[11];
	int i=0,j = 0;
	int k = 0;
	int lenA = (sizeof(LA) / sizeof(LA[0]));//A数组长度
	int lenB = (sizeof(LB) / sizeof(LB[0]));//B数组长度
	while ((i < lenA) && (j<lenB))
	{
		if(LA[i] <= LB[j])
		{
			LC[k] = LA[i];
			++k;
			++i;
		}
		else
		{
			LC[k] = LB[j];
			++k;
			++j;
		}
		
	}
	while (i < lenA)
	{
		LC[k] = LA[i];
		i++;
		k++;
	}
	while (j < lenB)
	{
		LC[k] = LB[j];
		j++;
		k++;
	}
	printf("数组LC：");
	
	for (i = 0; i <sizeof(LC) / sizeof(LC[0]); i++)
	{
		printf("%d ", LC[i]);
	}

	system("pause");
	return 0;
}