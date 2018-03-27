#pragma warning(disable:4996)
#include<iostream>
#include<sstream>
#include<string>
#include<queue>

using namespace std;

struct Node {
	bool has_init = false;
	int val;
	string loc;
	Node *left = NULL, *right = NULL;

	Node(){}
	Node(int val, string loc): val(val), loc(loc) {}
};

Node *root = NULL;
bool error = false;

void addNode(int val, string loc) {
	if (root == NULL) root = new Node();
	int l = loc.length();
	Node *node = root;
	for (int i = 0; i < l; i++) {
		char ch = loc[i];
		if (ch == 'L') {
			if (node->left == NULL) {
				node->left = new Node();
			}
			node = node->left;
		}
		else if (ch == 'R') {
			if (node->right == NULL) {
				node->right = new Node();
			}
			node = node->right;
		}
	}
	if (node->has_init) {
		error = true;
		return;
	}
	node->val = val;
	node->has_init = true;
}

void dfs() {
	if (error) {
		//cout << "NOT COMPLETED!" << "\n";
		return;
	}
	queue<Node*> q;
	Node *node = root;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node->left != NULL && node->left->has_init) q.push(node->left);
		if (node->right != NULL && node->right->has_init) q.push(node->right);
		cout << node->val << " ";
		node->has_init = false;
	}
	cout << "\n";
}

void destory(Node *node) {
	if (node == nullptr) return;
	destory(node->left);
	destory(node->right);
	delete node;
}

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin, line)) {
		error = false;
		stringstream ss(line);
		string p;
		int val;
		while (ss >> p) {
			if (p == "()") break;
			sscanf_s(&p[1], "%d", &val);
			addNode(val, p.substr(p.find(",") + 1));
			if (error) break;
		}
		dfs();
	}
	destory(root);
	return 0;
}