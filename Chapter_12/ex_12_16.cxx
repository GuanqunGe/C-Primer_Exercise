#include <iostream>
#include <memory>

int main(){

    std::unique_ptr<int> p1(new int(100));
    std::cout << "p1 points to: " << *p1 << std::endl;

    //std::unique_ptr<int> p2(p1); //error message: use of deleted function
    std::unique_ptr<int> p2 = p1; //same error message
    std::cout << "p2 points to: " << *p2 << std::endl;

    return 0;
}
