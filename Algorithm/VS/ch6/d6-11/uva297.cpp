#include<iostream>
#include<sstream>
#include<string>
#pragma warning(disable:4996)

using namespace std;

int const len = 1 << 5;
int buf[len][len];
int sum;

void fill(string line, int &index, int r, int c, int edge) {
	char ch = line[index++];
	if (ch == 'p') {
		edge /= 2;
		fill(line, index, r, c + edge, edge);
		fill(line, index, r, c, edge);
		fill(line, index, r + edge, c, edge);
		fill(line, index, r + edge, c + edge, edge);
	}
	else if (ch == 'f') {
		for (int i = r; i < r + edge; i++) {
			for (int j = c; j < c + edge; j++) {
				if (buf[i][j] == 0) {
					buf[i][j] = 1;
					sum++;
				}
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	while (getchar() != '\n');
	string line;
	while (n--) {
		memset(buf, 0, sizeof(buf));
		sum = 0;
		for (int i = 0; i < 2; i ++ ) {
			getline(cin, line);
			int index = 0;
			fill(line, index, 0, 0, len);
		}
		cout << sum << "\n";
	}
	return 0;
}