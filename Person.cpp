#include <iostream>
#include <cstring>
using namespace std;
class Person {
private:
    char name[50];
public:
    void setName(const char* newName) {       
            strcpy(name, newName);        
    }    
    const char* getName() {
        return name;
    }
};
int main() {
    Person p;
    p.setName("Nguyen Van A");
    cout << "Ten: " << p.getName() << endl;
    return 0;
}

