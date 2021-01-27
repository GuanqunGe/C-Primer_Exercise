#include <iostream>

int main(){

    int v = 10;
    auto f = [v]{return v;};

    std::cout << "v: " << v << ", f by value: " << f() << std::endl;
    v = 20;
    std::cout << "v: " << v << ", f by value: " << f() << std::endl;

    auto f_mutable = [v] () mutable {return ++v; };
    // a lambda capturing variable by value does not change the variable it captured
    // but every call to the mutable lambda will update its local copy of that variable.
    std::cout << "v: " << v << ", f_mutable: " <<  f_mutable() << std::endl;
    std::cout << "v: " << v << ", f_mutable: " << f_mutable() << std::endl;


    auto f_by_reference = [&v]{return v++; };
    std::cout << "v: " << v;
    std::cout << ", f_by_referece:" << f_by_reference() << std::endl;
    std::cout << "v: " << v  << ", f_by_referece:" << f_by_reference() << std::endl;
    std::cout << "v: " << v << std::endl;
    // I think I find one thing:
    // when two expressions are in one std::cout line, we can not assume they will be evaluated from left to right. 
    
    return 0;
}
