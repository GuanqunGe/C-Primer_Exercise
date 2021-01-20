// if we don't assigned the result of insert to begin, the program will have undefined behaviors.
// because we are trying to add elements before begin iterator, thus after the insertion, begin iterator will be invalid, and further operation on it will be undefined.

// what I get from running the code: segmentation fault

#include <vector>
#include <iostream>

int main(){
    std::vector<int> ivec = {1, 2, 3, 4, 5};
   
    auto begin = ivec.begin();
    while(begin != ivec.end()){
	++begin;
        ivec.insert(begin, 42);
	++begin;
    }

    for(begin = ivec.begin(); begin != ivec.end(); ++begin)
	std::cout << *begin << " ";
    std::cout << std::endl;

    return 0;
}
