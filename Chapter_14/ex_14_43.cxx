#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

int main(){

    std::vector<int> ivec = {89, 7, 5, 23, 4, 67, 53, 61, 98};
 
    int n;

    std::cout << "Number u want to use: ";
    std::cin >> n;
    while(true){
	auto pos = std::find_if_not(ivec.begin(), ivec.end(), std::bind(std::modulus<int>(), n, _1));
 	if(pos == ivec.end()) std::cout << n << " is not divisible by any element in the container" << std::endl;
  	else std::cout << n << " is divisible by " << *pos << " in the contrainer" << std::endl;

	std::cout << "Number u want to use: 0 to quit: ";
	std::cin >> n;
	if( !std::cin || n ==0) break;
    }

    return 0;
}
