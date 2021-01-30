#include "include/Sales_data.h"
#include <set>

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

using FuncP = bool (*) (const Sales_data&, const Sales_data &);
using Func = bool (const Sales_data&, const Sales_data &);
typedef bool Func2 (const Sales_data&, const Sales_data &);
typedef bool (*FuncP2) (const Sales_data&, const Sales_data &);

int main(){

    // method 1
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data &)>
     bookstore(compareIsbn);

    //method 2
    std::multiset<Sales_data, Func *> bookstore2(compareIsbn);

     //method 3
    std::multiset<Sales_data, FuncP > bookstore3(&compareIsbn);

     //method 4
    std::multiset<Sales_data, Func2 *> bookstore4(&compareIsbn);

    //method 5
    std::multiset<Sales_data, FuncP2 > bookstore5(&compareIsbn);

    return 0;
}
