#include<iostream>
#include<Math.h>
using namespace std;
//-------------------------------//
class Hinh_tron {
	int x, y;
	float r;
public:
	Hinh_tron() {
    	x = y = 0; r = 0.0;
	}	
	float Dien_tich() {
    	return (3.14*r*r);
	}
	bool Kiem_tra (int xA, int yA) {
   		return (sqrt((xA-x)*(xA-x) +(yA-y)*(yA-y)) > r);
	}
	friend istream& operator>> (istream& is, Hinh_tron& ht);
	friend ostream& operator<< (ostream& os, Hinh_tron& ht);	
};
//-------------------------------//
istream& operator >> (istream& is, Hinh_tron& ht) {
	cout << "x = "; is >> ht.x;
	cout << "y = "; is >> ht.y;
	cout << "R = "; is >> ht.r;
	return is;
}
ostream& operator << (ostream& os, Hinh_tron& ht) {
	os << "Toa do tam: (" << ht.x << ", " << ht.y << ")" << endl;
	os << "Ban kinh: " << ht.r;
	return os;
}
//-------------------------------//
int main() {
	Hinh_tron HT[50];
	int n;
	cout << "Nhap vao so luong cac duong tron: "; cin >> n;
		
	cout << "\nNHAP VAO CAC DUONG TRON\n";
	for (int i=0;i<n;i++) {
		cout << "\nDuong tron thu " << i+1 << ":\n";
		cin >> HT[i];
	}
	cout << "\nCAC DUONG TRON VUA NHAP";
	for (int i=0;i<n;i++) {
		cout << "\n\nDuong tron thu " << i+1 << ":\n";
		cout << HT[i];
		cout << "\nDien tich: " << HT[i].Dien_tich();
	}
	
	int i, j;
    for(i = 0; i < n - 1; i++)         
        for(j = 0; j < n - i - 1; j++)
            if(HT[j].Dien_tich() < HT[j+1].Dien_tich()) {
            	Hinh_tron tmp = HT[j];
            	HT[j] = HT[j+1];
            	HT[j+1] = tmp;
			}               

	cout << "\n\nCAC DUONG TRON SAP GIAM DAN DIEN TICH";
	for (int i=0;i<n;i++) {
		cout << "\n\nDuong tron thu " << i+1 << ":\n";
		cout << HT[i];
		cout << "\nDien tich: " << HT[i].Dien_tich();
	}	
	
	int xA, yA;
	cout << "\n\nNhap toa do diem A:\n";
	cout << "xA = "; cin >> xA;
	cout << "yA = "; cin >> yA;
	
	cout << "\n\n10% DUONG TRON CO DIEN TICH LON NHAT KHONG CHUA DIEM A";
	for (int i=0;i<n*0.1;i++) {
		if (HT[i].Kiem_tra(xA,yA)) {
			cout << "\n\nDuong tron thu " << i+1 << ":\n";
			cout << HT[i];
			cout << "\nDien tich: " << HT[i].Dien_tich();
		}		
	}		
	return 0;
}
