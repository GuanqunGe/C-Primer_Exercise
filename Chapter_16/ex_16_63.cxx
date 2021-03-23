#include <iostream>
#include <vector>
#include <string>

template <typename T1, typename T2>
unsigned counter(const std::vector<T1> &s, T2 element){ //use two typename parameters, to allow comparison between convertible variables
    unsigned count = 0;
    for(auto &e : s){
	if( e == element) ++count;
    }
    return count;
}

int main(){

    std::vector<int> ivec{1,2,3,4,5, 7,9,8,3, 6};
    std::vector<double> dvec{1,2,3,4, 4.0, 8, 3.0};
    std::vector<std::string> svec{"Hello", "how","are", "you", "Hello", "back"};

    std::cout << counter(ivec, 3.0) << std::endl;
    std::cout << counter(dvec, 4) << std::endl;
    std::cout << counter(svec, std::string("Hello")) << std::endl;
    std::cout << counter(svec, "H") << std::endl; // T2 will be deducedd as const char*
						  // I thought this would be in error, but apparently 
						  // we can compare std::string with const char*

    //const char *p = "World";  //OK
    char p[] = "World";    //OK
    std::cout << ( std::string("World") == p ? "true" : "false") << std::endl;

    return 0;
}
