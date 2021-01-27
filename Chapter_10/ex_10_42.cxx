#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>

std::ostream &print(std::ostream &os, const std::list<std::string> &lst){
    std::for_each(lst.begin(), lst.end(), [&](const std::string &s){ os << s << " "; } );

    return os;
}

void elimDups(std::list<std::string> &lst){

    std::cout << "\nBefore sorting\n" << std::endl;
    print(std::cout, lst) << std::endl;

    lst.sort();
    std::cout << "\nAfter sorting\n" << std::endl;
    print(std::cout, lst) << std::endl;
    
    lst.unique();
    std::cout << "\nAfter remove duplicate\n" << std::endl;
    print(std::cout, lst) << std::endl;
}

int main(){
    std::cout << "Please enter a list of strings " << std::endl;
    std::istream_iterator<std::string> in_iter(std::cin), in_eof;

    std::list<std::string> lst(in_iter, in_eof);
    elimDups(lst);

    return 0;
}
