#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial//����ʽ��ÿһ��ṹ
{
	double coefficient;//ϵ��
	int index;//ָ��
	struct polynomial *next;//ָ��->ָ����һ���ڵ�
}node;

struct polynomial *create();//��������
void sort+++++++++++++++++++++++++(struct polynomial *head);//��������
void add_subtract(struct polynomial *head1, struct polynomial *head2);//�Ӽ���
void display(struct polynomial *head);//�������ʽ
void check(node *head1, node *head2);//У�����ʽ
int count;//����ѡ���������ʽa��b,�����ڶ���ʽȡ��

int main()
{
	int choice;
	node *head1 = NULL;
	node *head2 = NULL;
	do{
		printf("\n");
		printf("����������������������һԪϡ�����ʽ���㩥��������������������\n");
		printf("��                                      ��\n");
		printf("��1----��������ʽ A&B    2----�ӷ� A+B  ��\n");
		printf("��                                      ��\n");
		printf("��3----���� A-B          4----���� B-A  ��\n");
		printf("��                                      ��\n");
		printf("��5----��ʾ����ʽ A&B    0----�˳�����  ��\n");
		printf("��                                      ��\n");
		printf("��������������������������������������������������������������������������������\n");
		printf(" ����������ѡ��");
		scanf("%d", &choice);//�����Լ���ѡ��
		printf(" ��������������������������������������������������������������������\n");
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
			printf("�����������������ѡ��");
			break;
		}
	} while (choice);//��choice=0ʱ��false��ѭ������
	system("pause");
	return 0;
}
//��������ʽ
struct polynomial *create()
{
	node *head = NULL, *p1=NULL, *p2 = NULL;
	int n;//����
	count++;//����ѡ���������ʽa��b
	printf(" ���������ʽ");
	if (count == 1){
		printf(" A ");
		}
	else {
		printf(" B ");
	}
	printf("�� <����>��");
	scanf("%d", &n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//��̬��������
	int i;
	for (i = 1; i <= n; i++)
	{
		if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next = NULL;
		printf(" ���������ʽ");
		if (count == 1)printf(" A ");
		else printf(" B ");
		printf("�ĵ� %d ��ϵ����ָ����", i);
		scanf("%lf", &p1->coefficient);
		scanf("%d", &p1->index);
		if (i == 1){
			head->next = p1;
		}//�����ǵ�һ��ʱ��ͷ�ڵ�ָ��ָ���һ��
		else { 
			p2->next = p1; 
		}//��������
		p2 = p1;
	}
	printf(" ����ʽ");
	if (count == 1)printf(" A = ");
	else printf(" B = ");
	sort(head);//�Զ���ʽ���н�������
	display(head);//�������ʽ
	printf(" ����������������������������������������\n");
	return head;
}
//��������
void sort(struct polynomial *head)
{
	node *p1 = NULL, *curr = NULL, *pre = NULL, *p2 = NULL;//�½�����
	p1 = head->next;//p1ָ����ָ��Ľ��Ҫ���ȡ����Ϊ������
	head->next = NULL;//headָ���ͷ��㣬��ʼΪ������
	while (p1 != NULL)//p1ָ�벻Ϊ��ʱѭ��
	{
		curr = head->next;
		pre = head;
		//��λ����λ�ã��˳�ѭ��ʱ��preָ����Ҫ����ڵ��λ��
		while (curr != NULL && curr->index >= p1->index)
		{
			pre = curr;
			curr = curr->next;
		}
		p2 = p1; //p2ָ��ָ��Ҫ�������λ��
		p1 = p1->next;//p1ָ��ָ����һ�����
		//p2ָ����ָ������preָ����ָ����
		p2->next = pre->next;
		pre->next = p2;
	}
}
void add_subtract(struct polynomial *head1, struct polynomial *head2)
{
	node *head = NULL;//�½���������Ӻ����ʽ
	node *p1 = NULL;//�м����
	node *p2 = NULL;//����ǰһ�����
	node *p = NULL;//��һ������ʽ��ѭ������
	node *pp = NULL;//�ڶ�������ʽ��ѭ������
	if ((head = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
		printf("ERROR");
		exit(0);
	}
	head->next = NULL;
	for (pp = head2->next; pp != NULL; pp = pp->next){//���Ƶڶ�������ʽ����
		if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
			printf("ERROR");
			exit(0);
		}
		p1->next = NULL;
		if (count == 2){
			p1->coefficient = pp->coefficient;//�ӷ�ֱ�Ӹ���
		}
		if (count == 3 || count == 4){
			p1->coefficient = (-1.0)*pp->coefficient;//����ȡ�෴��
			
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
	for (p = head1->next; p != NULL; p = p->next){//ѭ������ʽ��ÿһ��
		for (pp = head->next, p2 = head; pp != NULL;){
			if (p->index == pp->index){//ָ�����
				pp->coefficient = p->coefficient + pp->coefficient;//ϵ�����
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
			if (pp->next == NULL){//û����ָͬ����������
				if ((p1 = (struct polynomial*)malloc(sizeof(struct polynomial))) == NULL){
					printf("ERROR");
					exit(0);
				}
				p1->next = NULL; //��ʼΪ������
				p1->coefficient = p->coefficient;//��������ӵ��½�����
				p1->index = p->index;
				p1->next = head->next;
				head->next = p1;

				pp = pp->next;//ѭ��
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
	printf(" ����������������������������������������\n");
}
//�������ʽ
void display(struct polynomial *head)
{
	struct polynomial *p = NULL;
	
	for (p = head->next; p != NULL; p = p->next)
		//��ͷָ�븶���м����p����p��Ϊ��ʱ��p = p->nextʵ��ѭ������
	{
		if (p->index == 0){
			if (p->coefficient == 0){
				printf("0.00");
			}
			else printf("%.2lf", p->coefficient);// %.2lf������λС��
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
		//���Ӷ������ʽ����Ϊ�������ã��ţ�������ֱ�����Դ��ĸ���
	}
	printf("\n");
}
//У�����ʽ�Ƿ����
void check(node *head1, node *head2){
	if (head1 == NULL){
		printf("A����ʽ�����ڣ�\n");
		head1 = create();
	}
	if (head2 == NULL){
		printf("B����ʽ�����ڣ�\n");
		head2 = create();
	}
	printf(" ����ʽ A = ");
	display(head1);
	printf(" ����ʽ B = ");
	display(head2);
}