#include <iostream>
#include <type_traits>
#include <typeinfo>

template <typename T>
auto sum(T lhs, T rhs) -> typename std::make_unsigned<T>::type{
    return lhs + rhs;
}

int main(){

    auto result = sum<int>(1, 3);
    std::cout << result << ", type: " << typeid(result).name() << std::endl;

    return 0;
}
