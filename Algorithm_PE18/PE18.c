#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_N 11

int main(void) {
	int n;
	int arr[MAX_N];
	FILE* fp = fopen("data_18.txt", "r");
	fscanf(fp, "%d\n", &n);

	for (int i = 0; i < n; i++) {
		fscanf(fp,"%d\n", &arr[i]);
		if (arr[i] <= 0 || arr[i] >= 11) {
			printf("n값 범위 오류");
			return 0;
		}
	}
	int recursive[12] = { 0 };
	recursive[1] = 1;
	recursive[2] = 2;
	recursive[3] = 4;
	for(int i = 4; i < 11; i++){
		recursive[i] = recursive[i - 1] + recursive[i - 2] + recursive[i - 3];
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", recursive[arr[i]]);
	}

	fclose(fp);
	return 0;
}