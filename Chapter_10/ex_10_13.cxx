#include <iostream>
#include <list>
#include <string>
#include <algorithm>

bool IsLong(const std::string &s){
    return s.size() > 4;
}

//print elements in iterator range
std::ostream &print(std::ostream &os, std::list<std::string>::const_iterator begin, std::list<std::string>::const_iterator end){

    for(; begin != end; ++begin)
	os << *begin << " ";
    return os;
}

int main(){

    std::list<std::string> str_lst;
    std::cout << "Please enter a list of strings " << std::endl;
    for(std::string s; std::cin >> s; str_lst.push_back(s)) {}

    //after running partition, words with length >= 5 will be in the left half   
    auto end_iter = std::partition(str_lst.begin(), str_lst.end(), IsLong);

    print(std::cout, str_lst.cbegin(), str_lst.cend()) << "\n" << std::endl;;
    print(std::cout, str_lst.cbegin(), end_iter) << "\n" << std::endl;

    return 0;
}
