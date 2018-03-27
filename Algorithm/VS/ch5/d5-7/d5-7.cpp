#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

typedef long long LL;

priority_queue<LL, vector<LL> > pq;

int main() {

	pq.push(2);
	pq.push(3);
	pq.push(7);
	pq.push(4);
	pq.push(6);
	pq.push(5);
	pq.push(1);
	pq.push(9);

	system("pause");
	return 0;
}