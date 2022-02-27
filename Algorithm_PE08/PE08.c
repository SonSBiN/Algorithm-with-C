#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_SIZE 1001
int graph[MAX_SIZE][MAX_SIZE];
int dfs_visit[MAX_SIZE];
int bfs_visit[MAX_SIZE];
int queue[MAX_SIZE];

void dfs(int v, int vertex) {
	int w;
	dfs_visit[v] = 1;
	printf("%d ", v);
	for (w = 1; w <= vertex; w++) {
		if (graph[v][w] == 1 && dfs_visit[w] == 0) {
			dfs(w, vertex);
		}
	}
}

void bfs(int v, int vertex) {
	int w;
	int front;
	int rear;
	int pop;
	front = rear = 0;
	printf("%d ", v);
	bfs_visit[v] = 1;
	queue[0] = v; 
	rear++;
	while (front < rear) {
		pop = queue[front]; 
		front++;
		for (w = 1; w <= vertex; w++) {
			if (graph[pop][w] == 1 && bfs_visit[w] == 0) {
				printf("%d ", w);
				queue[rear] = w; 
				rear++;
				bfs_visit[w] = 1;
			}
		}
	}
}

int main(void) {
	FILE* fp = fopen("data_08.txt", "r");
	int vertex;
	int edge;
	int first_num;
	int i;
	int j;
	fscanf(fp,"%d %d %d\n", &vertex, &edge, &first_num); // 정상적으로 입력됨
	if (vertex > 1001 || vertex < 1 || edge > 10001 || edge < 1) {
		printf("범위 오류");
		return 0;
	}
	for (int k = 0; k < MAX_SIZE + 1; k++) { // 배열 초기화
		for (int m = 0; m < MAX_SIZE + 1; m++) {
			graph[k][m] = 0;
		}
		dfs_visit[k] = 0;
		bfs_visit[k] = 0;
	}

	while (edge-- > 0) {
		fscanf(fp, "%d %d\n", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}
	dfs(first_num, vertex);
	putchar('\n');
	bfs(first_num, vertex);
	putchar('\n');

	fclose(fp);
	return 0;
}