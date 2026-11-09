#include<iostream>
using namespace std;
class Point {
private:
	int x, y;
public:
	void Move(int,int);
	void Print() {
		cout << "x = " << x << ", y = " << y;
	}
	bool isZero();	
};
void Point::Move(int a,int b) {
	x = a;
	y = b;
}
int main() {
	Point p1; 		//p1 la object cua class Point
	p1.Move(4,6);
	p1.Print();
	return 0;
}
