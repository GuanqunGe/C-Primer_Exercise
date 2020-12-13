#include <iostream>

int main(){

    int i= 2, j= 3;
    int *p = nullptr;
    std::cout << "now p is: " << p << std::endl;

    p = &i;
    std::cout << "now p is: " << p << ", address of i is " << &i << ", i is " << i << std::endl;
    *p = 4;
    std::cout << "now p is: " << p << ", address of i is " << &i << ", i is " << i << std::endl;

    p = &j;
    std::cout << "now p is: " << p << ", address of j is " << &j << ", j is " << j << std::endl;

    return 0;

}
