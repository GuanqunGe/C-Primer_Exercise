#include <iostream>
#include <string>
#include <memory>
#include <utility>

template <typename T, typename... Args>
std::shared_ptr<T>  MakeShared(Args&&... args){

    T* pt = new T(std::forward<Args>(args)...);
    return std::shared_ptr<T>(pt);
}

int main(){
    std::shared_ptr<int> ip = MakeShared<int>();
    std::cout << *ip << std::endl;

    std::shared_ptr<std::string> sp = MakeShared<std::string>(10, 'h');
    std::cout << *sp << std::endl;

    return 0;
}
