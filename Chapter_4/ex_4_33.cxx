#include <iostream>

using std::cout;
using std::endl;

int main(){

    int x = 10, y = 10;
    (x== y)? ++x, ++y:--x, --y;

    cout << "x: " << x << ", y: "<< y << endl;

    return 0;
}
