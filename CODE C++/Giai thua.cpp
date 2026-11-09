#include <iostream>
using namespace std;
int A;
int n = 10;

int Giai_thua(int n){
	if (n == 0)
		return 1;
	else
		return (n*Giai_thua(n-1));
}

int main ()
{

    cout << "Nhap vao 1 so:";
	cin >> n;


	A = 1;
	int i;
	for (i=1;i<=n;i++)
    {
        A=A*i;
        //cout << i;
    }


	//cout << "Giai thua la:" << Giaithua (n);
	cout << "Giai thua la:" << A;

return 0;
}
