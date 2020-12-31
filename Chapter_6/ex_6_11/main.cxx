#include "reset.h"
#include <iostream>

int main(){

    int i = 4;
    std::cout << "i: " << i << std::endl;
    reset(i);
    std::cout << "i: " << i << std::endl;

    return 0;
}
