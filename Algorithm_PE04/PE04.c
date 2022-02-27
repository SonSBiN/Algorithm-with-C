#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


extern int count = 0;
void Find_Virus(int matrix[101][101],int line,int visit[]) {
	for (int i = 1; i <= 100; i++) {
		if (line == i)
			i++;
		if (matrix[line][i] == 1) {
			if (visit[i] == 1) {
				continue;
			}
			visit[i] = 1;
			count++;
			Find_Virus(matrix, i, visit);
		}
	}
	return;
}

int main(void) {
	FILE* fp = fopen("data.txt", "r");
	int vertex;
	int edge;
	int visit[101];
	fscanf(fp, "%d\n%d\n", &vertex, &edge); // 범위 초과시 리턴
	printf("vertex = %d, edge = %d\n", vertex, edge);
	if (vertex > 100 || vertex < 0) {
		printf("컴퓨터의 수 범위 오류");
		return 0;
	}
	for (int i = 1; i < 101; i++) { // visit 초기화
		visit[i] = 0;
	}

	int graph_matrix[101][101]; // 배열 초기화
	for (int j = 0; j < 101; j++) {
		for (int i = 1; i < 101; i++) {
			graph_matrix[j][i] = 0;
		}
	}
	for (int i = 1; i <= edge; i++) {
		int a, b;
		fscanf(fp, "%d %d\n", &a, &b);
		graph_matrix[a][b] = 1;
	}
	visit[1] = 1;
	Find_Virus(graph_matrix,1,visit);

	/*for (int j = 1; j < 101; j++) {
		for (int i = 1; i < 101; i++) {
			if (graph_matrix[j][i] == 1) {
				printf("matrix[%d][%d] = %d\n", j, i, graph_matrix[j][i]);
			}
		}
	}*/
	printf("count = %d\n", count);
	fclose(fp);

	return 0;
}