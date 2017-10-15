#include<stdio.h>
#include<string.h>


char ss[5][5];

int main() {
	int x = -1;
	int y = -1;
	for(int i = 0; i < 5; i++) {
		gets(ss[i]);
		if(x != -1) {
			continue;
		}
		for(int j = 0; j < 5; j++) {
			if(ss[i][j] == ' ') {
				x = j;
				y = i;
				break;
			}
		}
	}
	printf("(%d, %d)\n", y, x);
	char cd[100];
	while(scanf("%s", cd) != EOF) {
		int len = strlen(cd);
		for(int i = 0; i < len; i++) {
			char cmd = cd[i];
			if(cmd == 'A') {
				if(y == 0) {
					printf("ERROR");
					break;
				}
				ss[y][x] = ss[y - 1][x];
				ss[y - 1][x] = ' ';
				y--;
			} else if(cmd == 'B') {
				if(y == 4) {
					printf("ERROR");
					break;
				}
				ss[y][x] = ss[y + 1][x];
				ss[y + 1][x] = ' ';
				y++;
			} else if(cmd == 'L') {
				if(x == 0) {
					printf("ERROR");
					break;
				}
				ss[y][x] = ss[y][x - 1];
				ss[y][x - 1] = ' ';
				x--;
			} else if(cmd == 'R') {
				if(x == 4) {
					printf("ERROR");
					break;
				}
				ss[y][x] = ss[y][x + 1];
				ss[y][x + 1] = ' ';
				x++;
			} else {
				break;
			} 
		}
		printf("(%d, %d)\n", y, x);
		for(int i = 0; i < 5; i++) {
			puts(ss[i]);
		}
	}
	
	return 0;
}
