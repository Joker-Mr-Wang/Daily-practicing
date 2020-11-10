#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial//多项式的每一项结构
{
	double coefficient;//系数
	int index;//指数
	struct polynomial *next;//指针->指向下一个节点
}node;

struct polynomial *create();//创建链表
void sort+++++++++++++++++++++++++(struct polynomial *head);//降序排序
void add_subtract(struct polynomial *head1, struct polynomial *head2);//加减法
void display(struct polynomial *head);//输出多项式
void check(node *head1, node *head2);//校验多项式
int count;//用于选择输出多项式a或b,及用于多项式取反

int main()
{
	int choice;
	node *head1 = NULL;
	node *head2 = NULL;
	do{
		printf("\n");
		printf("┏━━━━━━━━━━一元稀疏多项式运算━━━━━━━━━━┓\n");
		printf("┃                                      ┃\n");
		printf("┃1----创建多项式 A&B    2----加法 A+B  ┃\n");
		printf("┃                                      ┃\n");
		printf("┃3----减法 A-B          4----减法 B-A  ┃\n");
		printf("┃                                      ┃\n");
		printf("┃5----显示多项式 A&B    0----退出程序  ┃\n");
		printf("┃                                      ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf(" 请输入您的选择：");
		scanf("%d", &choice);//输入自己的选项
		printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		switch (choice)
		{
		case 0:
			break;
		case 1:
		{
				  count = 0;
				  head1 = create();
				  head2 = create();
				  break;
		}
		case 2:
		{
				  check(head1, head2);
				  count = 2;
				  add_subtract(head1, head2);
				  break;
		}
		case 3:
		{
				  check(head1, head2);
				  count = 3;
				  add_subtract(head1, head2);
				  break;
		}
		case 4:
		{
				  check(head1, head2);
				  count = 4;
				  add_subtract(head2, head1);
				  break;
		}
		case 5:{
				   check(head1, head2);
			   break;

		}
		default:
			printf("您输入的有误，请重新选择！");
			break;
		}
	} while (choice);//当choice=0时，false，循环结束
	system("pause");
	return 0;
}
//创建多项式
struct polynomial *create()
{
	node *head = NULL, *p1=NULL, *p2 = NULL;
	int n;//项数
	count++;//用于选择输出多项式a或b
	printf(" 请输入多项式");
	if (count == 1){
		printf(" A ");
		}
	else {
		printf(" B ");
	}
	printf("的 <项数>：");
	scanf("%d", &n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//动态创建链表
	int i;
	for (i = 1; i <= n; i++)
	{
		if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next = NULL;
		printf(" 请输入多项式");
		if (count == 1)printf(" A ");
		else printf(" B ");
		printf("的第 %d 项系数和指数：", i);
		scanf("%lf", &p1->coefficient);
		scanf("%d", &p1->index);
		if (i == 1){
			head->next = p1;
		}//输入是第一项时，头节点指针指向第一项
		else { 
			p2->next = p1; 
		}//连接链表
		p2 = p1;
	}
	printf(" 多项式");
	if (count == 1)printf(" A = ");
	else printf(" B = ");
	sort(head);//对多项式进行降序排序
	display(head);//输出多项式
	printf(" ━━━━━━━━━━━━━━━━━━━━\n");
	return head;
}
//降序排列
void sort(struct polynomial *head)
{
	node *p1 = NULL, *curr = NULL, *pre = NULL, *p2 = NULL;//新建链表
	p1 = head->next;//p1指针所指向的结点要逐个取出作为插入结点
	head->next = NULL;//head指针带头结点，初始为空链表
	while (p1 != NULL)//p1指针不为空时循环
	{
		curr = head->next;
		pre = head;
		//定位插入位置，退出循环时，pre指针向要插入节点的位置
		while (curr != NULL && curr->index >= p1->index)
		{
			pre = curr;
			curr = curr->next;
		}
		p2 = p1; //p2指针指向要插入结点的位置
		p1 = p1->next;//p1指针指向下一个结点
		//p2指针所指结点插入pre指针所指结点后
		p2->next = pre->next;
		pre->next = p2;
	}
}
void add_subtract(struct polynomial *head1, struct polynomial *head2)
{
	node *head = NULL;//新建链表储存相加后多项式
	node *p1 = NULL;//中间变量
	node *p2 = NULL;//保留前一个结点
	node *p = NULL;//第一个多项式的循环变量
	node *pp = NULL;//第二个多项式的循环变量
	if ((head = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
		printf("ERROR");
		exit(0);
	}
	head->next = NULL;
	for (pp = head2->next; pp != NULL; pp = pp->next){//复制第二个多项式链表
		if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
			printf("ERROR");
			exit(0);
		}
		p1->next = NULL;
		if (count == 2){
			p1->coefficient = pp->coefficient;//加法直接复制
		}
		if (count == 3 || count == 4){
			p1->coefficient = (-1.0)*pp->coefficient;//减法取相反数
			
		}
		p1->index = pp->index;
		if (head->next == NULL){
			head->next = p1;
		}
		
		else {
			p2->next = p1;
		}
		p2 = p1;
	}
	for (p = head1->next; p != NULL; p = p->next){//循环多项式的每一项
		for (pp = head->next, p2 = head; pp != NULL;){
			if (p->index == pp->index){//指数相等
				pp->coefficient = p->coefficient + pp->coefficient;//系数相加
				if (pp->coefficient == 0){
					pp = pp->next;
					p2->next = pp;
				}
				else{
					pp = pp->next;
					p2 = p2->next;
				}
				break;
			}
			if (pp->next == NULL){//没有相同指数项，创建添加
				if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
					printf("ERROR");
					exit(0);
				}
				p1->next = NULL; //初始为空链表
				p1->coefficient = p->coefficient;//多余项添加到新建链表
				p1->index = p->index;
				p1->next = head->next;
				head->next = p1;

				pp = pp->next;//循环
				p2 = p2->next;
				break;
			}
			pp = pp->next;
			p2 = p2->next;
		}
	}
	if (count == 2)printf(" A + B = ");
	if (count == 3)printf(" A - B = ");
	if (count == 4)printf(" B - A = ");
	sort(head);
	display(head);
	printf(" ━━━━━━━━━━━━━━━━━━━━\n");
}
//输出多项式
void display(struct polynomial *head)
{
	struct polynomial *p = NULL;
	
	for (p = head->next; p != NULL; p = p->next)
		//将头指针付给中间变量p，当p不为空时，p = p->next实现循环传递
	{
		if (p->index == 0){
			if (p->coefficient == 0){
				printf("0.00");
			}
			else printf("%.2lf", p->coefficient);// %.2lf保留两位小数
		}
		else if (p->index == 1){
			if (p->coefficient == 1)printf("x");
			else if (p->coefficient == -1)printf("-x");
			else printf("%.2lfx", p->coefficient);
		}
		else if (p->index != 1){
			if (p->coefficient == 1 && p->index>0)printf("x^%d", p->index);
			else if (p->coefficient == -1 && p->index>0)printf("-x^%d", p->index);
			else if (p->coefficient == 1 && p->index<0)printf("x^(%d)", p->index);
			else if (p->coefficient == -1 && p->index<0)printf("-x^(%d)", p->index);
			else if (p->index<0)printf("%.2lfx^(%d)", p->coefficient, p->index);
			//TODO
			else printf("%.2lfx^%d", p->coefficient, p->index);
		}
		if (p->next != NULL&&p->next->coefficient >0)printf("+");
		//连接多个单项式，若为正数则用＋号，负数则直接用自带的负号
	}
	printf("\n");
}
//校验多项式是否存在
void check(node *head1, node *head2){
	if (head1 == NULL){
		printf("A多项式不存在！\n");
		head1 = create();
	}
	if (head2 == NULL){
		printf("B多项式不存在！\n");
		head2 = create();
	}
	printf(" 多项式 A = ");
	display(head1);
	printf(" 多项式 B = ");
	display(head2);
}