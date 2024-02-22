#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define jida  32768     // ���弫��ֵ����������� 
typedef struct Vertex
{
	int num;  //������ 
	char name[5000];  //�������� 
	char jianjie[15000];   //������ 
}Vertex;    //�ṹ�嶨�嶥�� 

typedef struct Graph
{
	Vertex vexs[11];   //ͼ����ʮ������ 
	int arc[20][20];   //ͼ�������Ļ���Ȩֵ��Ҳ��·�� 
	int vnum, e;    // ͼ�ж�������ͱ��� 
}Graph;  //�ṹ�嶨��ͼ 

Graph* CreateGraph()   //  ��ʼ��ͼ 
{
	Graph* G;
	int i, j, k;
	G = (Graph*)malloc(sizeof(Graph));  //�����ڴ� 
	G->e = 18;   //  ͼ��18���� 
	G->vnum = 10;   //   ͼ��ʮ������ 
	for (i = 1; i <= G->vnum; i++)
		G->vexs[i].num = i;    //��ʼ��������Ϊ1-10 
	for (j = 1; j <= 10; j++)
		for (k = 1; k <= 10; k++)
		{
			G->arc[j][k] = jida;  // ��ʼ��ÿ�������ľ���Ϊ����ֵ 
		}

	G->arc[1][2] = G->arc[2][1] = 450;    //���ڽӾ���洢������Ȩֵ�����θ�ֵ�洢 
	G->arc[1][5] = G->arc[5][1] = 600;    // δ�ڴ˸�ֵ�Ļ�����ȨֵΪ֮ǰ��ʼ���ļ���ֵ 
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

	strcpy_s(G->vexs[1].name, "УҽԺ");   //�洢ͼ��ÿ��������֣����θ�ֵ�洢
	strcpy_s(G->vexs[2].name, "��ɽ�ٳ�");
	strcpy_s(G->vexs[3].name, "�����ѧԺ");
	strcpy_s(G->vexs[4].name, "ҽѧԺ");
	strcpy_s(G->vexs[5].name, "ͼ���");
	strcpy_s(G->vexs[6].name, "��ɽ�ٳ�");
	strcpy_s(G->vexs[7].name, "C��");
	strcpy_s(G->vexs[8].name, "G��");
	strcpy_s(G->vexs[9].name, "��ɽ¥");
	strcpy_s(G->vexs[10].name, "����¥");
	strcpy_s(G->vexs[1].jianjie, "УҽԺ������С��С�������շѲ���");    //Ϊͼ��ÿ������洢�������ļ�� 
	strcpy_s(G->vexs[2].jianjie, "��ɽ�ٳ�������ʥ��");
	strcpy_s(G->vexs[3].jianjie, "�����ѧԺ�߱��๦�ܻ�������ϰ�ҵ�����");
	strcpy_s(G->vexs[4].jianjie, "ҽѧԺ������ҽѧ��");
	strcpy_s(G->vexs[5].jianjie, "ͼ����ڲ���ܶ࣬���ǿ�����˲��࣬��������ʱ��");
	strcpy_s(G->vexs[6].jianjie, "��ɽ�ٳ����˶���ٰ�ĵط�");
	strcpy_s(G->vexs[7].jianjie, "C���Ǻ��ϵ�������");
	strcpy_s(G->vexs[8].jianjie, "G���Ǻ��µ�������");
	strcpy_s(G->vexs[9].jianjie, "��ɽ¥��Ҫ�ϵ������Ŀγ�");
	strcpy_s(G->vexs[10].jianjie, "����¥�ķ�ܴ���ĺܴ�");
	return G;
}

