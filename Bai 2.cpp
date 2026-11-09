#include<iostream>
using namespace std;
class Hang_hoa {
	int 	Mahang;
	char 	Tenhang[30];
	float 	Gianhap;
	float 	Giaban;
	int 	Soluong;
public:
	Hang_hoa() {}
 	~Hang_hoa() {}
 	void Nhap();
 	void Xuat();
 	float Loi_nhuan() {
		return((Giaban-Gianhap)*Soluong);
	}
	int Get_Soluong() {
		return Soluong;
	}
};
//-----------------------------------//
void Hang_hoa::Nhap() {
	cout << "Ma hang: "; cin >> Mahang;
	cout << "Ten hang: "; cin.ignore(); cin.get(Tenhang,30);
	cout << "Gia nhap: "; cin >> Gianhap;
	cout << "Gia ban: "; cin >> Giaban;
	cout << "So luong: "; cin >> Soluong;	
}
//-----------------------------------//
void Hang_hoa::Xuat() {
	cout << "Ma hang: " << Mahang << endl;
	cout << "Ten hang: " << Tenhang << endl;
	cout << "Gia nhap: " << Gianhap << endl;
	cout << "Gia ban: " << Giaban << endl;
	cout << "So luong: " << Soluong << endl;	
}
//-----------------------------------//
int main() {
	Hang_hoa HH[50];
	int n;
	cout << "Nhap vao so luong hang hoa: "; cin >> n;
	
	cout << "\nNHAP DANH SACH HANG HOA\n";
	for (int i = 0; i < n; i++) {
		cout << "\nMat hang thu " << i+1 << ":\n";
		HH[i].Nhap(); 
	}
	
	cout << "\nDANH SACH HANG HOA VUA NHAP\n";
	for (int i = 0; i < n; i++) {
		cout << "\nMat hang thu " << i+1 << ":\n";
		HH[i].Xuat();
		cout << "Loi nhuan: " << HH[i].Loi_nhuan() << endl;
	}
	/*
	// TINH TONG LOI NHUAN CUA CAC HANG HOA
	float Tong = 0.0;
	for (int i = 0; i < n; i++) {
		Tong = Tong + HH[i].Loi_nhuan();
	}
	cout << "\nTONG LOI NHUAN: " << Tong;
	
	//SAP DS MAT HANG GIAM THEO LOI NHUAN
	int i, j; 
	for (i = 0; i < n-1; i++)        
		for (j = 0; j < n-i-1; j++)  
        	if (HH[j].Loi_nhuan() < HH[j+1].Loi_nhuan()) {
        		Hang_hoa temp = HH[j];
        		HH[j] = HH[j+1];
        		HH[j+1] = temp;        		
			}            
	
	cout << "\nDANH SACH 10% MAT HANG BAN LAI NHAT VA CO SO LUONG BAN > 5\n";
	for (int i = 0; i < 0.1*n; i++) {
		if (HH[i].Get_Soluong() > 5)
			HH[i].Xuat();		
	}
	*/
	return 0;
}
