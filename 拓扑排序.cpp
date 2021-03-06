#include<iostream>
#include<string.h>
using namespace std;//避免导致全局命名冲突问题 
typedef string Vertex;//定义一个字符串类型 
typedef int InfroType;//存放权值
#define null 0
const int MAXN = 20;//定义拓扑排序数组的大小（最大顶点个数） 

typedef struct ArcNode  //边表 （弧的结构体） 
{
	int adjvex;//该边所指向的顶点位置
	struct ArcNode * nextarc;//指向下一条边的指针 
	InfroType Infro;//存放权值
	bool flag;//判断是否有边 
}ArcNode;

typedef struct VNode//顶点表结构体 
{
	Vertex data;//节点名称 
	int count;//计数器 计算入度 
	ArcNode *firstarc;//指向第一个边表 
}VNode;

typedef struct Graph //邻接表，带权有向图 
{
	VNode adjlist[MAXN];
	int n, e;//n顶点 e边数	
}Graph;

int visited[MAXN];
int ve[MAXN];//事件最早发生 
int vl[MAXN];//事件最晚发生 
int stack[MAXN];//栈 
int st[MAXN];
int tp;//两个栈顶 
int top;
//取二者最大值 
int max(int x, int y)
{
	if( x > y) return x;
	else return y;
}
//取二者最小值 
int min(int x, int y)
{
	if(x < y)
		return x;
	else return y;
}
//Init(&g):初始化有向图
void Init(Graph   * & g)
{
	int i;
	//g->n是有向图的顶点个数，g->e是有向图的边数，g->adjlist是存放有向图的顶点和邻接点的指针的数组。
	g->n = 0;
	g->e = 0;
	for(i = 0; i < MAXN; i++)
	{
		g->adjlist[i].firstarc = null;
		g->adjlist [i].count = 0;
	}//g->n,g->e赋值为零，数组中的每一行的指针域都赋值为空。
}
//判断是否为空 
bool Empty(Graph * g)
{
	if( g->n == 0 && g->e == 0 )
		return true;
	else
		return false;
}

//寻找结点在连接表中的位置 
int Find(Graph * g,Vertex v)
{
	if(Empty(g))
	{
		cout << "图为空." << endl;
		return -1;//图为空返回-1 
	}
	int i;
	for(i = 0; i < g->n; i++)
		if(g->adjlist[i].data == v)
			return i;//返回字串在整个数组中的位置 
	return -1;//找不到则返回-1 
}

