#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
#pragma warning(disable:4996)

using namespace std;

int const maxn = 10;

struct Node
{
	int r, c, dir;
	Node() {}
	Node(int r, int c, int dir): r(r), c(c), dir(dir) {}
};

char *dir_abs = "WNES";
char *dir_rel = "FLR";
int dir_map[4][2] = { {0, -1},{ -1, 0 }, { 0, 1 }, { 1, 0 } };
string dsp;
int in_r, in_c, out_r, out_c, in_r2, in_c2;
char in_dir;
Node pre[maxn][maxn][4];
int avai[maxn][maxn][4][3];
int traced[maxn][maxn][4];

bool is_legal(int r, int c) {
	return r > 0 && r < maxn && c > 0 && c < maxn;
}

int dir_id(char c) {
	return strchr(dir_abs, c) - dir_abs;
}

int turn_id(char c) {
	return strchr(dir_rel, c) - dir_rel;
}

int dir_id(int dir, int turn) {
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return dir;
}

void print(Node n) {
	vector<Node> p;
	do {
		p.push_back(n);
		n = pre[n.r][n.c][n.dir];
	} while (traced[n.r][n.c][n.dir]);
	cout << "(" << in_r << "," << in_c << ")" << "  ";
	cout << "(" << n.r << "," << n.c << ")" << "  ";
	for (int i = p.size() - 1; i >= 0; i--) {
		n = p[i];
		cout << "(" << n.r << "," << n.c << ")" << "  ";
	}
	cout << "\n";
}

void track() {
	memset(traced, 0, sizeof(traced));
	int r, c, d;
	queue<Node> path;

	Node node = Node(in_r2, in_c2, dir_id(in_dir));
	traced[in_r][in_c][in_dir] = 1;
	traced[in_r2][in_c2][in_dir] = 1;
	path.push(node);

	cout << dsp << "\n";
	while (!path.empty()) {
		node = path.front();
		path.pop();
		for (int i = 0; i < 3; i++) {
			d = dir_id(node.dir, i);
			r = node.r + dir_map[d][0];
			c = node.c + dir_map[d][1];
			if (is_legal(r, c) && avai[node.r][node.c][node.dir][i] && !traced[r][c][d]) {
				traced[r][c][d] = 1;
				Node n = Node(r, c, d);
				pre[r][c][d] = node;
				//cout << r << ", " << c << ", " << d << "(" << node.r << "," << node.c << ")" << "  ";
				if (r == out_r && c == out_c) {
					print(n);
					return;
				}
				else path.push(n);
			}
		}
	}
	cout << "  No Solution Possible\n";
	
}

bool input() {
	int r, c, d;
	if (scanf("%d%d %c%d%d", &in_r, &in_c, &in_dir, &out_r, &out_c) != 5) return false;
	memset(avai, 0, sizeof(avai));
	d = dir_id(in_dir);
	in_r2 = in_r + dir_map[d][0];
	in_c2 = in_c + dir_map[d][1];
	string line;
	while (getchar() != '\n');
	for (;;) {
		getline(cin, line);
		stringstream ss(line);
		ss >> r >> c;
		if (r == 0) break;
		string dir;
		while (ss >> dir && dir != "*") {
			d = dir_id(dir[0]);
			for (int i = 1; i < dir.length(); i++) {
				avai[r][c][d][turn_id(dir[i])] = 1;
			}
		}
	}
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> dsp && dsp != "END") {
		if (!input()) break;
		track();
	}
	

	return 0;
}