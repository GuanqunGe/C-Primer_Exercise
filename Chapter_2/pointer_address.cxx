#include <iostream>

int main(){

    int i = 2, j = 3;
    int *p = &i;

    std::cout << i << " " << *p << std::endl;
    std::cout << "address of i is " << &i << std::endl;
    std::cout << "p is " << p << " (expected address of i)" << std::endl;
    std::cout << "address of p is " << &p << std::endl;

    p = &j;
    std::cout << j << " " << *p << std::endl;
    std::cout << "address of j is " << &j << std::endl;
    std::cout << "p is " << p << " (expected address of j)" << std::endl;
    std::cout << "address of p is " << &p << std::endl;

    return 0;
}
