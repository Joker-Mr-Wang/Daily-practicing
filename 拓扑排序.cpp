#include<iostream>
#include<string.h>
using namespace std;//���⵼��ȫ��������ͻ���� 
typedef string Vertex;//����һ���ַ������� 
typedef int InfroType;//���Ȩֵ
#define null 0
const int MAXN = 20;//����������������Ĵ�С����󶥵������ 

typedef struct ArcNode  //�߱� �����Ľṹ�壩 
{
	int adjvex;//�ñ���ָ��Ķ���λ��
	struct ArcNode * nextarc;//ָ����һ���ߵ�ָ�� 
	InfroType Infro;//���Ȩֵ
	bool flag;//�ж��Ƿ��б� 
}ArcNode;

typedef struct VNode//�����ṹ�� 
{
	Vertex data;//�ڵ����� 
	int count;//������ ������� 
	ArcNode *firstarc;//ָ���һ���߱� 
}VNode;

typedef struct Graph //�ڽӱ���Ȩ����ͼ 
{
	VNode adjlist[MAXN];
	int n, e;//n���� e����	
}Graph;

int visited[MAXN];
int ve[MAXN];//�¼����緢�� 
int vl[MAXN];//�¼������� 
int stack[MAXN];//ջ 
int st[MAXN];
int tp;//����ջ�� 
int top;
//ȡ�������ֵ 
int max(int x, int y)
{
	if( x > y) return x;
	else return y;
}
//ȡ������Сֵ 
int min(int x, int y)
{
	if(x < y)
		return x;
	else return y;
}
//Init(&g):��ʼ������ͼ
void Init(Graph   * & g)
{
	int i;
	//g->n������ͼ�Ķ��������g->e������ͼ�ı�����g->adjlist�Ǵ������ͼ�Ķ�����ڽӵ��ָ������顣
	g->n = 0;
	g->e = 0;
	for(i = 0; i < MAXN; i++)
	{
		g->adjlist[i].firstarc = null;
		g->adjlist [i].count = 0;
	}//g->n,g->e��ֵΪ�㣬�����е�ÿһ�е�ָ���򶼸�ֵΪ�ա�
}
//�ж��Ƿ�Ϊ�� 
bool Empty(Graph * g)
{
	if( g->n == 0 && g->e == 0 )
		return true;
	else
		return false;
}

//Ѱ�ҽ�������ӱ��е�λ�� 
int Find(Graph * g,Vertex v)
{
	if(Empty(g))
	{
		cout << "ͼΪ��." << endl;
		return -1;//ͼΪ�շ���-1 
	}
	int i;
	for(i = 0; i < g->n; i++)
		if(g->adjlist[i].data == v)
			return i;//�����ִ������������е�λ�� 
	return -1;//�Ҳ����򷵻�-1 
}

