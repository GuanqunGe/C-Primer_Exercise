#include <iostream>
#include <vector>
#include <numeric>

int main(){

    std::vector<int> ints;
    std::cout << "Please enter a list of integers to sum: " << std::endl;
    for(int i; std::cin >> i; ) ints.push_back(i);

    std::cout << "The sum is : " << std::accumulate( ints.cbegin(), ints.cend(), 0) << std::endl;

    return 0;
}
