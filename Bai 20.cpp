#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//++++++++++++++++++++++++++++//
template <class myT,class myU>
myU tMax(myT A[], myU N, myU M) {
	myT Max = A[N];
	myU index = N;
	for (int i = N+1; i < M; i++) {
		if (Max < A[i]) {
			Max = A[i];
			index = i;
		}
			
	}
	return index;
}
//++++++++++++++++++++++++++++//
class Sinhvien {
public:
	Sinhvien() {			
	}
	Sinhvien(string hoten1, int tuoi1, float dtb1) {
		hoten = hoten1; tuoi = tuoi1; dtb = dtb1;
	}
	friend ostream& operator << (ostream& os, Sinhvien& r);
	friend istream& operator >> (istream& is, Sinhvien& r);
	bool operator < (const Sinhvien& r);
	bool operator > (const Sinhvien& r);	 
   	friend void sapxep(Sinhvien a[], int n);
private:
	string hoten;
	int tuoi;
	float dtb;
};
//++++++++++++++++++++++++++++//
ostream& operator << (ostream& os, Sinhvien& r) {
	os << r.hoten << ", " << r.tuoi << ", " << r.dtb << endl;
	return os;
}
//++++++++++++++++++++++++++++//
istream& operator >> (istream& is, Sinhvien& r) {
	cout << "Nhap ho va ten: ";
	is >> r.hoten;
	cout << "Nhap tuoi: ";
	is >> r.tuoi;
	cout << "Nhap diem trung binh: ";
	is >> r.dtb;
	return is;
}
//++++++++++++++++++++++++++++//
bool Sinhvien::operator < (const Sinhvien& r) {
	// so sanh theo diem trung binh
	if(dtb < r.dtb)
		return true;
	return false;
}
//++++++++++++++++++++++++++++//
bool Sinhvien::operator > (const Sinhvien& r) {
	// so sanh theo diem trung binh
	if(dtb > r.dtb)
		return true;
	return false;
}
//++++++++++++++++++++++++++++//
void sapxep(Sinhvien *a, int n) {
	sort(a,a+n); // goi tu thu vien algorithm
}
//++++++++++++++++++++++++++++//
int main() {
	int arr_i[] = {4, -5, 21, 8, 43, -11, 82, 54};
	int n = 0;
	int m = sizeof(arr_i)/sizeof(arr_i[0]);
	cout << "Max arr_i: " << tMax<int,int>(arr_i,n,m);
	
	cout << endl;
	
	float arr_f[] = {6.1, -3.3, -1.2, 8.6, 4.3, -1.1, 8.2, 5.4};
	int u = 0;
	int v = sizeof(arr_f)/sizeof(arr_f[0]);
	cout << "Max arr_f: " << tMax<float,int>(arr_f,u,v);
	
	/////////////////////////////////////////
	cout << endl;
	
	Sinhvien SV[5];
	
	for(int i=0;i<5;i++) {
		cout << "\nSinh vien thu " << i+1 << ":\n";
		cin >> SV[i];
	}
	cout << "\nDanh sach sinh vien vua nhap\n";
	for(int i=0;i<5;i++) {
		cout << SV[i];
	}
	cout << "Max Sinh vien thu: "  << tMax<Sinhvien,int>(SV,0,5);;
	
	return 0;
}
