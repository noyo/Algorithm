#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int const maxm = 10;

map<string, int> cache;
vector<int> db[maxm];
int val = 0;

struct node {
	int r, c;
	node(int r, int c): r(r), c(c) {}
	bool operator < (const node& n) const {
		return r < n.r || (r == n.r && c < n.c);
	}
};

int get_id(string s) {
	if (cache.count(s)) return cache[s];
	cache[s] = val++;
	return cache[s];
}

int main() {

	int n, m;
	string word;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> word;
			db[j].push_back(get_id(word));
		}
	}

	for (int j = 0; j < m; j++) {
		for (vector<int>::iterator it = db[j].begin(); it != db[j].end(); it++) {
			cout << *it << " ";
		}
		cout << "\n";
	}

	map<node, int> tmp;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			tmp.clear();
			for (int k = 0; k < n; k++) {
				node n = node(db[i][k], db[j][k]);
				if (tmp.count(n)) {
					cout << tmp[n] << "," << i << "\t" << tmp[n] << "," << j << "\n";
					cout << k << "," << i << "\t" << k << "," << j << "\n";
					system("pause");
					return 0;
				}
				tmp[n] = k;
			}
		}
	}

	system("pause");
	return 0;
}