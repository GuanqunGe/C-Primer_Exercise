#include <iostream>
#include "include/Sales_item.h"

int main(){

    Sales_item sum, current;

    std::cout << "Please enter the sales information" << std::endl;
    if(std::cin >> sum){
        while(std::cin >> current){
	    if(current.isbn() == sum.isbn()){
		sum += current;
	    }
	    else{
		std::cout << "The isbn number is different, print out previous sum " << sum << std::endl;
		sum = current;
	    }
	}

        std::cout << "The sum is " << sum << std::endl;
    }
    return 0;
}
