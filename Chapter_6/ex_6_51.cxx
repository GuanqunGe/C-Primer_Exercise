#include <iostream>

void f(){
    std::cout << "This function does nothing" << std::endl;
}

void f(int val){
    std::cout << "This function takes 1 int variable: " << val << std::endl;
}

void f(int val1, int val2){
    std::cout << "This function takes 2 int variable: " << val1 << ", " << val2 << std::endl;
}

void f(double d1, double d2 = 3.14){
    std::cout << "This function takes 1~2 double variables: " << d1 << ", " << d2 << std::endl;
}

int main(){
    // f(2.56, 42);  //ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
