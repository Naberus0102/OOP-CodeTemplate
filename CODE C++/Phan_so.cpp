#include<iostream>
#include<Math.h>
using namespace std;
//--------------------------//
class Phan_so {
	int Tu_so;
	int Mau_so;
public:
	Phan_so() {
		Tu_so = 0;
		Mau_so = 1;
	}
	
	Phan_so(int ts, int ms) {
		Tu_so = ts;
		if (ms==0) {
			cerr << "LOI CHIA CHO KHONG";
			exit(0);
		} 
		else 
			Mau_so = ms;
	}
	friend istream& operator>>(istream&, Phan_so&);
	friend ostream& operator<<(ostream&, Phan_so&);
	friend void Sap_xep(Phan_so Ps[], int n); 
	Phan_so operator+(const Phan_so&);
	Phan_so operator-(const Phan_so&);
	Phan_so operator*(const Phan_so&);
	Phan_so operator/(const Phan_so&);
	
	int gcd(int n, int d) {
    	if (d == 0) 
			return n;
    	else 
			return abs(gcd(d,n%d));
	}
	
	void Rut_gon() {
		int UC = gcd(Tu_so, Mau_so);
		Tu_so = Tu_so / UC;
		Mau_so = Mau_so / UC;
	}
	
	// So sanh hai phan so
    bool operator<(const Phan_so& ps) const {
        return (long long)Tu_so * ps.Mau_so < (long long)ps.Tu_so * Mau_so;
    }

    bool operator>(const Phan_so& ps) const {
        return (long long)Tu_so * ps.Mau_so > (long long)ps.Tu_so * Mau_so;
    }
};
//----------------------------//
istream& operator >> (istream& is, Phan_so& ps) {
	cout << "Tu so = "; is >> ps.Tu_so;
	cout << "Mau so = "; is >> ps.Mau_so;
	return is;
}
//----------------------------//
ostream& operator << (ostream& os, Phan_so& ps) {
	os << ps.Tu_so << "/" << ps.Mau_so;
	return os;
}
//----------------------------//
Phan_so Phan_so::operator+(const Phan_so& ps) {
	Phan_so tmp;
	tmp.Tu_so = Tu_so*ps.Mau_so + Mau_so*ps.Tu_so;
	tmp.Mau_so = Mau_so*ps.Mau_so;
	tmp.Rut_gon();
	return tmp;	
}
//----------------------------//
Phan_so Phan_so::operator-(const Phan_so& ps) {
	int ts = Tu_so*ps.Mau_so - Mau_so*ps.Tu_so;
	int ms = Mau_so*ps.Mau_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
Phan_so Phan_so::operator*(const Phan_so& ps) {
	int ts = Tu_so*ps.Tu_so;
	int ms = Mau_so*ps.Mau_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
Phan_so Phan_so::operator/(const Phan_so& ps) {
	int ts = Tu_so*ps.Mau_so;
	int ms = Mau_so*ps.Tu_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
void Sap_xep(Phan_so Ps[], int n) {
	int i, j;  
    for (i = 0; i < n-1; i++)      
    	for (j = 0; j < n-i-1; j++)  
    		if (Ps[j] > Ps[j+1]) {     			
				swap(Ps[j], Ps[j+1]);
			}           	 
}
//----------------------------//
int main() {
	Phan_so ps1, ps2, ps3;
	cout << "Nhap vao phan so thu nhat:\n";
	cin >> ps1;
	cout << ps1;
	
	cout << endl;
	
	cout << "\nNhap vao phan so thu hai:\n";
	cin >> ps2;
	cout << ps2;
	
	cout << endl;
	cout << "\nThuong cua hai phan so:\n";
	ps3 = ps1 / ps2; 	//ps3 = ps1.operator+(ps2); 
	cout << ps1 << " / " << ps2 << " = " << ps3;
	
	cout << endl;
	int n;
    cout << "\nNhap so luong phan so: ";
    cin >> n;

    Phan_so ps[n];

    // Nhap mang phan so
    for (int i = 0; i < n; i++) {
        cout << "\nNhap phan so thu " << i + 1 << ":\n";
        cin >> ps[i];
    }

    // Tinh tong
    Phan_so Tong(0, 1);
    for (int i = 0; i < n; i++)
        Tong = Tong + ps[i];

    cout << "\nTong cac phan so: ";
    cout << Tong;
    cout << endl;

    // Tim min va max
    Phan_so maxPS = ps[0], minPS = ps[0];
    for (int i = 1; i < n; i++) {
        if (ps[i] > maxPS) maxPS = ps[i];
        if (ps[i] < minPS) minPS = ps[i];
    }

    cout << "Phan so lon nhat: ";
    cout << maxPS;
    cout << "\nPhan so nho nhat: ";
    cout << minPS;
    cout << endl;	
	
	// Sap xep
	Sap_xep(ps, n);
	cout << "\nDS PHAN SO SAU KHI SAP XEP\n";
	for(int i=0;i<n;i++) {
		cout << ps[i] << "  ";
	}	
	
	return 0;
}
