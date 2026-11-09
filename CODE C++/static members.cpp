// static members in classes
#include <iostream>
using namespace std; 
class CDummy { 
public: 
	static int n; 
 	CDummy () { n++; }; 
 	~CDummy () { n--; }; 
}; 
CDummy::n=0;
int main () { 
 	CDummy a; 
 	CDummy b[5]; 
 	CDummy * c = new CDummy; 
 	cout << c->n << endl; 
 	delete c; 
 	return 0; 
} 
