#include <iostream>

int main(){

    std::cout << "Enter a number please" << std::endl;
    std::cin >> int input_value;     //wrong, need to define the variable, before read stuff into it.
    std::cout << "Value entered: " << input_value << std::endl;


    int i={3.14};   //{} initialization does not allow narrowing conversion
    int i=3.14;
    std::cout << "Value of i: " << i << std::endl;

    double salary = wage = 999.9;   //wrong, wage is not defined when you tried to initialize salary
    double wage = 999.9, salary=wage;

    return 0;
  
}
