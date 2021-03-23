#include <iostream>
#include <string>
#include "Screen.h"

void test_Screen(){
    Screen<int, char> s1(5, 5, 'h');
    std::cout << s1.get() << " " << s1.get(4,4) << std::endl;
    std::cout << s1.move(1,1).get() << std::endl;

    Screen<size_t, std::string> s2(3, 3, "Hello");
    std::cout << s2.get(1, 0) << std::endl;
    std::cout << s1 << s2 << std::endl; 

    Screen<int, int> s3;
    Screen<int, char> s4;
    std::cin >> s3 >> s4;
    std::cout << s3 << s4 << std::endl;
}

int main(){
    test_Screen();
    return 0;
}
