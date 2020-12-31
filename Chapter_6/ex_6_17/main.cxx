#include "string_manipulation.h"
#include <iostream>

int main(){

    std::cout << "String 'Hello World!' has capital letter? " << (has_capital("Hello World!") ? "True" : "False" ) << std::endl;
    std::cout << "String 'hello world!' has capital letter? " << (has_capital("hello world!") ? "True" : "False" ) << std::endl;

    std::string s("2020 SUCKS");
    std::cout << s << ", lower case version: ";
    to_lowercase(s);
    std::cout << s << std::endl;

    return 0;
}
