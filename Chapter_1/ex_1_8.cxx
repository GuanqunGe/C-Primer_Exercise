#include <iostream>

int main(){

    std::cout << "/*";
    std::cout << "*/";
    // /* will pair will any */ it sees , no matter insides the quote mark or not.
    //std::cout << /* "*/" */;
    std::cout << /* "*/" */";


    // in this case, */ pairs with the neast /* it sees.
    // but normally between /*  */ pair any character that's not */ is allowed. 
    std::cout << /* "*/" /* "/*" */;
    return 0;
}
