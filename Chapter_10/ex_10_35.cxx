#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::vector<int> ints = {0, 1,2,3,4,5,6,7,8,9};

    std::cout << "Method 1" << std::endl;
    std::vector<int> v2;
    std::reverse_copy(ints.cbegin(), ints.cend(), std::back_inserter(v2));
    std::for_each(v2.cbegin(), v2.cend(), [](int s){ std::cout << s << " " ;});
    std::cout << std::endl;


    std::cout << "Method 2" << std::endl;
    if(ints.cend() != ints.cbegin()){
	// only question here is that, once iterator is not valid anymore (not associated with container)
	// can we still use >= relational operator
	for( auto iter = ints.cend() - 1; iter >= ints.cbegin(); --iter)
	    std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
