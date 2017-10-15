#include<stdio.h>
#include<math.h>

#define MAX 100

int source[MAX];
int dest[MAX];

void error() {
	int no = 1;
	int n;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &source[i]);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &dest[i]);
		}
		int a = 0;
		int b = 0;
		for(int j = 0; j < n; j++) {
			for(int i = 0; i < n; i++) {
				if(i == j && dest[j] == source[i]) {
					a++;
				} else if(i != j && dest[j] == source[i]) {
					b++;
				}
			}
		}
		printf("no = %d, n = %d, A = %d B = %d\n", no++, n, a, b);
	}
}

void real() {
	int no = 1;
	int n;
	while(scanf("%d", &n) == 1 && n) {
		int a = 0;
		int b = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &source[i]);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &dest[i]);
			if(dest[i] == source[i]) {
				a++;
			}
		}
		for(int j = 1; j < 9; j++) {
			int c1 = 0;
			int c2 = 0;
			for(int i = 0; i < n; i++) {
				if (source[i] == j) {
					c1++;
				}
				if (dest[i] == j) {
					c2++;
				}
			}
			b += (c1 > c2 ? c2 : c1);
		}
		b -= a;
		printf("no = %d, n = %d, A = %d B = %d\n", no++, n, a, b);
	}
}

int main() {
	
	//error();
	real();
	
	
	return 0;
}
