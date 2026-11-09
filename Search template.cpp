#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//-------------------------------------------------//
template <class T, class U>
int Search(T a[], U n, U m, T x) {
    U i;
    for (i = n; i < m; i++)
        if (a[i] == x)
            return i;
    return -1;
}
//-------------------------------------------------//
class Hocsinh {
	public:
		Hocsinh() {			
		}
		Hocsinh(string hoten1, int tuoi1, float dtb1) {
			hoten = hoten1;
			tuoi = tuoi1;
			dtb = dtb1;
		}
		friend ostream& operator << (ostream& os, Hocsinh& r);
		friend istream& operator >> (istream& is, Hocsinh& r);
		bool operator < (const Hocsinh& r);
		bool operator > (const Hocsinh& r);
		bool operator == (const Hocsinh& r);
		friend void sapxep(Hocsinh a[], int n);
	private:
		string hoten;
		int tuoi;
		float dtb;
};
ostream & operator << (ostream & os, Hocsinh & r) {
	os << r.hoten << ", " << r.tuoi << ", " << r.dtb << endl;
	return os;
}
istream & operator >> (istream & is, Hocsinh & r) {
	cout << "Nhap ho va ten: ";
	is >> r.hoten;
	cout << "Nhap tuoi: ";
	is >> r.tuoi;
	cout << "Nhap diem trung binh: ";
	is >> r.dtb;
	return is;
}
bool Hocsinh::operator < (const Hocsinh & r) {
	// so sanh theo diem trung binh
	if(hoten.compare(r.hoten) < 0)
		return true;
	return false;
}
bool Hocsinh::operator > (const Hocsinh & r) {
	// so sanh theo diem trung binh
	if(hoten.compare(r.hoten) > 0)
		return true;
	return false;
}
bool Hocsinh::operator == (const Hocsinh & r) {
	// so sanh theo diem trung binh
	if(hoten.compare(r.hoten) == 0)
		return true;
	return false;
}
void sapxep(Hocsinh a[], int n) {
	sort(a, a+n); // goi tu thu vien algorithm
}
//-------------------------------------------------//
int main() {
	int arr_i[] = {4, -5, 21, 8, 43, -11, 82, 54};
	int x = 8;
	int n = 0;
	int m = sizeof(arr_i)/sizeof(arr_i[0]);
	int result = Search<int>(arr_i,n,m,x);
	if (result==-1) 
		cout << "Khong co gia tri nay";
	else
		cout << "Co gia tri nay trong mang o vi tri: " << result;
	
		
	cout << endl;
	
	double arr_d[] = {6.1, -3.3, -1.2, 8.6, 4.3, -1.1, 8.2, 5.4};
	double d = 6.1;
	int u = 0;
	int v = sizeof(arr_d)/sizeof(arr_d[0]);
	int flag = Search<double>(arr_d,u,v,d);
	if (flag==-1) 
		cout << "Khong co gia tri nay";
	else
		cout << "Co gia tri nay trong mang o vi tri: " << flag;
	
	/////////////////////////////////////////
	cout << endl;
	
	Hocsinh HS[5];
	
	for(int i=0;i<5;i++) {
		cout << "\nSinh vien thu " << i+1 << ":\n";
		cin >> HS[i];
	}
	cout << "\nDanh sach sinh vien vua nhap\n";
	for(int i=0;i<5;i++) {
		cout << HS[i];
	}	
	
	Hocsinh X;
	cout << "\nNhap gia tri can tim\n"; cin >> X;
	int found = Search<Hocsinh>(HS,0,5,X);
	if (found==-1) 
		cout << "Khong co gia tri nay";
	else
		cout << "Co gia tri nay trong mang o vi tri: " << found; 	
		
	return 0;
}
