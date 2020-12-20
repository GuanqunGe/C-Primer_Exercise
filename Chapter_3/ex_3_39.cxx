#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(){

    string s1 = "Hello I am Gretchen", s2 = "Hello I am Greg";

    //compare two strings
    if(s1 < s2) cout << "string " << s1 << " is smaller than string " << s2 << endl;
    else if(s1 > s2) cout << "string " << s1 << " is larger than string " << s2 <<endl;
    else cout << "two strings are the same: " << s1<< endl;


    const char ca1[] = "Hello I am Gretchen", ca2[]="Hello I am Greg";
    //compare two C-style strings
    //can use cout << ca1 to print out C-style strings, but it will only stop printing the characters when it sees a null character
    if(strcmp(ca1, ca2) < 0) cout << ca1 << "is smaller than " << ca2 <<endl;
    else if(strcmp(ca1, ca2) > 0) cout << ca1 << " is larger than " << ca2 << endl;
    else cout << "two C-style strings are the same: " << ca1 << endl;


    const char ca3[] = {'h', 'e', 'e', 'q'};
    //can use cout << ca1 to print out C-style strings, but it will only stop printing the characters when it sees a null character
    cout << ca3 << endl; 

    return 0; 

}
