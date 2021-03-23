#include <iostream>

template<typename T, unsigned N>
constexpr unsigned size( const T (&array)[N]){
    return N;
}

int main(){
    const char p[] = "String";
    std::cout << "size of p[] is " << size(p) << std::endl;

    std::cout << "size of \"Hello\" is " << size("Hello")-1 << std::endl;

    return 0;
}
