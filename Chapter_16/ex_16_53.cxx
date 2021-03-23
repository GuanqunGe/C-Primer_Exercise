#include <iostream>
#include <string>
#include <memory>

//------ VERSION 1-------

// this nonvariadic function needs to go before the variadic version.
// otherwise if a call to print() with more than 2 arguments is made, the variadic version will be instantiated
// and since the variadic version can not see this version, it will recursively call itself, and eventually there will be
// an instantiation error, complaining "no matching function for call to ‘print(std::ostream&)’" 
template <typename T>
std::ostream &print(std::ostream &os, const T &t){
    return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest){

    os << t << ", ";  //require type T and Args have << operator defined.
		      // this works on T of type char* as well.
    return print(os, rest...);
}


/*
//-------- VERSION 2-----------------
// This version does not work. The compiler still seems to try to instantiate print(std::ostream &), which causes compilation failre
// I don't know why it's still trying to instantiate that function....
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest){
     os << t << ", ";
     //std::cout << sizeof...(rest) << std::endl;
     unsigned size = sizeof...(rest);
     if(size == 0)
	return os;
     else 
	return print(os, rest...);
}
*/

int main(){
    int i = 9;
    print(std::cout, 3, std::string("hello")) << std::endl;
    print(std::cout, 3, "hello") << std::endl;
    print(std::cout, 3)  << std::endl;
    print(std::cout, 3, 3.14, "hello", std::string("you"), &i) << std::endl;

    //to test answer for 'ex_16_54'
    std::unique_ptr<int> ip(new int(1));
    //std::unique_ptr<int> ip = new int(1); //error, unique_ptr constructor that takes a built-in pointer is explicit. 
    print(std::cout, ip) << std::endl;
    return 0;

}
