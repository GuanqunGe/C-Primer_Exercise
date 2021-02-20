#include <iostream>
#include <string>
#include <memory>
using std::string;

int main(){

    string s = "Hello";
    string *ps = &s;
    std::cout << s << " " << *ps << std::endl;

    *ps = "Hey";
    std::cout << s << " " << *ps << std::endl;

    string *ps2 = new string("hello");
    std::cout << ps2 << " " << *ps2 << std::endl;

    *ps2 = *ps;
    std::cout << ps2 << " " << *ps2 << std::endl;
   
    delete ps2;
    return 0;
}
