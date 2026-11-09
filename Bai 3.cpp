#include<iostream>
#include<cstring>
using namespace std;
//------------------------------//
class Thuoc {
	char Ten_thuoc[30];
	int Ma_thuoc;
	int So_luong;
	float Gia_ban;
public:	
	friend bool comparator(const Thuoc* p, const Thuoc *q);
	friend void Sap_xep(Thuoc TH[], int n); 
	friend void swap(Thuoc& p, Thuoc& q);
	friend istream& operator>>(istream& is, Thuoc& Th);
	friend ostream& operator<<(ostream& os, Thuoc& Th);
};
//------------------------------//
istream& operator>>(istream& is, Thuoc& Th) {
	cout << "Ma thuoc: "; is >> Th.Ma_thuoc;	
	cout << "Ten thuoc: "; is.ignore(); is.get(Th.Ten_thuoc,30);	
	cout << "So luong: "; is >> Th.So_luong;
	cout << "Gia ban: "; is >> Th.Gia_ban;
	return is;
}
//------------------------------//
ostream& operator<<(ostream& os, Thuoc& Th) {
	os << "Ma thuoc: " << Th.Ma_thuoc << endl;	
	os << "Ten thuoc: " << Th.Ten_thuoc << endl;
	os << "So luong: " << Th.So_luong << endl;
	os << "Gia ban: " << Th.Gia_ban << endl;
	return os;
}
//------------------------------//
bool comparator(const Thuoc* p, const Thuoc* q) {
	return ((strcmp(p->Ten_thuoc,q->Ten_thuoc) > 0) ||
    		((strcmp(p->Ten_thuoc,q->Ten_thuoc) == 0) && (p->Ma_thuoc > q->Ma_thuoc)));
}
//------------------------------//
void swap(Thuoc& p, Thuoc &q) {
	Thuoc tmp = p;
	p = q;
	q = tmp;
}
//------------------------------//
void Sap_xep(Thuoc TH[], int n) {
	int i, j;  
    for (i = 0; i < n-1; i++)      
    	for (j = 0; j < n-i-1; j++)  
    		if (comparator(&TH[j], &TH[j+1])) {     			
				swap(TH[j], TH[j+1]);
			}           	 
}
//------------------------------//
int main() {
	Thuoc *TH;
	int n;
	cout << "Nhap vao so luong thuoc: "; cin >> n;
	TH = new Thuoc[n];
	
	cout << "\nNHAP VAO DS THUOC\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		cin >> TH[i];
	}
	
	cout << "\nDS THUOC VUA NHAP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		cout << TH[i];
	}
	Sap_xep(TH, n);
	
	cout << "\nDS THUOC SAU KHI SAP XEP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		cout << TH[i];
	}	
	return 0;
}
