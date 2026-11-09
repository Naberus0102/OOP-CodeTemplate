#include<iostream>
using namespace std;
//--------------------------//
class Vector {
	int n;
	float *data;
public:
	Vector() {
		n = 0;
		data = NULL;		
	}
	~Vector() {
		delete []data;
	}
	Vector(int size) {
		n = size;
		data = new float[size];		
	}	
	Vector& operator=(const Vector& v) {
    	if (this == &v)
            return *this;
        if (data != NULL)
            delete[] data;

        n = v.n;
        data = new float[n];
        for (int i=0; i<n; ++i){
    		data[i] = v.data[i];
  		}
  		return *this;
    }    
	void Nhap();/// khoi tao
	void Xuat();
	Vector operator+(Vector&); //v3 = v1 + v2; (v3 = v1.operator+(v2))
	Vector operator*(Vector&);
	float operator[](int);
	float Tinh_tong();
};
void Vector::Nhap() {
	for(int i=0;i<n;i++) {
		cout << "data[" << i << "] = ";
		cin >> data[i];
	}
}
void Vector::Xuat() {
	for(int i=0;i<n;i++) {
		cout << data[i] << "  ";
	}
}
Vector Vector::operator+(Vector& param) {
	Vector tmp(n);
	for(int i=0;i<n;i++)
		tmp.data[i] = data[i] + param.data[i];	
	return tmp; 
}
Vector Vector::operator*(Vector& param) {
	Vector tmp(n);
	for(int i=0;i<n;i++)
		tmp.data[i] = data[i] * param.data[i];	
	return tmp; 
}
float Vector::operator[](int index) {
	if ((index>=0) && (index<n)) {
		return data[index];
	}
	else
		cout << "Khong co gia tri nay";
}
float Vector::Tinh_tong() {
	float Tong = 0.0;
	for(int i=0;i<n;i++)
		Tong = Tong + data[i];
	return Tong;
}
//--------------------------//
int main() {
	Vector v1(3);
	cout << "Nhap vao Vector 1: \n";
	v1.Nhap();
	cout << "Vector 1 vua nhap la: \n";
	v1.Xuat();
	
	cout << endl;
	
	Vector v2(3);
	cout << "Nhap vao Vector 2: \n";
	v2.Nhap();
	cout << "Vector 2 vua nhap la: \n";
	v2.Xuat();
	
	cout << "\nVector 3 la: \n";
	Vector v3(3);
	v3 = v1 * v2;	
	v3.Xuat();
	
	cout << "\nv3[1] = ";
	cout << v3[1];
	cout << "\nTong cua v3 la: " << v3.Tinh_tong();
	return 0;
}
