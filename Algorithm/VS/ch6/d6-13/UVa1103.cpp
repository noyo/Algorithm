#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<set>
#pragma warning(disable:4996)

using namespace std;

int const maxn = 200;
int const maxm = 50 << 2;
map<char, string> binary = { {'0', "0000"},{ '1', "0001" } ,{ '2', "0010" } ,{ '3', "0011" }
							,{ '4', "0100" } ,{ '5', "0101" } ,{ '6', "0110" } ,{ '7', "0111" }
							,{ '8', "1000" } ,{ '9', "1001" } ,{ 'a', "1010" } ,{ 'b', "1011" }
							,{ 'c', "1100" } ,{ 'd', "1101" } ,{ 'e', "1110" } ,{ 'f', "1111" } };
string words = "WAKJSD";
int n, m;
int cnt, Case = 1;
int buf[maxn + 1][maxm + 1];
vector<set<int>> cir_cnt;
int edge[8][2] = { { 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 } };

int k = 1;
bool islegal(const int r, const int c) {
	return r >= 0 && r <= n && c >= 0 && c <= m;
}


void dfs_r(const int r, const int c) {
	if (!islegal(r, c) || buf[r][c] != 0) return;
	buf[r][c] = -1;
	for (int i = 0; i < 8; i += 2) {
		dfs_r(r + edge[i][0], c + edge[i][1]);
	}
}

void dfs(const int r, const int c) {
	buf[r][c] = -1;
	for (int i = 0; i < 8; i += 2) {
		int l = r + edge[i][0];
		int m = c + edge[i][1];
		if (islegal(l, m)) {
			if (buf[l][m] == 1) {
				dfs(l, m);
			}
			else if (buf[l][m] == 0) {
				cnt++;
				dfs_r(l, m);
			}
		}
	}
}

int main() {

	freopen("in.txt", "r", stdin);
	string line;
	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0) break;
		cout << Case++ << ": ";
		memset(buf, 0, sizeof(buf));
		for (int i = 0; i < n; i++) {
			cin >> line;
			for (int j = 0; j < m; j++) {
				string bin = binary[line[j]];
				for (int k = 0; k < 4; k++)
					buf[i + 1][4 * j + k + 1] = bin[k] - '0';
			}
		}
		m <<= 2;
		n++; m++;
		dfs_r(0, 0);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (buf[i][j] == 1) {
					cnt = 0;
					dfs(i, j);
					cout << words[cnt];
				}
			}
		}
		cout << "\n";
	}
	return 0;
}