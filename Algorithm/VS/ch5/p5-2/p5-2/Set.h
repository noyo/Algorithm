#pragma once
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct Set
{
	vector<int> group;
	int size = 0;

	Set() {}

	void add_element(int element) {
		group.push_back(element);
		size++;
	}

	Set get_next() {
		Set next;
		for (int i = 0; i < size; i++) {
			next.group.push_back(abs(group[i] - group[(i + 1) % size]));
		}
		next.size = size;
		return next;
	}

	bool is_empty() {

		for (int i = 0; i < size; i++) {
			if (group[i] != 0) return false;
		}
		return true;
	}
};

bool operator == (const Set &A, const Set &B) {
	vector<int> group_a = A.group;
	vector<int> group_b = B.group;
	int la = A.size;
	int lb = B.size;
	if (la == lb) {
		for (int i = 0; i < la; i++) {
			if (group_a[i] != group_b[i]) {
				return false;
			}
		}
	}
	return la == lb;
}

ostream& operator << (ostream &out, const Set &set) {
	out << "(";
	vector<int> group = set.group;
	for (int i = 0; i < set.size; i++) {
		out << group[i];
		if ((i + 1) != set.size) {
			out << ", ";
		}
	}
	cout << ")";
	return out;
}