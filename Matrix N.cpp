#include<iostream>
using namespace std;
//++++++++++++++++++++++++++++//
class Matrix {
	int data[255][255];
	int N;
public:
	Matrix(int n) {
		N = n;
	}
	~Matrix() {	
	}
	friend istream& operator >> (istream& is, Matrix& m);
	friend ostream& operator << (ostream& os, Matrix& m);
	void Nhap();
	void Xuat();
	Matrix operator+ (Matrix& m) {
		Matrix T(N);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				T.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return T;
	}
	int operator() (int i, int j) {
		if (i >= N || j >= N) {
			cout << "Khong co gia tri nay";
			exit(0);	
		}
		else
			return data[i][j];
	}
	// Tang dang tien to
	void operator++() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				data[i][j] = ++data[i][j];
			}
		}		
	}
	//Tang dang hau to
	Matrix operator++(int) {
		Matrix T(N);
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					T.data[i][j] = data[i][j]++;
				}
			}
		return T;
	}		
};
//++++++++++++++++++++++++++++//
void Matrix::Nhap() {
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j <<"] = ";
			cin >> data[i][j];
		}
}
//---------------------------------------//
void Matrix::Xuat() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout  << data[i][j] << " ";
		cout << endl;
	}
}
//---------------------------------------//
istream& operator>> (istream& is, Matrix& m) {
	for(int i = 0; i < m.N; i++)
		for(int j = 0; j < m.N; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j <<"] = ";
			is >> m.data[i][j];
		}
}
ostream& operator<< (ostream& os, Matrix& m) {
	for(int i = 0; i < m.N; i++) {
		for(int j = 0; j < m.N; j++)
			os  << m.data[i][j] << " ";
			os << endl;
	}
}
//---------------------------------------//
int main() {
	Matrix m1(3), m2(3);
	m1.Nhap();
	m1.Xuat();
	
	m2.Nhap();
	m2.Xuat();
	cout <<"m3 = m1 + m2:\n";
	Matrix m3 = m1 + m2;
	cout << m3;
	cout << m1(2,1);
	cout << endl;
	m3++;
	cout << m3; 
	return 0;
}
