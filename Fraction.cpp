#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;

    // Ham rut gon phan so
    void rutGon() {
        int a = abs(tu), b = abs(mau);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        int gcd = a;
        tu /= gcd;
        mau /= gcd;
        if (mau < 0) { // chuan hoa mau duong
            tu = -tu;
            mau = -mau;
        }
    }

public:
    PhanSo(int t = 0, int m = 1) {
        tu = t;
        mau = (m == 0 ? 1 : m);
        rutGon();
    }

    // Nhap phan so
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) mau = 1;
        rutGon();
    }

    // Xuat phan so
    void xuat() const {
        if (mau == 1) cout << tu;
        else cout << tu << "/" << mau;
    }

    // Toan tu cong
    PhanSo operator+(const PhanSo& ps) const {
        PhanSo kq(tu * ps.mau + ps.tu * mau, mau * ps.mau);
        return kq;
    }

    // Toan tu tru
    PhanSo operator-(const PhanSo& ps) const {
        PhanSo kq(tu * ps.mau - ps.tu * mau, mau * ps.mau);
        return kq;
    }

    // Toan tu nhan
    PhanSo operator*(const PhanSo& ps) const {
        PhanSo kq(tu * ps.tu, mau * ps.mau);
        return kq;
    }

    // Toan tu chia
    PhanSo operator/(const PhanSo& ps) const {
        PhanSo kq(tu * ps.mau, mau * ps.tu);
        return kq;
    }

    // So sanh hai phan so
    bool operator<(const PhanSo& ps) const {
        return (long long)tu * ps.mau < (long long)ps.tu * mau;
    }

    bool operator>(const PhanSo& ps) const {
        return (long long)tu * ps.mau > (long long)ps.tu * mau;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    PhanSo a[n];

    // Nhap mang phan so
    for (int i = 0; i < n; i++) {
        cout << "\nNhap phan so thu " << i + 1 << ":\n";
        a[i].nhap();
    }

    // Tinh tong
    PhanSo tong(0, 1);
    for (int i = 0; i < n; i++)
        tong = tong + a[i];

    cout << "\nTong cac phan so: ";
    tong.xuat();
    cout << endl;

    // Tim min và max
    PhanSo maxPS = a[0], minPS = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxPS) maxPS = a[i];
        if (a[i] < minPS) minPS = a[i];
    }

    cout << "Phan so lon nhat: ";
    maxPS.xuat();
    cout << "\nPhan so nho nhat: ";
    minPS.xuat();
    cout << endl;

    return 0;
}

