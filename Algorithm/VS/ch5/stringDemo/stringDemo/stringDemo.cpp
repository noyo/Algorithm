#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {

	string line;
	while (getline(cin, line)) {

		int sum = 0, x;
		stringstream ss(line);
		while (ss >> x) {
			cout << "x = " << x << "\n";
			sum += x;
		}
		cout << "sum: " << sum << "\n";
	}

	return 0;
}
