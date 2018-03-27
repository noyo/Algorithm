#pragma warning(disable:4996)
#include<iostream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

map<string, int> array_n;
map<string, map<int, int> > arrays;
bool legel = true;

void define(string line) {
	int edge_left = line.find("[");
	int size;
	string name = line.substr(0, edge_left);
	string num = line.substr(edge_left + 1, line.find_last_of("]") - edge_left - 1);
	stringstream ss(num);
	ss >> size;
	array_n[name] = size;
}

int get_value(string line) {
	if (!legel) return -1;
	int edge_left = line.find("[");
	if (edge_left != string::npos) {
		string name = line.substr(0, edge_left);
		string val = line.substr(edge_left + 1, line.length() - edge_left - 1);
		int v = get_value(val);
		if (array_n[name] <= v || v < 0 || !arrays[name].count(v)) {
			legel = false;
		}
		return arrays[name][v];
	}
	else {
		int val;
		stringstream ss(line);
		ss >> val;
		return val;
	}
}

bool evaluate(string line, int e) {
	stringstream ss(line);
	string left = line.substr(0, e);
	string right = line.substr(e + 1, line.length() - e - 1);

	int edge_left = left.find("[");
	string name = left.substr(0, edge_left);
	string val = left.substr(edge_left + 1, line.length() - edge_left - 1);

	int l = get_value(val);
	int r = get_value(right);

	if (!legel || array_n[name] <= l) {//下面注释的代码漏掉了这个判断：array_n[name] <= l
		legel = false;
		return false;
	}
	arrays[name][l] = r;
	return true;
}

int main() {
	string line;
	while (cin >> line) {
		if (line == ".") break;
		arrays.clear(); array_n.clear();
		define(line);
		int wr_line = 1;
		legel = true;
		while (cin >> line) {
			if (line == ".") break;
			if (!legel) continue;
			wr_line++;
			int equal = line.find("=");
			if (equal == string::npos) {
				define(line);
				continue;
			}
			if (!evaluate(line, equal)) {
				continue;
			}
		}
		if (legel) wr_line = 0;
		cout << wr_line << "\n";
	}

	system("pause");
	return 0;
}

//#pragma warning(disable:4996)
//#include<iostream>
//#include<sstream>
//#include<string>
//#include<map>
//
//using namespace std;
//
//map<string, int> array_n;
//map<string, map<int, int> > arrays;
//bool legel = true;
//
//void define(string line) {
//	int edge_left = line.find("[");
//	int size;
//	string name = line.substr(0, edge_left);
//	string num = line.substr(edge_left + 1, line.find_last_of("]") - edge_left - 1);
//	stringstream ss(num);
//	ss >> size;
//	array_n[name] = size;
//}
//
//int get_value(string line) {
//	if (!legel) return -1;
//	int edge_left = line.find("[");
//	if (edge_left != string::npos) {
//		string name = line.substr(0, edge_left);
//		string val = line.substr(edge_left + 1, line.length() - edge_left - 1);
//		int v = get_value(val);
//		if (array_n[name] <= v || v < 0) {
//			legel = false;
//		}
//		return arrays[name][v];
//	}
//	else {
//		int val;
//		stringstream ss(line);
//		ss >> val;
//		return val;
//	}
//}
//
//bool evaluate(string line, int e) {
//	stringstream ss(line);
//	string left = line.substr(0, e);
//	string right = line.substr(e + 1, line.length() - e - 1);
//
//	int edge_left = left.find("[");
//	string name = left.substr(0, edge_left);
//	string val = left.substr(edge_left + 1, line.length() - edge_left - 1);
//
//	int l = get_value(val);
//	int r = get_value(right);
//
//	if (!legel) {
//		return false;
//	}
//	arrays[name][l] = r;
//	return true;
//}
//
//int main() {
//	freopen("data.txt", "r", stdin);
//
//	string line;
//	int wr_line = 0;
//	while (getline(cin, line)) {
//		legel = true;
//		wr_line++;
//		int equal = line.find("=");
//
//		if (equal == string::npos) {
//			define(line);
//		}
//		else if (!evaluate(line, equal)) {
//			cout << wr_line << "\n";
//			//break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}