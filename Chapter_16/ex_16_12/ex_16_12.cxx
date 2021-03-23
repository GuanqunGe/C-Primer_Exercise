#include <iostream>
#include <vector>
#include <string>
#include "Blob.h"
#include "BlobPtr.h"

void test_Blob(){
    Blob<int> ivec={1,2,3,4};
    ivec.push_back(5);
    std::cout << "size: " << ivec.size() << " "<< ivec.back() << std::endl;
    std::cout << ivec[3]<< std::endl;


    Blob<std::string> strvec;
    std::cout << "is strvec empty? " << (strvec.empty() ? "true" : "false") << std::endl;
    strvec.push_back("Hello");
    std::cout << "size: " << strvec.size() << " " << strvec[0] << std::endl;

    std::vector<double> dvec = {3.14, 1.414, 1.21};
    Blob<int> ivec2(dvec.begin(), dvec.end());
    std::cout << "size: " << ivec2.size() << " " << ivec2[1] << " " << ivec2[0] << std::endl;
}

void test_BlobPtr(){
    Blob<int> ivec = {1, 2, 3, 4, 5};
    BlobPtr<int> ip(ivec);
    std::cout << *ip << ", expected: 1" << std::endl;
    ++++*ip;
    std::cout << *ip << ", expected: 3" << std::endl;
    ++ip;
    std::cout << *ip << ", expected: 2" << std::endl;
    std::cout << *ip++ << ", expected: 2" << std::endl;
    std::cout << *ip << ", expected: 3" << std::endl;

    BlobPtr<int> ip1(ivec);
    BlobPtr<int> ip2(ivec);
    std::cout << (ip1 == ip2 ? "true" : "false") << std::endl;

    BlobPtr<std::string> ip3;
    BlobPtr<std::string> ip4;
    std::cout << (ip3 == ip4 ? "true" : "false") << std::endl;
}

int main(){
    test_Blob();
    test_BlobPtr(); 
    return 0;
}
