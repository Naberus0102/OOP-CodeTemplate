#include<iostream>
using namespace std;
//============================//
class Matrix {
	int h, c;
	float *a;
public:
	Matrix() {
 		h=c=0;
 		a=NULL;
 	}
 	~Matrix() {
 		delete []a;
 		h=c=0;
 	}
 	Matrix &operator=(const Matrix &p);
 	friend istream &operator>>(istream &is, Matrix &p);
 	friend ostream &operator<<(ostream &os, Matrix &p); 
 	Matrix &operator++();//++x
 	Matrix &operator++(int);//x++
 	void random(int hh=3, int cc=3);
};
//============================//
Matrix &Matrix::operator=(const Matrix &p) {
	this->h=p.h;
	this->c=p.c;
	this->a=new float [h*c];
	for(int i=0; i<h; i++)
 		for(int j=0; j<c; j++)
 			*(a+c*i+j)=*(p.a+p.c*i+j);
 			//*(a+i)=*(p.a+i);
 	return *this;
}
//============================//
istream &operator>>(istream &is, Matrix &p) {
	cout<<"Nhap so hang, so cot: ";
 	is>>p.h>>p.c;
 	p.a=new float [p.h*p.c];
 	for(int i=0; i<p.h; i++)
 		for(int j=0; j<p.c; j++) {
 			cout<<"Nhap pt "<<i<<","<<j<<"= ";
 			is >> *(p.a+p.c*i+j);
 	}
 return is;
}
//============================//
ostream &operator<<(ostream &os, Matrix &p) {
	for(int i=0; i<p.h; i++) {
 		for(int j=0; j<p.c; j++)
 			os << *(p.a+p.c*i+j)<<" ";
 		os<<endl; 
 	}
 return os;
}
//============================//
int main() {
	return 0;
}
//============================//
