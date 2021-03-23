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
std::string debug_rep(const char *p){
    return debug_rep(std::string(p));
}

// need to write char* version because, if I don't, then calling debug_rep on char* will pick the instantiated
// std::string debug_rep<char>(char *) function, because the other two viable function both require const conversion
// calling std::string debug_rep<char>(char *) is not what we want.
std::string debug_rep(char *p){
    return debug_rep(std::string(p));
}
