#include <iostream>
#include <initializer_list>

//initializer_list is standard library type, there goes "std::" 
int Sum(std::initializer_list<int> il){

    int sum = 0;
    for(auto begin = il.begin(); begin != il.end(); ++begin)
        sum += *begin;   //dereference has higher precedence than compound assignment.
 
    return sum;
}

int main(){

    std::cout << "1+2+3+4+5+6+10 = " << Sum({1, 2, 3, 4, 5, 6, 10}) << std::endl;
    std::cout << "Expect 31 " << std::endl;

    return 0;
}
