#include <iostream>
#include <typeinfo>


// If we only declare these function but not define them, then during compilation, 
// compilation error will tell us what instantiation is picked for every call to these functions.

template <typename T> void f(T){
    std::cout << "void f(T) : " << typeid(T).name() << std::endl;
}
template <typename T> void f(const T*){
    std::cout << "void f(const T*) : " << typeid(T).name() << std::endl;
}
template <typename T> void g(T){
    std::cout << "void g(T) : " << typeid(T).name() << std::endl;
}
template <typename T> void g(T*){
    std::cout << "void g(T*) : " << typeid(T).name() << std::endl;
}

int main(){

    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    //(1)
    g(42); //instantiate void g<int>(int) and call it

    //(2)
    g(p); // instantiate void g<int>(int*) and call it.
	  // both void g<int*>(int*) and void g<int>(int*) are viable, but void g(T*) is more specialized
	  
    //(3)
    g(ci); // instantiate void g<int>(int) and call it.
	   // because top-level const is ignored

    //(4)
    g(p2); // instantiate void g<const int>(const int*) and call it
	   // both void g<const int*>(const int *) and void g<const int>(const int*) are viable but g(T*) is more specialized
	   

    //(5)
    f(42); // same as g(42), instantiate void f<int>(int) can call it

    //(6)
    f(p);  // instantiate void f<int*>(int*) and call it
	   // both void f<int*>(int*) and void f<int>(const int *) are viable, but the latter one requires const conversion.
	   
	   
    //(7)
    f(ci); //instantiates void f<int>(int) and call it.

    //(8)
    f(p2); // instantiate void f<int>(const int *) and call it
 	   // both void f<const int*>(const int*) and void f<int>(const int*) are viable, but the latter one is more specialized.
 	   
    return 0;

}
