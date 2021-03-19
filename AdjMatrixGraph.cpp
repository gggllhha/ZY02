#include"Graph.h"
#include<stdio.h>
#include"Graph.h"
void CreateGraph(Graph* G) {
	int i, j, k, weight;
	char start, end;
	printf("输入各顶点信息:\n");
	for (i = 0; i < G->VertexNum; i++) {
		getchar();
		printf("第%d个顶点：", i + 1);
		scanf("%c", &(G->Vertex[i]));
	}
	printf("输入构成各边的两个顶点及权值：\n");
	for (k = 0; k < G->EdgeNum; k++) {
		getchar();
		printf("第%d条边:", k + 1);
		scanf("%c %c %d", &start, &end, &weight);
		for (i = 0; start != G->Vertex[i]; i++);
		for (j = 0; end != G->Vertex[j]; j++);
		G->Edges[i][j] = weight;
	}
}
