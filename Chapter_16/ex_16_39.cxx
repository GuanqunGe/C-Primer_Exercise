#include <iostream>
#include <string>

template <typename T>
int compare(const T &v1, const T &v2){
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}

int main(){

    //compare("Hello", "Hiii"); //error, T will be deduced as const char[], and these two arguments have different sizes.

    int result = compare<std::string>("Hello", "Hiiii");
    std::cout << result << std::endl;

    return 0;
}
