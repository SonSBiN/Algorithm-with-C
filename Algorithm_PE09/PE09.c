#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count = 0;

void connect_island(int my_array[50][50], int visit[50][50], int j, int i) {

	visit[j][i] = 1;

	if (my_array[j - 1][i - 1] == 1 && visit[j - 1][i - 1] == 0) { // 왼쪽 위
		connect_island(my_array, visit, j - 1, i - 1);
	}
	if (my_array[j - 1][i] == 1 && visit[j - 1][i] == 0) { // 위
		connect_island(my_array, visit, j - 1, i);
	}
	if (my_array[j - 1][i + 1] == 1 && visit[j - 1][i + 1] == 0) { // 오른쪽 위
		connect_island(my_array, visit, j - 1, i + 1);
	}
	if (my_array[j][i - 1] == 1 && visit[j][i - 1] == 0) { // 왼쪽
		connect_island(my_array, visit, j, i - 1);
	}
	if (my_array[j][i + 1] == 1 && visit[j][i + 1] == 0) { // 오른쪽
		connect_island(my_array, visit, j, i + 1);
	}
	if (my_array[j + 1][i - 1] == 1 && visit[j + 1][i - 1] == 0) { // 왼쪽 아래
		connect_island(my_array, visit, j + 1, i - 1);
	}
	if (my_array[j + 1][i] == 1 && visit[j + 1][i] == 0) { // 아래
		connect_island(my_array, visit, j + 1, i);
	}
	if (my_array[j + 1][i + 1] == 1 && visit[j + 1][i + 1] == 0) { // 오른쪽 아래
		connect_island(my_array, visit, j + 1, i + 1);
	}
	return;
}

void Find_island(int my_array[50][50], int visit[50][50], int m, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {

			if (my_array[j][i] == 1 && visit[j][i] == 0) {
				count++;
				visit[j][i] = 1;
				if (my_array[j - 1][i - 1] == 1 && visit[j - 1][i - 1] == 0) { // 왼쪽 위
					connect_island(my_array, visit, j - 1, i - 1);
				}
				if (my_array[j - 1][i] == 1 && visit[j - 1][i] == 0) { // 위
					connect_island(my_array, visit, j - 1, i);
				}
				if (my_array[j - 1][i + 1] == 1 && visit[j - 1][i + 1] == 0) { // 오른쪽 위
					connect_island(my_array, visit, j - 1, i + 1);
				}
				if (my_array[j][i - 1] == 1 && visit[j][i - 1] == 0) { // 왼쪽
					connect_island(my_array, visit, j, i - 1);
				}
				if (my_array[j][i + 1] == 1 && visit[j][i + 1] == 0) { // 오른쪽
					connect_island(my_array, visit, j, i + 1);
				}
				if (my_array[j + 1][i - 1] == 1 && visit[j + 1][i - 1] == 0) { // 왼쪽아래
					connect_island(my_array, visit, j + 1, i - 1);
				}
				if (my_array[j + 1][i] == 1 && visit[j + 1][i] == 0) { // 아래
					connect_island(my_array, visit, j + 1, i);
				}
				if (my_array[j + 1][i + 1] == 1 && visit[j + 1][i + 1] == 0) { // 오른쪽 아래
					connect_island(my_array, visit, j + 1, i + 1);
				}
			}
		}
	}
}

int main(void) {
	FILE* fp = fopen("data_09.txt", "r");
	int m, n;
	int c = 1;
	fscanf(fp, "%d %d\n", &m, &n);
	while (m != 0 || n != 0) {
		if (m == 0 && n == 0) {
			return 0;
		}
		int size = m*n;
		if (m > 50 || n > 50 || m < 0 || n < 0) {
			printf("지도 범위 오류");
			return 0;
		}
		c++;
		int my_array[50][50];
		int visit[50][50];

		for (int j = 0; j < 50; j++) {
			for (int i = 0; i < 50; i++) {
				my_array[j][i] = 0;
				visit[j][i] = 0;
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				my_array[j][i] = fgetc(fp) - 48;
				fgetc(fp);
			}
		}
		Find_island(my_array, visit, m, n);

		printf("%d\n", count);
		fscanf(fp, "%d %d\n", &m, &n);
		count = 0;

	}
	fclose(fp);

	return 0;
}