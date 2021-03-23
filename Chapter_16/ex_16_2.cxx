#include <iostream>
#include <string>
#include <vector>
#include <functional>

template <typename T>
int compare(const T &v1, const T &v2){
    if(v1 < v2) return 1;
    if(v2 < v1) return -1;
    return 0;
}

template <typename T>
int compare_all(const T &v1, const T &v2){
    if(std::less<T>()(v1, v2)) return 1;
    if(std::less<T>()(v2, v1)) return -1;
    return 0;
}

int main(){
    std::cout << compare(std::string("Hello"), std::string("Hey")) << " expected: 1" << std::endl; 
    //std::cout << compare("Hello", "Hey") << " expected: 1" << std::endl; //error, compiler will detect the string literal as const char [], and these two arguments have different length..
    std::cout << compare("Hello", "Hayyy") << " expected: -1" << std::endl; // OK, T is const char [6], but it's comparing two unrelated address isnt' it?
									   // that's right, it's not comparing the content, but comparing addresses
									   // definitely need to use std::strcmp() if we want to compare content of two const char[]
    
    std::cout << compare(1, -1) << " expected: -1" << std::endl;
    std::cout << compare(std::vector<int>({1,2,3}), std::vector<int>({4,5,6})) << " expected: 1" << std::endl;


    const char arr1[]="Hello";
    const char arr2[]="Hey";
    std::cout << compare_all(std::string("Hello"), std::string("Hey")) << " expected: 1" << std::endl;
    //std::cout << compare_all(arr1, arr2) << std::endl; // error, compiler will detect the type of T as const char [], instead of const char*, 
						       // and these two arrays have different size. 
						       // Even if I compare two arrays with the same size in this way, the code will successfully 
						       // compile and run but the result will not be the same as you would  expect.
    std::cout << compare_all(&arr1[0], &arr2[0]) << std::endl;

    return 0;
}
