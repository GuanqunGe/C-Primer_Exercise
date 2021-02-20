#include <vector>
#include <iostream>

int f(){ return 0; }

int main(){
    std::vector<int> v1(100);

    int &&r1 = f(); // return of f() is through temporary object
    std::cout << r1 << std::endl;
  
    int &r2 = v1[0]; //subscript returns lvalue

    int &r3 = r1; //r1 is long live variable

    int &&r4 = v1[0] * f(); //arithmetic operation returns rvalue

    //Q: can we redirect rvalue reference?
    //My guess: no, it'd be like changing the temporary object
    //But, looks like we can
    r1 = 3; 
    std::cout << r1 << std::endl;

    return 0;
}
