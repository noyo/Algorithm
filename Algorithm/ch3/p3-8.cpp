#include<stdio.h>

#define MAX 3000

int remainder[MAX] = {0};
int decimal[MAX];

int isCircleEnd(int len, int rmd) {
	int s = -1;
	for (int i = 0; i < len; i++) {
		if(remainder[i] == rmd) {
			s = i;
			break;
		}
	}
	return s;
}

int main() {
	
	int a;
	int b;
	scanf("%d%d", &a, &b);
	a %= b;
	int i = 0;
	int circle_start; 
	remainder[i] = a;
	do {
		a *= 10;
		decimal[i++] = a / b;
		a %= b;
		circle_start = isCircleEnd(i, a);
		if(circle_start == -1) {
			remainder[i] = a;
		} else {
			break;
		}
	} while(a != 0); 
	
	return 0;
} 
