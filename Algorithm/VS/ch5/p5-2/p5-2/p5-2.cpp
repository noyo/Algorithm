#include<iostream>
#include"Set.h"

using namespace std;

int main() {

	while (1) {
		int n;
		cin >> n;
		int val;
		Set set;
		while (n-- > 0) {
			cin >> val;
			set.add_element(val);
		}
		cout << set << "\n";
		Set next = set;
		while (!((next = next.get_next()) == set) && !next.is_empty()) {
			cout << "->" << next;
		}
		cout << "->" << next;
	}

	system("pause");
	return 0;
}