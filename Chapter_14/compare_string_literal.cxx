#include <iostream>
#include <string>

int main(){
    // use == to compare string literals seems to be actually comparing the content, instead 
    // of comparing const char pointers
    std::cout << " \"hello\" == \"hello\" " << ("hello" == "hello" ? "yes": "no" ) << std::endl;
    std::cout << " \"hello\" == \"world\" " << ("hello" == "world" ? "yes": "no" ) << std::endl; 

    return 0;
}
