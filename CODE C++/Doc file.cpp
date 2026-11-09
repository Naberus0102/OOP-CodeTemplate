#include<iostream>
#include<fstream>
using namespace std;
int main() {
	string line;
	ifstream myfile("example.txt");
	while(!myfile.eof()) {
		getline(myfile,line);
		cout << line << " ";		
	}
	myfile.close();
	return 0;
}
