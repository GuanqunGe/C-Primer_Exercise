#include <iostream>
#include <string>
#include <cstring>

int main(){

    std::cout << "Input: a string" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    int length = input.size() + 1; // +1 for size, to hold '\0'
    char *p = new char[length];
    // p = input.c_str(); //wrong, as c_str() returns const char *
    std::strcpy(p, input.c_str());

    std::cout << "Output: " << p << std::endl;
    delete [] p;
    return 0;
}

// handling varying size input:
// since in new T[], the length of array can be a non-constant,so we can always
// use the size of string read from the input to allocate array with enough size.

// std::strcpy( p, (input + "!").c_str()); seems to work just as fine
