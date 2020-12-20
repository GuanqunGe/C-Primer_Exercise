#include <iostream>

using std::cout;
using std::endl;

int main(){

    const char ca[] = {'h', 'e', 'l','l','o'};
    const char *cp = ca;
    while(*cp){  // when cp is at or after the off-the-end pointer, the behavior is undefined
        cout << *cp << endl;
        ++cp;
    }
    return 0;
}
