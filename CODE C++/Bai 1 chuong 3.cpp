#include<iostream>
#include<fstream>
using namespace std;
int a[100], n;
void Nhap_mang();
void Ghi_mang();
void Doc_mang();
//------------------------//
int main() {
	//Nhap_mang();
	//Ghi_mang();
	Doc_mang();
	return 0;
}
//------------------------//
void Nhap_mang() {
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << "a[" << i << "]= ";
		cin >> a[i];		
	}		
}
//------------------------//
void Ghi_mang() {
	ofstream ghi_file("du_lieu.txt");
	if(ghi_file.is_open()) {
		for(int i=0; i<n; i++)
			ghi_file << a[i] << " ";
	}
	else
		cout << "Khong mo duoc file";
	ghi_file.close();
}
//------------------------//
void Doc_mang() {
	string noi_dung;
	ifstream doc_file("du_lieu.txt");
	if (doc_file.is_open()) {
		while(!doc_file.eof()) {
			getline(doc_file,noi_dung);
			cout << noi_dung << " ";			
		}
	}
	else
		cout << "Khong mo duoc file";
	doc_file.close();	
}
//------------------------//








