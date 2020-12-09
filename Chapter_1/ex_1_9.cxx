#include <iostream>

int main(){

    //sum is the sum of num ranging from 50 to 100
    int sum=0, num = 50;

    while(num <= 100){
	sum += num;
 	num++;
    }

    //equivalent for loop
    //for(int i =50; i<=100; i++) sum+=i;
    

    std::cout << "The sum of numbers from 50-100 is " << sum << std::endl;
    return 0;
}