Graph* short_path_floyd(Graph* G, int p[20][20], int d[20][20])
{
	int v, w, k; // v,w,k�ֱ��ʾ�����㣬Ŀ�ĵأ��¼���ĵ� 
	for (v = 1; v <= G->vnum; v++) {
		for (w = 1; w <= G->vnum; w++)
		{
			d[v][w] = G->arc[v][w]; // d[20][20]������������·������ʼ��Ϊ�����Ȩֵ 
			p[v][w] = w;            //  p[20][20]��¼���·����ǰһ���� 
		}
	}
	for (k = 1; k <= 10; k++) //��������ѭ�����ҳ�ÿ����������·�� 
	{
		for (v = 1; v <= 10; v++)
		{
			for (w = 1; w <= 10; w++)
			{
				if (d[v][w] > (d[v][k] + d[k][w]))
				{
					d[v][w] = d[v][k] + d[k][w];
					p[v][w] = p[v][k];
					/* ����¼���ĵ���ɵ�·��С����С·��,������С·����
					���ҽ��¼���ĵ�������·���� */
				}
			}
		}
	}
	return G;  // ����ͼ������ 
}

void print()   //  ���溯�� 
{
	printf("\n\n\n");
	printf("\t****************************************\t\n");
	printf("\t*      ���մ�ѧУ԰����ϵͳ        *\t\n");
	printf("\t****************************************\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      1.������Ϣ��ѯ                  *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      2.·����Ϣ��ѯ                  *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t*      3.�˳�ϵͳ                      *\t\n");
	printf("\t*                                      *\t\n");
	printf("\t****************************************\t\n");
	printf("\n\n��ѡ������Ҫ�Ĺ��ܣ�������ţ�\n");
}

int main()
{
	int c, i, f, k, l;  // f,k�ֱ�Ϊ��������Ŀ�ĵر�� 
	Graph* T;
	int q, w;
	int d[20][20];  // d[20][20]������������·��
	int p[20][20];  //  p[20][20]��¼���·����ǰһ���� 
	system("color F");  //  �ı����������ɫ 
	for (q = 1; q <= 10; q++)
		for (w = 1; w <= 10; w++)
		{
			d[q][w] = jida;    //  ������������·����ʼ��Ϊ����ֵ 
		}
	T = CreateGraph();   //  ���ú�����ʼ��ͼ 
	T = short_path_floyd(T, p, d);  //���ú��������·�� 

	while (1)
	{
		print();     //  ��������� 
		scanf_s("%d", &c);  //����ѡ�� 
		while (c > 3 || c < 1)
		{
			printf("�����������������:\n");
			scanf_s("%d", &c);
		}
		if (c == 1)
		{
			printf("\n���մ�ѧ��������ʮ�����㣺\n");
			for (i = 1; i <= 10; i++)
			{
				printf("%d.", T->vexs[i].num);   //��������� 
				printf("%s: ", T->vexs[i].name);   //����������� 
				printf("%s\n\n", T->vexs[i].jianjie);  // ��������� 
			}
		}
		else if (c == 2)
		{
			printf("�����뵱ǰ�����ź�����Ҫȥ�ľ�����(�ո����):\n");
			scanf_s("%d %d", &f, &k);   // f,k�ֱ���ܳ�������Ŀ�ĵر�� 
			while (f < 1 || f>10 || k < 1 || k>10)  //�Ƿ����� 
			{
				printf("�����������������:\n");
				scanf_s("%d %d", &f, &k);
			}
			if (f == k)  //�Ƿ����� 
			{
				printf("����������Ѿ��ڴ˵�,����������:\n");
				scanf_s("%d %d", &f, &k);
			}

			printf("\n%s->%s����С·��Ϊ��%d��\n", T->vexs[f].name, T->vexs[k].name, d[f][k]);
			l = p[f][k];  // l��Ϊ�м���������������·���еĸ��׽ڵ� 
			printf("���·��Ϊ:   %s", T->vexs[f].name);   // ������·�� 
			while (l != k)
			{
				printf("-> %s", T->vexs[l].name);
				l = p[l][k];  //  ���ϸ���l�ڵ� 
			}
			printf("-> %s\n", T->vexs[k].name);

		}
		else
			break;  //�˳����� 
	}

}
