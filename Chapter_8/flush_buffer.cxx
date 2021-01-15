#include <iostream>

int main(){
    std::cout << "hi" << std::endl;
    std::cout <<" hi, flush" << std::flush;
    std::cout << "hi, ends" << std::ends;

    std::cout << std::unitbuf;
    std::cout << "how are you";
    std::cout << " I am ok" << std::endl;
    return 0;
}
