#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//-------------------------------------------------//
template <class T>
void Sapxep(T *arr, int n) { 
	int i, j; 
   	for (i = 0; i < n-1; i++)       
    	for (j = 0; j < n-i-1; j++)  
        	if (arr[j] < arr[j+1]) {
        		T temp = arr[j];
        		arr[j] = arr[j+1];
        		arr[j+1] = temp;
			}            	
}
//-------------------------------------------------//
class Sinhvien {
public:
	Sinhvien() {			
	}
	Sinhvien(string hoten1, int tuoi1, float dtb1) {
		hoten = hoten1; tuoi = tuoi1; dtb = dtb1;
	}
	friend ostream& operator<< (ostream& os, Sinhvien& r);
	friend istream& operator>> (istream& is, Sinhvien& r);
	bool operator< (const Sinhvien& r);
	bool operator> (const Sinhvien& r);		
private:
	string hoten;
	int tuoi;
	float dtb;
};
ostream& operator << (ostream& os, Sinhvien& r) {
	os << r.hoten << ", " << r.tuoi << ", " << r.dtb << endl;
	return os;
}
istream& operator >> (istream & is, Sinhvien& r) {
	cout << "Nhap ho va ten: "; is >> r.hoten;
	cout << "Nhap tuoi: "; is >> r.tuoi;
	cout << "Nhap diem trung binh: "; is >> r.dtb;
	return is;
}
bool Sinhvien::operator < (const Sinhvien& r) {
	// so sanh theo diem trung binh
	return (dtb < r.dtb);	
}
bool Sinhvien::operator > (const Sinhvien& r) {
	// so sanh theo diem trung binh
	return (dtb > r.dtb);
}
//-------------------------------------------------//
int main() {
	int arr_i[] = {4, -5, 21, 8, 43, -11, 82, 54};
	int n = sizeof(arr_i)/sizeof(arr_i[0]);
	Sapxep<int>(arr_i,n); //Goi ham ban mau
	for(int i = 0; i < n; i++)
		cout << arr_i[i] << "  ";
		
	cout << endl;
	
	double arr_d[] = {6.1, -3.3, -1.2, 8.6, 4.3, -1.1, 8.2, 5.4};
	int m = sizeof(arr_d)/sizeof(arr_d[0]);
	Sapxep<double>(arr_d,m); //Goi ham ban mau
	for(int i = 0; i < n; i++)
		cout << arr_d[i] << "  ";
	
	/////////////////////////////////////////
	cout << endl;
	
	Sinhvien SV[5];
	
	for(int i=0;i<5;i++) {
		cout << "Sinh vien thu " << i+1 << ":\n";
		cin >> SV[i];
	}
	cout << "\nDanh sach sinh vien vua nhap\n";
	for(int i=0;i<5;i++) {
		cout << SV[i];
	}
	
	Sapxep<Sinhvien>(SV,5); //Goi ham ban mau
	
	cout << "\nDanh sach sinh vien sap xep\n";
	for(int i=0;i<5;i++) {
		cout << SV[i];
	}
	
	return 0;
}
