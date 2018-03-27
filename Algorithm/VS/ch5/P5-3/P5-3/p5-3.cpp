#include<iostream>
#include<queue>

using namespace std;

queue<int> cards;

int main() {
	int n;
	while (1) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cards.push(i);
		}
		while (cards.size() >= 2) {
			cout << cards.front() << " ";
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
		cout << "\n";
		if (!cards.empty()) {
			cout << "left: " << cards.front() << "\n";
		}
	}

	system("pause");
	return 0;
}