#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int const maxn = 10;
int buf[maxn][maxn];
string s[maxn];
int n, m, cnt;
int edge[8][2] = { {0, -1}, { -1, -1 }, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };

bool islegal(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int r, int c) {
	buf[r][c] = 1;
	for (int i = 0; i < 8; i++) {
		int l = r + edge[i][0];
		int m = c + edge[i][1];
		if (islegal(l, m) && s[l][m] == '@' && buf[l][m] == 0)dfs(l, m);
	}
}

int main() {

	freopen("in.txt", "r", stdin);
	while (scanf_s("%d%d", &n, &m) == 2) {
		if (n == 0 || m == 0) break;
		memset(buf, 0, sizeof(buf));
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '@' && buf[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}