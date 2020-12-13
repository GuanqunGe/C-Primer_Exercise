/* simply curious about what's the type of expression (const int +1).
 */
#include <iostream>

int main(){

    const int i = 3;
    auto j = i;   //j is int
    j++;
    std::cout << " j is " << j << std::endl;

    auto k = i +1;  //k is int
    k++;
    std::cout << "k is "<< k << std::endl;


    decltype(i) m = 3;   // m is const int
    m++; //wrong, since m is const type
    std::cout << "m is " << m << std::endl;

    decltype(i+1) l;    // l is int!!!
    l = 2333;
    std::cout <<"l is " << l << std::endl; 
    return 0;


}
