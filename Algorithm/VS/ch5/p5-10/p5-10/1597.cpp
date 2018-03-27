#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
#include<ctype.h>

using namespace std;

vector<vector<string> > passages;
vector<struct Cmd> cmds;
vector<string> sentences;

struct Cmd {
	vector<int> indexs;
	int complex = -1;//0,1,2
	string words[2];
	bool and[2] = { false, false };
	Cmd() {}
	Cmd(string line) {
		if (line.find("AND") != string::npos) complex = 0;
		else if (line.find("OR") != string::npos) complex = 1;
		else if (line.find("NOT") != string::npos) complex = 2;

		stringstream ss(line);
		string tmp;
		if (complex == 0 || complex == 1) ss >> words[0] >> tmp >> words[1];
		else if (complex == 2) ss >> tmp >> words[0];
		else ss >> words[0];
	}

	bool find(string word, string line) {
		stringstream ss(line);
		string w;
		while (ss >> w) {
			if (!isalpha(w[w.length() - 1])) w = w.substr(0, w.length() - 1);
			if (w == word) return true;
		}
		return false;
	}

	bool find(string line) {
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		if (complex == 0) {
			bool f0 = find(words[0], line);
			bool f1 = find(words[1], line);
			if (!and[0] && f0) and [0] = true;
			if (!and[1] && f1) and [1] = true;
			return f0 || f1;
		}
		else if (complex == 1) return find(words[0], line) || find(words[1], line);
		else if (complex == 2) return find(words[0], line);
		else return find(words[0], line);
	}
};

void getPassages() {
	int n;
	cin >> n;
	string str = "\n";
	getline(cin, str);
	string line;
	while (n--) {
		vector<string> psg;
		while (getline(cin, line)) {
			if (line == "**********") break;
			psg.push_back(line);
		}
		passages.push_back(psg);
	}
}

void getCmd() {
	int n;
	cin >> n;
	string str = "\n";
	getline(cin, str);
	string line;
	while (n--) {
		getline(cin, line);
		cmds.push_back(Cmd(line));
	}
}

void find() {
	for (vector<Cmd>::iterator cmd = cmds.begin(); cmd != cmds.end(); cmd++) {
		int cmp = 0;
		for (vector<vector<string> >::iterator it = passages.begin(); it != passages.end(); it++) {
			bool isCmp = false;
			bool isNot = true;
			sentences.clear();
			if (cmd->complex == 0) {
				cmd->and[0] = cmd->and[1] = false;
			}
			for (vector<string>::iterator psg = it->begin(); psg != it->end(); psg++) {
				if (cmd->find(*psg)) {
					isNot = false;
					if (cmd->complex == 2) {
						break;
					}
					isCmp = true;
					sentences.push_back(*psg);
				}
			}

			if (cmd->complex == 0 && (!cmd->and[0] || !cmd->and[1])) {
				isCmp = false;
			}
			if (cmp > 0 && isCmp) {
				cout << "----------" << "\n";
			}
			if (isCmp)
				for (vector<string>::iterator it = sentences.begin(); it != sentences.end(); it++)
					cout << *it << "\n";
			if (cmd->complex == 2 && isNot) {
				isCmp = true;
				if (cmp > 0) {
					cout << "----------" << "\n";
				}
				for (vector<string>::iterator psg = it->begin(); psg != it->end(); psg++) {
					cout << *psg << "\n";
				}
			}
			if (isCmp) {
				cmp++;
			}

		}
		if (cmp == 0) {
			cout << "Sorry, I found nothing." << "\n";
		}
		cout << "==========" << "\n";
	}
}

int main() {
	getPassages();

	getCmd();

	find();

	return 0;
}


