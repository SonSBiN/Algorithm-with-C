#include<stdio.h>

static blue = 0;
static white = 0;
void UpBlue(void) // blue의 색종이 갯수를 증가시키는 함수
{
	blue = blue + 1;
}

void UpWhite(void) { // white의 색종이 갯수를 증가시키는 함수
	white = white + 1;
}

void FindNumOfSquare(int x_min,int x_max, int y_min, int y_max, int arr[8][8]) // 정사각형을 찾는 함수
{
	int x1 = x_min;
	int x2 = x_max;
	int y1 = y_min;
	int y2 = y_max;
	int mid_x = (x_min + x_max) / 2;
	int mid_y = (y_min + y_max) / 2;

	if (x1 == x2 && x1 == x2) {
		if (arr[x1][y1] == 1) {
			UpBlue();
			return;
		}
		else {
			UpWhite();
			return;
		}
			
	}
	for (; y1 <= y2; y1++) {
		for (; x1 <= x2; x1++) {
			if (arr[x_min][y_min] != arr[x1][y1]) {
				FindNumOfSquare(x_min, mid_x, y_min, mid_y, arr);
				FindNumOfSquare(x_min, mid_x, mid_y + 1, y_max,arr);
				FindNumOfSquare(mid_x + 1, x_max, y_min, mid_y,arr);
				FindNumOfSquare(mid_x + 1, x_max, mid_y + 1, y_max, arr);
				return;
			}
		}
	}
	if (arr[x_min][y_min] == 1) {
		UpBlue();
		return;
	}
	else {
		UpWhite();
		return;
	}
}
int main(void) {
	int arr[8][8] = {
		{1,1,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1},
		{0,0,0,0,1,1,0,0},
		{0,0,0,0,1,1,0,0},
		{1,0,0,0,1,1,1,1},
		{0,1,0,0,1,1,1,1},
		{0,0,1,1,1,1,1,1},
		{0,0,1,1,1,1,1,1}};
	FindNumOfSquare(0,7,0,7,arr,8);


	printf("%d\n", white);
	printf("%d\n", blue);

	return 0;
}
