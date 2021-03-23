// my naive guess is that, sizeof...(Args) should always match sizeof...(args)
#include <iostream>

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest){
    std::cout << sizeof...(Args) << " " << sizeof...(rest) << std::endl;
}

int main(){
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";

    foo(i, s, 24, d); 
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");

    //foo<int, int, int , int>(3, 3, 3); //error, the supplied function arguments should at least be the same amount as the specified template arguments.
    foo<int, int, int , int>(3, 3, 3, 3, 3); //OK
    return 0;
}
