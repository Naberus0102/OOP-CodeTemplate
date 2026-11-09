#include<iostream>
using namespace std;
template <class myType>
myType GetMax(myType a, myType b) {
	return (a>b?a:b);
}
int main() {
	int a, b, c;
	a = 7; b = -9;
	c = GetMax<int>(a,b);
	cout << c;
	cout << endl;
	float x, y, z;
	x = -8.7; y = 9.3;
	z = GetMax<float>(x,y);
	cout << z;	
	return 0;
}

