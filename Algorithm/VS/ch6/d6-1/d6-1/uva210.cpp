#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<deque>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;

struct Program;

int schedule[6];
map<int, Program> programList;
map<string, int> vars;
deque<int> waitQueue;
queue<int> blockQueue;
bool isLocked = false;

int n, Q;
int li = 1;

struct Program {
	int id;
	int runPos = 0;
	vector<string> codes;
	int runTime = 0;
	bool isRunCompleted = false;

	Program() {}

	Program(int id): id(id) {}

	string getRunCode() {
		return codes[runPos];
	}

	int excute() {
		string code = getRunCode();
		//cout << "id: " << id << "  pos: " << runPos << "   " << code << "\n";
		int index = 0;
		if (code.find("=") != string::npos) {
			index = 1;
			stringstream ss(code);
			string var, tmp;
			ss >> var >> tmp;
			ss >> vars[var];
		}
		else if (code.find("print") != string::npos) {
			index = 2;
			stringstream ss(code);
			string var, tmp;
			ss >> tmp >> var;
			cout << id + 1 << ": " << vars[var] << "\n";
		}
		else if (code.find("unlock") != string::npos) {
			if (!blockQueue.empty()) {
				waitQueue.push_front(blockQueue.front());
				blockQueue.pop();
			}
			index = 4;
			isLocked = false;
		}
		else if (code.find("lock") != string::npos) {
			if (isLocked) {
				blockQueue.push(id);
				return -1;
			}
			index = 3;
			isLocked = true;
		}
		else if (code.find("end") != string::npos) {
			index = 5;
			isRunCompleted = true;
		}
		return schedule[index];
	}

	void writeCode(string code) {
		codes.push_back(code);
	}

	void run() {
		runTime = 0;
		while (!isRunCompleted && runTime < Q) {
			int time = excute();
			if (time == -1) {
				return;
			}
			runPos++;
			runTime += time;
		}
		if (!isRunCompleted) {
			waitQueue.push_back(id);
		}
	}
};

void start() {
	int id;
	while (!waitQueue.empty()) {
		id = waitQueue.front();
		waitQueue.pop_front();
		programList[id].run();
	}
}

void input() {
	freopen("in2.txt", "r", stdin);
	freopen("out3.txt", "w", stdout);
	int m;
	cin >> m;
	while (getchar() != '\n');
	cout << "\n";
	while (m--) {
		programList.clear();
		vars.clear();
		cin >> n >> schedule[1] >> schedule[2] >> schedule[3] >> schedule[4] >> schedule[5] >> Q;
		while (getchar() != '\n');
		string line;
		for (int i = 0; i < n; i++) {
			Program pm(i);
			while (getline(cin, line)) {
				pm.writeCode(line);
				if (line == "end") {
					break;
				}
			}
			programList[i] = pm;
			waitQueue.push_back(i);
		}

		start();
		if (m > 0)cout << "\n";
	}
}

int main() {

	input();

	system("pause");
	return 0;
}