#pragma warning(disable:4996)
#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<map>

using namespace std;

struct Matrix {
	int m;
	int n;

	Matrix() {}
	Matrix(int m, int n): m(m), n(n) {}

	int operator * (const Matrix& B) {
		if (n != B.m) return -1;
		return m * n * B.n;
	}
};

map<char, Matrix> ms;
stack<Matrix> stack_m;

int main() {

	freopen("in.txt", "r", stdin);

	int size;
	cin >> size;
	while (getchar() != '\n') break;
	string line;
	while (size--) {
		getline(cin, line);
		stringstream ss(line);
		char ch;
		int m, n;
		ss >> ch >> m >> n;
		ms[ch] = Matrix(m, n);
	}
	int left = 0, count;
	while (getline(cin, line)) {
		int len = line.length();
		count = 0;
		while (!stack_m.empty()) stack_m.pop();
		for (int i = 0; i < len; i++) {
			if (line[i] == '(') left++;
			else if (line[i] == ')') {
				left--;
				Matrix m2 = stack_m.top();
				stack_m.pop();
				Matrix m1 = stack_m.top();
				stack_m.pop();
				if (m1.n != m2.m) {
					count = -1;
					break;
				}
				count += (m1 * m2);
				stack_m.push(Matrix(m1.m, m2.n));
			}
			else {
				stack_m.push(ms[line[i]]);
			}
		}
		cout << count << "\n";
	}

	return 0;
}