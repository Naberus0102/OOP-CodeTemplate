#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
private:
    double x, y;   // toa do tam
    double r;      // ban kinh

public:
    // Ham khoi tao mac dinh
    Circle() {
        x = y = 0;
        r = 1;
    }

    // Ham nhap
    void input() {
        cout << "Nhap toa do tam (x y): ";
        cin >> x >> y;
        cout << "Nhap ban kinh r: ";
        cin >> r;
    }

    // Ham xuat
    void output() const {
        cout << "Tam(" << x << ", " << y << "), r = " << r 
             << ", Dien tich = " << area() << endl;
    }

    // Ham tinh dien tich
    double area() const {
        return 3.141592653589793 * r * r;
    }

    // Kiem tra diem (px,py) co nam trong duong tron
    bool containsPoint(double px, double py) const {
        double dist = sqrt((px - x)*(px - x) + (py - y)*(py - y));
        return dist <= r;
    }
};

int main() {
    int n;
    cout << "Nhap so luong hinh tron: ";
    cin >> n;

    vector<Circle> a(n);

    // Nhap mang hinh tron
    cout << "\n=== Nhap thong tin hinh tron ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nHinh tron thu " << i + 1 << ":\n";
        a[i].input();
    }

    // Nhap diem can kiem tra
    double px, py;
    cout << "\nNhap diem can kiem tra (x y): ";
    cin >> px >> py;

    // In ra mang vua nhap
    cout << "\n=== Danh sach cac hinh tron ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Hinh tron " << i + 1 << ": ";
        a[i].output();
    }

    // Sap xep giam dan theo dien tich
    sort(a.begin(), a.end(), [](const Circle &c1, const Circle &c2) {
        return c1.area() > c2.area();
    });

    cout << "\n=== Danh sach sau khi sap xep giam dan dien tich ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Hinh tron " << i + 1 << ": ";
        a[i].output();
    }

    // In ra toi da 10% hinh tron lon nhat khong chua diem da nhap
    int k = max(1, n / 10);  // it nhat 1 phan tu

    cout << "\n=== Toi da " << k << " hinh tron co dien tich lon nhat va KHONG chua diem ===\n";

    int countPrinted = 0;
    for (int i = 0; i < n && countPrinted < k; i++) {
        if (!a[i].containsPoint(px, py)) {
            a[i].output();
            countPrinted++;
        }
    }

    if (countPrinted == 0) {
        cout << "Khong co hinh tron nao thoa man.\n";
    }

    return 0;
}
