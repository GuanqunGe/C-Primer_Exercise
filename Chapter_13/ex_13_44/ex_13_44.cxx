#include "String.h"
#include <iostream>
#include <vector>

int main(){
    String s1;

    String s2 = "Hello World!";
    String s3 = s2;
    String s4(10, 'c');

    std::cout << s2.size() << " " << s2.capacity() << " " <<  s2.empty() << std::endl;

    s2.push_back('L');
    std::cout << s2.size() << " " << s2.capacity() << " " <<  s2.empty() << std::endl;

    s2 = s4;
    std::cout << s2.size() << " " << s2.capacity() << " " <<  s2.empty() << std::endl;


    std::vector<String> vec;
    vec.push_back("Monday");
    vec.push_back(String("Tuesday"));
    vec.push_back(String(5, 'F'));
    vec.push_back("Friday");

    return 0;
}
