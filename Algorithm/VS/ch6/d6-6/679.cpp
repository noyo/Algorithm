#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

const int maxn = 20;

int key[1 << maxn];
int n, D, I;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	cin >> n;
	while (getchar() != '\n');
	while (n--) {
		getline(cin, line);
		if (line == "-1") break;
		memset(key, 0, sizeof(key));
		stringstream ss(line);
		ss >> D >> I;
		int m = (1 << D) - 1;
		int k;
		for (int i = 0; i < I; i++) {
			k = 1;
			for (;;) {
				key[k] = !key[k];
				k = key[k] ? (2 * k) : (2 * k + 1);
				if (k > m) break;
			}
		}
		cout << k / 2 << "\n";
	}

	return 0;
}