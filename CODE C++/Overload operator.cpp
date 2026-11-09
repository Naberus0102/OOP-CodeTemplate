#include<iostream>
using namespace std;
class Point {
	int x, y;
public:
	void setValue(int a, int b) {
		x = a;
		y = b;
	}
	void Print() {
		cout << "x = " << x << ", y = " << y;
	}
	Point operator+(Point para);
	Point operator-(Point para);
	Point operator*(Point para);
	Point operator/(Point para);
	Point operator++(); 	//Tang tien to
	Point operator--(); 	//Giam tien to
	Point operator++(int); 	//Tang hau to
	Point operator--(int); 	//Giam hau to
	void operator=(Point); 	//Toan tu gan
	void operator()();		//Toan tu goi ham
};
Point Point::operator+(Point para) {
	Point tmp;
	tmp.x = x + para.x;
	tmp.y = y + para.y;
	return tmp;
}
Point Point::operator-(Point para) {
	Point tmp;
	tmp.x = x - para.x;
	tmp.y = y - para.y;
	return tmp;
} 
Point Point::operator*(Point para) {
	Point tmp;
	tmp.x = x * para.x;
	tmp.y = y * para.y;
	return tmp;
} 
Point Point::operator/(Point para) {
	Point tmp;
	tmp.x = x / para.x;
	tmp.y = y / para.y;
	return tmp;
}
Point Point::operator++() { //Tang hau to
	x++; y++;
	return *this;
}
Point Point::operator--() { //Giam hau to
	x--; y--;
	return *this;
}
Point Point::operator++(int) { //Tang tien to
	Point temp = *this;
	++*this;
	return temp;	
}
Point Point::operator--(int) {	//Giam tien to
	Point temp = *this;
	--*this;
	return temp;	
}
void Point::operator=(Point para) {
	x = para.x;
	y = para.y;
}
void Point::operator()() {
	cout << "(" << x << "," << y << ")" << endl;
}
int main() {
	Point p1, p2, p3;
	p3 = p1 + p2;	//p3=p1.perator+(p2);
	--p1; 			//p1.operator--(); 
	p1--; 			//p1.operator--(0);
	p2 = p1; 		//p2.operator=(p1);
	p1(); 			//p1.operator();
	return 0;
}
