#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

const int maxn = 100000;
int pre[maxn], rear[maxn];
int n, m;
int op, X, Y;
int c = 1;
bool is_reverse;

void print() {
	int s = 1, sum = 0;
	for (int i = rear[0]; i != 0; i = rear[i]) { 
		//cout << i << " ";
		if (s % 2 == 1) sum += i;
		s++;
	}
	if (is_reverse && !(n % 2)) sum = n * (n + 1) / 2 - sum;
	cout << "case " << c++ << ": " << sum;
	cout << "\n";
}

//void reverse() {
//	int start_i, end_i = rear[0];
//	while (rear[end_i] != 0) {
//		start_i = rear[0];
//		rear[0] = rear[end_i];
//		rear[end_i] = rear[rear[end_i]];
//		pre[rear[end_i]] = end_i;
//		rear[rear[0]] = start_i;
//		pre[start_i] = rear[0];
//		pre[rear[0]] = 0;
//	}
//}
//
//void left() {
//	if (rear[X] == Y) return;
//	pre[rear[X]] = pre[X];
//	rear[pre[X]] = rear[X];
//	rear[X] = Y;
//	pre[X] = pre[Y];
//	rear[pre[Y]] = X;
//	pre[Y] = X;
//}
//
//void right() {
//	if (rear[Y] == X) return;
//	pre[rear[X]] = pre[X];
//	rear[pre[X]] = rear[X];
//	rear[X] = rear[Y];
//	pre[X] = Y;
//	rear[Y] = X;
//	pre[rear[X]] = X;
//}
//
//void ex() {
//	if (rear[X] == Y) {
//		rear[X] = rear[Y];
//		pre[rear[X]] = X;
//		rear[Y] = X;
//		pre[Y] = pre[X];
//		pre[X] = Y;
//		rear[pre[Y]] = Y;
//		return;
//	}
//	int x_pre = pre[X];
//	int x_rear = rear[X];
//	pre[X] = pre[Y];
//	pre[Y] = x_pre;
//	rear[pre[X]] = X;
//	rear[x_pre] = Y;
//	rear[X] = rear[Y];
//	rear[Y] = x_rear;
//	pre[x_rear] = Y;
//	pre[rear[X]] = X;
//}

void link(int L, int R) {
	rear[L] = R;
	pre[R] = L;
}

void exXY(int X, int Y) {
	link(pre[Y], X);
	link(Y, rear[X]);
	link(X, Y);
}

int main() {
	string line;
	freopen("in.txt", "r", stdin);
	while (getline(cin, line)) {
		stringstream ss(line);
		ss >> n >> m;
		pre[0] = n;
		rear[0] = 1;
		for (int i = 1; i <= n; i++) {
			rear[i] = (i + 1) % (n + 1);
			pre[i] = i - 1;
		}
		is_reverse = false;
		while (m--) {
			getline(cin, line);
			stringstream ss(line);
			ss >> op;
			if (op != 4) {
				ss >> X >> Y;
				if (op != 3 && is_reverse) op = 3 - op;
				if (op == 1 && rear[X] != Y) {
					if (pre[X] == Y) {
						exXY(X, Y);
					}
					else {
						link(pre[X], rear[X]);
						link(pre[Y], X);
						link(X, Y);
					}
				}
				else if (op == 2 && pre[X] != Y) {
					if (rear[X] == Y) {
						exXY(Y, X);
					}
					else {
						link(pre[X], rear[X]);
						link(X, rear[Y]);
						link(Y, X);
					}
				}
				else if (op == 3) {
					if (rear[X] == Y) exXY(Y, X);
					else if (pre[X] == Y) exXY(X, Y);
					else {
						int x_l = pre[X], x_r = rear[X];
						link(pre[Y], X);
						link(X, rear[Y]);
						link(x_l, Y);
						link(Y, x_r);
					}
				}
			}
			else is_reverse = !is_reverse;
			/*cout << line << "\n";
			print();*/
		}
		print();
	}

	return 0;
}