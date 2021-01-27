#include "Sales_item.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // to use accumulate
#include <iterator>

// function named compareIsbn has already been defined in Sales_item.h
bool compareIsbn_v2(const Sales_item &s1, const Sales_item &s2){
    return s1.isbn() < s2.isbn();
}

int main(){

    std::cout << "Please enter your list of transactions" << std::endl;
    std::istream_iterator<Sales_item> in(std::cin), in_eof;
    std::ostream_iterator<Sales_item> out(std::cout, "\n");
    std::vector<Sales_item> trans(in, in_eof); // a vector of Sales_item

    // sort the vector according to book ISBN
    std::sort(trans.begin(), trans.end(), compareIsbn_v2);

    std::cout << "after sorting: \n" << std::endl;
    // do sum for book with same ISBN, and print info out
    auto first = trans.cbegin();
    while(first != trans.cend()){

	auto end = first + 1;
        
        while(std::find_if( end, trans.cend(), [first](const Sales_item &s){ return compareIsbn(*first, s); }) != trans.cend()){
        //while(std::find( end, trans.cend(), *first) != trans.cend()){
	// can't use find, as it uses == operator which compares isbn, unit_sold and revenue

            //can use std::find_if_not, to avoid this inner while loop
	    end = std::find_if(end, trans.cend(), [first](const Sales_item &s){ return compareIsbn(*first, s); });
	    ++end;
        }


        // accumulating, start with an empty object with the same isbn number
        out = std::accumulate(first, end, Sales_item(first->isbn()));

        first = end;
    }
    std::cout << std::endl;

    return 0;
}
