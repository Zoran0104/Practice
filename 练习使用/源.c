#include<stdio.h>
#define SIZE 20 
int column; 
int row;
void inputMatrix(int a[][SIZE], int n, int m) { 
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void outputMatrix(int b[][SIZE], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n"); 
	}
}

void matrixTransport(int a[][SIZE], int b[][SIZE]) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			b[i][j] = a[j][i];

		}
	}
}
int main()
{

	int a[SIZE][SIZE] = { 0 };
	int b[SIZE][SIZE] = { 0 };
	printf("请输入您要进行转置的矩阵的行数 : column =  ");
	scanf("%d", &column);
	printf("\n请输入您要进行转置的矩阵的列数 : row = ");
	scanf("%d", &row);
	printf("请输入一个 %d X %d 的矩阵 \n", column, row);
	inputMatrix(a, column, row);
	matrixTransport(a, b);
	printf("转置后的矩阵是 :\n");
	outputMatrix(b, row, column);
	getchar();
	return 0;
}