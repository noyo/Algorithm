#include<stdio.h>
#include<string.h>

#define N 1001

int light[N];


void method1() {
	int n;
	int k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int value = 0;
		for(int j = 1; j <= i && j <=k; j++) {
			if(i % j == 0) {
				value = (value + 1) % 2;
			}
		}
		if(value == 1) {
			printf("%d\t", i); 
		}
	}
}

void m2() {
	
	int n;
	int k;
	scanf("%d%d", &n, &k);
	memset(light, 0, sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i && j <=k; j++) {
			if(i % j == 0) {
				light[i] = !light[i];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(light[i] == 1) {
			printf("%d\t", i);
		}
	}
}

int main() {
	m2();
	
	
	return 0;
}
