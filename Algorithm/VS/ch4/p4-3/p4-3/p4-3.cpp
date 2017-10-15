#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 9

char chess[N][N];
int oris[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
bool isLegalPos = false;
char curPlayer = 'W';

void init() {
	memset(chess, ' ', N * N * sizeof(char));
	chess[3][4] = 'B';
	chess[3][7] = 'W';
	chess[4][4] = chess[4][5] = chess[4][6] = 'B';
	chess[5][3] = 'W';
	chess[5][4] = 'B';
	chess[5][5] = chess[5][6] = 'W';
	chess[6][3] = chess[6][4] = chess[6][5] = 'B';
	chess[6][6] = 'W';
}

void next() {
	curPlayer = curPlayer == 'W' ? 'B' : 'W';
}

bool isRival(char rival) {
	return rival == (curPlayer == 'W' ? 'B' : 'W');
}

bool isValid(int r, int c) {
	return r >= 1 && r <= 8 && c >= 1 && c <= 8;
}

bool isLegal(int r, int c, int ori) {
	if (isValid(r, c) && chess[r][c] == ' ') {
		r += oris[ori][0];
		c += oris[ori][1];
		while (isRival(chess[r][c])) {
			r += oris[ori][0];
			c += oris[ori][1];
			if (chess[r][c] == curPlayer) {
				return true;
			}
		}
	}
	return false;
}

void displayLegalMoves() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 0; k < 8; k++) {
				if (isLegal(i, j, k)) {
					printf("(%d, %d) ", i, j);
					break;
				}
			}
		}
	}
}

void makeMove(int r, int c) {
	for (int i = 0; i < 8; i++) {
		if (isLegal(r, c, i)) {
			isLegalPos = true;
			int cur_r = r + oris[i][0];
			int cur_c = c + oris[i][1];
			while (isRival(chess[cur_r][cur_c])){
				chess[cur_r][cur_c] = curPlayer;
				cur_r += oris[i][0];
				cur_c += oris[i][1];
			}
		}
	}
	if (isLegalPos) {
		chess[r][c] = curPlayer;
		next();
	}
}

void displayLegalMove() {

}

void display() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			printf("%c ", chess[i][j]);
		}
		printf("\n");
	}
}

int main() {
	
	init();
	display();
	displayLegalMoves();
	makeMove(7, 3);
	display();

	system("pause");
	return 0;
}