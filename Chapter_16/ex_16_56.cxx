#include <iostream>
#include <string>

template <typename T>
std::ostream &print(std::ostream &os, const T &t){
    return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest){
    os << t << ", ";
    return print(os, rest...);
}

// function errorMsg needs to be called with at least two arguments
template <typename T, typename... Args>
std::ostream &errorMsg(std::ostream &os, const T &t, const Args&... rest){
    return print(os, t, rest...);
}

int main(){
    int i = 0;
    std::string s1 = "function not found";
    errorMsg(std::cout, "Error:", 1, s1, 2, "memory leak: ", &i) << std::endl;

    return 0;
}
