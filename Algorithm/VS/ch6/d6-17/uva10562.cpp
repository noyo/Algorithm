#pragma warning(disable:4996)
#include<iostream>
#include<sstream>
#include<string.h>
#include<map>

using namespace std;

struct Node {
	char val;
	Node* child[10];
	Node () {}
} *Tree;

int const maxn = 100;

string tree[maxn][maxn];
map<int, Node*> node_map;

bool is_node(char ch) {
	return ch != '|' && ch != '-';
}

void input() {
	freopen("in.txt", "r", stdin);
	int n; string line;
	cin >> n;
	while (getchar() != '#') { cout << "q";continue; }
	for (;;) {
		if (getline(cin, line) && line != "#") {
			int i = 0, len = line.length(); char ch;
			for (; i < len; i++) {
				if (line[i] != ' ') {

				}
			}
		}
		else {
			if (!--n) break;
		}
	}
}

int main() {

	input();

	return 0;
}