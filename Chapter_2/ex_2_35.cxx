#include <iostream>

int main(){

    const int i = 42;
    auto j = i; j++;  //j is int
    std::cout << "i is " << i << ", j is " << j << std::endl;

    const auto &k = i;
    std::cout << "k is " << k << std::endl;
    k++; //wrong, k is const int &
    std::cout << "k is " << k << std::endl;


    auto *p = &i;
    (*p)++;   //wrong, p is const int *
    std::cout << "object p points to is " << *p << std::endl;


    const auto j2 = i, &k2 = i;
    std::cout << "j2 is "<< j2 << std::endl;
    j2++;  //wrong, j2 is const int

    
    k2++;// wrong, k2 is a const int &
    
}
