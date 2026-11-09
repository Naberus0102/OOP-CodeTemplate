#include <iostream>
using namespace std;
class Vector {
	int size;     
    float *data; 
public:
//---------------------------------//
    Vector(int N) {
         size = N;
         data = new float[N];         
    }
//---------------------------------//    
    ~Vector() {
        delete[] data;
    }
//---------------------------------//
    void Nhap() {
    	for(int i=0; i<size; i++) {
			cout << "V[" << i << "]=";
			cin >> data[i];	
		}		
    }
//---------------------------------//    
    void Xuat() {
        for(int i=0; i<size; i++) {
			cout << data[i] << "  ";
    	}
	}
//---------------------------------//    
    Vector(const Vector& v) {
        size = v.size;
        data = new float[size];
        for (int i = 0; i < size; ++i){
    		data[i] = v.data[i];
  		}
    }
//---------------------------------//    
    Vector& operator=(const Vector& v) {
        if (this == &v)
            return *this;
        if (data != NULL)
            delete[] data;

        size = v.size;
        data = new float[size];
        for (int i=0; i<size; ++i){
    		data[i] = v.data[i];
  		}
  		return *this;
    }
//---------------------------------//      
    Vector operator+(const Vector &v) {
    	Vector tmp(size);    	
		for (int i=0; i<size; i++){
    		tmp.data[i] = data[i] + v.data[i];
  		}  		
		return tmp;    	
	}
//---------------------------------//      
    Vector operator*(const Vector &v) {
    	Vector tmp(size);    	
		for (int i=0; i<size; i++){
    		tmp.data[i] = data[i] * v.data[i];
  		}  		
		return tmp;    	
	}
//---------------------------------//
	float operator[](int index) {
		if(index >= size) {
			cout << "Khong co phan tu nay";
			exit (0);
		}
		else
			return data[index];
	}
};
//---------------------------------//
int main() {
	int n;
	cout << "Nhap vao so phan tu: ";
	cin >> n;
	
	Vector v1(n);
	v1.Nhap();
	v1.Xuat();
	
	cout << endl;
	
	Vector v2(n);
	v2.Nhap();
	v2.Xuat();
	
	Vector v3(n);
	v3 = v1 + v2;
	cout << endl;
	v3.Xuat();
	
	cout << endl;
	cout << v3[2];
	
	return 0;	
}
//---------------------------------//
