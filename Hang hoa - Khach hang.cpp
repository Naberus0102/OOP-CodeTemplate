#include<iostream>
#include<cstring>
using namespace std;
//---------------------------------//
class Mat_hang {
	int 	Ma_hang;
	char 	Ten_hang[30];
	float 	Gia_ban;
public:
	friend istream& operator>>(istream& is, Mat_hang &h);
	friend ostream& operator<<(ostream& os, Mat_hang &h);
	float Tien() {
		return Gia_ban;
	}
};
istream& operator>>(istream& is, Mat_hang &h) {
	cout << "Ma hang: "; is >> h.Ma_hang;
	cout << "Ten hang: "; is.ignore(); is.get(h.Ten_hang,30);
	cout << "Gia ban: "; is >> h.Gia_ban;
	return is;
}
ostream& operator<<(ostream& os, Mat_hang &h) {
	cout << "Ma hang: " << h.Ma_hang << endl;
	cout << "Ten hang: "<< h.Ten_hang << endl;
	cout << "Gia ban: " << h.Gia_ban << endl;
	return os;
}
//---------------------------------//
class Khach_hang {
	int 		Ma_khach_hang;
	char 		Ten_khach_hang[30];
	int 		So_luong;
 	Mat_hang 	Hang[20];
public:
	friend istream& operator>>(istream& is, Khach_hang &k);
	friend ostream& operator<<(ostream& os, Khach_hang &k);
	float Tong_tien(Khach_hang &k) {
		float Tong = 0;
		for(int i=0;i<k.So_luong;i++)
			Tong = Tong + k.Hang[i].Tien();		
		return Tong;
	}	
};
istream& operator>>(istream& is, Khach_hang &k) {
	cout << "Ma khach hang: "; is >> k.Ma_khach_hang;
	cout << "Ten khach hang: "; is.ignore(); is.get(k.Ten_khach_hang,30);	
	cout << "Nhap so luong hang mua: "; is >> k.So_luong;
	for(int i=0;i<k.So_luong;i++) {
		cout << "Hang thu " << i+1 << ":\n";
		is >> k.Hang[i];
	}		
	return is;
}
ostream& operator<<(ostream& os, Khach_hang &k) {
	os << "Ma khach hang: " << k.Ma_khach_hang << endl;
	os << "Ten khach hang: " << k.Ten_khach_hang << endl;	
	os << "So luong hang mua: "; os << k.So_luong;
	for(int i=0;i<k.So_luong;i++) {
		cout << "\nHang thu " << i+1 << ":\n";
		os << k.Hang[i];
	}
	return os;
}
//---------------------------------//
int main() {
	Khach_hang KH[50];
	int So_luong;
	cout << "Nhap so luong khach hang: "; cin >> So_luong;
	for(int i=0;i<So_luong;i++) {
		cout << "\nThong tin khach hang thu " << i+1 << ":\n";
		cin >> KH[i];
	}
	cout << "\n******************************";
	for(int i=0;i<So_luong;i++) {
		cout << "\nThong tin khach hang thu " << i+1 << ":\n";
		cout << KH[i];
		cout << "Tong tien: " << KH[i].Tong_tien(KH[i]) << endl;
	}
	float Max = 0;
	int j = 0;
	for(int i=0;i<So_luong;i++) {
		if (Max < KH[i].Tong_tien(KH[i])) {
			Max = KH[i].Tong_tien(KH[i]);
			j = i;
		}				
	}
	cout << "\nKHACH HANG CO TONG TIEN LON NHAT\n";
	cout << KH[j];
	
	return 0;
}
