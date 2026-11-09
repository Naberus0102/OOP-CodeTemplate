#include<iostream>
#include<cstring>
using namespace std;
//--------------------------------//
class Nhan_vien {
	char Hoten[30];
	int Namsinh;
	int LuongCB;
	int Songaycong;
public:
    Nhan_vien() {
		strcpy(Hoten,"");
		Namsinh = 0;
		LuongCB = 0;
		Songaycong = 0;
	}
	void Nhap() {
		cout << "Ten nhan vien: "; cin.ignore(); cin.get(Hoten,30);
		cout << "Nam sinh: "; cin >> Namsinh;
		cout << "Luong co ban: "; cin >> LuongCB;
		cout << "So ngay cong: "; cin >> Songaycong;
	}
	void Xuat() {
		cout << "Ho ten: " << Hoten << endl;
		cout << "Nam sinh: " << Namsinh << endl;
		cout << "Luong co ban: " << LuongCB << endl;
		cout << "So ngay cong: " << Songaycong << endl;
	}
	float Luong() {
		return (LuongCB*Songaycong);
	}	
};
//--------------------------------//
class Bang_luong {
	int SoNV;
	Nhan_vien *NV;
public:
    Bang_luong() {
		SoNV = 0;
		NV = NULL;	    	
	}
	Bang_luong(int n) {
		SoNV = n;
		NV = new Nhan_vien[SoNV];	    	
	}		
	~Bang_luong() {
		SoNV = 0;
		delete []NV;	
	}
	void Nhap() {
		for(int i=0; i < SoNV; i++) {
		   cout << "\nNhan vien thu " << i+1 << ": " << endl;	
		   NV[i].Nhap();
	    }
	}
	void Xuat() {
		for(int i=0; i<SoNV; i++) {
		   	cout << "\nNhan vien thu " << i+1 << ": " << endl;
		    NV[i].Xuat();
		}
	}
	void Thongke() { 
		for(int i=0; i<SoNV; i++)
		   if(NV[i].Luong() < 5000) {
				NV[i].Xuat();			  	
		   }		
	}
};
//--------------------------------//
int main() {
	int N;
	cout << "Nhap so luong nhan vien: "; cin >> N;
	Bang_luong BL(N);
	
	BL.Nhap();
	cout << "\nDANH SACH BAN DAU" << endl;
	BL.Xuat();
	cout << "\nDANH SACH NHAN VIEN CO LUONG < 5.000.000" << endl;
	BL.Thongke();
	
	return 0;
}
