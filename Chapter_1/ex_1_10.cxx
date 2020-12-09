#include <iostream>

int main(){

    int num = 10;
    while(num >= 0){
        std::cout << "num: " << num << std::endl;
	num--;
    }

    //equivalent for loop
    // for(int i=10; i >= 0; i--) std::cout << num << " ";    


    return 0;
}
