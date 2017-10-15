#include<stdio.h>

#define MAX 51
#define DEL_ROW 1
#define DEL_COL 2
#define INSERT_ROW 3
#define INSERT_COL 4 

int data[MAX][MAX] = {
	{
		-1, -1, -1, -1, -1, -1
	}, {
		-1, 11, 12, 13, 14, 15
	}, {
		-1, 21, 21, 23, 24, 25
	}, {
		-1, 31, 32, 33, 34, 35
	}, {
		-1, 41, 42, 43, 44, 45
	}, {
		-1, 51, 52, 53, 54, 55
	}
};
int row = 5, col = 5;

void insert(int loc, int type) {
	if (type == INSERT_ROW) {
		for(int i = row + 1; i >= loc; i--) {
			for(int j = 1; j <= col; j++) {
				if (i != loc) {
					data[i][j] = data[i - 1][j];
				} else {
					data[i][j] = -1;
				}
			}
		}
		row++;
	} else if (type == INSERT_COL) {
		for(int j = col + 1; j >= loc; j--) {
			for(int i = 1; i <= row; i++) {
				if (j != loc) {
					data[i][j] = data[i][j - 1];
				} else {
					data[i][j] = -1;
				}
			}
		}
		col++;
	}
}

void del(int loc, int type) {
	if (type == DEL_ROW) {
		if (loc != row) {
			for(int i = loc; i < row; i++) {
				for(int j = 1; j <= col; j++) {
					data[i][j] = data[i + 1][j];
				}
			}
		}
		row--;
	} else if (type == DEL_COL) {
		if (loc != col) {
			for(int j = loc; j < col; j++) {
				for(int i = 1; i <= row; i++) {
					data[i][j] = data[i][j + 1];
				}
			}
		}
		col--;
	}
}

void exchange(int r1, int r2, int c1, int c2) {
	int tmp = data[r1][c1];
	data[r1][c1] = data[r2][c2];
	data[r2][c2] = tmp;
}

void display() {
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	
	display();
	
	exchange(2, 3, 1, 2);
	
	display();
	
	insert(2, 3);
	display();
	insert(3, 4);
	display();
	del(4, 1);
	display();
	del(6, 2);
	display();
	
	return 0;
}
