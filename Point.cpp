#include<iostream>
using namespace std;
//------------------------//
class Point {
	int x,y;
public:
	Point() {		
		x = 0; y = 0;
	}
	Point(int x1, int y1) {	
		x = x1;
		y = y1;
	}	
	void Move(int,int);
	bool isZero();
	void Print();
	Point operator+(Point);
	Point operator*(Point);
};
void Point::Move(int x1, int y1) {
	x = x1;
	y = y1;
}
bool Point::isZero() {
	return (x==0 && y==0);
}
void Point::Print() {
	cout << "x = " << x << ", y = " << y << endl;
}
Point Point::operator+(Point param) {
	Point tmp;
	tmp.x = x + param.x;
	tmp.y = y + param.y;
	return tmp;	
}
Point Point::operator*(Point param) {
	Point tmp;
	tmp.x = x * param.x;
	tmp.y = y * param.y;
	return tmp;	
}
//------------------------//
int main() {
	Point p1;
	p1.Move(1,2);
	p1.Print();
	
	Point p2;
	p2.Move(3,4);
	p2.Print();
	
	Point p3;	
	//p3=p1+p2;	
	p3=p1.operator+(p2);
	
	p3.Print();
	
	return 0;
}
