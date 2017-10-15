#include<stdio.h>
#include<string.h>

#define N 11
#define M 11

char tab[N][M];

bool isStart(int i, int j) {
	bool is_start = false;
	if(i <= 0 || j <= 0) {
		is_start = true;
	} else if(tab[i - 1][j] == '*' || tab[i][j - 1] == '*') {
		is_start = true;
	}
	return is_start;
}

int main() {
	
	int n;
	int start_n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", &tab[i]);
	}
	int len = strlen(tab[0]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++) {
			if(tab[i][j] != '*' && isStart(i, j)) {
				tab[i][j] = ++start_n + '0';
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++) {
			printf("%c", tab[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
} 
