#include<stdio.h>
#include<string.h>

#define N 81

char ch[N];

int main() {
	
	int n; 
    scanf("%d", &n);
	while(n-- > 0) {
		scanf("%s", ch);
		int len = strlen(ch);
		int l = 0;
		int score = 0;
		for(int i = 0; i < len; i++) {
			if(ch[i] == 'O') {
				l++;
				score += l;
			} else {
				if(l > 0) {
					l = 0;
				}
			}
		}
		printf("%d\n", score);
	}
	
		
		
//		int len = strlen(ch);
//		int l = 0;
//		int score = 0;
//		for(int i = 0; i < len; i++) {
//			if(ch[i] == 'O') {
//				l++;
//			} else {
//				if(l > 0) {
//					score += (l * (l + 1)) / 2;
//					l = 0;
//				}
//			}
//		}
//		if(l > 0) {
//			score += (l * (l + 1)) / 2;
//			l = 0;
//		}
//		printf("%d\n", score);
//	}
	
	return 0;
}
