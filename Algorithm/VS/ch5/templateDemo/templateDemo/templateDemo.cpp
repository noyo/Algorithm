#include<iostream>

using namespace std;

template <typename T>

struct Point {
	T x, y;
	Point(T x, T y): x(x), y(y) {
		
	}
};

int main() {
	Point<int> p = Point<int>(1, 2);
	cout << p.x << " " << p.y << endl;

	system("pause");
	return 0;
}