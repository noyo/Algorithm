#include<stdio.h>
#include<stdlib.h>

#define N 10

int square[N] = {0};
int n;
int edge[N][N][2] = {0};

int max(int a, int b) {
	return a > b ? a : b;
}

void init() {
	/*edge[1][1][0] = edge[1][1][1] = 1;
	edge[1][2][1] = 1;
	edge[1][3][0] = 1;
	edge[1][4][1] = 1;
	edge[2][1][0] = 1;
	edge[2][2][0] = edge[2][2][1] = 1;
	edge[2][3][0] = edge[2][3][1] = 1;
	edge[2][4][1] = 1;
	edge[3][2][0] = edge[3][2][1] = 1;
	edge[3][4][1] = 1;
	edge[4][2][0] = 1;
	edge[4][3][0] = 1;*/
	edge[1][1][0] = edge[1][1][1] = 1;
	edge[1][2][0] = edge[1][2][1] = 1;
	edge[1][3][0] = 1;
	edge[1][4][0] = edge[1][4][1] = 1;
					edge[1][5][1] = 1;

	edge[2][1][0] = edge[2][1][1] = 1;
	edge[2][2][0] = edge[2][2][1] = 1;
	edge[2][3][0] = edge[2][3][1] = 1;
	edge[2][4][0] = edge[2][4][1] = 1;
					edge[2][5][1] = 1;

					edge[3][1][1] = 1;
	edge[3][2][0] = edge[3][2][1] = 1;
					edge[3][3][1] = 1;
					edge[3][4][1] = 1;
					edge[3][5][1] = 1;

	edge[4][1][0] = edge[4][1][1] = 1;
	edge[4][2][0] = 1;
	edge[4][3][0] = edge[4][3][1] = 1;
					edge[4][4][1] = 1;
					edge[4][5][1] = 1;

	edge[5][1][0] = 1;
	edge[5][2][0] = 1;
	edge[5][3][0] = 1;
	edge[5][4][0] = 1;
}

void count() {
	int vh[2][2] = { 0 };
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int l = n - max(i, j);
			for (int k = 0; k < l; k++) {
				vh[0][0] = i + k; vh[0][1] = j;
				vh[1][0] = i; vh[1][1] = j + k;
				if (edge[vh[0][0]][vh[0][1]][1] == 1 && edge[vh[1][0]][vh[1][1]][0] == 1) {
					vh[0][0]++;
					vh[1][1]++;
					while (edge[vh[0][0]][vh[0][1]][0] == 1 && edge[vh[1][0]][vh[1][1]][1] == 1) {
						vh[0][1]++;
						vh[1][0]++;
						if (vh[0][1] == vh[1][1]) {
							square[k + 1]++;
							break;
						}
					}
				} else {
					break;
				}
			}
		}
	}

}

int main() {

	scanf_s("%d", &n);
	init();

	count();

	for (int i = 1; i <= n; i++) {
		printf("%d ", square[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}