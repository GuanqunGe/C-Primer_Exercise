#include <iostream>
#include <forward_list>

std::ostream &print_lst(std::ostream &os, const std::forward_list<int> &flst){
    for(auto iter = flst.begin(); iter != flst.end(); ++iter)
	os << *iter << " ";
    return os;
}

int main(){

    std::forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto prev = flst.before_begin(), curr = flst.begin();

    print_lst(std::cout, flst) << std::endl;

    while(curr != flst.end()){
        if( *curr % 2){
	    curr = flst.erase_after(prev); //after erasion, prev still points to element (or off-the-beginning) before curr iterator.
        }
 	else{
	    prev = curr;
	    ++curr;
	}
    }

    print_lst(std::cout, flst) << std::endl;

    return 0;
}
