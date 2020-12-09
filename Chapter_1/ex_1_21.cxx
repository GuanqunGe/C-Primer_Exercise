#include <iostream>
#include "include/Sales_item.h"

int main(){
    Sales_item A, B;
    std::cout << "please enter two sales items"<< std::endl;
    std::cin >> A >> B;
    if(A.isbn() == B.isbn()){
	std::cout << "The sum is " << A+B << std::endl;
	return 0;
    }
    else{
	 std::cerr << "The isbn are different" << std::endl;
	 return -1;
    }

}
