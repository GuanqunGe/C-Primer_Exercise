#include <iostream>
#include "include/Sales_item.h"

int main(){
	Sales_item book;

	std::cout << "Please enter the book sale information"<< std::endl;
	while(std::cin >> book){
	     std::cout << book << std::endl;
	}
	return 0;
}
