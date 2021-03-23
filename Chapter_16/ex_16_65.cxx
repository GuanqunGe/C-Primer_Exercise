#include <iostream>
#include <sstream>
#include <string>

//general version
template <typename T> std::string debug_rep(const T &t){
    std::ostringstream oss;
    oss << t; //require T to have << operator
    return oss.str();
}

//pointer version
template <typename T> std::string debug_rep(T *p){
    std::ostringstream oss;
    oss << "Pointer: " << p;
    if(p)
	oss << ", points to: " << debug_rep(*p);
	//oss << " , points to: " << *p;
    else
	oss << ", null pointer";
    return oss.str();
}

// const char* version
// template specialization
template <>
std::string debug_rep(const char *p){
    return debug_rep(std::string(p));
}

// need to write char* version because, if I don't, then calling debug_rep on char* will pick the instantiated
// std::string debug_rep<char>(char *) function, because the other two viable function both require const conversion
// calling std::string debug_rep<char>(char *) is not what we want.
template <>
std::string debug_rep(char *p){
    return debug_rep(std::string(p));
}

int main(){
    int i = 9; char p[] = "hello";
    std::cout << debug_rep(std::string("Hello")) << std::endl; //debug<std::string>(const std::string &)
    std::cout << debug_rep(&i) << std::endl;  //debug_rep<int>(int*)
    std::cout << debug_rep("Hello") << std::endl;  //specialized debug_rep(const char *p);
    std::cout << debug_rep(p) << std::endl;        //specialized debug_rep(char*)

    return 0;
}
