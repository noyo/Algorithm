#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<sstream>
#include<map>

#define max(a, b) ((a) > (b)) ? (a) : (b)

using namespace std;

const int maxn = 1000;

vector<string> words[maxn];
map<int, int> word_maxn;

int main() {
	freopen("data.txt", "r", stdin);
	string line;
	string word;
	int row = 0, col = 0;
	while (getline(cin, line)) {
		stringstream ss(line);
		col = 0;
		while (ss >> word) {
			if (!word_maxn.count(col) || word_maxn[col] < word.length()) {
				word_maxn[col] = word.length();
			}
			words[row].push_back(word);
			col++;
		}
		row++;
	}
	int len = words->size();
	for (int i = 0; i < len; i++) {
		int col = 0;
		vector<string> ss = words[i];
		for (vector<string>::iterator it = ss.begin(); it != ss.end(); it++) {
			cout << *it;
			for (int j = (*it).length(); j <= word_maxn[col]; j++) {
				cout << " ";
			}
			col++;
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}