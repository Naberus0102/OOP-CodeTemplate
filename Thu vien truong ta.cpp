#include<iostream>
using namespace std;
//++++++++++++++++++++++++++++//
class Sach {
	char 	Ten_sach[30];
	char 	Tac_gia[30];
	int 	Nam_XB;
	char 	NXB[30];
public:
	Sach() {
	}
	void Nhap() {
		cout << "Ten_sach: "; cin.ignore(); cin.get(Ten_sach,30);
		cout << "Tac_gia: "; cin.ignore(); cin.get(Tac_gia,30);
		cout << "Nam_XB: "; cin >> Nam_XB;
		cout << "NXB: "; cin.ignore(); cin.get(NXB,30);
	}
	void Xuat() {
		cout << "Ten_sach: " << Ten_sach << endl;
		cout << "Tac_gia: " << Tac_gia << endl;
		cout << "Nam_XB: " << Nam_XB << endl;
		cout << "NXB: " << NXB << endl;
	}
};
//++++++++++++++++++++++++++++//
class Doc_gia {
	char	Ten[30];
	int 	Ma;
	char 	Khoa[20];
	char 	Lop[10];
	int SL_sach;
	Sach Arr[30];
public:
	Doc_gia() {
	}
	void Nhap() {
		cout << "Ten doc gia: "; cin.ignore(); cin.get(Ten,30);
		cout << "Ma doc gia: "; cin >> Ma;
		cout << "Khoa: "; cin.ignore(); cin.get(Khoa,20);
		cout << "Lop: "; cin.ignore(); cin.get(Ten,10);		
		cout << "So luong sach: "; cin >> SL_sach;
		for(int i=0;i<SL_sach;i++) {
			cout << "+--------------------+";
			cout << "\nSach thu " << i+1 << ":\n";
			Arr[i].Nhap();
		}
	}
	void Xuat() {
		cout << "Ten doc gia: " << Ten << endl;
		cout << "Ma doc gia: " << Ma << endl;
		cout << "Khoa: " << Khoa << endl;
		cout << "Lop: " << Ten << endl;
		for(int i=0;i<SL_sach;i++) {
			cout << "+--------------------+";
			cout << "\nSach thu " << i+1 << ":\n";
			Arr[i].Xuat();
		}
	}
};
//++++++++++++++++++++++++++++//
int main() {
	int SL_DG;
	Doc_gia DG[60];
	cout << "Nhap so luong doc gia: "; cin >> SL_DG;
	cout << "\nNHAP VAO DS DOC GIA\n";
	for (int i=0;i<SL_DG;i++) {
		cout << "\n***Doc gia thu " << i+1 << ":\n";
		DG[i].Nhap();
	}
	///////////////////////////////////////
	cout << "\nDS DOC GIA VUA NHAP\n";
	for (int i=0;i<SL_DG;i++) {
		cout << "\n***Doc gia thu " << i+1 << ":\n";
		DG[i].Xuat();
	}
	//.........................
	return 0;
}
