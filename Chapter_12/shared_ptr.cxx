#include <iostream>
#include <memory>

int main(){

    std::shared_ptr<int> ptr; //null pointer
    std::cout << "Use count: " << ptr.use_count() << ", is unique? " << (ptr.unique() ? "true" : "false" ) << std::endl;

    ptr = std::make_shared<int>(100);
    std::cout << "Use count: " << ptr.use_count() << ", is unique? " << (ptr.unique() ? "true" : "false" ) << std::endl;

    return 0;
}
