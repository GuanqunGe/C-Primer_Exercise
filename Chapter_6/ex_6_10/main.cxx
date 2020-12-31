#include <iostream>
#include "swap.h"

int main(){

    int val1, val2;
    std::cout << "Please enter two integers to swap" << std::endl;
    std::cin >> val1 >> val2;
 
    std::cout << "Before swap: " << val1 << " " << val2 << std::endl;

    swap(&val1, &val2);   //use pointers to swap values of two variables
 
    std::cout << "After swap: " << val1 << " " << val2 << std::endl;

    return 0;
}
