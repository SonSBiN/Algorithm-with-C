#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n, k;
	int arr[10];
	int temp;
	FILE* fp = fopen("data_12.txt", "r");
	fscanf(fp, "%d %d\n", &n, &k);

	if (n < 0 || n > 11 || k < 0 || k > 100000000) {
		printf("n,k 범위 오류");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d\n", &temp);
		arr[i] = temp;
	}
	int count = 0;
	int idx = n - 1;
	while (k > 0) {
		if (k >= arr[idx]) {
			k -= arr[idx];
			count++;
		}
		else
			idx--;
	}
	printf("%d\n", count);
	fclose(fp);
	return 0;
}