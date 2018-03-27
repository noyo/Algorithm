#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> dict;

int main() {

	int n, maxn = 0, row, col;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		dict.push_back(word);
		if (word.length() > maxn) {
			maxn = word.length();
		}
	}
	col = (60 + 2) / (maxn + 2);
	row = (n + col - 1) / col;

	sort(dict.begin(), dict.end());
	for (int i = 0; i < 60; i++) {
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			string wd = dict[i + j * row];
			cout << wd;
			for (int k = 0; j < (col - 1) && k < (maxn + 2 - wd.length()); k++) {
				cout << " ";
			}
		}
		cout << "\n";
	}



	system("pause");
	return 0;
}