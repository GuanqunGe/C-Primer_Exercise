#include <iostream>
#include "include/Sales_item.h"

int main(){

    Sales_item sum, current;
    if(std::cin >> sum){
	int transaction = 1;
	while(std::cin >> current){

	    if(current.isbn() == sum.isbn()){
	    	sum += current;
	    	transaction ++;
	    }
	    else{
	        std::cout << sum.isbn() << " has " << transaction << " transactions" << std::endl;
	        sum = current;
		transaction= 1;
	    }
	} // end of while 
	std::cout << sum.isbn() << " has " << transaction << " transactions" << std::endl;
	return 0;
    } //end of if
    else{
	std::cerr << "No data input?" << std::endl;
	return -1;
    }

}
