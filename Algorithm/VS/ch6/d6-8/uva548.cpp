#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

const int maxn = 10000;

int l[maxn], r[maxn];
int mid[maxn], rear[maxn];

int best, best_sum;

int build2count(int l1, int r1, int l2, int r2, int sum) {
	if (l1 > r1) return 0;
	int size = 0, i = l1;
	int node = rear[r2];
	while (node != mid[i]) i++;
	size = i - l1;
	sum += node;
	l[node] = build2count(l1, i - 1, l2, l2 + size - 1, sum);
	r[node] = build2count(i + 1, r1, l2 + size, r2 - 1, sum);
	if (!l[node] && !r[node]) {
		if (best_sum > sum || (best_sum == sum && node < best)) {
			best = node;
			best_sum = sum;
		}
	}
	return node;
}

//#include<queue>
//void display() {
//	queue<int> q;
//	q.push(root);
//	while (root && !q.empty())
//	{
//		int val = q.front();
//		q.pop();
//		if (l[val] != 0) q.push(l[val]);
//		if (r[val] != 0) q.push(r[val]);
//		cout << val << " ";
//	}
//}

int main() {
	freopen("in.txt", "r", stdin);
	string line1, line2;
	int n;
	while (getline(cin, line1)) {
		stringstream ss1(line1);
		getline(cin, line2);
		stringstream ss2(line2);
		n = 0;
		int val1, val2;
		while (ss1 >> val1 && ss2 >> val2) {
			mid[n] = val1;
			rear[n++] = val2;
		}
		best_sum = 100000000;
		build2count(0, n - 1, 0, n - 1, 0);
		//display();
		cout << best << "\n";
	}

	return 0;
}