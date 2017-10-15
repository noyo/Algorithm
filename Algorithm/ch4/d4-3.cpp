#include<stdio.h>

int n, k, m;
int a[21] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int eliminate(int index, int d, int sign) {
	while(d--) {
		do {
			index = (index + sign + n - 1) % n + 1;
		} while(!a[index]);
	}
	return index;
}

int main() {
	
	scanf("%d%d%d", &n, &k, &m);
	int left = n;
	int index1 = 0, index2 = 1;
	while(left) {
		index1 = eliminate(index1, k, 1);
		index2 = eliminate(index2, m, -1);
		printf("%3d", index1);
		left--;
		if(index1 != index2) {
			printf("%3d", index2);
			left--;
		}
		a[index1] = a[index2] = 0;
		printf(",");
	}
	
	return 0;
} 
