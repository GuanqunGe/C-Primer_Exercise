#include <iostream> // use iostream library

int main(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1=0, v2=0;

    //takes input from outside world, no matter how many numbers you entered, it only takes the first two.
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and "<< v2 << " is " << v1+v2<< std::endl;


    //without std::endl, this ostream will still be printed out.
    std::cout<< "Hello, are you there?";
    return 0;

}
