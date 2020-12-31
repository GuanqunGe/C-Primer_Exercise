#include <iostream>
#include <string>

constexpr bool isShorter(const std::string &s1, const std::string &s2){
    return s1.size() < s2.size();
    //return true;
}

int main(){
    std::cout << isShorter("Hello", "Hi") << std::endl;
    return 0;
}
