//write a program that compares elements list<int> with vector<int>
#include <iostream>
#include <vector>
#include <list>

bool have_same_elements(const std::list<int> &lst, const std::vector<int> &vec){
    if(lst.size() != vec.size() ) return false;

    //if list and vector have same length, then compare element
    auto iter1 = lst.begin();
    auto iter2 = vec.begin();
    for(; iter1 != lst.end() && iter2 != vec.end(); ++iter1, ++iter2){
        if( *iter1 != *iter2 ) return false;
    }

    return true;
}


int main(){
    std::list<int> lst{1, 2, 3, 4, 5};
    std::vector<int> vec{1, 2, 2, 4, 5};
    std::cout << "Two list and vectors have same elements? " << (have_same_elements(lst, vec) ? "true" :"false") << std::endl;
    return 0;
}
