#include"Graph.h"
#include<stdio.h>
#include"Graph.h"
void CreateGraph(Graph* G) {
	int i, j, k, weight;
	char start, end;
	printf("�����������Ϣ:\n");
	for (i = 0; i < G->VertexNum; i++) {
		getchar();
		printf("��%d�����㣺", i + 1);
		scanf("%c", &(G->Vertex[i]));
	}
	printf("���빹�ɸ��ߵ��������㼰Ȩֵ��\n");
	for (k = 0; k < G->EdgeNum; k++) {
		getchar();
		printf("��%d����:", k + 1);
		scanf("%c %c %d", &start, &end, &weight);
		for (i = 0; start != G->Vertex[i]; i++);
		for (j = 0; end != G->Vertex[j]; j++);
		G->Edges[i][j] = weight;
	}
}
