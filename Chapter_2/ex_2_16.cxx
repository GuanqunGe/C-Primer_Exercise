#include <iostream>

int main(){

    int i=3, &r1 = i;
    double d = 4.0, &r2 = d;

    r2 = 3.14159;
    std::cout << "d is "<< d << "( expected 3.14159)" << std::endl;
  
    r2 = r1;
    std::cout << "d is " << d << " (expected 3) " << std::endl;


    i = r2;
    std::cout << "i is " << i << "( expected 3 - int)" << std::endl;

    r1 = d;
    std::cout << "i is " << i <<  "(expected 3 - int)" << std::endl;

    return 0;
}
