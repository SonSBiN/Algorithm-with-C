#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void my_swap(int my_array[9],int n, int m,int a, int b ) {
	if (b == 0) {
		for (int i = 1; i <= m; i++) {
			printf("%d ", my_array[i]);
		}
		printf("\n");
		return;
	}
	int new_array[9];
	for (int i = 1; i <= n; i++) { // 새로운 배열에 값 넣는다.
		new_array[i] = my_array[i];
	}
	for (int i = a; i <= n; i++) {
		if ((i - a) == 0) {
			my_swap(new_array, n, m, a + 1, b - 1);
		}
		else {
			int temp = new_array[a];
			new_array[a] = new_array[i];
			new_array[i] = temp;
			my_swap(new_array, n, m, a + 1, b - 1);
		}
	}
}
int main(void) {
	FILE* fp = fopen("data_07.txt", "r");
	int m, n;
	int my_array[9];
	fscanf(fp,"%d %d\n", &n, &m);
	printf("n = %d, m = %d\n", n, m); // n, m 정상 입력
	for (int i = 1; i <= n; i++) {
		my_array[i] = i;
	}
	my_swap(my_array, n, m, 1, m);


	fclose(fp);
	return 0;
}