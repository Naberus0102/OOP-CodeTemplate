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
	Point operator+(Point);
	Point operator-(Point);
	Point operator*(Point);
	Point operator/(Point);
	void operator=(Point); 	//Toan tu gan
	void operator()();		//Toan tu goi ham
	void operator++();		//Toan tu tang tien to
	void operator--();		//Toan tu giam tien to
	Point operator++(int);	//Toan tu tang hau to
	Point operator--(int);	//Toan tu giam hau to	
	friend istream& operator>> (istream&, Point&);
	friend ostream& operator<< (ostream&, Point&);
};
//--------------------------------------//
Point Point::operator+(Point param) {
	Point temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}
//--------------------------------------//
Point Point::operator-(Point param) {
	Point temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}
//--------------------------------------//
Point Point::operator*(Point param) {
	Point temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	return temp;
}
//--------------------------------------//
Point Point::operator/(Point param) {
	Point temp;
	temp.x = x / param.x;
	temp.y = y / param.y;
	return temp;
}
//--------------------------------------//
void Point::operator=(Point param) {
	x = param.x;
	y = param.y;	
}
//--------------------------------------//
void Point::operator()() {	
	cout << "(" << x << ", " << y << ")"; 
}
//--------------------------------------//
void Point::operator++() {
	x++; 
	y++;
}
//--------------------------------------//
void Point::operator--() {
	--x; 
	--y;
}
//--------------------------------------//
Point Point::operator++(int) {
	Point temp = *this; //Luu giu gia tri ban dau
	++*this;
	return temp;
}
//--------------------------------------//
Point Point::operator--(int) {
	Point temp = *this; //Luu giu gia tri ban dau
	--*this;
	return temp;
}
//--------------------------------------//
istream& operator>> (istream& is, Point& param) {
	cout << "x = ";
	cin >> param.x;
	cout << "y = ";
	cin >> param.y;
	return is;
}
//--------------------------------------//
ostream& operator<< (ostream& os, Point& param) {
	cout << "x = " << param.x << endl;
	cout << "y = " << param.y;	
	return os;
}
//--------------------------------------//
int main() {
	Point p1, p2, p3;
	p1.setValue(3,4);
	p2.setValue(5,6);
	p3 = p1 + p2; 	//p3 = p1.operator+(p2);
	Point p4 = p3; 	//p4.operator=(p3); 
	--p4;			//p4.operator--(); 
	p4();			//p4.operator();
	p4++;
	p4();
	cout << endl;
	Point p5;
	cin >> p5;
	cout << p5;
	return 0;
}
