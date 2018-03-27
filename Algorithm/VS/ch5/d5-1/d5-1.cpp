#include<iostream>
#include<algorithm>

using namespace std;

int const maxn = 100;

int main() {

	int n, q, x, a[maxn];

	while (scanf_s("%d%d", &n, &q) == 2 & n) {
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &a[i]);
		}
		sort(a, a + n);
		while (q--) {
			cin >> x;
			cout << "index = " << lower_bound(a, a + n, x) - a << endl;
		}
	}

	system("pause");
	return 0;
}