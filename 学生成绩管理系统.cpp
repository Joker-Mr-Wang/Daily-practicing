#include <stdio.h>
#include<stdlib.h>
#define X 100

struct Student       
{  
    int num;                       
	char name[X];              
	float Math;             
	float c;                    
	float english;                 
	float average;                                                                                               	
}sdu[X];                      

int n;                        //����һ��ȫ�ֱ���n�����������������ѧ���ĸ���.

int main()
{  
    system("color c1");
     //��������                                                                                                     
	void input(struct Student sdu[]);                                  
	void output(struct Student sdu[]);                                  
	void search(struct Student sdu[]);                              
	void c(struct Student sdu[]);                                                                
	void Math(struct Student sdu[]);                               
	void english(struct Student sdu[]);                               
	int Mathlow(struct Student sdu[]);                                   
	int clow(struct Student sdu[]);                                      
	int englishlow(struct Student sdu[]);
	void rest(struct Student sdu[]);
                                                      
	void del(struct Student sdu[]);                                   
	void rew(struct Student sdu[]);                                     
	int menu;                                                           
	
                      // �˵�����
	printf("*************************************************************************\n");
	printf("*       ����ѧ���ɼ���������1��       ���ѧ����Ϣ��������2��           *\n"); 
	printf("*                                                                       *\n");
	printf("*       ȱʡ��ѯ��������3��           �޸�ѧ����Ϣ��������4��           *\n");  
	printf("*                                                                       *\n");
	printf("*   ������߷ֺͲ�����ͳ�ƣ�������5��  ɾ��ѧ����Ϣ��������6��          *\n");
	printf("*                                                                       *\n");
	printf("*                                                                       *\n");
	printf("*                                                                       *\n"); 
	printf("*************************************************************************\n"); 
	printf("������ѧ��������\a\a");
	scanf("%d",&n);
	
	
	
	menu=1;                                        // �˵�ѡ�������ʼ��Ϊ1��Ŀ���ǽ���while�����switch���ѡ��
	while(menu>=1 && menu<=8)                      
	{   
		printf("������ѡ��: ");
		scanf("%d", &menu);
		
		switch(menu) 
		{
		case 1:
		    input(sdu);                            
			break;
		case 2:
	     	output(sdu);                           
			break;
		case 3:
			search(sdu);
			
			                          
			break;
		case 4:
			rew(sdu);
		                            
			break;
		
		case 5:
			Math(sdu);                       
			printf("%f\n",sdu[0].Math);
			c(sdu);                       
			printf("%f\n",sdu[0].c);
			english(sdu);                       
			printf("%f\n",sdu[0].english); 	
			printf("��ѧ����������Ϊ:%d\n",Mathlow(sdu));	
			printf("c�ﲻ��������Ϊ:%d\n",clow(sdu)); 
			printf("Ӣ�ﲻ��������Ϊ:%d\n",englishlow(sdu));
		    rest(sdu); 
			                            
			break;
            case 6:
			del(sdu);
			break;
		

	
	
		default:
			printf("error!\n");                    // ��ѡ����1--6��Χ��ʱ��ִ�и���䣬��ֹswitch��䣬Ȼ������ѭ������������
			break;
		}
	}                                                           
    
	return 0;
}


	

/* ����ѧ����Ϣ*/
void input(struct Student sdu[])   
{    
	int i;
    printf("*************************************************************************\n");
	printf("��¼��ѧ����Ϣ��ѧ�� ���� ��ѧ c���� Ӣ�����֮���ÿո������:   \n"); 

	for(i=0;i<n;i++)                                                                                                                           
	{
		scanf("%d %s %f %f %f", &sdu[i].num, sdu[i]. name, &sdu[i].Math, &sdu[i].c, &sdu[i].english);
		sdu[i].average=(sdu[i].Math+sdu[i].c+sdu[i].english)/3;
	}
    printf("������� \n");
}                                                                                   

