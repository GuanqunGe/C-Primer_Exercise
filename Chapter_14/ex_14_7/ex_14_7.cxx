#include "String.h"
#include <iostream>
#include <vector>

int main(){
    String s1;

    String s2 = "Hello World!";
    String s3 = s2;
    s3.push_back('?');
    String s4(10, 'c');

    std::vector<String> vec;
    vec.push_back("Monday");
    vec.push_back(String("Tuesday"));
    vec.push_back(String(5, 'F'));
    vec.push_back(s3);
    vec.push_back("Friday");

    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    return 0;
}
