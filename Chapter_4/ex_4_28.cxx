#include <iostream>

using std::cout;
using std::endl;

int main(){
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of bool: " << sizeof(bool) << endl;
    cout << "size of unsigned int: " << sizeof(unsigned int) << endl;

    //can we print out size of a reference? --> yes, it'll just be size of the object the reference refers to
    cout << "size of a int pointer: " << sizeof(int*) << endl;
    cout << "size of a int reference: " << sizeof(int &) << endl;
    return 0;
}
