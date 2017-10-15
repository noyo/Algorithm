#include<stdio.h>
#include<string.h>

#define N 81

char t[N];
char s[N];

int main() {
	
	while(true) {
		scanf("%s%s", t, s);
		int t_l = strlen(t);
		int s_l = strlen(s); 
		int curIndex = 0;
		for(int i = 0; i < t_l && curIndex < s_l; i++) {
			if(t[i] == s[curIndex]) {
				curIndex++;
			}
		}
		bool ans = curIndex == s_l;
		printf("%d", ans);
	}
	return 0;
}
//
//bool isSub = false;
//
//int main() {
//	
//	while(true) {
//		scanf("%s%s", t, s);
//
//		int t_l = strlen(t);
//		printf("%d", isSub);
//		int s_l = strlen(s);
//		if (s_l > t_l || (s_l == t_l && strcmp(s, t))) {
//			printf("%b", isSub);
//		}
//		if (s_l == 1) break;
//		int start_t = 0;
//		int end_t = t_l - 1;
//		int start_s = 0;
//		int end_s = s_l - 1;
//		while(start_s < end_s) {
//			while(start_t < end_t && s[start_s] != t[start_t]) {
//				start_t++;
//			}
//			while(end_t > start_t && s[end_s] != t[end_t]) {
//				end_t--;
//			}
//			if((end_t - start_t) < (end_s - start_s)) {
//				break;
//			}
//			if(start_s == (end_s - 1) && s[end_s] == t[end_t] && s[start_s] == t[start_t]) {
//				isSub = true;
//				break;
//			}
//			start_s++;
//			end_s--;
//		}
//		
//		printf("%d", isSub);
//	} 
//	return 0;
//}
