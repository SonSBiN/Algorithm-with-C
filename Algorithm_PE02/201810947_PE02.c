#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

static int count = 0;
void count_arr(int n, int c, int r) {
	//1. degenerate case
	if (n < 2) {
		if (r == 0 && c == 0);
		else if (r == 0 && c == 1)
			count += 1;
		else if (r == 1 && c == 0)
			count += 2;
		else if (r == 1 && c == 1)
			count += 3;
		printf("count = %d\n", count);
		return;
	}
	//2. divide % conquer
	//    r <= n, c <= n 1번째 케이스
	if (c <= n && r <= n) {
		count_arr(n - 1, c, r);
	}
	//    r <= n, c > n 2번째 케이스
	else if (c <= n && r > n) {
		count += (int)pow((double)4, (double)(n - 1));
		count_arr(n - 1, c, r - (int)pow((double)2, (double)(n - 1)));
	}
	//    r > n, c <= n 3번째 케이스
	else if (c > n && r <= n) {
		count += 2 * (int)pow((double)4, (double)(n - 1));
		count_arr(n - 1, c- (int)pow((double)2, (double)(n - 1)), r);
	}
	//    r > n, c > n 4번째 케이스
	else if (c > n && r > n) {
		count += 3 * (int)pow((double)4, (double)(n - 1));
		count_arr(n - 1, c - (int)pow((double)2, (double)(n - 1)), r - (int)pow((double)2, (double)(n - 1)));
	}
	return;
}
int main(void)
{
	int n;
	int r;
	int c;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		return 0;
	}
	fscanf(fp, "%d %d %d", &n, &r, &c);
	fclose(fp);
	if (1 <= n <= 15 && 0 <= r <= (int)pow((double)2, (double)n) && 0 <= c <= (int)pow((double)2, (double)n)) {
		count_arr(n, r, c);
	}
	else 
		printf("범위 오류.");
	return 0;
}