#include <iostream>
#include "Sales_data.h" //copied from Chapter_14/ex_14_2.cxx

template <typename T>
int compare(const T &v1, const T &v2){
    if(v1 < v2) return 1;
    if(v2 < v1) return -1;
    return 0;
}

template <typename T>
int compare_all(const T &v1, const T &v2){
    if(std::less<T>()(v1, v2)) return 1;
    if(std::less<T>()(v2, v1)) return -1;
    return 0;
}

int main(){

    Sales_data item1("AAA", 5, 35.4);
    Sales_data item2("BBB", 6, 13.5);
   
    //std::cout << compare(item1, item2) << std::endl; //error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
    std::cout << compare_all(&item1, &item2) << std::endl;

    return 0;
}
