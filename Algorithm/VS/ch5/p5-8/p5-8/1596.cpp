#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

struct Book
{
	string author;
	string name;
	int state = 2;

	Book() {}

	Book(string author, string name, int state): author(author), name(name), state(state) {}

	bool operator < (const Book &book) {
		if (name == book.name) {
			return name < book.name;
		}
		return author < book.author;
	}
};

vector<Book> books;
map<string, Book> lib;

int main() {

	freopen("data.txt", "r", stdin);
	string line;
	while (getline(cin, line)) {
		if (line == "END") break;
		stringstream ss(line);
		string author, name;
		ss >> author >> name;
		cout << name << " ";
		books.push_back(Book(author, name, 2));
	}
	cout << "\n";

	sort(books.begin(), books.end());

	for (vector<Book>::iterator it = books.begin(); it != books.end(); it++) {
		lib[(*it).name] = *it;
	}
	while (getline(cin, line)) {
		if (line == "END") break;
		char cmd;
		string name;
		stringstream ss(line);
		ss >> cmd >> name;
		if (!lib.count(name)) {
			cout << "ERROR book name!" << "\n";
			continue;
		}
		if (cmd == 'B') {
			lib[name].state = 0;
		}
		else if (cmd == 'R') {
			lib[name].state = 1;
		}
		else if (cmd == 'S') {
			int i = 0;
			for (map<string, Book>::iterator it = lib.begin(); it->first != name; it++){
				if (it->second.state == 2) i++;
			}
			lib[name].state = 2;
			cout << i << ": " << name << "\n";
		}
	}

	system("pause");
	return 0;
}