#include<stdio.h>

void test(int type) {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		if (type == 1) {
			for(int i = 10; i <= 100; i++) {
				if(i % 3 == a && i % 5 == b && i % 7 == c) {
					printf("%d\n", i);
					return;
				} 
			}
		} else {
			int s = (70 * a + 21 * b + 15 * c) % 105;
			printf("%d\n", s);
			return;
		}
		printf("No answer");
	}
}

int main() {
	printf("hello world\n");
//	test(1);
	test(2);
	return 0;
}
