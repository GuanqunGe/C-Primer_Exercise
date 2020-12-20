/* this is to answer my question of:
 * whether or not can a pointer point to element in a container or a char in string
 *
 * The answer is yes! 
 * 1. When we say we can't take address of reference, we mean that a reference is not an object, so it does not have an address.
 * 2. Taking the address of a reference will yield the address of its referent.
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){

    string s = "Hello World!";
    // s[1] is a reference to the 1th char in s.

    auto c = s[1];   // c is a char of value 'e'

    auto &rc = s[1]; //rc is a reference to the 1th char in string s

    auto *pc = &s[1];   //holly!! it's okay to take address of reference?
    *pc = 'E';
    cout << s << endl;   //'HEllo World!'


    //try to take address of an reference to int
    int i = 4, &r = i;
    int *pi = &r;
    (*pi)++;
    cout << "Address of i: " << &i << " " << &r << endl;   // &r and &i yield the same result
    cout << i << endl;

    return 0;
}
