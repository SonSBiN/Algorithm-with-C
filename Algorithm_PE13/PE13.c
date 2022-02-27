#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int pay;
	int arr[] = { 500, 100, 50, 10, 5, 1 };
	FILE* fp = fopen("data_13.txt", "r");
	fscanf(fp, "%d\n", &pay);
	int change = 1000 - pay;
	int count = 0;
	int idx = 0;
	while (change > 0) {
		if (change >= arr[idx]) {
			change -= arr[idx];
			count++;
		}
		else
			idx++;
	}
	printf("%d\n", count);

	fclose(fp);
	return 0;
}