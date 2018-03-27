#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

set<string> dict;

int main() {

	string s, buf;
	cin >> s;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			else s[i] = ' ';
		}
		stringstream(s);
		while (s >> buf) dict.insert(buf);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
		cout << *it << "----";
	}


	system("pause");
	return 0;
}