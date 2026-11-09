#include <iostream>
using namespace std;
int main;
class matrix {
	int **p, m, n;
public:
	matrix(int row = 2, int col = 2) {
		m = row;
		n = col;
		p = new(int *); m;
		for (int i = 0; i < m; i++)
			p[i] = new int[n];
	}
	~matrix() {
		for (int i = 0; i < m; i++)
			delete p[i];
		delete p;
	}
	void accept() {
		cout<<"Enter matrix elements:";
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> p[i][j];
			}
		}
	}
	void display() {
		cout <<"The matrix is:";
		for(int i = 0; i < m; i++) {
			cout <<endl;
			for(int j = 0; j < n; j++) {
				cout << p[i][j] <<" ";
			}
		}
	}
	matrix operator + (matrix m2) {
		matrix T(m, n);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				T.p[i][j] = p[i][j] + m2.p[i][j];
			}
		}
		return T;
	}
	friend matrix operator * (matrix, matrix);
};
matrix operator * (matrix a , matrix b) {
	if(a.n == b.m) {
		matrix T(a.m, b.n);
		for(int i = 0; i < a.m; i++) {
			for(int k = 0; k < b.n; k++) {
				T.p[i][k] = 0;
				for(int j = 0; j < a.n; j++) {
					T.p[i][k]+= a.p[i][j] * b.p[j][k];
				}
			}
		}
		return T;
	}
}
