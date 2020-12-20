#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){

    string s1, s2;
    cout << "Please enter two strings to compare" << endl;
    cin >> s1 >> s2;
   
    //compare which string is larger 
/*    if(s1 == s2) cout << "Two strings are the same: " << s1 << endl;
    else if (s1 > s2) cout << s1 << " is larger than " << s2 << endl;
    else cout << s1 << " is smaller than " << s2 << endl;
*/


    //compare the length
    if(s1.size() == s2.size()) cout << "Two strings have the same length" << endl;
    else if(s1.size() > s2.size()) cout << s1 << " has longer length than " << s2 << endl;
    else cout << s2 << " has longer length than " << s1 << endl;
    return 0; 
}
