#pragma warning(disable:4996)
#include<iostream>
#include<string>

using namespace std;

const int maxn = 10;

int cur, last, next_i[maxn];

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin, line)) {
		next_i[0] = 0;
		cur = last = next_i[0];
		int l = line.length();
		for (int i = 1; i <= l; i++) {
			char ch = line[i - 1];
			if (ch == '[') cur = 0;
			else if (ch == ']') cur = last;
			else {
				next_i[i] = next_i[cur];
				next_i[cur] = i;
				if (cur == last) last = i;
				cur = i;
			}
		}
		for (int i = next_i[0]; i != 0; i = next_i[i]) {
			cout << line[i - 1];
		}
		cout << "\n";
	}

	return 0;
}