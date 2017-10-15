#include<stdio.h>
#include<string.h>
#include"qsort.h"

char words1[30];
char words2[30];
int num1[26] = {0};
int num2[26] = {0};

int main() {
	
	scanf("%s%s", words1, words2);
	int l1 = strlen(words1);
	int l2 = strlen(words2);
	for(int i = 0; i < l1; i++) {
		num1[words1[i] - 'a']++;
	}
	for(int i = 0; i < l2; i++) {
		num2[words2[i] - 'a']++;
	}
	qsort(num1, 0, 25);
	qsort(num2, 0, 25);
	bool can_map = true;
	for(int i = 0; i < 26; i++) {
		if(num1[i] != num2[i]) {
			can_map = false;
			break;
		}
	}
	printf("%d", can_map);
	return 0;
} 
