#include<stdio.h>

int num[10];

int getCount(int n, int digit) {
	int count = 0;
	int high = n / 10;
	int low = 0;
	int weight = 1;
	int crt = n % 10;
	while(high || (digit && digit <= crt)) {
		count += high * weight;
		if(digit == 0) {
			count -= weight;
		}
		if(crt > digit) {
			count += weight;
		} else if(digit == crt) {
			count += low + 1;
		}
		low += crt * weight;
		weight *= 10;
		n /= 10;
		high = n / 10;
		crt = n % 10;
	}
	return count;
}

int main() {
	
	int n;
	scanf("%d", &n);
	int digit;
	while(n-- > 0) {
		scanf("%d", &digit)	;
		for(int i = 0; i <10; i++) {
			num[i] = getCount(digit, i);
			printf("%d%c", num[i], i == 9 ? '\n' : ' ');
		}
	}
	return 0;
}



//#include<stdio.h>
//
//int num[10];
//
//int main() {
//	int n;
//	
//	for(int i = 0; i < 10; i++) {
//		printf("%d\t", num[i]);
//	}
//	printf("\n");
//	while(scanf("%d", &n) != 0) {
//		int digit = 1;
//		while(digit <= n) {
//			int d_temp = digit;
//			while(d_temp > 0) {
//				num[d_temp % 10]++;
//				d_temp /= 10;
//			}
//			digit++;
//		}
//		for(int i = 0; i < 10; i++) {
//			printf("%d\t", num[i]);
//			num[i] = 0;
//		}
//		printf("\n");
//	}
//	
//		
//	return 0;
//}
