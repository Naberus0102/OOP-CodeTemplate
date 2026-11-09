// class templates
#include <iostream>
using namespace std;
//++++++++++++++++++++++++++//
template <class T> 
class Mypair { 
	T a, b; 
public: 
	Mypair (T first, T second) {
		a = first; b = second;
	} 
 	T getmax(); 
};
//++++++++++++++++++++++++++//
template <class T>
T Mypair<T>::getmax() { 
	T retval; 
	retval = (a>b)?a:b; 
	return retval; 
}
//++++++++++++++++++++++++++//
int main () { 
 Mypair<int> myobject(100, 75); 
 cout << myobject.getmax();
 
 cout << endl;
 
 Mypair<float> object_f(63.252, -636.75); 
 cout << object_f.getmax(); 
 
 return 0; 
} 
