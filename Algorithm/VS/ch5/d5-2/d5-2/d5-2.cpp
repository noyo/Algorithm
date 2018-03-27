#include <iostream>
#include <vector>
#include <string>

using namespace std;

int const maxn = 25;
vector<int> treap[maxn];

void get_pile(int x, int n, int &pile, int &heigh) {
	for (pile = 0; pile < n; pile++) {
		for (heigh = 0; heigh < treap[pile].size(); heigh++) {
			if (treap[pile][heigh] == x) {
				return;
			}
		}
	}
}

void reset(int p, int h) {
	int size = treap[p].size();
	for (int i = h + 1; i < size; i++) {
		int val = treap[p][i];
		treap[val].push_back(val);
	}
	treap[p].resize(h + 1);
}

void move(int s_p, int s_h, int d_p) {
	int size = treap[s_p].size();
	for (int i = s_h; i < size; i++) {
		treap[d_p].push_back(treap[s_p][i]);
	}
	treap[s_p].resize(s_h);
}

int main() {

	int n, a, b;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		treap[i].push_back(i);
	}
	
	while (cin >> s1 >> a >> s2 >> b) {
		int ha, hb, pa, pb;
		get_pile(a, n, pa, ha);
		get_pile(b, n, pb, hb);
		if (s1 == "move") {
			reset(pa, ha);
		}
		if (s2 == "onto") {
			reset(pb, hb);
		}
		move(pa, ha, pb);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < treap[i].size(); j++) {
				cout << treap[i][j] << " ";
			}
			cout << "\n";
		}
	}

	system("pause");
	return 0;
}