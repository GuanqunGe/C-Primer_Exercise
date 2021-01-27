#include <iostream>

int main(){

    //int f = [](int i1, int i2) -> int {return i1+i2;};  //wrong
    //type of f is not the return type, instead f is a function pointer
    int (*f) (int, int) = [](int i1, int i2) -> int {return i1+i2;};
    //auto f = [](int i1, int i2) -> int {return i1+i2;};

    int i1, i2;
    while(std::cin){
    	std::cout << "Enter two integers to add" << std::endl;
	std::cin >> i1 >> i2;
        std::cout << "Sum: " << f(i1, i2) << std::endl;
    }

    return 0;
}
