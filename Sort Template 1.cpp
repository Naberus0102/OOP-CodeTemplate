#include<iostream>
#include <iomanip>
using namespace std;
//----------------------------//
template <typename myT, typename myU>
void Sort(myT a[], myU n, myU m) {
	for (myU i = n; i < m - 1; i++) {   
           myU min_idx = i;   
        for (myU j = i + 1; j < m; j++) {
            if (a[j] > a[min_idx]) {        
                min_idx = j;
            }
        }                
        myT temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}
//----------------------------//
class Sinh_Vien {
    string 	hoTen;
    string 	maSV;
    float 	diemTichLuy;
public:
    Sinh_Vien() : hoTen(""), maSV(""), diemTichLuy(0.0) {
	}
    
    Sinh_Vien(string ht, string ma, float d) {
        hoTen = ht;
        maSV = ma;
        diemTichLuy = d;
    }
    
	// Nap chong toan tu <
    bool operator>(const Sinh_Vien& other) const {
        return diemTichLuy > other.diemTichLuy;
    }
    
    void xuat() const {       
        cout << left << setw(20) << hoTen << setw(10) << maSV
             << setw(10) << diemTichLuy << endl;
    }
};
//----------------------------//
int main() {
	int a_i[] = {4, 8, 7, 9, 12, 32, 26, 11, 21, 17, 5};
	Sort<int,int>(a_i, 0, sizeof(a_i)/sizeof(a_i[0]));
	for(int i=0; i< sizeof(a_i)/sizeof(a_i[0]); i++)
		cout << a_i[i] << "  ";
	
	cout << endl << endl;	
	float a_f[] = {4.5, 8.1, 3.7, 2.9, 1.2, 3.2, 2.6, 1.1, 2.1, 1.7, 5.6};
	Sort<float,int>(a_f, 0, sizeof(a_f)/sizeof(a_f[0]));
	for(int i=0; i< sizeof(a_f)/sizeof(a_f[0]); i++)
		cout << a_f[i] << "  ";
	
	cout << endl << endl;	
	char a_ch[] = {'b', 'c', 'f', 'g', 'u', 'm', 'v', 'n', 'd', 'a', 'q'};
	Sort<char,int>(a_ch, 0, sizeof(a_ch)/sizeof(a_ch[0]));
	for(int i=0; i< sizeof(a_ch)/sizeof(a_ch[0]); i++)
		cout << a_ch[i] << "  ";
	
	cout << endl << endl;
	Sinh_Vien sv[] = {
        Sinh_Vien("Nguyen Van A", 	"SV01", 	7.8),
        Sinh_Vien("Tran Thi B", 	"SV02", 	8.5),
        Sinh_Vien("Le Van C", 		"SV03", 	6.9),
        Sinh_Vien("Steve Cornel", 	"SV04", 	4.2),	
        Sinh_Vien("John Stone", 	"SV05", 	7.5),
        Sinh_Vien("Michael Kate", 	"SV06", 	9.1),
        Sinh_Vien("Harry Maguire", 	"SV03", 	7.2)
    };
    Sort<Sinh_Vien,int>(sv, 0, sizeof(sv)/sizeof(sv[0])); // sap xep giam dan theo diem tich luy
    for(int i = 0; i < sizeof(sv)/sizeof(sv[0]); i++)
		sv[i].xuat();	
	
	return 0;
}

