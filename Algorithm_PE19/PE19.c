#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_SIZE 10001
#define Max(a,b) (a > b)?a:b

int price[MAX_SIZE];
int dp[MAX_SIZE];

void buy(int n) {
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = Max(dp[i], dp[i - j] + price[j]);
		}
	}
	printf("%d\n", dp[n]);
}

int main(void) {
	int n;
	FILE* fp = fopen("data_19.txt", "r");
	fscanf(fp, "%d\n", &n);
	if (n < 1 || n > 1000) {
		printf("카드의 갯수 범위 오류");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d ", &price[i]);
		if (price[i] < 1 || price[i] > 10000) {
			printf("카드팩의 가격 범위 오류");
			return 0;
		}
	}
	buy(n);
	
	fclose(fp);
	return 0;
}