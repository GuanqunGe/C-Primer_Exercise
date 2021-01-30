#include "include/Sales_data.h"
#include <set>
#include <iostream>

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

int main(){

    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data &)>
     bookstore(compareIsbn);

    std::multiset<Sales_data>::iterator iter = bookstore.begin();
    if(iter == bookstore.end()) std::cout << "this multiset is empty" << std::endl;

    return 0;
}
