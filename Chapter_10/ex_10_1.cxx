#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    // fill the vector
    std::vector<int> vec;
    std::cout << "Please enter a list of integers" << std::endl;
    for(int i; std::cin >> i; ) vec.push_back(i);

    // grab the number to be found
    int num_to_find;
    std::cin.clear(); //validate the state of std::cin
    std::cout << "Please enter the number you wanna count" << std::endl;
    std::cin >> num_to_find;

    std::cout << num_to_find << " has appeared " << std::count(vec.begin(), vec.end(), num_to_find) << " times." << std::endl;

    return 0;
}
