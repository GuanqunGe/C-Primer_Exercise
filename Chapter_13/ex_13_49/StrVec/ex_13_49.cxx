#include "StrVec.h"
#include <iostream>
#include <utility> //to use std::move()

int main(){
 
    StrVec v1;
    v1.push_back("Hello");
    v1.push_back("Jenny");
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    StrVec v2 = v1; 
    v2.push_back("2021");
   
    for(auto iter = v2.begin(); iter != v2.end(); ++iter)
	std::cout << *iter << " ";
    std::cout << v2.size() << " " << v2.capacity() << std::endl;


    v2.reserve(10);
    v2.push_back("Year of Ox");
    for(auto iter = v2.begin(); iter != v2.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    v2.resize(6, "LOL");
    for(auto iter = v2.begin(); iter != v2.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    StrVec v3 = {"I", "Want", "To", "Learn", "Violin"};
    for(auto iter = v3.begin(); iter != v3.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << v3.size() << " " << v3.capacity() << std::endl;
    v3.resize(3, "HA");
    for(auto iter = v3.begin(); iter != v3.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << v3.size() << " " << v3.capacity() << std::endl;

 
    const StrVec v4 = {"Today", "is", "Tuesday"};
    std::cout << v4.size() << " " << v4.capacity() << std::endl;
    std::cout << *v4.begin() << " " << v4[0] << std::endl;


    //test move constructor and move assignment
    StrVec v5 = std::move(v3);
    std::cout << v5.size() << " " << v5.capacity() << std::endl;
    std::cout << v3.size() << " " << v3.capacity() << std::endl;

    v3 = std::move(v5);
    std::cout << v5.size() << " " << v5.capacity() << std::endl;  
    std::cout << v3.size() << " " << v3.capacity() << std::endl;  
    return 0;
}
