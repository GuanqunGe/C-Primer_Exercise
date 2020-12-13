#include <iostream>
int main(){

    //int month = 9, day = 7;
    int month = 09, day = 07;   //not valid, as in octal literal, there should be digit equal to or larger than 8
    std::cout << month << " " << day << std::endl;
}
