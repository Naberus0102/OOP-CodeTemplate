#include<iostream>
#include<cstring>
using namespace std;
//---------------------------------//
class Sach {
	char Ten_sach[30];
	char Tac_gia[30];
	int Nam_xuat_ban;
	char NXB[30];
public:
	Sach() {
		strcpy(Ten_sach,"");
		strcpy(Tac_gia,"");
		Nam_xuat_ban=0;
		strcpy(NXB,"");
	}
	Sach(char *Ten_sach1, char *Tac_gia1, int Nam_xuat_ban1, char *NXB1) {
		strcpy(Ten_sach,Ten_sach1);
		strcpy(Tac_gia,Tac_gia1);
		Nam_xuat_ban=Nam_xuat_ban1;
		strcpy(NXB,NXB1);
	}
	friend istream& operator>>(istream& is, Sach &s);
	friend ostream& operator<<(ostream& os, Sach &s);
};
istream& operator>>(istream& is, Sach &s) {
	cout << "Ten sach: "; is.ignore(); is.get(s.Ten_sach,30);
	cout << "Tac gia: "; is.ignore(); is.get(s.Tac_gia,30);
	cout << "Nam xuat ban: "; is >> s.Nam_xuat_ban;
	cout << "NXB: "; is.ignore(); is.get(s.NXB,30);
	return is;
}
ostream& operator<<(ostream& os, Sach &s) {
	cout << "Ten sach: " << s.Ten_sach << endl;
	cout << "Tac gia: " << s.Tac_gia << endl;
	cout << "Nam xuat ban: " << s.Nam_xuat_ban << endl;
	cout << "NXB: " << s.NXB;
	return os;
}
//---------------------------------//
class Doc_gia {
	char Ten[30];
	int Ma_so;
	char Khoa[20];
	char Lop[20];
	Sach s[10];
	int n;
public:
	friend istream& operator>>(istream& is, Doc_gia &d);
	friend ostream& operator<<(ostream& os, Doc_gia &d);
	int So_luong();
};
istream& operator>>(istream& is, Doc_gia &d) {
	cout << "Ten: "; is.ignore(); is.get(d.Ten,30);
	cout << "Ma so: "; is >> d.Ma_so;
	cout << "Khoa: "; is.ignore(); is.get(d.Khoa,20);	
	cout << "Lop: "; is.ignore(); is.get(d.Lop,20);
	cout << "Nhap so luong sach muon: "; is >> d.n;
	for(int i=0;i<d.n;i++) {
		cout << "Sach thu " << i+1 << ":\n";
		is >> d.s[i];
	}		
	return is;
}
ostream& operator<<(ostream& os, Doc_gia &d) {
	os << "Ten: " << d.Ten << endl;
	os << "Ma so: " << d.Ma_so << endl;
	os << "Khoa: " << d.Khoa << endl;	
	os << "Lop: " << d.Lop << endl;
	cout << "So luong sach muon: "; os << d.n;
	for(int i=0;i<d.n;i++) {
		cout << "\nSach thu: " << i+1 << ":\n";
		os << d.s[i];
	}	
	return os;
}
int Doc_gia::So_luong() {
	return n;
}
//---------------------------------//
int main() {
	Doc_gia DG[50];
	int So_DG;
	cout << "Nhap so luong sinh vien: "; cin >> So_DG;
	for(int i=0;i<So_DG;i++) {
		cout << "\nThong tin sinh vien thu " << i+1 << ":\n";
		cin >> DG[i];
	}
	cout << "\n******************************\n";
	for(int i=0;i<So_DG;i++) {
		cout << "Thong tin sinh vien thu " << i+1 << ": ";
		cout << DG[i];
	}
	int Max = DG[0].So_luong();
	for(int i=1;i<So_DG;i++) {
		if (Max < DG[i].So_luong())
			Max =  DG[i].So_luong();
	}
	cout << "\nThong tin sinh vien muon nhieu sach nhat:\n";
	for(int i=1;i<So_DG;i++) {
		if (Max = DG[i].So_luong())
			cout << DG[i];
	}
	return 0;
}
