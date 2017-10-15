#include<stdio.h>
#include<string.h>

char words1[30];
char words2[30];

int num[26] = {0};

int main() {
	int n;
	scanf("%d", &n);
	cir:
	while(n-- > 0) {
		scanf("%s%s", words1, words2);
		int l1 = strlen(words1);
		int l2 = strlen(words2);
		
		int a = 0, b = 0;
		for(int i = 0; i < l1; i++) {
			num[words1[i] - 'a']++;
		}
		for(int i = 0; i < l2; i++) {
			if(num[words2[i] - 'a'] > 0) {
				l1 -= num[words2[i] - 'a'];
				num[words2[i] - 'a'] = 0;
			} else {
				b++;
				if(b > 6) {
					printf("ERROR\n");
					goto cir;
				}
			}
		}
		if(l1 > 0) {
			printf("YOU chickened out\n");
			goto cir;
		}
		printf("SUCCESS\n");
		
	}
	
	return 0;
}
