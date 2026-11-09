#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ofstream my_file;
	my_file.open("example.txt");
	for(int i=0; i<100; i++)
		my_file << i << " ";
	my_file.close(); 
	return 0;
}
