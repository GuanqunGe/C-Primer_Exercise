#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main(){

    std::vector<int> ivec = {0, 1,2,3,4,5,6,7,8,9};

    //method 1
    std::list<int> ilst(ivec.crbegin() +2, ivec.crend() - 3);
    std::for_each(ilst.cbegin(), ilst.cend(), [](int i){std::cout << i << " ";} );
    std::cout << std::endl;

    //method 2 
    ilst.clear();
    std::reverse_copy(ivec.begin() + 3, ivec.end() -2, std::back_inserter(ilst));
    std::for_each(ilst.cbegin(), ilst.cend(), [](int i){std::cout << i << " ";} );
    std::cout << std::endl;
    
    return 0;
}
