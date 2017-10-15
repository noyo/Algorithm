#include<stdio.h>
#include<string.h>

#define N 51
#define M 1001

char net[N][M];

char ch[] = {'A', 'C', 'G', 'T'};

int main() {
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", net[i]);
	}
	int len = strlen(net[0]);
	char ans[len];
	int c_n[26];
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < n; j++) {
			c_n[net[j][i] - 'A']++;
		}
		int max = 0;
		int max_i = 0;
		for(int k = 0; k < 4; k++) {
			int index = ch[k] - 'A';
			if(c_n[index] > max) {
				max = c_n[index];
				max_i = k;
			}
			c_n[index] = 0;
		}
		ans[i] = ch[max_i];
	}
	
	printf("%s\n", ans);
	
	return 0;
}
