#include<stdio.h>

int main() {
	
	int n, m;//long long int
	float s = 0;
	while(true){
		scanf("%d%d", &n, &m);//scanf("%lld%lld", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		if(m < 100) {
		} else if(n >= 334) {
			s += 1.0 / n - 1.0 / m;
		} else {
			for(int i = n; i < 334; i++) {
				s += 1.0 / (i * i); 
			}
			s += 1.0 / 334 - 1.0 / m; 
		}
	}
	printf("%.5f", s);
	
	return 0;
} 
