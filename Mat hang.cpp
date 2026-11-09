#include<iostream>
using namespace std;
//++++++++++++++++++++++++++++//
class Mat_hang {
	char Ten[30];
	int Ma;
	float Gia_ban;
public:
	Mat_hang() {
	}
	void Nhap() {
		cout << "Ten hang: "; cin.ignore(); cin.get(Ten,30);
		cout << "Ma hang: "; cin >> Ma;
		cout << "Gia ban: "; cin >> Gia_ban;
	}
	void Xuat() {
		cout << "Ten hang: " << Ten << endl;
		cout << "Ma hang: " << Ma << endl;
		cout << "Gia ban: " << Gia_ban << endl;
	}
};
//++++++++++++++++++++++++++++//
class Khach_hang {
	char TenKH[30];
	int Ma;
	int SL;
	Mat_hang Arr[20];
public:
	Khach_hang() {
	}
	void Nhap() {
		cout << "Ten khach hang: "; cin.ignore(); cin.get(TenKH,30);
		cout << "Ma khach hang: "; cin >> Ma;
		cout << "So luong hang: "; cin >> SL;
		for(int i=0;i<SL;i++) {
			cout << "+--------------------+";
			cout << "\nMat hang thu " << i+1 << ":\n";
			Arr[i].Nhap();
		}
	}
	void Xuat() {
		cout << "Ten khach hang: " << TenKH << endl;
		cout << "Ma khach hang: " << Ma << endl;
		cout << "So luong hang: " << SL << endl;
		for(int i=0;i<SL;i++) {
			cout << "+--------------------+";
			cout << "\nMat hang thu " << i+1 << ":\n";
			Arr[i].Xuat();
		}
	}
};
//++++++++++++++++++++++++++++//
int main() {
	int SL_KH;
	Khach_hang KH[20];
	cout << "Nhap so luong khach hang: "; cin >> SL_KH;
	cout << "\nNHAP VAO DS KHACH HANG\n";
	for (int i=0;i<SL_KH;i++) {
		cout << "\n***Khach hang thu " << i+1 << ":\n";
		KH[i].Nhap();
	}
	///////////////////////////////////////
	cout << "\nDS KHACH HANG VUA NHAP\n";
	for (int i=0;i<SL_KH;i++) {
		cout << "\n***Khach hang thu " << i+1 << ":\n";
		KH[i].Xuat();
	}
	//.........................
	return 0;
}
