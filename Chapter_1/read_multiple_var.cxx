#include <iostream>

int main(){

    int sum =0, var = 0;
    std::cout << "Please enter the list of number you want to sum" << std::endl;


    // read the next number from standard input, until we hit end-of-file (ctrl-d in unix os), or an invalid input
    while(std::cin >> var){
	sum += var;
    }

    std::cout << std::endl;
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}
