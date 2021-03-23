#include <iostream>
#include <vector>
#include <set>
#include <string>

template <class T>
void print(const T &t){

    for(typename T::const_iterator iter = t.begin(); iter != t.end(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;
}

int main(){

    print(std::vector<int>({1,2,3,4,5,6,7}));
    std::cout << "================== " << std::endl;
    //print({"Hello", "How", "are", "you", "?"}); //error, cannot deduce type of T.
    print(std::initializer_list<std::string>{"Hello", "How", "are", "you", "?"});
    std::cout << "================== " << std::endl;
    print(std::set<std::string>({"Hi", "I", "am", "good"}));

    return 0;
}
