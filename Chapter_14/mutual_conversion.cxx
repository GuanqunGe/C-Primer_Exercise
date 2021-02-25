#include <iostream>

struct B;

struct A{
    A()=default;
    A(const B&) { 
	std::cout << "A(const B&)" << std::endl;
    };
};

struct B{
    operator A() const{ 
	std::cout << "B::operator A()" << std::endl;
	return A(); }
};

A f(const A&){}

int main(){

    B b;

    //both the f() and cast run just fine...
    A a = f(b);
    A a2 = f(static_cast<A>(b));

    return 0;
}
