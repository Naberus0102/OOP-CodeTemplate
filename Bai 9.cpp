#include<iostream>
using namespace std;
//-----------------------------------------//
class Nhan_vien {
protected:
	char Hoten[30];
	float Hesoluong;
	float Phucap;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float Luong() {
    	return(Hesoluong*1310+Phucap);
	}
	float get_Hesoluong() {
		return Hesoluong;
	}	
};
void Nhan_vien::Nhap() {
	cout << "Ho ten: "; cin.ignore(); cin.get(Hoten,30);
	cout << "He so luong: "; cin >> Hesoluong;
	cout << "Phu cap: "; cin >> Phucap;
}
void Nhan_vien::Xuat() {
	cout << "Ho ten: " << Hoten << endl;
	cout << "He so luong: " << Hesoluong << endl;
	cout << "Phu cap: " << Phucap << endl;
}
//-----------------------------------------//
class Can_bo: public Nhan_vien {
	float Hesochucvu;
public:
	void Nhap();
	void Xuat();
	float Luong() {
		return((Hesoluong+Hesochucvu)*1310+Phucap);
	}
};
void Can_bo::Nhap() {
	Nhan_vien::Nhap();
	cout << "He so chuc vu: "; cin >> Hesochucvu;
}
void Can_bo::Xuat() {
	Nhan_vien::Xuat();
	cout << "He so chuc vu: " << Hesochucvu << endl;
} 
//-----------------------------------------//
int main() {
	Nhan_vien *DS[50];
	int N;
	int Chon;	
	
	cout << "Nhap vao so luong Nhan vien va Can bo: "; 
	cin >> N;
	
	cout << "\nNHAP DS NHAN VIEN VA CAN BO\n";
	for (int i = 0; i < N; i++ ) {
		cout << "\nNhan vien/Can bo thu " << i+1 << ":\n";
		cout << "Nhap 1(Nhan vien), 2(Can bo): "; cin >> Chon;
		if (Chon == 1)
			DS[i] = new Nhan_vien();
		else if (Chon == 2)
			DS[i] = new Can_bo();
		else
			cout << "Gia tri nhap vao khong phu hop";
			
		DS[i]->Nhap();  
	}
	
	cout << "\nDS NHAN VIEN VA CAN BO VUA NHAP\n";
	for (int i = 0; i < N; i++ ) {
		cout << "\nNhan vien/Can bo thu " << i+1 << ":\n";	
		DS[i]->Xuat();
		cout << "Luong: " << DS[i]->Luong() << endl;  
	}	
	
	//SAP XEP DS NHAN VIEN/CAN BO TANG THEO LUONG
	int i, j;
   	for (i = 0; i < N-1; i++)      
    	for (j = 0; j < N-i-1; j++) 
        	if (DS[j]->Luong() > DS[j+1]->Luong()) {
        		Nhan_vien *temp = DS[j];
        		DS[j] = DS[j+1];
        		DS[j+1] = temp;
			}
	
	cout << "\n10% DANH SACH NHAN VIEN LUONG THAP NHAT VA CO HE SO < 3.0\n";
	for(int i = 0; i < N*0.1; i++) {
		if (DS[i]->get_Hesoluong() < 3.0) {
			cout << "\nNhan vien thu " << i+1 << ":" << endl;
			DS[i]->Xuat();
			cout << "Luong: " << DS[i]->Luong() << endl;
		}		
	}	
			
	return 0;
}
