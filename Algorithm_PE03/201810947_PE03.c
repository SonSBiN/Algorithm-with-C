#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int calculation(int A, int B, int C) {
	if (B == 1)
		return (A % C);
	else
		return ((calculation(A, B / 2, C) % C) *(calculation(A, B - B / 2, C) % C) % C);
}

int main(void)
{
	int A, B, C;

	FILE *fp = fopen("data.txt", "r");
	fscanf(fp, "%d %d %d", &A, &B, &C);
	fclose(fp);

	if (A > 2147483647 || B > 2147483647 || C > 2147483647) {
		printf("숫자 범위 초과");
		return 0;
	}
	else {
		printf("%d\n", calculation(A, B, C));
	}
	return 0;
}