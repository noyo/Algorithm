#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAX 100

char ch[MAX];
float weight[] = {12.01, 1.008, 16, 14.01};

int main() {
	int n;
	scanf("%d", &n) ;
	while(n-- > 0) {
		float quality = 0.0;
		scanf("%s", ch);
		int len = strlen(ch);
		float s = 0;
		float num = 1.0;
		for(int i = 0; i < len; ) {
			char c = ch[i];
			
			if(c == 'C') {
				quality = weight[0];
			} else if(c == 'H') {
				quality = weight[1];
			} else if(c == 'O') {
				quality = weight[2];
			} else if(c == 'N') {
				quality = weight[3];
			}
			i++;
			int loc = 0;
			num = 1.0;
			while(isdigit(ch[i])) {
				num = loc * 10 + (ch[i++] - '0');
				loc = num;
			}
			s += quality * num;
			
		}
		printf("%.3f\n", s);
	}
	
//	while(scanf("%s", ch) != EOF) {
//		float quality = 0.0;
//		int len = strlen(ch);
//		int l = 0;
//		float s = 0;
//		float num = 1.0;
//		for(int i = 0; i < len; i++) {
//			char c = ch[i];
//			if(c >= 'A') {
//				if(l > 0) {
//					int p = pow(10, l - 1);
//					num = 0;
//					while(l > 0) {
//						num += (ch[i - l] - '0') * p;
//						p /= 10;
//						l--;
//					}
//				}
//				s += quality * num;
//				num = 1;
//				if(c == 'C') {
//					quality = weight[0];
//				} else if(c == 'H') {
//					quality = weight[1];
//				} else if(c == 'O') {
//					quality = weight[2];
//				} else if(c == 'N') {
//					quality = weight[3];
//				}
//			} else {
//				l++;
//			}
//		}
//		printf("%f\n", s);
//	}
	
	return 0;
}
