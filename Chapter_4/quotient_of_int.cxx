#include <iostream>

using std::cout;
using std::endl;

int main(){

    double x = 21/6;
    cout << "21/6 in c++ is " << x << endl;   //will print out '3'

    x = 21/-6;
    cout << "21/-6 in c++ is " << x << endl;   //will print out '-3', quotient is alway truncated toward 0 in C++11 standard
    
    return 0;
}
