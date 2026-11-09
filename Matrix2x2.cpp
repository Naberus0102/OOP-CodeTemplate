#include <iostream>
using namespace std;
//----------------------------------//
class Matrix2x2 {
private:
    int** a;    // ma tran cap phat dong 2x2

public:
    // Constructor mac dinh
    Matrix2x2() {
        a = new int*[2];
        for (int i = 0; i < 2; i++)
            a[i] = new int[2];
    }
//----------------------------------//
    // Constructor sao chép (copy constructor)
    Matrix2x2(const Matrix2x2& other) {
        a = new int*[2];
        for (int i = 0; i < 2; i++) {
            a[i] = new int[2];
            for (int j = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
        }
    }
//----------------------------------//
    // Toan tu gán operator=
    Matrix2x2& operator=(const Matrix2x2& other) {
        // Bao ve tu gan
        if (this == &other)
            return *this;

        // Xoa du lieu cu
        for (int i = 0; i < 2; i++)
            delete[] a[i];
        delete[] a;

        // Cap phat lai
        a = new int*[2];
        for (int i = 0; i < 2; i++) {
            a[i] = new int[2];
            for (int j = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
        }

        return *this;
    }
//----------------------------------//
    // Destructor
    ~Matrix2x2() {
        for (int i = 0; i < 2; i++)
            delete[] a[i];
        delete[] a;
    }
//----------------------------------//
    // Ham nhap
    void input() {
        cout << "Nhap ma tran 2x2:\n";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> a[i][j];
    }
//----------------------------------//
    // Ham xuat
    void output() {
        cout << "Ma tran:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
//----------------------------------//
};
int main() {
	return 0;
}

