#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define jida  32768     // 定义极大值，代表无穷大 
typedef struct Vertex
{
	int num;  //顶点编号 
	char name[5000];  //顶点名称 
	char jianjie[15000];   //顶点简介 
}Vertex;    //结构体定义顶点 

typedef struct Graph
{
	Vertex vexs[11];   //图中有十个顶点 
	int arc[20][20];   //图中两点间的弧线权值，也即路程 
	int vnum, e;    // 图中顶点个数和边数 
}Graph;  //结构体定义图 

Graph* CreateGraph()   //  初始化图 
{
	Graph* G;
	int i, j, k;
	G = (Graph*)malloc(sizeof(Graph));  //开辟内存 
	G->e = 18;   //  图有18条边 
	G->vnum = 10;   //   图有十个顶点 
	for (i = 1; i <= G->vnum; i++)
		G->vexs[i].num = i;    //初始化顶点编号为1-10 
	for (j = 1; j <= 10; j++)
		for (k = 1; k <= 10; k++)
		{
			G->arc[j][k] = jida;  // 初始化每两个点间的距离为极大值 
		}

	G->arc[1][2] = G->arc[2][1] = 450;    //用邻接矩阵存储两点间的权值，依次赋值存储 
	G->arc[1][5] = G->arc[5][1] = 600;    // 未在此赋值的弧，其权值为之前初始化的极大值 
	G->arc[1][4] = G->arc[4][1] = 650;
	G->arc[2][5] = G->arc[5][2] = 450;
	G->arc[2][3] = G->arc[3][2] = 800;
	G->arc[4][6] = G->arc[6][4] = 460;

	G->arc[4][5] = G->arc[5][4] = 404;
	G->arc[3][5] = G->arc[5][3] = 200;
	G->arc[3][7] = G->arc[7][3] = 100;
	G->arc[5][7] = G->arc[7][5] = 400;
	G->arc[7][8] = G->arc[8][7] = 100;
	G->arc[7][9] = G->arc[9][7] = 200;

	G->arc[8][9] = G->arc[9][8] = 300;
	G->arc[6][8] = G->arc[8][6] = 100;
	G->arc[5][8] = G->arc[8][5] = 100;
	G->arc[5][10] = G->arc[10][5] = 400;
	G->arc[6][10] = G->arc[10][6] = 500;
	G->arc[8][10] = G->arc[10][8] = 800;

	strcpy_s(G->vexs[1].name, "校医院");   //存储图中每个点的名字，依次赋值存储
	strcpy_s(G->vexs[2].name, "西山操场");
	strcpy_s(G->vexs[3].name, "计算机学院");
	strcpy_s(G->vexs[4].name, "医学院");
	strcpy_s(G->vexs[5].name, "图书馆");
	strcpy_s(G->vexs[6].name, "东山操场");
	strcpy_s(G->vexs[7].name, "C区");
	strcpy_s(G->vexs[8].name, "G区");
	strcpy_s(G->vexs[9].name, "三山楼");
	strcpy_s(G->vexs[10].name, "三江楼");
	strcpy_s(G->vexs[1].jianjie, "校医院可以治小伤小病，但收费不菲");    //为图中每个景点存储关于它的简介 
	strcpy_s(G->vexs[2].jianjie, "西山操场是乐跑圣地");
	strcpy_s(G->vexs[3].jianjie, "计算机学院具备多功能机房，自习室的作用");
	strcpy_s(G->vexs[4].jianjie, "医学院经常有医学生");
	strcpy_s(G->vexs[5].jianjie, "图书馆内藏书很多，但是看书的人不多，除非特殊时期");
	strcpy_s(G->vexs[6].jianjie, "东山操场是运动会举办的地方");
	strcpy_s(G->vexs[7].jianjie, "C区是很老的宿舍区");
	strcpy_s(G->vexs[8].jianjie, "G区是很新的宿舍区");
	strcpy_s(G->vexs[9].jianjie, "三山楼主要上的是人文课程");
	strcpy_s(G->vexs[10].jianjie, "三江楼的风很大，真的很大");
	return G;
}

