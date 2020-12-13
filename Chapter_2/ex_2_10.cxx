#include <iostream>

std::string global_str;
int global_int;

int main(){

    int local_int;
    std::string local_str;

    std::cout<<"Global string: " << global_str << std::endl;
    std::cout << "Global int: " << global_int << std::endl;
    std::cout << "Local string: "<< local_str << std::endl;
    std::cout << "local int: " << local_int << std::endl;

    return 0;
}
