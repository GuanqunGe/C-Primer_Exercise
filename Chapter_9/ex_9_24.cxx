#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec;
    
    std::cout << vec[0] << std::endl;  // no compilation error, run-time error of segmentation fault

    // at member: no compilation error, exception of std::out_of_range throwed in run-time:
    //'''terminate called after throwing an instance of 'std::out_of_range'
    //   what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
    //   Aborted'''
    std::cout << vec.at(0) << std::endl;

    std::cout << vec.front() << std::endl; // no compilation error, run-time error of segmentation fault


    std::cout << *vec.begin() << std::endl; // no compilation error, run-time error of segmentation fault


    return 0;
}
