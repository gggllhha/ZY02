#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
void Dijkstra(Graph G) {
	int weight[VERTEX_MAX];   //源点到各顶点的最短路径长度
	char path[VERTEX_MAX];    //源点到终点经过的顶点集合
	int tmpvertex[VERTEX_MAX]; //最短路径的终点集合
	int i, j, k, v0, min;
	printf("\n请输入源点编号：");
	scanf("%d", &v0);
	v0--;			//编号减一代表数组从0开始
	for (i = 0; i < G.VertexNum; i++) {     //初始化数组
		weight[i] = G.Edges[v0][i];
		if (weight[i] < MAXVALUE && weight[i]>0) {
			path[i] = v0;
		}
		tmpvertex[i] = 0;
	}
	tmpvertex[v0] = 1; //将起始点加入集合
	weight[v0] = 0;
	for (i = 0; i < G.VertexNum; i++) {   //将所有顶点遍历一次
		min = MAXVALUE;
		k = v0;
		for (j = 0; j < G.VertexNum; j++) {
			if (tmpvertex[j] == 0 && weight[j] < min) {
				min = weight[j];
				k = j;
			}
		}
		tmpvertex[k] = 1;
		for (j = 0; j < G.VertexNum; j++) {  //以K为中间顶点加入U集合
			if (tmpvertex[j] == 0 && weight[k] + G.Edges[k][j] < weight[j]) { //有更小的权值路径
				weight[j] = weight[k] + G.Edges[k][j];  //更新权值
				path[j] = k;
			}
		}
	}
	printf("\n从顶点%c到各顶点的最短路径为:(终点<源)\n", G.Vertex[v0]);
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
			printf("%c<-%c:无路径\n", G.Vertex[i], G.Vertex[v0]);
	}
}
int main(void){
	Graph G;
	int path[VERTEX_MAX];
	int i, j;
	printf("输入图的顶点和边数量：");
	scanf("%d %d", &G.VertexNum, &G.EdgeNum);
	for (i = 0; i < G.VertexNum; i++)
		for (j = 0; j < G.VertexNum; j++)
			G.Edges[i][j] = MAXVALUE;
	CreateGraph(&G);
	Dijkstra(G);
	system("pause");
}