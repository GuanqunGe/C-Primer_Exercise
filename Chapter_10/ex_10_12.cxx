#include "Sales_data.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool compareIsbn(const Sales_data &sale1, const Sales_data &sale2){
    return sale1.isbn() < sale2.isbn();
}

std::ostream &print_vector(std::ostream &os, const std::vector<Sales_data> &vec){
    for(auto &e : vec){
	print(os, e) << "\n";
    }
    return os;
}

int main(){

    std::vector<Sales_data> vec{Sales_data("Bad Blood"), Sales_data("Cprimer"), 
				Sales_data("Harry Potter"), Sales_data("On writing well"), 
				Sales_data("Korean")};
    print_vector(std::cout, vec) << std::endl;
    std::sort(vec.begin(), vec.end(), compareIsbn);
    print_vector(std::cout, vec) << std::endl;
    return 0;
}
