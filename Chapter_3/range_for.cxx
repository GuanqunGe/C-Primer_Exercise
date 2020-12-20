#include <iostream>
#include <string>
#include <cctype>   // to use the 'toupper()' function

using std::string;
using std::cout;
using std::endl;

int main(){

    string s = "Hello World!!!";
    //covert s to uppercase
    for(auto &c : s){   
        c = toupper(c);  //s is being changed gradually, one char by one char
        cout << s << endl;
    }

    return 0;
}
