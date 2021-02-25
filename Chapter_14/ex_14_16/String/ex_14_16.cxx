#include "String.h"
#include <iostream>
#include <vector>

int main(){
    String s1;

    String s2 = "Hello World!";
    String s3 = s2;
    String s4(10, 'c');

    std::cout << "s2 == s3: " << (s2 == s3 ? "true" : "false" ) << std::endl;
    std::cout << "s2 <= s3:" << (s2 <= s3 ? "true" : "false") << std::endl;
    std::cout << "s2 == s4:" << (s2 == s4 ? "true" : "false" ) << std::endl;
    std::cout << "s2 < s4: " << (s2 < s4 ? "true" : "false" ) << std::endl;

    s2.push_back('L');
    std::cout << "s2 == s3: " << (s2 == s3 ? "true" : "false" ) << std::endl;
    std::cout << "s2 < s3: " << (s2 < s3 ? "true" : "false" ) << std::endl;
    std::cout << "s2 > s3: " << (s2 > s3 ? "true" : "false" ) << std::endl;
    std::cout << "s2 >= s3: " << ( s2 >= s3 ? "true" : "false") << std::endl;

    s2 = s4;
    std::cout << "s2 == s4:" << (s2 == s4 ? "true" : "false" ) << std::endl;
    std::cout << "s2 < s4: " << (s2 < s4 ? "true" : "false") << std::endl;
    std::cout << "s2 > s4: " << (s2 > s4 ? "true" : "false") << std::endl;

    std::vector<String> vec;
    vec.push_back("Monday");
    vec.push_back(String("Tuesday"));
    vec.push_back(String(5, 'F'));
    vec.push_back(s3);
    vec.push_back("Friday");

    std::cout << vec[0][1] << std::endl;
    vec[0][1] = 'F';
    std::cout << vec[0][1] << std::endl;

    const String s5("Triangle");
    std::cout << s5[2] << std::endl;
    //std::cout << s5[10] << std::endl;

    return 0;
}
