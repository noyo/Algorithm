#include<stdio.h>


void test(int *a, int *e)  {
	a++;
}

int main() {
	int a[] = {1, 2, 3 , 4};
	test(a, a + 3);
	for(int i = 0; i < 4; i++) {
		
		printf("%d ", a[i]);
	}
	
	
	return 0;
}
