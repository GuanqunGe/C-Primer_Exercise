#include <iostream>
#include <cstdlib>

struct numbered{
    //constructor
    numbered():mysn(rand()%1000), i(10){}
    //copy constructor
    //version 1
    //numbered(const numbered &in):mysn(in.mysn), i(in.i){}

    //version 2
    numbered(const numbered &in):mysn(rand()%1000), i(in.i){}

    int mysn;
    int i;
};

void f(numbered s) {std::cout << s.mysn << " " << s.i << std::endl; }
void f_1( const numbered &s){ std::cout << s.mysn << " " << s.i << std::endl;}

int main(){

    numbered a, b = a, c = b;
    std::cout << a.mysn << " " << a.i << std::endl;
    std::cout << b.mysn << " " << b.i << std::endl;
    std::cout << c.mysn << " " << c.i << std::endl;
    f_1(a); f_1(b); f_1(c);

    return 0;
}
