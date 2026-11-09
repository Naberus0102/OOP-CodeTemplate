#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ========================= CLASS SACH ===============================
class Sach {
private:
    string maSach;
    string tenSach;
    string tacGia;
    int namXB;

public:
    Sach(string ma = "", string ten = "", string tg = "", int nam = 0) {
        maSach = ma;
        tenSach = ten;
        tacGia = tg;
        namXB = nam;
    }

    void nhap() {
        cin.ignore();
        cout << "   Ma sach: ";
        getline(cin, maSach);
        cout << "   Ten sach: ";
        getline(cin, tenSach);
        cout << "   Tac gia: ";
        getline(cin, tacGia);
        cout << "   Nam xuat ban: ";
        cin >> namXB;
    }

    void in() const {
        cout << "      + " << maSach << " | " << tenSach
             << " | TG: " << tacGia
             << " | Nam: " << namXB << endl;
    }
};

// ======================= CLASS SINH VIÊN =============================
class SinhVien {
private:
    string maSV;
    string hoTen;
    string lop;
    string khoa;
    vector<Sach> dsSach;   // t?i da 10 sách

public:
    SinhVien(string ma = "", string ten = "", string lop = "", string khoa = "") {
        this->maSV = ma;
        this->hoTen = ten;
        this->lop = lop;
        this->khoa = khoa;
    }

    void nhap() {
        cin.ignore();
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Lop: ";
        getline(cin, lop);
        cout << "Khoa: ";
        getline(cin, khoa);

        int n;
        do {
            cout << "Nhap so sach da muon (0 - 10): ";
            cin >> n;
        } while (n < 0 || n > 10);

        dsSach.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "  Nhap sach thu " << i + 1 << ":\n";
            dsSach[i].nhap();
        }
    }

    void in() const {
        cout << "\n------------------------------------\n";
        cout << "Ma SV: " << maSV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Lop: " << lop << endl;
        cout << "Khoa: " << khoa << endl;
        cout << "So sach da muon: " << dsSach.size() << endl;

        for (const Sach &s : dsSach)
            s.in();
    }

    int soSachMuon() const {
        return dsSach.size();
    }

    string getHoTen() const {
        return hoTen;
    }

    string getMaSV() const {
        return maSV;
    }
};

// ============================ MAIN =================================
int main() {
    int N;
    cout << "Nhap so sinh vien: ";
    cin >> N;

    vector<SinhVien> dsSV(N);

    // Nh?p danh sách sinh viên
    for (int i = 0; i < N; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---\n";
        dsSV[i].nhap();
    }

    // In danh sách sinh viên
    cout << "\n\n===== DANH SACH SINH VIEN =====\n";
    for (auto &sv : dsSV) {
        sv.in();
    }

    // Tìm sinh viên mu?n nhi?u sách nh?t
    int maxSach = -1;
    for (auto &sv : dsSV)
        if (sv.soSachMuon() > maxSach)
            maxSach = sv.soSachMuon();

    cout << "\n===== SINH VIEN MUON NHIEU SACH NHAT (" << maxSach << " cuon) =====\n";
    for (auto &sv : dsSV)
        if (sv.soSachMuon() == maxSach)
            cout << sv.getMaSV() << " - " << sv.getHoTen() << endl;

    return 0;
}

