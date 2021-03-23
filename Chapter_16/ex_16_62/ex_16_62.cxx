#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

int main(){

    std::unordered_multiset<Sales_data> set1;
    set1.insert(Sales_data());
    set1.insert(Sales_data("AAAAA"));
    set1.insert(Sales_data("AAAAA", 5, 30));
    set1.insert(Sales_data("BBBBB", 9, 10.4));
    set1.insert(Sales_data("AAAAA", 5, 30));

    //print out the set
    for(auto iter = set1.begin(); iter != set1.end(); ++iter)
	std::cout << *iter << std::endl;

    return 0;
}
