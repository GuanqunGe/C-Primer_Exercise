/*************************************
 * because iter += n is only available to sequential containers that allow random access
 */
#include <iostream>
#include <list>
#include <forward_list>

//function that removes even-valued elements and duplicate odd-valued element in LIST
void dup_odd_list(std::list<int> &lst){

    auto iter = lst.begin();
    while( iter != lst.end()){
        if( *iter % 2){
	    lst.insert( iter, *iter);
	    ++iter;  // for list, iterator stay valid after erasing/inserting elements
		     // ++iter is to move on to the next unprocessed element
	}
        else iter = lst.erase(iter);
    }

}

//function that removes even-valued elements and duplicate odd-valued element in FORWARD LIST
void dup_odd_flst(std::forward_list<int> &flst){

    auto prev = flst.before_begin(),
	 iter = flst.begin();
    while(iter != flst.end()){
	if( *iter % 2){
	    flst.insert_after(prev, *iter);
	    prev = iter; //for forward list, iterators stay valid after erasing/inserting elements
	    ++iter;      //move on to the next unprocessed element
 	}
	else{
	    iter = flst.erase_after(prev);
        }
    }

}

// function that prints a list
std::ostream &print_lst(std::ostream &os, const std::list<int> &lst){
    for(auto iter = lst.begin(); iter != lst.end(); ++iter)
	os << *iter << " ";
    return os;
}

//function that prints a forward list
std::ostream &print_flst(std::ostream &os, const std::forward_list<int> &flst){
    for(auto iter = flst.begin(); iter != flst.end(); ++iter)
	os << *iter << " ";
    return os;
}

int main(){
    std::list<int> lst {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::forward_list<int> flst(lst.begin(), lst.end());

    print_lst( std::cout, lst) << std::endl;
    dup_odd_list(lst);
    print_lst( std::cout, lst) << std::endl;

    print_flst( std::cout, flst) << std::endl;
    dup_odd_flst(flst);
    print_flst( std::cout, flst) << std::endl;

    return 0;
}
