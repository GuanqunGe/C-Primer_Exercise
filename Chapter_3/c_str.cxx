#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){

    string s = "HelloWorld!";
    auto str = s.c_str();  //str is a const char pointer, point to the first element of character array
    cout << *str << endl;  //expect to see 'H'
    cout << str << endl;   //expect to see "HelloWorld!"


    //now let's change s
    s = "GoodBye!";
    cout << str << endl; //now str is invalid, you'll compilation error here.
    cout << *str << endl;  //wrong, str is invalid.
    return 0;
}
