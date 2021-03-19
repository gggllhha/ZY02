#ifndef GRAPH_H
#define GRAPH_H
#define VERTEX_MAX 50
#define MAXVALUE 32767
typedef struct {
	char Vertex[VERTEX_MAX];
	int Edges[VERTEX_MAX][VERTEX_MAX];
	int VertexNum;
	int EdgeNum;
}Graph;
void Dispath(Graph G,int A[][VERTEX_MAX],int path[][VERTEX_MAX]);
void Floyd(Graph G);
void CreateGraph(Graph* G);
void Ppath(int path[][VERTEX_MAX], int i, int j);
#endif // !GRAPH_H

