#include<iostream>
#include<math.h>
using namespace std;
//------------------------//
class Point {
	int x,y;
public:
	void setValue(int,int);
	void Print();
	static float Do_dai(Point p1, Point p2) {
		return (sqrt(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
	}
};
void Point::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}
void Point::Print() {
	cout << "x = " << x << ", y = " << y << endl;
}
//------------------------//
int main() {
	Point a, b, c;
	a.setValue(1,3);
	a.Print(); 
	b.setValue(9,3);
	b.Print();
	cout << c.Do_dai(a,b);
	return 0;
}
