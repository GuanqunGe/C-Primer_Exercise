#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>   //to use inserter
#include <algorithm>  //to use std::copy


//this print function is very repetitive.. 
std::ostream &print(std::ostream &os, const std::vector<int> vec){
    for(auto & e : vec)
	os << e << " ";
    return os;
}

std::ostream &print(std::ostream &os, const std::list<int> vec){
    for(auto iter= vec.begin(); iter != vec.end(); ++iter)
	os << *iter << " ";
    return os;
}

std::ostream &print(std::ostream &os, const std::deque<int> vec){
    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
	os << *iter << " ";
    return os;
}

int main(){

    std::vector<int> ints = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> copy1;
    std::list<int> copy2;
    std::deque<int> copy3;

    std::copy(ints.cbegin(), ints.cend(), std::back_inserter(copy1));
    std::copy(ints.cbegin(), ints.cend(), std::front_inserter(copy2));
    std::copy(ints.cbegin(), ints.cend(), std::inserter(copy3, copy3.begin()) );

    // expect, copy1 and copy3 to have the same order as ints, copy2 has reverse order
    print(std::cout, copy1) << std::endl;
    print(std::cout, copy2) << std::endl;
    print(std::cout, copy3) << std::endl;

    
    copy1.clear(); copy2.clear(); copy3.clear();

    //use inserters to add element one by one
    auto iter1 = std::back_inserter(copy1);
    auto iter2 = std::front_inserter(copy2);
    auto iter3 = std::inserter(copy3, copy3.begin());
    for(const auto &i : ints){
        //iter1 = i; // will do the same thing as *iter1 = i;
	*iter1 = i;  //iter1 is updated to be the end of sequence everytime
	*iter2 = i;  //iter2 is updated to be the front of sequence everytime
	*iter3 = i;  //iter3 always denotes the same elements
    }

    // expect copy1 and copy to have same order as ints, copy2 has reversed order
    print(std::cout, copy1) << std::endl;
    print(std::cout, copy2) << std::endl;
    print(std::cout, copy3) << std::endl;

    return 0;
}

