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

int n;                        //定义一个全局变量n，用来控制需输入的学生的个数.

int main()
{  
    system("color c1");
     //函数声明                                                                                                     
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
	
                      // 菜单功能
	printf("*************************************************************************\n");
	printf("*       输入学生成绩（请输入1）       输出学生信息（请输入2）           *\n"); 
	printf("*                                                                       *\n");
	printf("*       缺省查询（请输入3）           修改学生信息（请输入4）           *\n");  
	printf("*                                                                       *\n");
	printf("*   各科最高分和不及格统计（请输入5）  删除学生信息（请输入6）          *\n");
	printf("*                                                                       *\n");
	printf("*                                                                       *\n");
	printf("*                                                                       *\n"); 
	printf("*************************************************************************\n"); 
	printf("请输入学生个数：\a\a");
	scanf("%d",&n);
	
	
	
	menu=1;                                        // 菜单选项变量初始化为1，目的是进入while下面的switch语句选择
	while(menu>=1 && menu<=8)                      
	{   
		printf("请输入选项: ");
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
			printf("数学不及格人数为:%d\n",Mathlow(sdu));	
			printf("c语不及格人数为:%d\n",clow(sdu)); 
			printf("英语不及格人数为:%d\n",englishlow(sdu));
		    rest(sdu); 
			                            
			break;
            case 6:
			del(sdu);
			break;
		

	
	
		default:
			printf("error!\n");                    // 当选择不在1--6范围内时，执行该语句，终止switch语句，然后跳出循环，函数结束
			break;
		}
	}                                                           
    
	return 0;
}


	

/* 输入学生信息*/
void input(struct Student sdu[])   
{    
	int i;
    printf("*************************************************************************\n");
	printf("请录入学生信息：学号 姓名 数学 c语言 英语（数据之间用空格隔开）:   \n"); 

	for(i=0;i<n;i++)                                                                                                                           
	{
		scanf("%d %s %f %f %f", &sdu[i].num, sdu[i]. name, &sdu[i].Math, &sdu[i].c, &sdu[i].english);
		sdu[i].average=(sdu[i].Math+sdu[i].c+sdu[i].english)/3;
	}
    printf("输入完成 \n");
}                                                                                   

/* 输出学生信息 */
void output(struct Student sdu[]) 
{                                                           
    int i;
	printf("输出结果为 \n");
    printf("学号    姓名    数学    c语言    英语   平均成绩\n");
	for(i=0;i<n;i++)                                                             
	{
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                                               
}

/* 缺省查询学生 */
void search(struct Student sdu[])                                                              
{
	int i,x=0;
	char num_get;                                                           
	printf("请输入要查询学生的姓名首字母: ");
	scanf("%s", &num_get);;
	for (i=0;i<n;i++)
	{ 
		if(num_get==sdu[i].name[0])  
		{                                                                
			                        
			printf(" 所查学生信息为 \n");
			printf("学号    姓名    数学    c语言    英语   平均成绩\n");
			printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i].name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
			x=x+1;
		}
    }
		if(x==0)                         
			printf("无该学生信息！\n"); 
			    
}
/* 修改学生信息 */
void rew(struct Student sdu[])
{
	int i,j;                                  
	printf("请输入修改学生的学号：");
	scanf("%d",&j);
	printf("请输入修改后该学生信息；");
	scanf("%d %s %f %f %f", &sdu[j-1].num, sdu[j-1]. name, &sdu[j-1].Math, &sdu[j-1].c, &sdu[j-1].english);
	sdu[j-1].average=(sdu[j-1].Math+sdu[j-1].c+sdu[j-1].english)/3;//平均分的运算
	printf("修改后的结果\n");
	printf("学号    姓名    数学    c语言    英语   平均成绩\n");
	for(i=0;i<n;i++)                                                               
	{
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}

/* 学生成绩最高分及不及格统计 */
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
	printf("数学最高分为: \n");
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
	printf("c语最高分为: \n");
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
	printf(" 物理最高分为: \n");
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

   
/* 删除学生信息 */
void del(struct Student sdu[])
{
	int i,j;                                  
	printf("请输入删除学生的学号：");
	scanf("%d",&j);
	printf("删除后的结果\n");
	printf("学号    姓名    数学    c语言    英语   平均成绩\n");
	for(i=0;i<n;i++)                                                               
	{
		if(i!=j-1)
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}
void l(struct Student sdu[])
{
	int i,j;                                  
	printf("请输入学生的学号：");
	scanf("%d",&j);
	printf("结果\n");
	printf("学号    姓名    数学    c语言    英语   平均成绩\n");
	for(i=0;i<n;i++)                                                               
	{
		if(i!=j-1)
		printf("%3d %8s %8.1f %8.1f %8.1f %10.1f\n", sdu[i].num, sdu[i]. name, sdu[i].Math, sdu[i].c, sdu[i].english, sdu[i].average);
	}                                  
}
