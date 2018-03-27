#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>;

using namespace std;

int const maxn = 100;
int sum[maxn];

void build(int i) {
	int val;
	cin >> val;
	if (val == -1) return;
	sum[i] += val;
	build(i - 1);
	build(i + 1);
}

int main() {
	freopen("in.txt", "r", stdin);
	int root;
	while (true) {
		cin >> root;
		if (root == -1) break;
		memset(sum, 0, sizeof(sum));
		int i = maxn / 2;
		sum[i] += root;
		build(i - 1);
		build(i + 1);
		i = 0;
		while (sum[i] == 0) i++;
		while (sum[i] != 0) cout << sum[i++] << " ";
		cout << "\n";
		while (getchar() != '\n');
	}

	return 0;
}