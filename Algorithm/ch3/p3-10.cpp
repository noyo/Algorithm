#include<stdio.h> 

int wh[6][2];

int main() {
	
	while(true) {
		int rwh[3][2];
		for(int i = 0; i < 12; i++) {
			int v = i / 2 + 1;
			int h = i - v * 2;
			scanf("%d", &wh[v][h]);
		}
		
		int i = 0;
		int k = 0;
		while(i < 6) {
			if(wh[i][0] == 0) {
				i++;
				continue;
			}
			for (int j = i + 1; j < 6; j++) {
				if((wh[i][0] == wh[j][0] && wh[i][1] == wh[j][1]) 
					|| (wh[i][0] == wh[j][1] && wh[i][1] == wh[j][0])) {
					rwh[k][0] = wh[j][0];
					rwh[k++][1] = wh[j][1];
					wh[j][0] = 0;
					wh[j][1] = 0;
					break;
				}
			}
			i++;
		}
		bool ans = false;
		
		if(rwh[0][0] == rwh[1][0]) {
			if(rwh[1][1] == rwh[2][0]) {
				ans = rwh[2][1] == rwh[0][1];
			} else if (rwh[1][1] == rwh[2][1]) {
				ans = rwh[2][0] == rwh[0][1];
			} 
			if(!ans && rwh[0][1] == rwh[1][1]) {
				if(rwh[1][0] == rwh[2][0]) {
					ans = rwh[2][1] == rwh[0][0];
				} else if (rwh[1][0] == rwh[2][1]) {
					ans = rwh[2][0] == rwh[0][0];
				} 
			}
		} else if(rwh[0][0] == rwh [1][1]) {
			if(rwh[1][0] == rwh[2][0]) {
				ans = rwh[2][1] == rwh[0][1];
			} else if (rwh[1][0] == rwh[2][1]) {
				ans = rwh[2][0] == rwh[0][1];
			}
		}
		
		printf("%d", ans);
	} 
	
	return 0;
} 