/* ���ѧ����Ϣ */
void output(struct Student sdu[]) 
{                                                           
    int i;
	printf("������Ϊ \n");
    printf("ѧ��    ����    ��ѧ    c����    Ӣ��   ƽ���ɼ�\n");
	for(i=0;i<n;i++)                                                             
	{
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                                               
}

/* ȱʡ��ѯѧ�� */
void search(struct Student sdu[])                                                              
{
	int i,x=0;
	char num_get;                                                           
	printf("������Ҫ��ѯѧ������������ĸ: ");
	scanf("%s", &num_get);;
	for (i=0;i<n;i++)
	{ 
		if(num_get==sdu[i].name[0])  
		{                                                                
			                        
			printf(" ����ѧ����ϢΪ \n");
			printf("ѧ��    ����    ��ѧ    c����    Ӣ��   ƽ���ɼ�\n");
			printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i].name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
			x=x+1;
		}
    }
		if(x==0)                         
			printf("�޸�ѧ����Ϣ��\n"); 
			    
}
/* �޸�ѧ����Ϣ */
void rew(struct Student sdu[])
{
	int i,j;                                  
	printf("�������޸�ѧ����ѧ�ţ�");
	scanf("%d",&j);
	printf("�������޸ĺ��ѧ����Ϣ��");
	scanf("%d %s %f %f %f", &sdu[j-1].num, sdu[j-1]. name, &sdu[j-1].Math, &sdu[j-1].c, &sdu[j-1].english);
	sdu[j-1].average=(sdu[j-1].Math+sdu[j-1].c+sdu[j-1].english)/3;//ƽ���ֵ�����
	printf("�޸ĺ�Ľ��\n");
	printf("ѧ��    ����    ��ѧ    c����    Ӣ��   ƽ���ɼ�\n");
	for(i=0;i<n;i++)                                                               
	{
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}

/* ѧ���ɼ���߷ּ�������ͳ�� */
void Math(struct Student sdu[])
{
	int i, j;
	struct Student temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)                 
		{
			if(sdu[j].Math<sdu[j+1].Math)
			{
			   temp=sdu[j];
			   sdu[j]=sdu[j+1];
			   sdu[j+1]=temp;
		    }
		}
	}
	printf("��ѧ��߷�Ϊ: \n");
}
void c(struct Student sdu[])
{
	int i, j;
	struct Student temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)                 
		{
			if(sdu[j].c<sdu[j+1].c)
			{
			   temp=sdu[j];
			   sdu[j]=sdu[j+1];
			   sdu[j+1]=temp;
		    }
		}
	}
	printf("c����߷�Ϊ: \n");
}
void english(struct Student sdu[])
{
	int i, j;
	struct Student temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)                 
		{
			if(sdu[j].english<sdu[j+1].english)
			{
			   temp=sdu[j];
			   sdu[j]=sdu[j+1];
			   sdu[j+1]=temp;
		    }
		}
	}
	printf(" ������߷�Ϊ: \n");
}
int Mathlow(struct Student sdu[])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
	   if(sdu[i].Math<60)
	   j++;
    }
	return j;
}
int clow(struct Student sdu[])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
	   if(sdu[i].c<60)
	   j++;
    }
	return j;
}
int englishlow(struct Student sdu[])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
	   if(sdu[i].english<60)
	   j++;
    }
	return j;
}
void rest(struct Student sdu[])
{
	int i=0;
	int j;
	struct Student temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)                 
		{
			if(sdu[j].num>sdu[j+1].num)
			{
			   temp=sdu[j];
			   sdu[j]=sdu[j+1];
			   sdu[j+1]=temp;
		    }
		}
	}
}

   
/* ɾ��ѧ����Ϣ */
void del(struct Student sdu[])
{
	int i,j;                                  
	printf("������ɾ��ѧ����ѧ�ţ�");
	scanf("%d",&j);
	printf("ɾ����Ľ��\n");
	printf("ѧ��    ����    ��ѧ    c����    Ӣ��   ƽ���ɼ�\n");
	for(i=0;i<n;i++)                                                               
	{
		if(i!=j-1)
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}
void l(struct Student sdu[])
{
	int i,j;                                  
	printf("������ѧ����ѧ�ţ�");
	scanf("%d",&j);
	printf("���\n");
	printf("ѧ��    ����    ��ѧ    c����    Ӣ��   ƽ���ɼ�\n");
	for(i=0;i<n;i++)                                                               
	{
		if(i!=j-1)
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}
