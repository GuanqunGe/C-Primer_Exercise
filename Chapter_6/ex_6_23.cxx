#include <iostream>
#include <iterator>

void print(const int *begin, const int *end){

    while(begin != end)
        std::cout << *begin++ << " ";
    std::cout << std::endl;
}

void print(const int *p, size_t size){

    for(size_t i = 0; i!= size; ++i)
        std::cout << *(p+i) << " ";
    std::cout << std::endl;
}

void print(const int (&arr)[2]){

    for(auto e : arr)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main(){

    int i = 0, j[2] = {0,1};
    print(std::begin(j), std::end(j));
    print(j, 2); // print(j, std::end(j)- std::begin(j)) is better.
    print(j);

    print(&i, 1);

    return 0;
}
