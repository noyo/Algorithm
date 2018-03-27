#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Player 
{
	string name;
	bool isAmateur = false;
	vector<int> score;
	bool is_DQ = false;
	int total_score[2] = {0};
	int rank = 100, real_rank = 100;
	float bonus = 0.0;

	Player() {}
	Player(string name, bool isAmateur): name(name), isAmateur(isAmateur) {}

	bool static comparator(const Player &A, const Player &B) {
		return A.total_score[0] > B.total_score[0];
	}

	bool operator < (const Player& A) const {
		return total_score[1] > A.total_score[1];
	}

	void set_score(int score) {
		this->score.push_back(score);
	}

	void set_name(string name) {
		if (this->name.length() > 0) {
			this->name += " ";
		}
		this->name += name;
	}

	void total() {
		int i = 0;
		int num = score.size();
		for (; i < 2 && i < num; i++) total_score[0] += score[i];
		total_score[1] = total_score[0];
		for (i = 2; i < num; i++) total_score[1] += score[i];
	}

};