#include <iostream>

int main(){

    int i  = 42;
    int *p = &i;
    *p = *p * *p;

    std::cout << "now *p is " << *p << ", i is " << i << std::endl;
    return 0;
}
