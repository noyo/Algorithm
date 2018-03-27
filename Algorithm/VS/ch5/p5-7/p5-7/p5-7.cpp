#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Job
{
	int pri;
	int index;
	Job(int pri, int index): pri(pri), index(index) {}
};

queue<Job> pri_jobs;
vector<int> jobs;

int main() {

	int n;
	cin >> n;
	int pri;
	for (int i = 0; i < n; i++) {
		cin >> pri;
		jobs.push_back(pri);
		pri_jobs.push(Job(pri, i));
	}
	sort(jobs.begin(), jobs.end());

	int time = 0;
	while (!pri_jobs.empty()) {
		int max_pri = jobs[--n];
		time++;
		while (pri_jobs.front().pri < max_pri) {
			pri_jobs.push(pri_jobs.front());
			pri_jobs.pop();
		}
		cout << pri_jobs.front().index << " end_time:"  << time << "\n";
		pri_jobs.pop();
	}

	system("pause");
	return 0;
}