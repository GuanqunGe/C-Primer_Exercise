#include <iostream>

using std::cout;
using std::endl;
int main(){

    int i = 0;
    cout << "i is " << i << endl;
    *(&i)  = 1;
    cout << "i is " << i << endl;

    return 0;
}
