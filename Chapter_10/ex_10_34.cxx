#include <iostream>
#include <iterator>
#include <vector>  //reverse iterator is included in here
#include <algorithm>

int main(){

    std::vector<int> ints = {0, 1,2,3,4,5,6,7,8,9};

    std::cout << "Method 1" << std::endl;
    std::for_each(ints.crbegin(), ints.crend(), [](int s){ std::cout << s << " "; });
    std::cout << std::endl;


    std::cout << "Method 2" << std::endl;
    std::ostream_iterator<int> o_iter(std::cout, " ");
    std::copy(ints.crbegin(), ints.crend(), o_iter);
    std::cout << std::endl;

    std::cout << "Method 3" << std::endl;
    for(auto iter = ints.crbegin(); iter != ints.crend(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;    
}
