#include<iostream>
using namespace std;
//--------------------------//
template <class T>
T tMax (T a[], int N, int M) {
	T max = a[N];
	for (int i = N+1; i < M; i++)
		if (max < a[i])
			max = a[i];
	return max;
}
int main() {
	int n = 0, m;
	
	int a_int[] = {34, -56, 21, 44, 12};
	m = sizeof(a_int)/sizeof(a_int[0]);
	cout << tMax<int>(a_int, n, m);
	
	cout << "\n";
	
	float a_float[] = {3.4, -5.6, 2.1, 4.4, 1.2};
	m = sizeof(a_float)/sizeof(a_float[0]);
	cout << tMax<float>(a_float, n, m);
	
	cout << endl;
	for (int i = n; i < m; i++)
		cout << a_float[i] << "  ";	
	
	return 0;	
}
