#include<stdio.h>
#include<string.h>

int codes[8][255];
char key[30];

void init() {
	int l = strlen(key);
	int row = 0, col = 0;
	for(int i = 0; i < l; i++) {
		if(col >= (1 << (row + 1)) - 1) {
			row++;
			col = 0;
		}
		codes[row][col++] = key[i];
	}
}

int main() {
	scanf("%s", key);
	init();
	int n;
	int d1, d2, d3, d;
	int num;
	while(1){
		scanf("%1d%1d%1d", &d1, &d2, &d3);
		int n = d1 * 4 + d2 * 2 + d3; 
		if(n == 0) break;
		num = 0;
		while(1) {
			for(int i = 0; i < n; i++) {
				scanf("%1d", &d);
				num = (num << 1) + d; 
			}
			if(num >= (1 << n) - 1) break;
			printf("%c", codes[n - 1][num]);
		}
	}
	
	return 0;
}
