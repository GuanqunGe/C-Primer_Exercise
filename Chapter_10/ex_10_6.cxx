#include <vector>
#include <iostream>
#include <algorithm>

int main(){

    std::vector<int> ints{0, 1,2,3,4,5,6,7,8,9};

    for(const auto &i : ints)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Reset to 0.." << std::endl;
    std::fill_n(ints.begin(), ints.size(), 0);

    for(const auto &i : ints)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
