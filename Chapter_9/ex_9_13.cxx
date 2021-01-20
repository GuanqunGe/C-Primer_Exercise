/* to initialize a vector<double> from either a list<int> or vector<int>, I would use
 *   vector<double> (list<int>::iterator begin, list<int>::iterator end)
 *   vector<double> (vector<int>::iterator begin, vector<int>::iterator end)
 */

#include <vector>
#include <list>
#include <iostream>

int main(){

    std::list<int> lst{1, 2, 3, 4, 5};
    std::vector<int> ints(10, 1);

    std::vector<int> vec1(lst.cbegin(), lst.cend());
    std::vector<int> vec2(ints.cbegin(), ints.cend());

    for(const auto e: vec1) std::cout << e << " ";
    std::cout << std::endl;

    for(const auto e: vec2) std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}
