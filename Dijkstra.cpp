#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
void Dijkstra(Graph G) {
	int weight[VERTEX_MAX];   //Դ�㵽����������·������
	char path[VERTEX_MAX];    //Դ�㵽�յ㾭���Ķ��㼯��
	int tmpvertex[VERTEX_MAX]; //���·�����յ㼯��
	int i, j, k, v0, min;
	printf("\n������Դ���ţ�");
	scanf("%d", &v0);
	v0--;			//��ż�һ���������0��ʼ
	for (i = 0; i < G.VertexNum; i++) {     //��ʼ������
		weight[i] = G.Edges[v0][i];
		if (weight[i] < MAXVALUE && weight[i]>0) {
			path[i] = v0;
		}
		tmpvertex[i] = 0;
	}
	tmpvertex[v0] = 1; //����ʼ����뼯��
	weight[v0] = 0;
	for (i = 0; i < G.VertexNum; i++) {   //�����ж������һ��
		min = MAXVALUE;
		k = v0;
		for (j = 0; j < G.VertexNum; j++) {
			if (tmpvertex[j] == 0 && weight[j] < min) {
				min = weight[j];
				k = j;
			}
		}
		tmpvertex[k] = 1;
		for (j = 0; j < G.VertexNum; j++) {  //��KΪ�м䶥�����U����
			if (tmpvertex[j] == 0 && weight[k] + G.Edges[k][j] < weight[j]) { //�и�С��Ȩֵ·��
				weight[j] = weight[k] + G.Edges[k][j];  //����Ȩֵ
				path[j] = k;
			}
		}
	}
	printf("\n�Ӷ���%c������������·��Ϊ:(�յ�<Դ)\n", G.Vertex[v0]);
	for (i = 0; i < G.VertexNum; i++) {
		if (tmpvertex[i] == 1) {
			k = i;
			while (k != v0) {
				j = k;
				printf("%c<", G.Vertex[k]);
				k = path[k];
			}
			printf("%c\n", G.Vertex[k]);
		}
		else
			printf("%c<-%c:��·��\n", G.Vertex[i], G.Vertex[v0]);
	}
}
int main(void){
	Graph G;
	int path[VERTEX_MAX];
	int i, j;
	printf("����ͼ�Ķ���ͱ�������");
	scanf("%d %d", &G.VertexNum, &G.EdgeNum);
	for (i = 0; i < G.VertexNum; i++)
		for (j = 0; j < G.VertexNum; j++)
			G.Edges[i][j] = MAXVALUE;
	CreateGraph(&G);
	Dijkstra(G);
	system("pause");
}