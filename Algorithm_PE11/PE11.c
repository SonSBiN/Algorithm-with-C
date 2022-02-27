#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_GRAPH 20001

int graph[MAX_GRAPH][MAX_GRAPH];
int visited[20001];
int dist[20001];
int vertex;
int edge;

int SmallDist()
{
	int min = 11;
	int index = 0;
	for (int i = 1; i <= vertex; ++i) {
		if (!visited[i] && dist[i] < min) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int start)
{
	for (int i = 1; i <= vertex; ++i)
		dist[i] = graph[start][i];
	dist[start] = 0;
	visited[start] = 1;
	for (int j = 1; j < vertex-1 ; ++j) {
		int current = SmallDist();
		visited[current] = 1;
		for (int j = 1; j <= vertex; ++j) {
			if (!visited[j])
				if (dist[j] >(graph[current][j] + dist[current])) {
					dist[j] = graph[current][j] + dist[current];
				}
		}
	}
}
int main(void) {
	int first_vertex;

	FILE* fp = fopen("data_11.txt", "r");
	fscanf(fp, "%d %d\n", &vertex, &edge);
	int a, b, c;

	if (vertex < 1 || vertex > 20000 || edge < 1 || edge > 300000) {
		printf("vertex의 갯수, 혹은 edge의 갯수 범위 초과");
		return 0;
	}

	fscanf(fp, "%d\n", &first_vertex);

	if (first_vertex > vertex || first_vertex < 1) {
		printf("시작 정점의 번호 범위 오류");
		return 0;
	}
	for (int i = 1; i <= vertex; ++i) {
		for (int j = 1; j <= vertex; ++j) {
			graph[i][j] = 11;
		}
	}
	for (int i = 0; i < edge; ++i) {
		fscanf(fp, "%d %d %d\n", &a, &b, &c);
		graph[a][b] = c;
	}

	Dijkstra(first_vertex);;
	for (int i = 1; i <= vertex; ++i) {
		if (dist[i] == 11)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	fclose(fp);

	return 0;
}