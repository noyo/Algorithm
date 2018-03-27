#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string line;

bool weigh(int &W) {
	int W1, D1, W2, D2;
	bool b1 = true, b2 = true;
	getline(cin, line);
	stringstream ss(line);
	ss >> W1 >> D1 >> W2 >> D2;
	if (!W1) b1 = weigh(W1);
	if (!W2) b2 = weigh(W2);
	W = W1 + W2;
	return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main() {

	freopen("in.txt", "r", stdin);
	int n;
	int tmp;
	cin >> n;
	while (getchar() != '\n');
	while (n--) {
		getline(cin, line);
		if (weigh(tmp)) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}


 	return 0;
}