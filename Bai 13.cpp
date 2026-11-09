#include<iostream>
using namespace std;
//------------------------------------//
class Benh_nhan {
	char 	Hoten[30];
	int 	MaHS;
	int 	NS;
	char 	Chuan_doan_benh[50];
	char 	Khoa[30];
public:
	virtual void Nhap() {
		cout << "Ho ten: "; cin.ignore(); cin.get(Hoten,30);
		cout << "Ma ho so: "; cin >> MaHS;
		cout << "Nam sinh: "; cin >> NS;
		cout << "Chuan doan benh: "; cin.ignore(); cin.get(Chuan_doan_benh,50);
		cout << "Khoa: "; cin.ignore(); cin.get(Khoa,30);
	}
	virtual void Xuat() {
		cout << "Ho ten: " << Hoten << endl;
		cout << "Ma ho so: " << MaHS << endl;
		cout << "Nam sinh: " << NS << endl;
		cout << "Chuan doan benh: " << Chuan_doan_benh << endl;
		cout << "Khoa: " << Khoa << endl;
	}
	int getMaHS() {
		return MaHS;
	}
};
//------------------------------------//
class Noi_tru : public Benh_nhan {
	char Ma_Phong_Giuong[30];
public:
	void Nhap() {
		Benh_nhan::Nhap();
		cout << "Ma Phong+Giuong: ";cin.ignore(); cin.get(Ma_Phong_Giuong,30);
	}
	void Xuat() {
		Benh_nhan::Xuat();
		cout << "Ma Phong+Giuong: " << Ma_Phong_Giuong << endl;
	}
};
//------------------------------------//
class Ngoai_tru : public Benh_nhan {
	char Don_thuoc[30];
public:
	void Nhap() {
		Benh_nhan::Nhap();
		cout << "Don thuoc: ";cin.ignore(); cin.get(Don_thuoc,30);
	}
	void Xuat() {
		Benh_nhan::Xuat();
		cout << "Don thuoc: " << Don_thuoc << endl;
	}
};
//------------------------------------//
int main() {
	Benh_nhan* BN[50];
	int N;
	cout << "Nhap vao so benh nhan: "; cin >> N;
	
	cout << "\nNHAP VAO DS BENH NHAN";
	int Loai;
	for (int i=0;i<N;i++) {
		cout << "\nNhap vao 1_(BN Noi tru), 2_(BN Ngoai tru): ";
		cin >> Loai;
		if (Loai == 1)
			BN[i] = new Noi_tru;
		else if (Loai == 2)
			BN[i] = new Ngoai_tru;	
		else
			cout << "Nhap gia tri khac";
			
		cout<<"\nThong tin Benh nhan thu " << i+1 << ": " << endl;
		BN[i]->Nhap(); 
	}
	cout<<"\n*******************************\n";
	cout<<"THONG TIN BENH NHAN";
	for(int i=0;i<N;i++) {
		cout << "\nThong tin benh nhan thu " << i+1 << ": " << endl;
		BN[i]->Xuat();		
	}
	
	int i, j; 
   	for (i = 0; i < N-1; i++)       
    	for (j = 0; j < N-i-1; j++)  
        	if (BN[j]->getMaHS() < BN[j+1]->getMaHS()) {
        		Benh_nhan *temp = BN[j];
        		BN[j] = BN[j+1];
        		BN[j+1] = temp;
			}     
	cout<<"\n*******************************\n";
	cout<<"THONG TIN BENH NHAN SAU KHI SAP";
	for(int i=0;i<N;i++) {
		cout << "\nThong tin benh nhan thu " << i+1 << ": " << endl;
		BN[i]->Xuat();		
	}
	return 0;
}
