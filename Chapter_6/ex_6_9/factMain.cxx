#include <iostream>
#include "../include/Chapter6.h"

int main(){

    int input;
    std::cout << "Please enter an integer.." << std::endl;
    std::cin >> input;
    std::cout << input << "! = " << fact(input) << std::endl;

    return 0;
}
