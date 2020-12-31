#include "swap.h"
#include <iostream>

int main(){

    int val1 = 1, val2 = 2;
    std::cout << "Before swap, val1: " << val1 << ", val2: " << val2 << std::endl;
  
    swap(val1, val2);
    std::cout << "After swap, val1: " << val1 << ", val2: " << val2 << std::endl;

    return 0;
}
