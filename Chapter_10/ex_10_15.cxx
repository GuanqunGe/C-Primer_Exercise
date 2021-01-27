#include <iostream>

int main(){

    int i = 30;
    auto f = [i] (int i1) -> int {return i + i1; };
    //int (*f) (int) = [i] (int i1) -> int {return i + i1; };  // wrong somehow, safer to use 'auto' instead

    int j = 4;
    std::cout << i << "+" << j << "=" << f(j) << std::endl;  //printed out: 30+4=34

    i = 100, j =5;
    std::cout << i << "+" << j << "=" << f(j) << std::endl; // printed out: 100+5=35
    // so seems like lambda expression only uses values of variables in the capture list at the time lambda expression is defined. It does not respond to later-updated values.

    return 0;
}