Graph* short_path_floyd(Graph* G, int p[20][20], int d[20][20])
{
	int v, w, k; // v,w,k分别表示出发点，目的地，新加入的点 
	for (v = 1; v <= G->vnum; v++) {
		for (w = 1; w <= G->vnum; w++)
		{
			d[v][w] = G->arc[v][w]; // d[20][20]代表两点间最短路径，初始化为两点间权值 
			p[v][w] = w;            //  p[20][20]记录最短路径的前一个点 
		}
	}
	for (k = 1; k <= 10; k++) //利用三阶循环，找出每两个点的最短路径 
	{
		for (v = 1; v <= 10; v++)
		{
			for (w = 1; w <= 10; w++)
			{
				if (d[v][w] > (d[v][k] + d[k][w]))
				{
					d[v][w] = d[v][k] + d[k][w];
					p[v][w] = p[v][k];
					/* 如果新加入的点组成的路径小于最小路径,更新最小路径，
					并且将新加入的点加入最短路径中 */
				}
			}
		}
	}
	return G;  // 返回图的类型 
}

void print()   //  界面函数 
{
	printf("\n\n\n");
	printf("\t****************************************\t\n");
	printf("\t*      江苏大学校园导航系统        *\t\n");
	printf("\t****************************************\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      1.景点信息查询                  *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      2.路线信息查询                  *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      3.退出系统                      *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t****************************************\t\n");
	printf("\n\n请选择你需要的功能，输入代号：\n");
}

int main()
{
	int c, i, f, k, l;  // f,k分别为出发点与目的地编号 
	Graph* T;
	int q, w;
	int d[20][20];  // d[20][20]代表两点间最短路径
	int p[20][20];  //  p[20][20]记录最短路径的前一个点 
	system("color F");  //  改变输出界面颜色 
	for (q = 1; q <= 10; q++)
		for (w = 1; w <= 10; w++)
		{
			d[q][w] = jida;    //  任意两点间最短路径初始化为极大值 
		}
	T = CreateGraph();   //  调用函数初始化图 
	T = short_path_floyd(T, p, d);  //调用函数求最短路径 

	while (1)
	{
		print();     //  输出界面栏 
		scanf_s("%d", &c);  //接受选项 
		while (c > 3 || c < 1)
		{
			printf("输入错误，请重新输入:\n");
			scanf_s("%d", &c);
		}
		if (c == 1)
		{
			printf("\n江苏大学共有以下十处景点：\n");
			for (i = 1; i <= 10; i++)
			{
				printf("%d.", T->vexs[i].num);   //输出景点编号 
				printf("%s: ", T->vexs[i].name);   //输出景点名字 
				printf("%s\n\n", T->vexs[i].jianjie);  // 输出景点简介 
			}
		}
		else if (c == 2)
		{
			printf("请输入当前景点编号和你想要去的景点编号(空格隔开):\n");
			scanf_s("%d %d", &f, &k);   // f,k分别接受出发点与目的地编号 
			while (f < 1 || f>10 || k < 1 || k>10)  //非法输入 
			{
				printf("输入错误，请重新输入:\n");
				scanf_s("%d %d", &f, &k);
			}
			if (f == k)  //非法输入 
			{
				printf("输入错误，你已经在此地,请重新输入:\n");
				scanf_s("%d %d", &f, &k);
			}

			printf("\n%s->%s的最小路径为：%d米\n", T->vexs[f].name, T->vexs[k].name, d[f][k]);
			l = p[f][k];  // l作为中间变量用来接受最短路径中的父亲节点 
			printf("最短路径为:   %s", T->vexs[f].name);   // 输出最短路径 
			while (l != k)
			{
				printf("-> %s", T->vexs[l].name);
				l = p[l][k];  //  不断更新l节点 
			}
			printf("-> %s\n", T->vexs[k].name);

		}
		else
			break;  //退出程序 
	}

}
