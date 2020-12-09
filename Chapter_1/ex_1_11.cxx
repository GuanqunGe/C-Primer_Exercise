#include <iostream>

int main(){

    int num1, num2;
    std::cout << "Please enter two numbers to print values between them" << std::endl;
    std::cin >> num1 >> num2;

    if(num1 > num2){
       int temp = num1;
       num1 = num2;
       num2 = temp;
    }

    while(num1 <= num2){
 	std::cout << num1 << " ";
	num1++;
    }
    
    //equivalent for loop
    // for(int i= num1; i <= num2; i++) std::cout << i <<" ";


    return 0;
}
