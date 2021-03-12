#include <iostream>

class Base{
public:
    virtual int fcn() {std::cout << "Base::int fcn()" << std::endl; }
};

class D1 : public Base{
public:
    //override Base::fcn()
    int fcn() {std::cout << "D1::int fcn() " << std::endl; }

    //create a new function, so that fcn() function is overloaded
    int fcn(int) {std::cout << "D1::int fcn(int)" << std::endl;}

     virtual void f2() { std::cout << "D1::void f2() " << std::endl;}

};


/*
// version 1 of class D2
class D2 : public D1{
public:
    //not override D1::fcn(int), instead inherits D1::fcn(int), but hides it
    int fcn(int) {std::cout << "D2::int fcn(int)" << std::endl;}

    //override virtual function D1::fcn()
    int fcn() {std::cout << "D2::int fcn() " << std::endl;}
    //override virtual function D1::f2()
    void f2(){std::cout << "D2::void f2() " << std::endl;}
};
*/

// version 2 of class D2
// if for D2 class, we want to override int fcn() function, but still want to keep the overloaded fcn() functions
// we can:
class D2 : public D1{
 public:
    //bring all overloaded fcn() function in D1 class into scope
    using D1::fcn;
   
    //override the fcn() fucntion
    int fcn() {std::cout << "D2::int fcn()" << std::endl; }

    void f2() {std::cout << "D2::void f2()" << std::endl; }
};

int main(){
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();  //call Base::fcn()
    bp2->fcn();  //call D1::fcn()
    bp3->fcn();   //call D2::fcn()

    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2->f2(); // error, as Base class doesn't have f2() member function
    d1p->f2(); // call D1::f2()
    d2p->f2(); // call D2::f2()

    Base *p1 = &d2obj;  D1 *p2 = &d2obj;  D2 *p3 = &d2obj;
    //p1->fcn(43); //error, as Base class doesn't have fcn(int) member
    p2->fcn(43); // call D1::fcn(int) 
    p3->fcn(43); // call D2::fcn(int) if version 1 of D2 class is used
		 // call D1::fcn(int) if version 2 of D2 class is used

    return 0;
}
