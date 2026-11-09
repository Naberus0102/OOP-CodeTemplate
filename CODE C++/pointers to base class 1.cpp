#include<iostream>
using namespace std;
//------------------------------//
class Base {
	int x;
public:
	void setValue(int a) {
		x = a;
	}
	void Print() {
		cout << "Bien x cua lop Co so: " << x;
	}
};
//------------------------------//
class Derived : public Base {
	int y;
public:
	void setValue(int b) {
		y = b;
	}
	void Print() {
		cout << "Bien y cua lop Dan xuat: " << y;
	}
};
//------------------------------//
int main() {
	Base b;
	b.setValue(10);
	
	Derived d;
	d.setValue(20);
	
	Base *ptr;
	char chon;

	cout << "Lop Base (b) hay lop Derived (d): "; cin >> chon;
	if (chon == 'b')
		ptr = &b;
	else
		ptr = &d;
		
	ptr->Print();	//Ham print nao se duoc goi
	
	return 0;
}
