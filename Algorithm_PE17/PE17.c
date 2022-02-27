#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[1001];

int main(void) {
	int n;
	FILE* fp = fopen("data_17.txt", "r");
	fscanf(fp, "%d\n", &n);

	if (n < 1 || n > 1000) {
		printf("n의 범위 오류");
		return 0;
	}
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	printf("%d\n", arr[n]);

	fclose(fp);
	return 0;
}