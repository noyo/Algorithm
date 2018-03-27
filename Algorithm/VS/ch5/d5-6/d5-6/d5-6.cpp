#include <iostream>
#include <queue>
#include <map>

using namespace std;

int const maxn = 10;

queue<int> general;
queue<int> branch[maxn];

int main() {

	int n;
	cin >> n;
	int val, q_index;
	map<int, int> data;
	while (scanf_s("%d%d", &val, &q_index) == 2) {
		data[val] = q_index;
	}
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'E') {
			cin >> val;
			q_index = data[val];
			if (branch[q_index].empty()) {
				general.push(q_index);
			}
			branch[q_index].push(val);
			val = branch[q_index].front();
		} else if (cmd == 'D') {
			q_index = general.front();
			val = branch[q_index].front();
			branch[q_index].pop();
			if (branch[q_index].empty()) {
				general.pop();
			}
		} else if (cmd == 'S') {
			break;
		}
		if (cmd == '\n') {
			cout << "------------------" << endl;
			continue;
		}
		cout << cmd << ": " << val << "\n";
	}

	system("pause");
	return 0;
}