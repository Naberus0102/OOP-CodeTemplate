#include<iostream>
using namespace std;
//----------------------------//
class Matrix {
	int **data;
public:	
	// Constructor mac dinh (Cau tu mac dinh)
	Matrix();
	
	// Destructor (Huy tu - Cau tu huy)
	~Matrix();	
	
	// Constructor sao chep (copy constructor)
    Matrix(const Matrix&);    
    
	// Toan tu gan operator=
	Matrix& operator=(const Matrix&);
    
	// Ham tinh dinh thuc
    int det();
	
	//Ham toan tu chi so ([][])
	int operator()(int i, int j);
		
	// Tang dang tien to
	void operator++();	
	
	//Tang dang hau to
	Matrix operator++(int);
	
	// Ham nhap		
	void Nhap();
	
	// Ham xuat
	void Xuat();
	
	// Ham toan tu nhap >>
	friend istream& operator>>(istream&, Matrix&);
	
	// Ham toan tu xuat <<
	friend ostream& operator<<(ostream&, Matrix&);
	
	//Ham toan tu cong hai ma tran
	Matrix operator+(Matrix&);
};
//----------------------------//
// Constructor mac dinh (Cau tu mac dinh)
Matrix::Matrix() {
	data = new int*[2];
    	for (int i = 0; i < 2; i++)
			data[i] = new int[2] {0, 0};
}
//----------------------------//
// Destructor (Huy tu - Cau tu huy)
Matrix::~Matrix() {
	for(int i=0; i<2; i++)
		delete data[i];
	delete data;
}
//----------------------------//	
// Constructor sao chep (copy constructor)
Matrix::Matrix(const Matrix& m) {
data = new int*[2];
	for (int i = 0; i < 2; i++) {
		data[i] = new int[2];
        for (int j = 0; j < 2; j++)
        	data[i][j] = m.data[i][j];
    }
}
//----------------------------// 
// Toan tu gán operator=
Matrix& Matrix::operator=(const Matrix& m) {       
    // Bao ve tu gan
    if (this == &m)
    	return *this;

    // Xoa du lieu cu
    for (int i = 0; i < 2; i++)
        delete[] data[i];
    delete[] data;

    // Cap phat lai
    data = new int*[2];
    for (int i = 0; i < 2; i++) {
        data[i] = new int[2];
        for (int j = 0; j < 2; j++)
            data[i][j] = m.data[i][j];
    }
    return *this;
}
//----------------------------//
// Ham tinh dinh thuc
int Matrix::det() {
	return (data[0][0]*data[1][1] - data[1][0]*data[0][1]);
}
//----------------------------//
//Ham toan tu chi so ([][])
int Matrix::operator()(int i, int j) {
	if (i >= 2 || j >= 2) {
		cout << "Khong co gia tri nay";
		exit(0);	
	}
	else
		return data[i][j];
}
//----------------------------//
// Tang dang tien to
void Matrix::operator++() {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			data[i][j] = ++data[i][j];
		}
	}		
}
//----------------------------//	
//Tang dang hau to
Matrix Matrix::operator++(int) {
	Matrix T;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				T.data[i][j] = data[i][j]++;
			}
		}
	return T;
}	
//----------------------------//
void Matrix::Nhap() {
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++) {
			cout << "data[" << i << "][" << j <<"] = ";
			cin >> data[i][j];
		}			
}
//----------------------------//
istream& operator>>(istream& is, Matrix& m) {
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++) {
			cout << "data[" << i << "][" << j <<"] = ";
			is >> m.data[i][j];
		}
	return is;			
}
//----------------------------//
void Matrix::Xuat() {
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) 
			cout << data[i][j] << "  ";
		cout << endl;					
	}		
}
//----------------------------//
ostream& operator<<(ostream& os, Matrix& m) {
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) 
			os << m.data[i][j] << "  ";
		os << endl;					
	}	
	return os;
}
//----------------------------//
Matrix Matrix::operator+(Matrix& m) {
	Matrix T;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++) 
			T.data[i][j] = data[i][j] + m.data[i][j];
	return T;	
}
//----------------------------//
int main() {
	Matrix m1;
	cin >> m1;
	cout << m1;
	
	cout << endl;
	Matrix m2;
	cin >> m2;
	cout << m2;
	
	cout << endl;
	Matrix m3; 
	m3 = m1 + m2;
	cout << m3;
	
	cout << endl;
	m3++;
	cout << m3;
	
	cout << endl;
	cout << m3(0,1); //Goi ham toan tu chi so
	
	return 0;
}
