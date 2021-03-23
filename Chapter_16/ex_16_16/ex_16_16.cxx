#include <iostream>
#include "Vec.h"
#include <string>


template <typename T>
void printVec(const Vec<T> &v){
    for(auto iter = v.begin(); iter != v.end(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;
}

void test_Vec(){
    Vec<int> ivec = {1, 2, 3, 4, 5};
    std::cout << ivec.size() << " " << ivec.capacity() << std::endl;
    ivec.push_back(6);
    std::cout << ivec.size() << " " << ivec.capacity() << std::endl;
    printVec(ivec);

    Vec<std::string> svec;
    std::cout << svec.size() << " " << svec.capacity() << std::endl;
    svec.push_back("Hello"); svec.push_back("How are you? " );
    std::cout << svec.size() << " " << svec.capacity() << std::endl;

    Vec<std::string> svec2 = svec;
    printVec(svec2);
}


int main(){
    test_Vec();
    return 0;
}
