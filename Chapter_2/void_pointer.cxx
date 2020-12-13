#include <iostream>

int main(){

    int i = 34;
    void *p = &i;
    
    //can we print out the object void pointer points to?
    // no, we can't. This can't even compile
    // because don't know the type of object p points to, we can't do ANY operation
    std::cout << *p << std::endl;
    return 0;

}
