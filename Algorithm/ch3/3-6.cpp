#include<stdio.h>
#include<string.h>

#define MAX 100

char ch[MAX];

int main() {
	
	scanf("%s", ch);
	int len = strlen(ch);
	printf("%d\n", len);
	int s = 0;
	for(int i = 1; i < len; i++) {
		int top = s;
		int bot = i; 
		int e = s + len;
		for(; top < e; top++, bot++) {
			if(ch[top % len] < ch[bot % len]) {
				break;
			} else if(ch[top % len] > ch[bot % len]) {
				s = i;
				break;
			}
		}
	}
	int e = s + len;
	printf("%d\n", s);
	for(; s < e; s++) {
		printf("%c", ch[s % len]);
	}
	
	
//	char low = 'X';
//	int s = 0;
//	int low_l = 0;
//	int max_s = 0;
//	int max_low_l = 0;
//	for(int i = 0; i < len; i++) {
//		if(ch[i] < low) {
//			s = i;
//			max_s = s;
//			low_l = 0;
//			low = ch[i];
//		} else if (ch[i] == low) {
//			if (i = s + low_l) {
//				low_l++;
//			} else{
//				s = i;
//				if(low_l > max_low_l || (low_l == max_low_l))
//			}
//		}
//	}
	
	return 0;
} 
