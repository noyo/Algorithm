#include<stdio.h> 
#include<stdlib.h>

char chessboard[11][10];

int b_r, b_c;

int h_n = 0;
int chess_h[2][2];

int mov[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool canSurvive(char chess, int dis) {
	if((dis == 1 && (chess == 'R' || chess == 'G')) || (dis == 2 && chess == 'C')) {
		return false;
	}
	return true; 
}

bool checkByH(int row, int col) {
	for(int i = 0; i < h_n; i++) {
		int r = chess_h[i][0] - row;
		int c = chess_h[i][1] - col;
		if((abs(r) == 2 && abs(c) == 1) || (abs(r) == 1 && abs(c) == 2)) {
			int cur_r = chess_h[i][0] - r / 2, cur_c = chess_h[i][1] - c / 2;
			if(cur_r > 0 && cur_r <= 10 && cur_c > 0 && cur_c <= 9) {
				char cur_chess = chessboard[cur_r][cur_c];
				if(!(cur_chess <= 'Z' && cur_chess >= 'A')) {
					return false;
				}
			}
		}
	}
	return true;
}

bool check(int row, int col) {
	int chess_n = 0; 
	if(h_n && !checkByH(row, col)) {
		return false;
	}
	for(int r = row - 1; r > 0; r--) {
		char c = chessboard[r][col];
		if(c >= 'A' && c <= 'Z')  {
			chess_n++;
			if(!canSurvive(c, chess_n)) return false;
		}
	}
	chess_n = 0;
	for(int r = row + 1; r <= 10; r++) {
		char c = chessboard[r][col];
		if(c >= 'A' && c <= 'Z') {
			chess_n++;
			if(!canSurvive(c, chess_n)) return false;
		}
	}
	chess_n = 0;
	for(int co = col - 1; co > 0; co--) {
		char c = chessboard[row][co];
		if(c >= 'A' && c <= 'Z')  {
			chess_n++;
			if(!canSurvive(c, chess_n)) return false;
		}
	}
	chess_n = 0;
	for(int co = col + 1; co <= 11; co++) {
		char c = chessboard[row][co];
		if(c >= 'A' && c <= 'Z')  {
			chess_n++;
			if(!canSurvive(c, chess_n)) return false;
		}
	}
	return true;
}

int main() {
	start:
	while(1) {//需要清空数组，这里暂时没做修复 
		int red_n;
		scanf("%d%d%d", &red_n, &b_r, &b_c);
		
		int r, c;
		h_n = 0;
		while(red_n-- > 0) {
			char red_chess[1];
			scanf("%s%d%d", red_chess, &r, &c);
			chessboard[r][c] = red_chess[0];
			if(red_chess[0] == 'H') {
				chess_h[h_n][0] = r;
				chess_h[h_n][1] = c;
				h_n++;
			}
		}
	
		for(int i = 0; i < 4; i++) {
			int row = b_r + mov[i][0];
			int col = b_c + mov[i][1];
			if((row >= 1 && row <= 3 && col >= 4 && col <= 6) && check(row, col)) {
				printf("YES\n");
				goto start;
			}
		}
		printf("NO\n");
	}
	return 0;
} 
