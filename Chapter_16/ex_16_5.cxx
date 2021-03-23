#include <iostream>

template <typename T, unsigned N>
void print(const T (&array)[N]){
    for( auto elem : array)
	std::cout << elem << std::endl;
}

int main(){

    std::cout << "Print out string literal in letters" << std::endl;
    print("Hey"); //will also print the trailing '\0'

    std::cout << "Print out int array" << std::endl;
    int iarray[] = {1,2,3,4,5};
    print(iarray);

    return 0;
}
