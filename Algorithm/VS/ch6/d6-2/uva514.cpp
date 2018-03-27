#pragma warning(disable:4996)
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

stack<int> trains;

int main() {

	freopen("in.txt", "r", stdin);

	int n;
	string line;
	while (1) {
		cin >> n;
		if (n == 0) break;
		while (getchar() == '\n') break;
		while (getline(cin, line)) {
			if (line == "0") break;
			stringstream ss(line);
			int val;
			bool isOk = true;
			int num = 1;
			bool isInput = true;
			for (int i = 0; i < n;) {
				if (isInput) ss >> val;
				isInput = true;
				if (val == num) {
					i++;
					num++;
				}
				else if (val < num && !trains.empty() && val == trains.top()) {
					i++;
					trains.pop();
				}
				else if (val > num) {
					trains.push(num);
					num++;
					isInput = false;
				}
				else {
					isOk = false;
					break;
				}
			}
			cout << (isOk ? "YES" : "NO") << "\n";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}