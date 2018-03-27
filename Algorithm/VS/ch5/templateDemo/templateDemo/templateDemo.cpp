#include<iostream>

using namespace std;

template <typename T>
struct Point {
	T x, y;
	Point(T x, T y): x(x), y(y) {
		
	}
};

template <typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B) {
	return Point(A.x = B.x, A.y + B.y);
}

template <typename T>
ostream& operator << (ostream& out, const Point<T>& p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

int main() {
	Point<int> p = Point<int>(1, 2);
	cout << p;

	system("pause");
	return 0;
}