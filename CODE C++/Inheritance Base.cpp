//--------------------------------//
class Base {
private:
	int k;
public:
	int i;
	void fb() {
	}
};
//--------------------------------//
class Derived: private Base {
private:
	int m;
public:
	using Base::i;
	using Base::fb; 
	void fd() {
	}
};
//------------------------------------------//
int main() {
	Base b;
	Derived d;

	
	b.i = 5;
	b.fb();
	
	d.fb(); //Loi
	d.i = 10; //Loi
	d.fd();
	
	return 0;
}
