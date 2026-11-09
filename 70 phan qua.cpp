#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------------- Lop Mat Hang ----------------------
class MatHang {
private:
    string ten;
    double dongia;
    int soluong;

public:
    MatHang() {}
    MatHang(string ten, double dongia, int soluong) {
        this->ten = ten;
        this->dongia = dongia;
        this->soluong = soluong;
    }

    double thanhTien() const {
        return dongia * soluong;
    }

    void xuat() const {
        cout << "   - " << ten 
             << " | Don gia: " << dongia
             << " | SL: " << soluong
             << " | Thanh tien: " << thanhTien() << endl;
    }
};

// ---------------------- Lop Khach Hang ----------------------
class KhachHang {
private:
    string ten;
    vector<MatHang> dsHang;

public:
    KhachHang() {}
    KhachHang(string ten) {
        this->ten = ten;
    }

    void themHang(const MatHang &mh) {
        dsHang.push_back(mh);
    }

    double tongTien() const {
        double sum = 0;
        for (auto &mh : dsHang)
            sum += mh.thanhTien();
        return sum;
    }

    bool duocTangQua() const {
        return tongTien() >= 1000000;
    }

    void xuat() const {
        cout << "\nKhach hang: " << ten << endl;
        cout << "Danh sach mat hang:\n";
        for (auto &mh : dsHang)
            mh.xuat();
        cout << "==> Tong tien: " << tongTien() << endl;
    }

    string getTen() const { return ten; }
};

// ---------------------- Hàm main ----------------------
int main() {
    int N;
    cout << "Nhap so khach hang: ";
    cin >> N;

    vector<KhachHang> dsKH;
    dsKH.reserve(N);

    for (int i = 0; i < N; i++) {
        cin.ignore();
        string tenKH;
        cout << "\nNhap ten khach hang thu " << i + 1 << ": ";
        getline(cin, tenKH);

        KhachHang kh(tenKH);

        int M;
        cout << "Nhap so mat hang da mua: ";
        cin >> M;

        for (int j = 0; j < M; j++) {
            cin.ignore();
            string tenMH;
            double gia;
            int sl;

            cout << "  + Ten mat hang: ";
            getline(cin, tenMH);
            cout << "  + Don gia: ";
            cin >> gia;
            cout << "  + So luong: ";
            cin >> sl;

            kh.themHang(MatHang(tenMH, gia, sl));
        }

        dsKH.push_back(kh);
    }

    // ------------------ Xuat danh sach khach hang ------------------
    cout << "\n\n===== DANH SACH KHACH HANG =====\n";
    for (auto &kh : dsKH)
        kh.xuat();

    // ------------------ Danh sach khach duoc tang qua ------------------
    cout << "\n===== DANH SACH KHACH HANG DUOC TANG QUA =====\n";
    int soQua = 70;

    for (auto &kh : dsKH) {
        if (kh.duocTangQua() && soQua > 0) {
            cout << "- " << kh.getTen() << " (Tong tien: " << kh.tongTien() << ")\n";
            soQua--;
        }
    }

    if (soQua == 70)
        cout << "Khong co khach hang nao dat muc tang qua.\n";
    else
        cout << "\nSo qua con lai: " << soQua << endl;

    return 0;
}

