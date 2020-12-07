#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 50 //叶子结点数目的最大数
#define M 2*N-1 //树中结点总数。（2倍叶子结点-1）


typedef struct{
	char data[1024];//结点名称 
	int weight;//权重 
	int parent;//双亲
	int lchild;//左孩子
	int rchild;//右孩子
}HTNode;//定义哈夫曼树存储结构

typedef char **HuffmanCode;//定义哈夫曼编码存储结构 

//构造具有n个结点的哈夫曼树
void CreateHT(HTNode ht[], int n){
	char *str[] = { "A", "B", "C", "D", "E", "F", "G", "H" };//待编码字符，这是一个字符串数组
	int fnum[] = { 5, 29, 7, 8, 14, 23, 3, 11 };//待编码字符出现的频率
	int i, k;
	int lnode, rnode;
	int min1, min2;
	//TODO：此处为方便调试将数值固定，后续可用scanf语句进行修改
	for (i = 0; i<n; i++){
		//用待编码字符以及频率初始化ht[]数组
		strcpy(ht[i].data, str[i]);//strcpy将str[]复制到ht[]中 
		ht[i].weight = fnum[i];//把fnum中的值放入ht[].weight
	}

	for (i = 0; i<2 * n - 1; i++){
		//n个叶子结点，总共2n-1个结点 
		//ht[]数组中所有结点的相关域初值设置为-1 
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}

	for (i = n; i<2 * n - 1; i++){
		min1 = 32767; min2 = 32767;//存放最小和次小权重值（short的最大值）
		lnode = -1; rnode = -1;//最小和次小权重的结点位置

		for (k = 0; k < i ; k++){//循环遍历寻找权值最小和次小的结点 
			if (ht[k].parent == -1){
				//根据parent是否等于-1来判断此结点是否已经跟另一结点结合成新结点。
				//那么循环结束后需要更新此轮所选出的最小和次小结点的parent值。 
				if (ht[k].weight<min1){//最小数放在左节点
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else{
					if (ht[k].weight<min2){//次小值放在右节点
						min2 = ht[k].weight;
						rnode = k;
					}
				}
			}
		}

		//设置双亲结点和权值 
		ht[rnode].parent = i;
		ht[lnode].parent = i;//最小和次小权重结点的双亲
		ht[i].weight = ht[rnode].weight + ht[lnode].weight;// 最小和次小权重结点双亲的权值

		//设置双亲结点的lchild和rchild。位序小的放在左子树上，位序大的放在右子树上 
		if (lnode>rnode){
			ht[i].lchild = lnode;
			ht[i].rchild = rnode;
		}
		else{
			ht[i].lchild = rnode;
			ht[i].rchild = lnode;
		}
	}
}

//构造哈夫曼编码hcd 
void CreateHCode(HTNode ht[], HuffmanCode hcd, int n){
	int i, f, c, temp;
	char *hc;//存放哈夫曼编码的工作数组

	//根据哈夫曼树求n个叶子的哈夫曼编码 
	for (i = 0; i<n; i++){
		hc = (char *)malloc(n*sizeof(char));//分配存放编码的工作区间 
		hc[n] = '\0';
		temp = n - 1;//temp指示编码字符在hc中首位置
		c = i;//c为被编码字符串位置
		f = ht[i].parent;//f为c的双亲位置
		while (f != -1){
			if (ht[f].lchild == c)
				hc[temp--] = '0';//左孩子的编码 
			else
				hc[temp--] = '1';//右孩子的编码 
			c = f;
			f = ht[f].parent;
		}
		hcd[i] = (char*)malloc((n - temp)*sizeof(char));//给第i个字符编码分配空间
		strcpy(hcd[i], hc + temp + 1);
	}
}

//输出哈夫曼编码 
void DispHCode(HTNode ht[], HuffmanCode hcd, int n){
	int i;
	int sum = 0, m = 0, j;
	printf("输出哈夫曼编码:\n");
	for (i = 0; i<n; i++){
		j = 0;
		printf("%s:\t", ht[i].data);
		while (hcd[i][j] != '\0'){
			printf("%c", hcd[i][j]);
			j++;
		}
		m += ht[i].weight;//计算码长，求路径长。
		sum += ht[i].weight*j;
		printf("\n");
	}
	printf("\n平均长度=%g\n", 1.0*sum / m);
}
//动态分配数组存储赫夫曼树, 设计一组输入数据（假定为一组整数），能够对其进行如下操作：
//编写主程序，实现对各不同的算法调用。
int main(){
	int n = 8;
	HTNode ht[M];
	HuffmanCode hcd;
	//创建一个新的顺序表，实现动态空间分配的初始化;
	hcd = (HuffmanCode)malloc((2 * n)*sizeof(char*));
	//对输入的数据构造成一棵Huffman 树；
	CreateHT(ht, n);
	//根据生成的Huffman 树进行Huffman 编码;
	CreateHCode(ht, hcd, n);
	//实现对输入数据的Huffman 编码输出;
	DispHCode(ht, hcd, n);
	printf("\n");
	system("pause");
	return 0;
}
