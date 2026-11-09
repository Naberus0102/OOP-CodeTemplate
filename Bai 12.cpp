#include<iostream>
#include<string.h>
using namespace std;
//---------------------------//
class Mat_hang { //Lop truu tuong khong tao ra doi tuong
protected:
	string 	Tenhang;
	int 	Mahang;
	float 	Gianhap;
	float 	Giaxuat;
public:
	Mat_hang() {
		Tenhang = ""; Mahang = 0; 
		Gianhap = 0.0; Giaxuat = 0.0;
	}
	void Nhap();
	void Xuat();
	virtual float Tinhthue(void) = 0; // Ham tinh thue
	virtual float Tinhlai(void) = 0; // Ham tinh lai
};
void Mat_hang::Nhap() {
	cout << "Ten hang: "; cin >> Tenhang;
	cout << "Ma hang: "; cin >> Mahang;
	cout << "Gia nhap: "; cin >> Gianhap;
	cout << "Gia xuat "; cin >> Giaxuat;	
}
void Mat_hang::Xuat() {
	cout << "Ten hang: " << Tenhang << endl;
	cout << "Ma hang: " << Mahang << endl;
	cout << "Gia nhap: " << Gianhap << endl;
	cout << "Gia xuat: " << Giaxuat << endl;
}
//---------------------------//
class Gia_dung : public Mat_hang {
public:
	float Tinhthue(void) {
		return (Gianhap * 0.1);
	}
	float Tinhlai(void) {
		return (Giaxuat - Gianhap);
	}
};
//---------------------------//
class O_to: public Mat_hang {
public:
	float Tinhthue(void) {
		return (Gianhap * 0.3);
	}
	float Tinhlai(void) {
		return (Giaxuat - Gianhap);
	}
};
//---------------------------//
class May_moc: public Mat_hang {
public:
	float Tinhthue(void) {
		return (Gianhap * 0.12);
	}
	float Tinhlai(void) {
		return (Giaxuat - Gianhap);
	}
};
//---------------------------//
int main() {
	Mat_hang *MH[50];
	int n;
	cout << "Nhap vao so phan tu: ";
	cin >> n;
	
	cout << "\nNHAP VAO DS MAT HANG\n";
	int Loai;
	for (int i=0;i<n;i++) {
		cout << "\nNhap vao (1-Gia dung, 2-O to, 3-May moc):";
		cin >> Loai;
		if (Loai == 1)
			MH[i] = new Gia_dung;
		else if (Loai == 2)
			MH[i] = new O_to;
		else if (Loai == 3)
			MH[i] = new May_moc;
		else
			cout << "Nhap gia tri khac";
			
		cout<<"\nThong tin mat hang thu " << i+1 << ": " << endl;
		
		MH[i]->Nhap(); 
	}
	
	cout<<"\nTHONG TIN CAC MAT HANG\n";
	for(int i=0;i<n;i++) {
		cout << "\nThong tin mat hang thu " << i+1 << ": " << endl;
		MH[i]->Xuat();
		cout << "Thue: " << MH[i]->Tinhthue() << endl;
	}
	
	///////////////////////////////////////////////////////////
	cout<<"\n************************************************\n";
	cout<<"\nMAT HANG CO LAI CAO NHAT\n";
	float max = 0.0;
	for(int i = 0; i<n; i++) {
		if(max<(MH[i]->Tinhlai() - MH[i]->Tinhthue()))
			max =(MH[i]->Tinhlai() - MH[i]->Tinhthue());
	}
	cout << "\nMat hang co lai xuat lon nhat la: \n" << endl;
	for(int i=0; i<n; i++){
		if(max==(MH[i]->Tinhlai() - MH[i]->Tinhthue()))
			MH[i]->Xuat();
	}
	
	return 0;
}
