#pragma warning(disable:4996)
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
#include "Player.h"

using namespace std;

int player_n;
vector<Player> players;
map<int, vector<Player> > rank_list;
int pros;//晋级人数

float bonuss[] = { 0.4, 0.3, 0.2, 0.1 };

int str2digit(string num) {
	int l = num.length();
	int digit = 0;
	for (int i = 0; i < l; i++) {
		if (num[i] < '0' || num[i] > '9') {
			return -1;
		}
		digit = digit * 10 + (num[i] - '0');
	}
	return digit;
}

void init() {
	freopen("data.txt", "r", stdin);
	string data;
	getline(cin, data);
	player_n = str2digit(data);
	while (getline(cin, data))
	{
		string s;
		Player pr;
		stringstream ss(data);
		while (ss >> s) {
			int digit = str2digit(s);
			if (digit != -1) {
				pr.set_score(digit);
			}
			else if (s == "DQ") {
				pr.is_DQ = true;
				break;
			}
			else {
				pr.set_name(s);
			}
		}
		pr.total();
		if (pr.name.length() > 0 && pr.name[pr.name.length() - 1] == '*') pr.isAmateur = true;
		players.push_back(pr);
	}
}

void get_advancer() {
	int rank;
	for (int i = 0; i < 5; rank = i) {
		int score = players[i].total_score[0];
		rank = i + 1;
		while(players[i].total_score[0] == score) {
			players[i++].rank = rank;
		}
	}
}

void get_rank() {
	int rank;
	int	pro_players = 0;
	for (int i = 0; i < 5;) {
		int score = players[i].total_score[1];
		rank = pro_players + 1;
		while (players[i].total_score[1] == score) {
			if (!players[i].isAmateur) {
				players[i].real_rank = rank;
				pro_players++;
				rank_list[rank].push_back(players[i]);
			}
			i++;
		}
	}
}

void get_bonus() {
	for (map<int, vector<Player> >::iterator it = rank_list.begin(); it != rank_list.end(); it++) {
		vector<Player> ps = it->second;
		int rank = it->first - 1;
		float bon = 0;
		int l = 0;
		for (int i = 0; i < ps.size(); i++) {
			bon += bonuss[rank++];
		}
		bon /= ps.size();
		for (vector<Player>::iterator player = ps.begin(); player != ps.end(); player++) {
			player->bonus = bon;
		}
		rank_list[it->first] = ps;
	}
}

int main() {
	init();

	sort(players.begin(), players.end(), Player::comparator);

	get_advancer();

	sort(players.begin(), players.end());

	get_rank();

	get_bonus();

	for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
		cout << "name: " << it->name << ", rank: " << it->real_rank << ", bonus: " << it->bonus << ", total: " << it->total_score[1] << "\n";
	}

	for (map<int, vector<Player> >::iterator it1 = rank_list.begin(); it1 != rank_list.end(); it1++) {
		vector<Player> players = it1->second;
		for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
			cout << "name: " << it->name << ", rank: " << it->real_rank << ", bonus: " << it->bonus << ", total: " << it->total_score[1] << "\n";
		}
	}

	system("pause");
	return 0;
}