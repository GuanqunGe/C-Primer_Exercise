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


    //after define the move constructor
    //push_back() uses move constructor to construct new elementsinstead of copy constructor
    //during reallocation of vector, move constructor is also used.
    std::vector<String> vec;
    vec.push_back("Monday");
    vec.push_back(String("Tuesday"));
    vec.push_back(String(5, 'F'));
    vec.push_back(s3);
    vec.push_back("Friday");
    //my only question left now, is what's the type of parameter in push_back()??
    //looks like for vector<T>, push_back(T p);
    //but vec.push_back(String("Tuesday")); did not use copy constructor to construct local variable p, so I am a bit confused.
    //after reading section 13.6.3, it becomes clear to me: there are two overloaded push_back() functions:
    // - void push_back(const X&); and - void push_back(X &&);
    //that's why copy constructor is used when s3 is used as argument of push_back().

    return 0;
}
