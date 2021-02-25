#include "StrVec.h"
#include <iostream>
#include <utility> //to use std::move()

int main(){
 
    StrVec v1;
    v1.push_back("Hello");
    v1.push_back("Jenny");
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    StrVec v2 = v1; 
    std::cout << "v1 == v2: " << (v2==v1 ? "true" : "false" ) << std::endl; 
    std::cout << "v1 != v2: " << (v2!=v1 ? "true" : "false" ) << std::endl; 
    std::cout << "v1 < v2: " << (v1 < v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 <= v2: " << (v1 <= v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 >= v2: " << (v1 >= v2 ? "true" : "false" ) << std::endl;

    v2.push_back("2021");
    std::cout << "v1 == v2: " << (v2==v1 ? "true" : "false" ) << std::endl; 
    std::cout << "v1 != v2: " << (v2!=v1 ? "true" : "false" ) << std::endl; 
    std::cout << "v1 < v2: " << (v1 < v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 <= v2: " << (v1 <= v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2 ? "true" : "false" ) << std::endl;
    std::cout << "v1 >= v2: " << (v1 >= v2 ? "true" : "false" ) << std::endl;

 
    v2.reserve(10);
    v2.push_back("Year of Ox");
    v2.resize(6, "LOL");

    StrVec v3 = {"I", "Want", "To", "Learn", "Violin"};
    v3.resize(4, "HA");
     
    const StrVec v4 = {"Today", "is", "Tuesday"};
    std::cout << "v4 < v3 : " << (v4 < v3 ? "true" : "false" ) << std::endl;
    std::cout << "v4 > v3 : " << (v4> v3 ? "true" : "false") << std::endl;    
     
    //test move constructor and move assignment
    StrVec v5 = std::move(v3);
    std::cout << v5.size() << " " << v5.capacity() << std::endl;
    std::cout << v3.size() << " " << v3.capacity() << std::endl;

    v3 = std::move(v5);
    std::cout << v5.size() << " " << v5.capacity() << std::endl;  
    std::cout << v3.size() << " " << v3.capacity() << std::endl;  

    v5 = {"Today", "is", "Sunday"};
    std::cout << v5.size() << " " << v5.capacity() << std::endl;
    std::cout << "v5 > v4: " << ( v5 > v4 ? "true" : "false" ) << std::endl;

    std::cout << v4[0] << std::endl;
    std::cout << v5[0] << std::endl;
    v5[0] = "Tomorrow";
    std::cout << v5[0] << std::endl;
    return 0;
}
