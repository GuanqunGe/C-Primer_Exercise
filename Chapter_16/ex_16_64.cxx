#include <iostream>
#include <vector>
#include <string>
#include <cstring>

template <typename T1, typename T2>
unsigned counter(const std::vector<T1> &s, T2 element){
    unsigned count = 0;
    for(auto &e : s){
	if( e == element) ++count;
    }
    return count;
}

// template specilization
template <>
unsigned counter(const std::vector<const char*> &s, const char *element){
    unsigned count = 0;
    for(auto &e : s){ //type of e: const char * const &
	if(strcmp(e, element) == 0) ++count;
    }
    //std::cout << "counter(const std::vector<const char*> &s, const char *element)" << std::endl;
    return count;
}

int main(){

    std::vector<const char*> svec{"Hello", "how","are", "you", "Hello", "back"};
    std::cout << counter(svec, "Hello") << std::endl; 

    char p1[] = "Hello";
    char p2[] = "how";
    char p3[] = "are";
    char p4[] = "you";
    char p5[] = "Hello";
    char p6[] = "back";
    std::vector<char*> svec2{p1,p2,p3,p4,p5,p6}; //works for vector<char*> as well
    std::cout << counter(svec, "Hello") << std::endl;
    return 0;
}
