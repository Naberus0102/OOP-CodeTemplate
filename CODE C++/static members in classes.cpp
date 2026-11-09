// static members in classes
#include <iostream>
using namespace std;
//------------------------------//
class CDummy {
public:
	int n =0 ;  // Bien cua lop
	CDummy () { n++; };
	~CDummy () { n--; };
};
//------------------------------//
//int CDummy::n=0;
//------------------------------//
int main () {
	CDummy a;
	CDummy b[5];
	CDummy* c = new CDummy;
	cout << a.n << endl;
	delete c;
	cout << a.n << endl;
return 0;
}
