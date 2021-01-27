#include <iostream>
#include <vector>
#include <numeric>

int main(){

    std::vector<double> doubles;
    std::cout << "Please enter a list of integers to sum: " << std::endl;
    for(double d; std::cin >> d; ) doubles.push_back(d);

    //std::cout << "The sum is : " << std::accumulate( doubles.cbegin(), doubles.cend(), 0) << std::endl;
    std::cout << "The sum is : " << std::accumulate( doubles.cbegin(), doubles.cend(), 0.) << std::endl;

    return 0;
}

/* the type of 3rd argument determines the return type of accumulate, and the '+' operation
 * giving 0 as the 3rd argument means that accumulation is done in an integer way, and the algorithm will return an integer
 * that is, all the double elements will be truncated before summation
 */
