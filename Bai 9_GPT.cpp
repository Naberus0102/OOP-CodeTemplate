#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class NhanVien {
protected:
    string hoten;
    float hesoLuong;
    float phuCap;

public:
    NhanVien() : hoten(""), hesoLuong(0), phuCap(0) {}

    virtual void nhap() {
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, hoten);
        cout << "Nhap he so luong: "; cin >> hesoLuong;
        cout << "Nhap phu cap: "; cin >> phuCap;
    }

    virtual void xuat() {
        cout << left << setw(20) << hoten  << setw(10) << hesoLuong
             << setw(10) << phuCap << setw(15) << tinhLuong();
    }

    virtual float tinhLuong() {
        return hesoLuong * 2340 + phuCap;
    }

    float getHeSoLuong() const { return hesoLuong; }
    float getThuNhap() { return tinhLuong(); }
};

class CanBo : public NhanVien {
private:
    float hesoChucVu;

public:
    CanBo() : NhanVien(), hesoChucVu(0) {}

    void nhap() override {
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, hoten);
        cout << "Nhap he so luong: "; cin >> hesoLuong;
        cout << "Nhap he so chuc vu: "; cin >> hesoChucVu;
        cout << "Nhap phu cap: "; cin >> phuCap;
    }

    void xuat() override {
        cout << left << setw(20) << hoten << setw(10) << hesoLuong
             << setw(10) << phuCap << setw(10) << hesoChucVu
             << setw(15) << tinhLuong();
    }

    float tinhLuong() override {
        return (hesoLuong + hesoChucVu) * 2340 + phuCap;
    }
};
int main() {
    int n;
    cout << "Nhap so luong nhan vien / can bo: ";
    cin >> n;

    vector<NhanVien*> ds;

    for (int i = 0; i < n; i++) {
        cout << "\n1. Nhan vien\n2. Can bo\nChon loai (1/2): ";
        int loai;
        cin >> loai;

        NhanVien* p;

        if (loai == 1) {
            p = new NhanVien();
        } else {
            p = new CanBo();
        }

        p->nhap();
        ds.push_back(p);
    }

    // ====================== In danh sach ======================
    cout << "\n===== DANH SACH NHAN VIEN - CAN BO =====\n";
    cout << left << setw(20) << "Ho ten"
         << setw(10) << "He so"
         << setw(10) << "Phu cap"
         << setw(10) << "CV"
         << setw(15) << "Luong" << endl;

    for (auto p : ds)
        p->xuat();

    // ====================== Loc tro cap kho khan ======================
    cout << "\n\n===== DANH SACH TRO CAP KHO KHAN =====\n";

    vector<NhanVien*> tro_cap;

    // loc nhan vien thuong co hesoLuong < 3.0
    for (auto p : ds) {
        if (dynamic_cast<CanBo*>(p) == nullptr) {  // chi nhan vien
            if (p->getHeSoLuong() < 3.0)
                tro_cap.push_back(p);
        }
    }

    // sap xep theo thu nhap thap nhat
    sort(tro_cap.begin(), tro_cap.end(),
        [](NhanVien* a, NhanVien* b) {
            return a->tinhLuong() < b->tinhLuong();
        }
    );

    // lay toi da 10%
    int so_luong = max(1, (int)(tro_cap.size() * 0.1));

    for (int i = 0; i < so_luong; i++)
        tro_cap[i]->xuat();

    // Giai phong bo nho
    for (auto p : ds) delete p;

    return 0;
}

