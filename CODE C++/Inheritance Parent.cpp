#include <iostream>
using namespace std;
//-------------------------------------------------//
class Parent {
public: 
	Parent() { 
		cout << endl << "Parent constructor"; 
	}
};
//-------------------------------------------------//
class Child: public Parent {
public: 
	Child() { 
		cout << endl << "Child constructor"; 
	}
};
//-------------------------------------------------//
int main() {
	Child ch; // create a Child object	
	return 0;
}

