#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::endl;

int main(){

    string s = "hello World!!";

    //auto c = s[0];   //c is not a reference to the 0th character of string s, it's a char
    auto &c = s[0];  // c is now a reference to the 0th character
    c = toupper(c);
 
    s[1] = toupper(s[1]);

    cout << s << endl;

    return 0;
}
