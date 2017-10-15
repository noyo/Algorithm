#include<stdio.h>
#include<string.h>

#define N 81

char str[N];

bool validate(int e_s, int k) {
	for(int i = 0; i < e_s; i++) {
		if(str[i] != str[i + k]) {
			return false;
		}
	}
	return true;
}

int main() {
	int len;
	char end;
	int k;
	int n;
	int cir_l;
	while(~scanf("%d",&n))
	while(n--) {
		scanf("%s", str);
		len = strlen(str);
		end = str[len - 1];
		k = 1;
		cir_l = len;
		for (int i = 0; i < len - k; i++) {
			if(!(len % k)) {//不要忘记这个条件，周期长度k必须为字符串长度len的约数 
				if(str[i] == end) {
					bool res = validate(len - k, k);
					if(res) {
						cir_l = k;
						break;
					}
				}
			}
			k++;
		}
		printf("%d\n", cir_l);
		if(n) {
			printf("\n");	
		}
	}
	
	return 0;
}
