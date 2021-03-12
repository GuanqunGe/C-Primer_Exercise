#include <iostream>

class Base{
public:
    virtual int fcn() {std::cout << "Base::int fcn() " << std::endl; }
};

class D1 : public Base{
public:
    int fcn(int) { std::cout << "D1::int fcn(int) " << std::endl;}
    virtual void f2() {std::cout << "D1::void f2()" << std::endl;}
};

int main(){

    D1 d;
    //d.fcn(); //error, as fcn(int) hides fcn(), thus only fcn(int) will be considered.

    D1 *pd = &d;
    //pd->fcn(); //error, same reason as above

    Base &b = d;
    b.fcn();

    return 0;
}

/**************************************************************************
 * calling hidden virtual function through object/pointer/reference of derived class type will not compile, as
 * it's hidden by function defined with the same name but different parameter, thus the function call will not be matched.
 *
 * calling hidden virtual function through reference/pointer of static type - base class, but dynamically bound to derived
 * class will succefully call the hidden virtual function.
