#include<iostream>
#include<map>

using namespace std;


int main() {

	int x, y;
	double sum_x = 0;
	double pivot_x;
	int n;
	//if (n == 1) cout << "YES";
	while (1) {
		cin >> n;
		int tmp = n;
		map<int, int> point_x;
		map<int, int> point_y;
		while (tmp--) {
			scanf_s("%d%d", &x, &y) == 2;
			sum_x += x;
			point_x[y] = x;
			if (!point_y.count(y)) point_y[y] = 0;
			point_y[y]++;
		}

		pivot_x = sum_x / n;
		int size = point_y.size();
		for (map<int, int>::iterator it = point_y.begin(); it != point_y.end(); it++) { 
			if (it->second % 2 != 0 && point_x[it->first] != pivot_x) {
				cout << "NO" << "\n";
				break;
			}
		}

		printf("x = %.1f\n", pivot_x);
	}

	system("pause");
	return 0;
}