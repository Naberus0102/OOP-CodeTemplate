//---------------------------------//
class Gparent {
public:
	int gData;
};
//---------------------------------//
class Mother: public Gparent {
};
//---------------------------------//
class Father: public Gparent {
};
//---------------------------------//
class Child: public Mother, public Father {
public:
	void cFunc() {
		gData = 10;
	}
};
//---------------------------------//
int main() {
	Child ch;
	ch.cFunc();	
}
