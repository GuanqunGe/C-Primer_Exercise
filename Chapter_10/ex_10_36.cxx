#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main(){

    std::cout << "Please enter a list of integers" << std::endl;
    std::istream_iterator<int> in_iter(std::cin), in_eof;
    std::list<int> lst(in_iter, in_eof);

    auto iter = std::find(lst.crbegin(), lst.crend(), 0);
    if(iter == lst.crend()){
	std::cout << "No element of value 0 is found in the list" << std::endl;
    }
    else{
	std::cout << "Have found element: " << *iter << std::endl;

	// wrong, list iterators don't have - operation
	//std::cout << "the last element of 0 is the " << iter.base() - lst.cbegin() << "th element" << std::endl;
    }
	
    return 0;
}
