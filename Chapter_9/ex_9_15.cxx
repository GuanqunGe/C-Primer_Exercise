//write a program to determine whether two vector<int>s are euqal

#include <iostream>
#include <vector>

bool is_equal(const std::vector<int> &vec1, const std::vector<int> &vec2){

    if(vec1.size() != vec2.size()) return false;

    //if two vector have same size, compare element pair one by one
    for(auto iter1 = vec1.begin(), iter2 = vec2.begin(); iter1 != vec1.end() &&  iter2!= vec2.end(); ++iter1, ++iter2){
    //for(auto iter1 = vec1.begin(), iter2 = vec2.begin(); iter1 != vec1.end(), iter2!= vec2.end(); ++iter1, ++iter2){   // wrong,comma statement only returns result of the second expression.
        if(*iter1 != *iter2) return false;
    }
    return true;
}

int main(){
    std::vector<int> vec1, vec2;
    std::cout << "Please enter a list of integers" << std::endl;
    for(int i; std::cin >> i; ) vec1.push_back(i);

    std::cout << "Please enter another list to compare" << std::endl;
    std::cin.clear();
    for(int i; std::cin >> i; vec2.push_back(i)) ;  //don't forget null statement

    std::cout << "Two vectors are equal? " << (is_equal(vec1, vec2) ? "true" : "false") << std::endl;

    return 0;
}
