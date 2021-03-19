#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
void Dispath(Graph G,int A[][VERTEX_MAX], int path[][VERTEX_MAX]) {
	int i, j;
	for (i = 0; i < G.VertexNum; i++) {
		for (j = 0; j < G.VertexNum; j++) {
			if (A[i][j] == MAXVALUE) {
				if (i != j) {
					printf("从%d到%d没有路径\n", i + 1, j + 1);
				}
			}
			else {
				printf("从%d到%d的最短路径为：%d，路径站点为：", i + 1, j + 1, A[i][j]);
				printf("%d,", i + 1);
				Ppath(path, i, j);
				printf("%d\n", j + 1);
			}
		}
	}
}
void Floyd(Graph G) {
	int i, j, k;
	int A[VERTEX_MAX][VERTEX_MAX], path[VERTEX_MAX][VERTEX_MAX];
	for (i = 0; i < G.VertexNum; i++) {                     //创建原始的邻接矩阵
		for (j = 0; j < G.VertexNum; j++) {
			A[i][j] = G.Edges[i][j];
			path[i][j] = -1;
		}
	}
	for (k = 0; k < G.VertexNum; k++) {                      //依次插入所有值
		for (i = 0; i < G.VertexNum; i++) {                     
			for (j = 0; j < G.VertexNum; j++) {              //插入第一个值
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	Dispath(G, A, path);
}
void Ppath(int path[][VERTEX_MAX], int i, int j) { //判断i,j之间是否有其他点
	int k;
	k = path[i][j];
	if (k == -1) {                 
		return;
	}
	Ppath(path, i, k);  
	printf("%d,", k + 1);
	Ppath(path, k, j);
}
int main(void){
	Graph G;
	int i, j;
	printf("输入图的顶点和边数量：");
	scanf("%d %d", &G.VertexNum, &G.EdgeNum);
	for (i = 0; i < G.VertexNum; i++)
		for (j = 0; j < G.VertexNum; j++)
			G.Edges[i][j] = MAXVALUE;
	CreateGraph(&G);
	Floyd(G);
	system("pause");
}