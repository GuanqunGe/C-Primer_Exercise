#include <iostream>
#include <string>
#include <vector>

int main(){

    std::vector<char> cvec = {'c', 'h','a','r', 'l','i','e'};
    //std::string str(cvec.begin(), cvec.size());  // wrong, cvec.begin() is iterator, not pointer
    std::string str(&cvec[0], cvec.size());
    std::cout << str << std::endl;

    std::string str2(cvec.begin(), cvec.end());
    std::cout << str2 << std::endl;
    std::cout << str2.substr() << std::endl;  // str.substr() == str
    return 0;
}
