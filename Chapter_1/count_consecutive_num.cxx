#include <iostream>

int main(){

    int currentVal=0, val=0, count;

    std::cout << "Please enter a list of numbers to count" << std::endl;
//    if(std::cin >> val){
//	currentVal = val;
      if(std::cin >> currentVal){
	count =1;

	while(std::cin >> val){
	    if(val == currentVal) count++;
	    else{
		std::cout << currentVal<< " has appeared " << count << " times" << std::endl;
		currentVal = val;
		count = 1;
	    } 
	}
    
        std::cout << currentVal<< " has appeared " << count << " times"
<< std::endl;

    }

    return 0;
}