//#pragma warning(disable:4996)
//#include<iostream>
//#include<vector>
//#include<sstream>
//#include<string>
//#include<algorithm>
//#include<ctype.h>
//
//using namespace std;
//
//vector<vector<string>> passages;
//vector<struct Cmd> cmds;
//vector<string> sentences;
//
//struct Cmd {
//	vector<int> indexs;
//	int complex = -1;//0,1,2
//	string words[2];
//	bool and[2] = { false, false };
//	Cmd() {}
//	Cmd(string line) {
//		if (line.find("AND") != string::npos) complex = 0;
//		else if (line.find("OR") != string::npos) complex = 1;
//		else if (line.find("NOT") != string::npos) complex = 2;
//
//		stringstream ss(line);
//		string tmp;
//		if (complex == 0 || complex == 1) ss >> words[0] >> tmp >> words[1];
//		else if (complex == 2) ss >> tmp >> words[0];
//		else ss >> words[0];
//	}
//
//	bool find(string word, string line) {
//		stringstream ss(line);
//		string w;
//		while (ss >> w) {
//			if (!isalpha(w[w.length() - 1])) w = w.substr(0, w.length() - 1);
//			if (w == word) return true;
//		}
//		return false;
//		//return line.find(word) != string::npos;
//	}
//
//	bool find(string line) {
//		transform(line.begin(), line.end(), line.begin(), ::tolower);
//		if (complex == 0) {
//			bool f0 = find(words[0], line);
//			bool f1 = find(words[1], line);
//			if (!and[0] && f0) and[0] = true;
//			if (!and[1] && f1) and[1] = true;
//			return f0 || f1;
//		}
//		else if (complex == 1) return find(words[0], line) || find(words[1], line);
//		else if (complex == 2) return find(words[0], line);
//		else return find(words[0], line);
//	}
//};
//
//void getPassages() {
//	int n;
//	cin >> n;
//	string line;
//	getline(cin, line);
//	while (n--) {
//		vector<string> psg;
//		while (getline(cin, line)) {
//			if (line == "**********") break;
//			psg.push_back(line);
//		}
//		passages.push_back(psg);
//	}
//}
//
//void getCmd() {
//	int n;
//	cin >> n;
//	string line;
//	getline(cin, line);
//	while (n--) {
//		getline(cin, line);
//		cmds.push_back(Cmd(line));
//	}
//}
//
//void find() {
//	for (vector<Cmd>::iterator cmd = cmds.begin(); cmd != cmds.end(); cmd++) {
//		int cmp = 0;
//		for (vector<vector<string>>::iterator it = passages.begin(); it != passages.end(); it++) {
//			bool isCmp = false;
//			bool isNot = true;
//			sentences.clear();
//			if (cmd->complex == 0) {
//				cmd->and[0] = cmd->and[1] = false;
//			}
//			for (vector<string>::iterator psg = it->begin(); psg != it->end(); psg++) {
//				if (cmd->find(*psg)) {
//					isNot = false;
//					if (cmd->complex == 2) {
//						break;
//					}
//					isCmp = true;
//					sentences.push_back(*psg);
//				}
//			}
//
//			if (cmd->complex == 0 && (!cmd->and[0] || !cmd->and[1])) {
//				isCmp = false;
//			}
//			if (cmp > 0 && isCmp) {
//				cout << "----------" << "\n";
//			}
//			if (isCmp)
//				for (vector<string>::iterator it = sentences.begin(); it != sentences.end(); it++)
//					cout << *it << "\n";
//			if (cmd->complex == 2 && isNot) {
//				isCmp = true;
//				if (cmp > 0) {
//					cout << "----------" << "\n";
//				}
//				for (vector<string>::iterator psg = it->begin(); psg != it->end(); psg++) {
//					cout << *psg << "\n";
//				}
//			}
//			if (isCmp) {
//				cmp++;
//			}
//			
//		}
//		if (cmp == 0) {
//			cout << "Sorry, I found nothing." << "\n";
//		}
//		cout << "==========" << "\n";
//	}
//}
//
//int main() {
//	freopen("data.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	getPassages();
//
//	getCmd();
//
//	find();
//
//	system("pause");
//	return 0;
//}