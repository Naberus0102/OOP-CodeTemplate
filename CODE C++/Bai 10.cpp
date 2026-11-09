#include<iostream>
using namespace std;
//--------------------------//
class Thi_sinh {
protected:
	char Hoten[30];
	float DiemTB;
	float DiemTA;
public:
	virtual void Nhap();
	virtual void Xuat();
	bool Xettuyen() {
		return(DiemTB>=7.0 && DiemTA>=400);
	}
};
void Thi_sinh::Nhap() {
	cout << "Ho ten: "; cin.ignore(); cin.get(Hoten,30);
	cout << "Diem TB: "; cin >> DiemTB;
	cout << "Diem TA: "; cin >> DiemTA; 
}
void Thi_sinh::Xuat() {
	cout << "Ho ten: " << Hoten << endl;
	cout << "Diem TB: " << DiemTB << endl;
	cout << "Diem TA: " << DiemTA << endl; 
}
//--------------------------//
class Thi_sinh_UT : public Thi_sinh {
	float DiemUT;
public:
	void Nhap();
	void Xuat();
	bool Xettuyen();		
};
void Thi_sinh_UT::Nhap() {
	Thi_sinh::Nhap();
	cout << "Diem UT: "; cin >> DiemUT;	
}
void Thi_sinh_UT::Xuat() {
	Thi_sinh::Xuat();
	cout << "Diem UT: " << DiemUT << endl;	
}
//--------------------------//
int main() {
	Thi_sinh *TS[50];
	int N;
	int Chon;
	
	cout << "Nhap vao so Thi sinh: "; cin >> N;
	
	cout << "\nNHAP VAO DS THI SINH\n";
	for (int i=0; i<N; i++) {
		cout << "\nThi sinh thu " << i+1 << ":\n";
		cout << "Nhap 1(Thi sinh), 2(Thi sinh UT): "; cin >> Chon;
		if (Chon == 1)
			TS[i] = new Thi_sinh;
		else if (Chon == 2)
			TS[i] = new Thi_sinh_UT;
		else
			cout << "Gia tri nhap vao khong phu hop";
		TS[i]->Nhap();
	}
	
	cout << "\nIN DS THI SINH\n";
	for (int i=0; i<N; i++) {
		cout << "\nThi sinh thu " << i+1 << ":\n";
		TS[i]->Xuat();
	}	
	
	return 0;
}
