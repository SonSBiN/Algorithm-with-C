#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_NUM 1001

int main(void) {
	int n;
	int arr[MAX_NUM];
	int temp;
	int sum = 0;
	int sum2 = 0;
	FILE* fp = fopen("data_14.txt", "r");
	fscanf(fp, "%d\n", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d ", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n-i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	}
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
		sum2 += sum;
	}
	printf("%d\n", sum2);
	
	fclose(fp);
	return 0;
}