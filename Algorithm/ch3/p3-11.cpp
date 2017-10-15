#include<stdio.h>
#include<string.h>

#define MAX 100

char ch1[MAX];
char ch2[MAX];

int main() {
	
	while(true) {
		scanf("%s%s", ch1, ch2);
		int n1 = strlen(ch1);
		int n2 = strlen(ch2);
		int top[n1];
		int bottom[n2];
		for(int i = 0; i < n1; i++) {
			top[i] = ch1[i] - '1';
		}
		for(int i = 0; i < n2; i++) {
			bottom[i] = ch2[i] - '1';
		}
		int cur = 0;
		int ans = 0;
		while (cur < n2) {//备注：需要考虑2种情况，1、向右移， 向左移（代码中并未考虑到）
			int i = 0;
			while((cur + i) < n2 && i < n1 && (top[i] + bottom[cur + i]) <= 1) {
				i++;
			}
			if(i == n1 || (cur + i) == n2) {
				ans = cur;
				break;
			}
			cur++;
		}
		printf("%d\n", ans);
		for(int i = 0; i < n1 + cur; i++) {
			if(i < cur) {
				printf("  ");
			} else {
				printf("%d ", top[i - cur]);
			}
		}
		printf("\n");
		for(int j = 0; j < n2; j++) {
			printf("%d ", bottom[j]);
		}
	} 
	
	return 0;
} 
