#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;

int main(){

    const string s = "Keep out!";
    for(auto &c : s){   // c is a const char &
 	c = toupper(c);  //wrong, can't change a read-only type
 	cout << s << endl;
    }
  
    return 0;
}
