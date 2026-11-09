#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
//----------------------------------//
template <typename T>
class List {
public:
	List();
	List(T *data, int n);
	~List();
	void sort();
	int timkiem(const T &key)const;
	void ghifile(char *tenfile);
	void docfile(char *tenfile);
	int timmax()const;
	int timmin()const;
	void xuat()const;
	void nhap();
	bool ktRong()const;
private:
	T *data;
	int n;
};
//----------------------------------//
template <typename T>
List<T>::List() {
	n = 0;
	data = NULL;
}
//----------------------------------//
template <typename T>
List<T>::List(T *data1, int n1) {
	n = n1;
	data = new T[n];
	for(int i=0;i<n;i++)
		data[i] = data1[i];
}
//----------------------------------//
template <typename T>
List<T>::~List() {
	if(n>0)
		delete []data;
	n = 0;
}
//----------------------------------//
template <typename T>
void List<T>::xuat()const {
	for(int i=0;i<n;i++)
		cout << data[i] << endl;
}
//----------------------------------//
template <typename T>
void List<T>::sort() {
	int i, j;
	T tam;
	for(i=1;i<n;i++) {
		j = i;
		while(j>0&&data[j-1]>data[j]) {
			tam = data[j-1];
			data[j-1] = data[j];
			data[j] = tam;
			j --;
		}
	}
}
//----------------------------------//
template <typename T>
int List<T>::timkiem(const T &key)const {
	for(int i=0;i<n;i++)
		if(data[i]==key)
			return i;
	return -1;
}
//----------------------------------//
template <typename T>
int List<T>::timmax()const {
	int kq = 0;
	for(int i=1;i<n;i++)
		if(data[i]>data[kq])
			kq = i;
	return kq;
}
//----------------------------------//
template <typename T>
int List<T>::timmin()const {
	int kq = 0;
	for(int i=1;i<n;i++)
		if(data[i]<data[kq])
			kq = i;
	return kq;
}
//----------------------------------//
template <typename T>
void List<T>::nhap(){
	if(n>0) {
		delete []data;
		n = 0;
	}
	cout << "Nhap n="; cin >> n;
	data = new T[n];
	for(int i=0;i<n;i++) {
		cout << "Nhap phan tu thu " << i << ":";
		cin >> data[i];
	}
}
//----------------------------------//
template <typename T>
void List<T>::ghifile(char *tenfile) {
	ofstream fout(tenfile);
	fout << n << endl;
	for(int i=0;i<n;i++)
		fout << data[i] << endl;
	fout.close();
}
//----------------------------------//
class Sinh_vien {
	public:
		Sinh_vien(string hoten1="", int tuoi1=0, float dtb1=0) {
			hoten = hoten1;
			tuoi = tuoi1;
			dtb = dtb1;
		}
		friend ostream& operator << (ostream& os, Sinh_vien& r);
		friend istream& operator >> (istream& is, Sinh_vien& r);
		bool operator > (Sinh_vien& r) {
			return dtb>r.dtb;
		}
		bool operator < (const Sinh_vien& r);
		friend void sapxep(Sinh_vien a[], int n);
	private:
		string hoten;
		int tuoi;
		float dtb;
};
//----------------------------------//
ostream & operator << (ostream & os, Sinh_vien & r) {
	os << r.hoten << "," << r.tuoi << ", " << r.dtb << endl;
	return os;
}
//----------------------------------//
istream & operator >> (istream & is, Sinh_vien & r) {
	cout << "Nhap ho va ten:";
	is >> r.hoten;
	cout << "Nhap tuoi:";
	is >> r.tuoi;
	cout << "Nhap diem trung binh:";
	is >> r.dtb;
	return is;
}
//----------------------------------//
bool Sinh_vien::operator < (const Sinh_vien & r) {
	// so sanh theo diem trung binh
	if(dtb<r.dtb)
		return true;
	return false;
}
//----------------------------------//
void sapxep(Sinh_vien a[], int n) {
	sort(a, a+n); // goi tu thu vien algorithm
}
//----------------------------------//
int main() {
	int a1[] = {10, 2, 13, 24};
	string s1[] = {"Kim Tan", "Bi Rain", "Le Roi", "Tran Trang"};
	int n1 = 4;
	//List<int> mi(a1, n1);
	//List<string> ms(s1, n1);	
	List<int> mi;
	List<string> ms;
	List<Sinh_vien> mhs;
	mhs.nhap();
	mi.nhap();
	ms.nhap();
	mhs.ghifile("Sinh_vien.txt");
	mhs.sort();
	ms.sort();
	mi.sort();
	ms.xuat();
	mi.xuat();
	mhs.xuat();
	int kq = ms.timkiem(string("Teo"));
	if(kq>=0)
		cout << "Tim thay Teo o vi tri " << kq << endl;
	else
		cout << "Khong tim thay Teo" << endl;
	return 0;
}
