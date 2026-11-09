#include<iostream>
#include<cstring>
using namespace std;
//---------------------------------//
class Hoc_vien {
	int 	MaHV;
	char 	Hoten[30];
	char 	Lop[30];
	float 	Diem;
public:
	Hoc_vien() {
		MaHV = 0;
		strcpy(Hoten,"");
		strcpy(Lop,"");
		Diem = 0.0;
	}
	Hoc_vien(int ma, char ten[30], char lop[30], float diem) {
		MaHV = ma;
		strcpy(Hoten,ten);
		strcpy(Lop,lop);
		Diem = diem;		
	}
	friend istream& operator >>(istream& is, Hoc_vien& hv);
	friend ostream& operator <<(ostream& os, Hoc_vien& hv);
	bool operator > (Hoc_vien& h) {
        return (Diem > h. Diem);
	}
};
istream& operator>> (istream& is, Hoc_vien&hv) {
	cout << "Ma hoc vien: "; 	is >> hv.MaHV;
	cout << "Ten hoc vien: "; 	is.ignore(); is.get(hv.Hoten,30);
	cout << "Lop: "; 			is.ignore(); is.get(hv.Lop,30);
	cout << "Diem: "; 			is >> hv.Diem;
	return is;
}
ostream& operator<<(ostream& os, Hoc_vien& hv) {
	cout << "Ma hoc vien: " << hv.MaHV;
	cout << "Ten hoc vien: "<< hv.Hoten;
	cout << "Lop: " << hv.Lop;
	cout << "Diem: " << hv.Diem;
	return os;
}
//---------------------------------//
int main() {
	Hoc_vien *HV;
	int n;
	cout << "Nhap vao so hoc vien: "; cin >> n;
	HV = new Hoc_vien[n];
	
	cout << "\nNHAP VAO DS HOC VIEN\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Hoc vien thu " << i+1 << ":\n";
		cin >> HV[i];
	}
	
	cout << "\nDS HOC VIEN VUA NHAP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Hoc vien thu " << i+1 << ":\n";
		cout << HV[i];
	}
	int i, j;  
    for (i = 0; i < n-1; i++)      
    	for (j = 0; j < n-i-1; j++)  
    		if (HV[j] > HV[j+1]) {     			
				Hoc_vien tmp = HV[j];
				HV[j] = HV[j+1];
				HV[j+1] = tmp;
			}           
	
	cout << "\nDS HOC VIEN SAU KHI SAP XEP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		cout << HV[i];
	}	
	return 0;
}