//Creat(&g):����������Ϣ��������ͼ
void Create(Graph * & g)//g�ǳ�ʼ�����ͼ��
{
	int i, i1, i2;
	Vertex v1, v2;//���v1 v2 
	InfroType w;//Ȩֵ 
	cout << "�����붥�����ͱ���(���� ����): " << endl;
	cin >> g->n >> g->e;
	cout << "�����붥�㣨�м��á����������" << endl;
	for(i = 0; i < g->n; i++)
		cin >> g->adjlist[i].data ;
	ArcNode * p;//��ʼ���߱� 
	p = null;
	cout << "�ߺ�Ȩֵ:������  ����  Ȩֵ�� " << endl;
	for(i = 1; i <= g->e; i++)
	{
		cin >> v1 >> v2 >> w ;
		i1 = Find(g, v1);//����v1��g�е�λ�ò���i1���� 
		i2 = Find(g, v2);//����v2��g�е�λ�ò���i2���� 
		if( i1 != -1 && i2 != -1)//v1�� v2���� 
		{
			p = new ArcNode;
			p->adjvex = i2;//p�Ķ�����i2 
			p->Infro = w;//p��Ȩֵ 
			p->flag = false;//��λ�ò�Ϊ�� 
			p->nextarc = g->adjlist[i1].firstarc ;//p����һ�����ʱv1��ͷ��� 
			g->adjlist [i1].firstarc = p;//�γ����� 
		}//�����������Ϣ�������ڽӱ�洢������ͼ��
	}
}
// ���մ洢�ṹ���
void Output(Graph *g)
{
	if(Empty(g))//�п� 
	{
		cout << "ͼΪ��." << endl;
		return;
	}
	int i;
	cout << "�����ڽӱ����Ϊ: " << endl;
	for( i = 0;  i < g->n; i++)
	{
		cout << g->adjlist [i].data;//����ڵ����� 
		ArcNode * p;
		p = g->adjlist [i].firstarc ;//�����Ԫ�ڵ� 
		while(p)
		{
			cout << " ---> " << "(" << g->adjlist[p->adjvex ].data << "," << p->Infro << ")" ;//�ڵ�����+Ȩֵ 
			p = p->nextarc ;//������������ڵ㣬ֱ����Ϊֹ 
		}
		cout << endl;
	}
	
}
//������� 
void Du(Graph * g)/*��ͼ�и�������Ķ�*/
{
	if(Empty(g))
	{
		cout << "ͼΪ��." << endl;
		return;//�п� 
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
		cout << "����" << g->adjlist[v].data  << "�ĳ���Ϊ: " << k <<endl;//��������Ϊ��β��������� 
	}
}
//������ 
void Rdu(Graph *g, int f)
{
	if(Empty(g))
	{
		cout << "����ͼΪ��." << endl;
		return;
	}
	int i;
	ArcNode * p;
	for(i = 0; i <= g->n; i++)
		g->adjlist [i].count = 0;//�ж���� 
	for(i = 0; i < g->n; i++)
	{
		p = g->adjlist [i].firstarc ;
		while(p)
		{
			g->adjlist [p->adjvex].count ++;//����ڣ���count++ 
			p = p->nextarc ;//Ѱ����һ���� 
		}
	}
	if(f == 0)
	{
	for(i = 0; i < g->n; i++)
		cout << g->adjlist [i].data << "�����Ϊ: " << g->adjlist [i].count << endl;//��������Ϊ��ͷ���������
	}
}
//������������ķ������¼�����������ʱ������ʱ�䣬��ȷ�����·�������Ľ��
bool Topsort(Graph * g, int &infro, int & v)
{
	int stack[MAXN];//��������ջ ���������Ϊ0�ĵ�ѹ��ջ 
    int st[MAXN];//����������ս�� 
    int tp;//������������λ��ջ�� 
    int top;
	memset(ve, 0, sizeof(int) * MAXN);//��ʼ��veջ 
	Rdu(g, 1);
	top = -1;//��ʼ��ջ��Ԫ�� 
	tp = -1;
	int i, m, n;
	ArcNode * p;//�߱�ṹ��ָ�� 
	p = null;//��ʼ��ArcNode 
	infro = 0;//��ʼ��infro 
	for(i = 0; i < g->n; i++)//ѭ�������������Ϊ0�Ľ�㣬������� 
		if(g->adjlist [i].count == 0)
		{
			if(g->adjlist [i].firstarc  && infro < g->adjlist [i].firstarc ->Infro )
			{
				infro = g->adjlist [i].firstarc ->Infro ;//�����Ϊ0ʱ����g�е�Ȩֵ����infro 
			}
		}
	m = v;
	//�ж�һ�������Ƿ���� 
	for(i = 0; i < g->n; i++)
		if(!g->adjlist [i].firstarc)
		{
			if( v == m)
				v = i;
			else//����ʱ�䲻��ȣ�������¼���Ψһ 
			{
				cout << "�����¼���Ψһ." << endl;
				return false;// 
			}	
		}
		
	if(infro == -1)//û�����Ϊ0�ĵ� 
	{
		cout << "û���ҵ���ʼ�¼�. " << endl;
		return false;
	}
	if(v == -1)
	{
		cout << "û���ҵ������¼�." << endl;
		return false;
	}
	
	for(i = 0; i <= g->n; i++)
		vl[i] = INT_MAX;//��ʼ��vl����ٷ���ʱ�� 
	for(i = 0; i < g->n; i++)
		if(g->adjlist [i].count  == 0)
			stack[++top] = i;//�������ݱ�����Ϊ0�Ľ��ѹ��stack��stackջ++ 
	while( top + 1 )//����ջ��Ϊ��ʱ 
	{
	    m = stack[top--];//��stack��ջ��ֵ��m 
		g->adjlist [m].count = -1;
		st[++tp] = m;//����������Ľ��m����st������ 
		p = g->adjlist [m].firstarc ;
		while(p)
		{
			n = p->adjvex ;
			if(g->adjlist [n].count == -1)
			{
				cout << "������ͼ�л�." << endl;
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
		cout << "�������򲻳ɹ�." << endl;
		return false;
	}
	else
		cout << "��������ɹ�." << endl;
	vl[tp] = ve[tp];//��vl=ve֤��ʱ���ؼ�� 
	tp--;
	while(tp + 1)//��tp��Ϊ�� 
	{
		p = g->adjlist [st[tp]].firstarc ;
		while(p)//��p��Ϊ��ʱ 
		{//�� vl[st[tp]], vl[p->adjvex ] - p->Infro��С�߸�ֵ�� vl[st[tp]]
			vl[st[tp]] = min(vl[st[tp]], vl[p->adjvex ] - p->Infro );
			p = p->nextarc ;//ѭ��Ѱ����һ��ֵ 
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
//����ͼ�Ķ���ͻ� 
void Print(Graph * g)
{
	if(Empty(g))
	{
		cout << "����ͼΪ��." << endl;
		return; 
	}
	int i;
	cout << "����ͼ�Ķ���Ϊ: " << endl;
	for(i = 0; i < g->n; i++)
	{
		cout << g->adjlist [i].data << " " ;//������� 
	}
	cout << endl;
	cout << "��: " << endl;
	for(i = 0; i < g->n; i++)
	{
		ArcNode *p;
		p = g->adjlist[i].firstarc;
		while(p)
		{
			cout << g->adjlist[i].data << " " << g->adjlist [p->adjvex].data << " " << p->Infro << endl;
			p = p->nextarc;//����� 
		}
	}
}
//�����ؼ�·��������� 
void Path(Graph * g,int u, int v,int path[], int d)
{
	int j, i;
	ArcNode * p;
	p = null;
	visited[u] = 1;
	d++;
	path[d] = u;
	p = g->adjlist [u].firstarc ;// 
	if(u == v) //������翪ʼʱ�������ʱ����ͬ 
	{
		cout << "�ؼ�·��: ";
		cout << g->adjlist [path[0]].data; 
		for(i = 1; i <= d; i++)
			cout << "--->" << g->adjlist [path[i]].data;//����ؼ�·�� 
		cout << "   �ܹ���: " << ve[v] << endl;//����ܹ��� 
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
//�����ؼ�·��
void CriticPath(Graph * g)
{
	if(Empty(g))
	{
		cout << "ͼΪ��." << endl;
		return;
	}
	int infro, v, i;
	infro = -1;
	v = -1;
	//�жϹؼ�·���Ƿ���� 
	if(Topsort(g, infro, v) == false || infro == -1 || v == -1)
	{
		return ;
	}
	Rdu(g, 1);
	for(i = 0; i < g->n; i++)
		if(g->adjlist [i].count == 0 && g->adjlist [i].firstarc && g->adjlist [i].firstarc ->Infro == infro)//���Ϊ0���� g->adjlist [i].firstarc ->Infro == infro
		{
			memset(visited, 0, sizeof(int) * MAXN);
			memset(st, 0, sizeof(int) * MAXN);
			Path(g, i, v, st, -1);
		}
}
//�˵��� 
void Menu()
{
	cout << "		  �ؼ�·��         " << endl;
	cout << "	  �½�������-------------------->1" << endl;
	cout << "	  ����ڽӱ�-------------------->2" << endl;
	cout << "	  ���������ĳ���-------------->3" << endl;
	cout << "	  �������������-------------->4" << endl;
    cout << "	  �������ͼ�Ķ���ͻ�---------->5" << endl;
    cout << "	  ����ؼ�·��------------------>6" << endl;
	cout << "	  �˳�-------------------------->0" << endl;
	cout << "������..." << endl;
}
//������ 
int main()
{
	Graph * g;
	g = new Graph;
	Init(g);//��ʼ���ڽӱ� 
	int choose;//����һ������choose����ѡ��˵�ѡ�� 
	while(1)
	{	
		Menu();//���ò˵����� 
		cin >> choose;//��׼������ 
		switch(choose)
		{
		case 1: Init(g); Create(g); break;// �½�������
		case 2:	Output(g); break;//�ڽӱ� 
		case 3: Du(g); break;//������ĳ��� 
		case 4: Rdu(g, 0); break;//���������� 
		case 5: Print(g); break;//����ͼ�Ķ���ͻ� 
		case 6: CriticPath(g); break;//�ؼ�·�� 
		default : return 0;
		}	
	}
}