//Creat(&g):根据输入信息创建有向图
void Create(Graph * & g)//g是初始化后的图。
{
	int i, i1, i2;
	Vertex v1, v2;//结点v1 v2 
	InfroType w;//权值 
	cout << "请输入顶点数和边数(顶点 边数): " << endl;
	cin >> g->n >> g->e;
	cout << "请输入顶点（中间用“”间隔）：" << endl;
	for(i = 0; i < g->n; i++)
		cin >> g->adjlist[i].data ;
	ArcNode * p;//初始化边表 
	p = null;
	cout << "边和权值:（顶点  顶点  权值） " << endl;
	for(i = 1; i <= g->e; i++)
	{
		cin >> v1 >> v2 >> w ;
		i1 = Find(g, v1);//查找v1在g中的位置并用i1返回 
		i2 = Find(g, v2);//查找v2在g中的位置并用i2返回 
		if( i1 != -1 && i2 != -1)//v1， v2存在 
		{
			p = new ArcNode;
			p->adjvex = i2;//p的顶点是i2 
			p->Infro = w;//p的权值 
			p->flag = false;//该位置不为空 
			p->nextarc = g->adjlist[i1].firstarc ;//p的下一个结点时v1的头结点 
			g->adjlist [i1].firstarc = p;//形成链接 
		}//根据输入的信息建立起邻接表存储的有向图。
	}
}
// 按照存储结构输出
void Output(Graph *g)
{
	if(Empty(g))//判空 
	{
		cout << "图为空." << endl;
		return;
	}
	int i;
	cout << "按照邻接表输出为: " << endl;
	for( i = 0;  i < g->n; i++)
	{
		cout << g->adjlist [i].data;//输出节点名称 
		ArcNode * p;
		p = g->adjlist [i].firstarc ;//输出首元节点 
		while(p)
		{
			cout << " ---> " << "(" << g->adjlist[p->adjvex ].data << "," << p->Infro << ")" ;//节点名称+权值 
			p = p->nextarc ;//依次输出其他节点，直到空为止 
		}
		cout << endl;
	}
	
}
//输出出度 
void Du(Graph * g)/*求图中各个顶点的度*/
{
	if(Empty(g))
	{
		cout << "图为空." << endl;
		return;//判空 
	}
	int v;
	int k = 0;
	for(v = 0; v < g->n; v++)
	{
		k = 0;
		ArcNode * p;
		p = g->adjlist[v].firstarc ;
		while(p)
		{
			k++;
			p = p->nextarc ;
		}
		cout << "顶点" << g->adjlist[v].data  << "的出度为: " << k <<endl;//以这个结点为弧尾，输出出度 
	}
}
//输出入度 
void Rdu(Graph *g, int f)
{
	if(Empty(g))
	{
		cout << "有向图为空." << endl;
		return;
	}
	int i;
	ArcNode * p;
	for(i = 0; i <= g->n; i++)
		g->adjlist [i].count = 0;//判断入度 
	for(i = 0; i < g->n; i++)
	{
		p = g->adjlist [i].firstarc ;
		while(p)
		{
			g->adjlist [p->adjvex].count ++;//如存在，则count++ 
			p = p->nextarc ;//寻找下一个弧 
		}
	}
	if(f == 0)
	{
	for(i = 0; i < g->n; i++)
		cout << g->adjlist [i].data << "的入度为: " << g->adjlist [i].count << endl;//以这个结点为弧头，输出出度
	}
}
//采用拓扑排序的方法求事件发生的最早时间和最迟时间，并确定最短路径包含的结点
bool Topsort(Graph * g, int &infro, int & v)
{
	int stack[MAXN];//构建两个栈 ，负责将入度为0的点压入栈 
    int st[MAXN];//负责输出最终结果 
    int tp;//定义两个变量位于栈顶 
    int top;
	memset(ve, 0, sizeof(int) * MAXN);//初始化ve栈 
	Rdu(g, 1);
	top = -1;//初始化栈顶元素 
	tp = -1;
	int i, m, n;
	ArcNode * p;//边表结构体指针 
	p = null;//初始化ArcNode 
	infro = 0;//初始化infro 
	for(i = 0; i < g->n; i++)//循环遍历查找入度为0的结点，优先输出 
		if(g->adjlist [i].count == 0)
		{
			if(g->adjlist [i].firstarc  && infro < g->adjlist [i].firstarc ->Infro )
			{
				infro = g->adjlist [i].firstarc ->Infro ;//当入度为0时，将g中的权值赋给infro 
			}
		}
	m = v;
	//判断一下数据是否合理 
	for(i = 0; i < g->n; i++)
		if(!g->adjlist [i].firstarc)
		{
			if( v == m)
				v = i;
			else//二者时间不相等，则结束事件不唯一 
			{
				cout << "结束事件不唯一." << endl;
				return false;// 
			}	
		}
		
	if(infro == -1)//没有入度为0的点 
	{
		cout << "没有找到开始事件. " << endl;
		return false;
	}
	if(v == -1)
	{
		cout << "没有找到结束事件." << endl;
		return false;
	}
	
	for(i = 0; i <= g->n; i++)
		vl[i] = INT_MAX;//初始化vl，最迟发生时间 
	for(i = 0; i < g->n; i++)
		if(g->adjlist [i].count  == 0)
			stack[++top] = i;//遍历数据表，将度为0的结点压入stack，stack栈++ 
	while( top + 1 )//当堆栈不为空时 
	{
	    m = stack[top--];//将stack出栈赋值给m 
		g->adjlist [m].count = -1;
		st[++tp] = m;//将拓扑排序的结果m存入st数组中 
		p = g->adjlist [m].firstarc ;
		while(p)
		{
			n = p->adjvex ;
			if(g->adjlist [n].count == -1)
			{
				cout << "该有向图有环." << endl;
				return false ;
			}
			ve[n] = max(ve[n],ve[m] + p->Infro) ;
			g->adjlist [n].count --;
			if(g->adjlist [n].count  == 0)
				stack[++top] = n;
			p = p->nextarc;
		}
	}
	if(tp < g->n - 1)
	{
		cout << "拓扑排序不成功." << endl;
		return false;
	}
	else
		cout << "拓扑排序成功." << endl;
	vl[tp] = ve[tp];//当vl=ve证明时，关键活动 
	tp--;
	while(tp + 1)//当tp不为空 
	{
		p = g->adjlist [st[tp]].firstarc ;
		while(p)//当p不为空时 
		{//将 vl[st[tp]], vl[p->adjvex ] - p->Infro较小者赋值给 vl[st[tp]]
			vl[st[tp]] = min(vl[st[tp]], vl[p->adjvex ] - p->Infro );
			p = p->nextarc ;//循环寻找下一个值 
		}
		p = g->adjlist [st[tp]].firstarc ;
		while(p)
		{
			if(vl[st[tp]] == vl[p->adjvex ] - p->Infro )
				p->flag = true;
			p = p->nextarc ;
		}
		tp--;
	}

	return true;
}
//有向图的顶点和弧 
void Print(Graph * g)
{
	if(Empty(g))
	{
		cout << "有向图为空." << endl;
		return; 
	}
	int i;
	cout << "有向图的顶点为: " << endl;
	for(i = 0; i < g->n; i++)
	{
		cout << g->adjlist [i].data << " " ;//输出顶点 
	}
	cout << endl;
	cout << "弧: " << endl;
	for(i = 0; i < g->n; i++)
	{
		ArcNode *p;
		p = g->adjlist[i].firstarc;
		while(p)
		{
			cout << g->adjlist[i].data << " " << g->adjlist [p->adjvex].data << " " << p->Infro << endl;
			p = p->nextarc;//输出弧 
		}
	}
}
//遍历关键路径并输出。 
void Path(Graph * g,int u, int v,int path[], int d)
{
	int j, i;
	ArcNode * p;
	p = null;
	visited[u] = 1;
	d++;
	path[d] = u;
	p = g->adjlist [u].firstarc ;// 
	if(u == v) //活动的最早开始时间与结束时间相同 
	{
		cout << "关键路径: ";
		cout << g->adjlist [path[0]].data; 
		for(i = 1; i <= d; i++)
			cout << "--->" << g->adjlist [path[i]].data;//输出关键路径 
		cout << "   总工期: " << ve[v] << endl;//输出总工期 
	}
	while(p)
	{
		j = p->adjvex ;
		if(visited[j] == 0 && vl[j] == ve[j] && p->flag )
			Path(g, j, v, path, d);
		p = p->nextarc ;
	}
	visited[u] = 0;
	d--;

}
//创建关键路径
void CriticPath(Graph * g)
{
	if(Empty(g))
	{
		cout << "图为空." << endl;
		return;
	}
	int infro, v, i;
	infro = -1;
	v = -1;
	//判断关键路径是否存在 
	if(Topsort(g, infro, v) == false || infro == -1 || v == -1)
	{
		return ;
	}
	Rdu(g, 1);
	for(i = 0; i < g->n; i++)
		if(g->adjlist [i].count == 0 && g->adjlist [i].firstarc && g->adjlist [i].firstarc ->Infro == infro)//入度为0，且 g->adjlist [i].firstarc ->Infro == infro
		{
			memset(visited, 0, sizeof(int) * MAXN);
			memset(st, 0, sizeof(int) * MAXN);
			Path(g, i, v, st, -1);
		}
}
//菜单栏 
void Menu()
{
	cout << "		  关键路径         " << endl;
	cout << "	  新建有向网-------------------->1" << endl;
	cout << "	  输出邻接表-------------------->2" << endl;
	cout << "	  输出各顶点的出度-------------->3" << endl;
	cout << "	  输出各顶点的入度-------------->4" << endl;
    cout << "	  输出有向图的顶点和弧---------->5" << endl;
    cout << "	  输出关键路径------------------>6" << endl;
	cout << "	  退出-------------------------->0" << endl;
	cout << "请输入..." << endl;
}
//主函数 
int main()
{
	Graph * g;
	g = new Graph;
	Init(g);//初始化邻接表 
	int choose;//定义一个变量choose用于选择菜单选项 
	while(1)
	{	
		Menu();//调用菜单函数 
		cin >> choose;//标准输入流 
		switch(choose)
		{
		case 1: Init(g); Create(g); break;// 新建有向网
		case 2:	Output(g); break;//邻接表 
		case 3: Du(g); break;//各顶点的出度 
		case 4: Rdu(g, 0); break;//各顶点的入度 
		case 5: Print(g); break;//有向图的顶点和弧 
		case 6: CriticPath(g); break;//关键路径 
		default : return 0;
		}	
	}
}

