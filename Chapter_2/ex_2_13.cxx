#include <iostream> 

int i = 42;
int main(){

    int i=1000;
    int j=i;
    std::cout << "j is "<< j << std::endl;
    std::cout << "global i is "<< ::i << std::endl;
}
